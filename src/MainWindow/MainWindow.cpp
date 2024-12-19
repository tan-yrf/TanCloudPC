#include "MainWindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->file->Init("D://code//TanCloudPc//src//MainWindow//icon//folder_common.svg", "qrc:/icon/file.png", u8"文件");
    ui->file->Init(":/MainWindow/folder_common.svg", ":/MainWindow/folder_selected.svg", u8"文件");
}

MainWindow::~MainWindow()
{
    delete ui;
}
