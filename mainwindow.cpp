/* Copyright 2022 Yisus7u7 <dev.yisus@hotmail.com>

* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
* USA.
*/

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
