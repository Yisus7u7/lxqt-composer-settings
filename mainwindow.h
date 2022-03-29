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
