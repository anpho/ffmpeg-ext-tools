#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <vector>
#include <QSettings>
#include <QDropEvent>
#include <QDragEnterEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setFiles(int argc,char* argv[]);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);


private slots:
    void on_actionGet_ffmpeg_exe_triggered();

    void on_btn_cancel_clicked();

    void on_actionExit_2_triggered();

    void on_lineEdit_file_surfix_editingFinished();

    void on_btn_add_file_clicked();

    void on_btn_remove_file_clicked();

    void on_actionAdd_Files_triggered();

    void on_actionRemove_triggered();

    void on_btn_selectAll_clicked();

    void on_btn_selectNone_clicked();

    void on_btn_ok_clicked();

    void on_actionLocate_ffmpeg_exe_triggered();

    void on_btn_choose_path_clicked();

    void on_actionAbout_FFmpeg_triggered();

    void on_actionAbout_triggered();

    void on_actionAboutQt_triggered();

private:
    Ui::MainWindow *ui;
    QSettings settings;
};

#endif // MAINWINDOW_H
