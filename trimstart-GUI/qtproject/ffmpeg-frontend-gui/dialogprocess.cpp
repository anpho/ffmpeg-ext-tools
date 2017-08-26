#include "dialogprocess.h"
#include "ui_dialogprocess.h"
#include <QMessageBox>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
DialogProcess::DialogProcess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogProcess)
{
    q=new QProcess(this);
    q->setReadChannel(QProcess::StandardOutput);
    connect(q,SIGNAL(channelReadyRead(int)),this,SLOT(channel_ready_read(int)));
    connect(q, SIGNAL(started()), this, SLOT(start_process()));
    connect(q, SIGNAL(readyReadStandardOutput()), this, SLOT(start_read_output()));
    connect(q, SIGNAL(readyReadStandardError()), this, SLOT(start_read_err_output()));
    connect(q, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(finish_process(int, QProcess::ExitStatus)));
    ui->setupUi(this);
    ui->checkbox_open_folder_when_complete->setChecked(settings.value("open_folder_when_complete",false).toBool());
}

DialogProcess::~DialogProcess()
{
    delete q;
    delete ui;
}

/* SLOTS */

void DialogProcess::start_process(){
    ui->label_filename->setText(tr(">>") + _files.at(currentProcessingFile));
}

void DialogProcess::channel_ready_read(int channelid)
{
    Q_UNUSED(channelid);
}
void DialogProcess::start_read_output(){
    QString ssd(q->readAllStandardOutput());
    QStringList qsl = ssd.split(QRegExp("\\n"));
    ssd = QString( qsl.last());
    if (ssd.isEmpty()){
        return;
    }
    if (!ssd.contains("=")){
        return ;
    }
    ui->lbl_status->setText(ssd);
    qDebug()<<qsl.last();
}
void DialogProcess::start_read_err_output(){
    QString ssd(q->readAllStandardError());
    QStringList qsl = ssd.split(QRegExp("\\n"));
    ssd = QString( qsl.last());
    if (ssd.isEmpty()){
        return;
    }
    if (!ssd.contains("=")){
        return ;
    }
    ui->lbl_status->setText(ssd);
    qDebug()<<qsl.last();
}
void DialogProcess::finish_process(int exitcode, QProcess::ExitStatus status){
    ui->progressBar->setValue(currentProcessingFile+1);
    if (currentProcessingFile<_files.count()-1){
        process();
    }else{
        if (ui->checkbox_open_folder_when_complete->isChecked()){
            // checked? open folder.
            QDesktopServices::openUrl(QUrl::fromLocalFile(_lastTargetFolder));
        }
        q->terminate();
        this->close();
    }
}

void DialogProcess::setup_files(QStringList files){
    _files.clear();
    _files+= files;
    qDebug()<<_files.count()<<" files to process";
    ui->progressBar->setMaximum(_files.count());
    ui->progressBar->setMinimum(0);
    currentProcessingFile = -1;
}

void DialogProcess::setup_params(QString binpath, QString seconds, QString filesurfix, QString targetFolder){
    _binpath = binpath;
    qDebug()<<_binpath;
    q->setProgram(_binpath);

    _seconds = seconds;
    qDebug()<<_seconds;
    _filesurfix = filesurfix;
    qDebug()<<_filesurfix;
    _targetFolder = targetFolder;
    qDebug()<<_targetFolder;
}

void DialogProcess::process(){
    currentProcessingFile ++;

    q->setProgram(_binpath);
    q->setArguments(gen_cmd_line(_files.at(currentProcessingFile),_filesurfix,_targetFolder));
    q->open();
    //    q->start();
    if (false == q->waitForStarted())
    {
        qDebug("Can't start.");
        QMessageBox::information(this,tr("Error"),tr("FFmpeg can't be invoked, please report to developer."));
    }
}

QStringList DialogProcess::gen_cmd_line(QString filepath,QString surfix,QString targetfolder){
    //TODO: change to qstringlist
    QStringList params ;
    params<<"-y";
    params<<"-ss"<< _seconds ;
    params<<"-i"<< filepath;
    params<<"-codec"<<"copy";

    QFileInfo qfi(filepath);
    QString targetFilename ;
    if (targetfolder == "."){
        _lastTargetFolder = qfi.path();
        targetFilename = qfi.path() +"/"+ qfi.completeBaseName() + surfix + "."+qfi.suffix();
    }else{
        _lastTargetFolder = targetfolder;
        targetFilename = targetfolder +"/"+ qfi.completeBaseName() + surfix +"."+ qfi.suffix();
    }
    params<<targetFilename;
    qDebug()<< "arguments : " << QString(params.join(" ")) ;
    return params;
}

void DialogProcess::on_pushButton_clicked()
{
    q->terminate();
    this->close();
}

void DialogProcess::on_checkbox_open_folder_when_complete_toggled(bool checked)
{
    settings.setValue("open_folder_when_complete",checked);
}
