#include "MainWindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->file->init(":/MainWindow/folder_common.svg", ":/MainWindow/folder_selected.svg", u8"文件");
    ui->transfer->init(":/MainWindow/transfer_common.svg", ":/MainWindow/transfer_selected.svg", u8"传输");
    ui->share->init(":/MainWindow/share_common.svg", ":/MainWindow/share_selected.svg", u8"分享");
    ui->setting->init(":/MainWindow/setting_common.svg", ":/MainWindow/setting_common.svg", u8"");
    ui->setting->setIconSize(20, 20);
}

MainWindow::~MainWindow()
{
    delete ui;
}
