#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QObject *shell;
    TermuxProcess = new QProcess(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Variables del programa

QString program = "/data/data/com.termux/files/usr/var/lib/lxqt-compositor/lxqt-compositor.sh";
//QStringList arguments;
//

static int alert(){
    QString info;
    info = "Restart the session to apply the changes.";
    QMessageBox::information(nullptr, "Info", info);
    return 0;
}


void MainWindow::on_actionAbout_triggered()
{
    QString txt;
    txt = "lxqt-composer-settings It is an application\n";
    txt+= "to manage compositing effects in lxqt\n";
    txt+= "Made by @Yisus7u7 (Jesús Chapman) <dev.yisus@hotmail.com>";
    QMessageBox::about(this, "About LXQt composer settings", txt);
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_btn_use_picom_clicked()
{
    QStringList arguments;
    arguments <<"--use-picom";
    TermuxProcess->execute(program, arguments);
    alert();
}

void MainWindow::on_btn_use_xorg_clicked()
{
    QStringList arguments;
    arguments <<"--use-xorg";
    TermuxProcess->execute(program, arguments);
    alert();
}

void MainWindow::on_btn_edit_PicomConf_clicked()
{
    QStringList arguments;
    arguments <<"--picom-conf";
    TermuxProcess->execute(program, arguments);
    alert();
}

void MainWindow::on_btn_edit_XorgConf_clicked()
{
    QStringList arguments;
    arguments <<"--xorg-conf";
    TermuxProcess->execute(program, arguments);
    alert();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "Qt");
}
