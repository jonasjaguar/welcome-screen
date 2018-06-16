#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QListWidget"
#include "QStackedWidget"
#include "QPushButton"
#include "QLabel"
#include "QPixmap"
#include "QProcess"
#include "QApplication"
#include "QDir"
#include "QFile"
#include "QCheckBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->categoryListWidget->setFocus();
    if (!(QFile::exists(QDir::homePath() + "/.config/autostart/welcome-screen.desktop"))) {
        ui->autostartCheckBox->setChecked(false);
    }
    ui->os_logo->setPixmap(QPixmap("/usr/share/about-distro/distribution-logo.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_categoryListWidget_currentRowChanged(int currentRow)
{
    ui->contentPages->setCurrentIndex(currentRow);
}

//Driver Manager
void MainWindow::on_launchButton_1_released()
{
    QProcess process;
    process.startDetached("kioclient5 exec /usr/share/applications/driver-manager.desktop");
}

//Software Center
void MainWindow::on_launchButton_2_released()
{
    QProcess process;
    process.startDetached("kioclient5 exec /usr/share/applications/software-center.desktop");
}

//Update Manager
void MainWindow::on_launchButton_3_released()
{
    QProcess process;
    process.startDetached("kioclient5 exec /usr/share/applications/update-manager.desktop");
}

//System Settings
void MainWindow::on_launchButton_5_released()
{
    QProcess process;
    process.startDetached("kioclient5 exec /usr/share/applications/systemsettings.desktop");
}

//YouTube Channel
void MainWindow::on_launchButton_8_released()
{
    QProcess process;
    process.startDetached("kioclient5 exec https://youtube.com/channel/UCiHu1MloUXISNQ-wj3hjS1w");
}

//Website
void MainWindow::on_launchButton_6_released()
{
    QProcess process;
    process.startDetached("kioclient5 exec https://norcuxos.github.io/");
}

//Discord Chat
void MainWindow::on_launchButton_4_released()
{
    QProcess process;
    process.startDetached("kioclient5 exec https://discord.gg/K2p9hf9");
}

void MainWindow::on_autostartCheckBox_toggled(bool checked)
{
    QProcess process;
    if (checked) {
        //Enable Autostart
        process.startDetached("cp /usr/share/applications/welcome-screen.desktop " + QDir::homePath() + "/.config/autostart/welcome-screen.desktop");
    } else {
        //Disable Autostart
        if (QFile::exists(QDir::homePath() + "/.config/autostart/welcome-screen.desktop")) {
            process.startDetached("rm " + QDir::homePath() + "/.config/autostart/welcome-screen.desktop");
        }
    }
}
