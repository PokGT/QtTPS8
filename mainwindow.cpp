#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vector<CUser> Listuser = CUserController::get_list_user("user.json");
    if(Listuser.size()<=0){
        ui->stackedWidget->setCurrentIndex(3);
    }
    else{
        ui->stackedWidget->setCurrentIndex(0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PB_deconexion_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_PB_cree_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

