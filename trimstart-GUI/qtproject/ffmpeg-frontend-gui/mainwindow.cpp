#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QProcess>
#include "dialogprocess.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFiles(int argc, char *argv[])
{
    ui->listWidget_files->clear();

    for (int i = 1;i<argc;i++){
        ui->listWidget_files->addItem(QString::fromLocal8Bit(argv[i]));
    }
}

void MainWindow::on_actionGet_ffmpeg_exe_triggered()
{
    QDesktopServices::openUrl(QUrl("http://ffmpeg.org/download.html"));
}

void MainWindow::on_btn_cancel_clicked()
{
    exit(0);
}

void MainWindow::on_actionExit_2_triggered()
{
    exit(0);
}

void MainWindow::on_lineEdit_file_surfix_editingFinished()
{
    if (ui->lineEdit_file_surfix->text().isEmpty()){
        if (ui->radio_original_folder->isChecked() || (ui->radio_other_folder->isChecked()&&ui->lineedit_folder_path->text().isEmpty())){
             QMessageBox::information(this,tr("Error"),tr("You must specify a surfix to avoid overwriting the original file."));
        }
    }
}

void MainWindow::on_btn_add_file_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
          fileDialog->setWindowTitle(tr("Select Media Files"));
          fileDialog->setFileMode(QFileDialog::ExistingFiles);
          if(fileDialog->exec() == QDialog::Accepted) {
              foreach (QString filename , fileDialog->selectedFiles()){
                  QList<QListWidgetItem*> resultlist = ui->listWidget_files->findItems(filename,Qt::MatchFixedString);
                  if (resultlist.size()>0){
                      continue;
                  }else{
                      qDebug()<< "Add File: "<<filename<<endl;
                      ui->listWidget_files->addItem(filename);
                  }
              }
          } else {
                  qDebug()<<"No files selected." <<endl;
          }
}

void MainWindow::on_btn_remove_file_clicked()
{
    QList<QListWidgetItem*> selectedItems = ui->listWidget_files->selectedItems();
    QList<QListWidgetItem*>::Iterator it;
    for (it = selectedItems.begin();it != selectedItems.end();it++){
        QListWidgetItem* currentItem = *it;
        int currentRow = ui->listWidget_files->row(currentItem);
        QListWidgetItem* item2delete = ui->listWidget_files->takeItem(currentRow);
        ui->listWidget_files->removeItemWidget(item2delete);
        delete item2delete;
    }
}

void MainWindow::on_actionAdd_Files_triggered()
{
     MainWindow::on_btn_add_file_clicked();
}

void MainWindow::on_actionRemove_triggered()
{
    MainWindow::on_btn_remove_file_clicked();
}

void MainWindow::on_btn_selectAll_clicked()
{
    ui->listWidget_files->selectAll();
}

void MainWindow::on_btn_selectNone_clicked()
{
    ui->listWidget_files->clearSelection();
}

void MainWindow::on_btn_ok_clicked()
{
    // Check if Files added.
    if (ui->listWidget_files->count()==0){
        QMessageBox::information(this,tr("Error"),tr("No file to process."));
        return;
    }

    // check if ffmpeg is specified
    QString bin = settings.value("ffmpegbin","").toString();
    QFile ffmpeg(bin);
    if (!ffmpeg.exists()){
        QMessageBox::information(this,tr("Error"),tr("FFmpeg is not specified"));
        return;
    }

    // Check if overwrite occured
    if (ui->lineEdit_file_surfix->text().isEmpty()){
        if (ui->radio_original_folder->isChecked() || (ui->radio_other_folder->isChecked()&&ui->lineedit_folder_path->text().isEmpty())){
             QMessageBox::information(this,tr("Error"),tr("You must specify a surfix to avoid overwriting the original file."));
             return;
        }
    }

    QStringList qstrlist;
    for (int i = 0;i<ui->listWidget_files->count();i++){
        qstrlist.append( ui->listWidget_files->item(i)->text());
    }

    DialogProcess dp(this);
    dp.setup_files(qstrlist);
    QString ffbin = settings.value("ffmpegbin","./ffmpeg.exe").toString();
    QString sec = ui->comboBox_secends_to_trim->currentText();
    QString targetFolder;
    if (ui->radio_original_folder->isChecked()){
        targetFolder=".";
    }else if (ui->radio_other_folder->isChecked()){
        if (ui->lineedit_folder_path->text().isEmpty()){
            targetFolder = ".";
        }else{
            targetFolder = ui->lineedit_folder_path->text();
        }
    }
    dp.setup_params(ffbin,sec,ui->lineEdit_file_surfix->text(),targetFolder);
    dp.process();
    dp.exec();
}

void MainWindow::on_actionLocate_ffmpeg_exe_triggered()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Select FFmpeg.exe"));
    fileDialog->setNameFilter("ffmpeg.exe (*.exe)");
       if(fileDialog->exec() == QDialog::Accepted) {
           qDebug() << "using FFmpeg bin:" << fileDialog->selectedFiles()[0];
           settings.setValue("ffmpegbin",fileDialog->selectedFiles()[0]);
       } else {
           QMessageBox::information(NULL, tr("FFmpeg Missing"), tr("You didn't select any ffmpeg executable."));
       }
}

void MainWindow::on_btn_choose_path_clicked()
{
    QString foldername= QFileDialog::getExistingDirectory(this,tr("Choose target folder"));
    qDebug()<<foldername;
    ui->lineedit_folder_path->setText(foldername);
    ui->lineedit_folder_path->setToolTip(foldername);
}

void MainWindow::on_actionAbout_FFmpeg_triggered()
{
    QDesktopServices::openUrl(QUrl("http://ffmpeg.org/about.html"));
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,tr("About this program"),tr("FFmpeg Ext\n\nI build this program in order to remove the beginning AD of Media Files,\nIt's simple and still under development.\nFeatures:\n1. Trim some seconds from the beginning of media files.\n2. CN & EN language included.\n\nMerrick Zhang\nanphorea@gmail.com"));
}

void MainWindow::on_actionAboutQt_triggered()
{
    QMessageBox::aboutQt(this);
}
