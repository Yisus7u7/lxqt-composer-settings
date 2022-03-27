#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QProcess;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

    void on_btn_use_picom_clicked();

    void on_btn_use_xorg_clicked();

    void on_btn_edit_PicomConf_clicked();

    void on_btn_edit_XorgConf_clicked();

    void on_actionAbout_Qt_triggered();

private:
    Ui::MainWindow *ui;
    QProcess *TermuxProcess;
};
#endif // MAINWINDOW_H
