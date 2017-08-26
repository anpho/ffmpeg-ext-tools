#ifndef DIALOGPROCESS_H
#define DIALOGPROCESS_H

#include <QDialog>
#include <QProcess>
#include <QFileInfo>
#include <QSettings>

namespace Ui {
class DialogProcess;
}

class DialogProcess : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProcess(QWidget *parent = 0);
    ~DialogProcess();
    void setup_files(QStringList files);
    void setup_params(QString binpath, QString seconds, QString filesurfix, QString targetFolder);
    QStringList gen_cmd_line(QString filepath,QString surfix,QString targetfolder);
    void process();
private:
    Ui::DialogProcess *ui;
    QString _binpath;
    QString _seconds;
    QString _filesurfix;
    QString _targetFolder;
    QString _lastTargetFolder;
    QStringList _files;
    QProcess *q;
    QSettings settings;
    int currentProcessingFile = -1;
private slots:
    void start_process();
    void channel_ready_read(int channelid);
    void start_read_output();
    void start_read_err_output();
    void finish_process(int exitcode, QProcess::ExitStatus status);
    void on_pushButton_clicked();
    void on_checkbox_open_folder_when_complete_toggled(bool checked);
};

#endif // DIALOGPROCESS_H
