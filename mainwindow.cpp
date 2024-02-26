#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),dialogCreatUser(new DialogCreatUser),dialogRemoveUser(new DialogRemoveUser),dialogAddProfil(new DialogAddProfil),dialogRemoveProfil(new DialogRemoveProfil)
{   
    ui->setupUi(this);
    vector<CUser> Listuser = CUserController::get_list_user();
    if(Listuser.size()<=0){
        ui->stackedWidget->setCurrentWidget(ui->pageCreeUser);
    }
    else{
        ui->stackedWidget->setCurrentWidget(ui->pageConection);
    }

    ui->TL_errorLogin->setText(0);
    ui->TL_errorCreate->setVisible(0);
    ui->menubar->setVisible(0);

    connect(ui->actionQuit,&QAction::triggered,this,&MainWindow::deconexion);
    connect(ui->actionCreate_User,&QAction::triggered,this,&MainWindow::openDialogCreatUser);
    connect(ui->actionRemove_User,&QAction::triggered,this,&MainWindow::openDialogRemoveUser);
    connect(ui->actionAdd_profile,&QAction::triggered,this,&MainWindow::openDialogAddProfil);
    connect(ui->actionRemove_profile,&QAction::triggered,this,&MainWindow::openDialogRemoveProfil);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDialogCreatUser(void)
{
    dialogCreatUser->exec();
}

void MainWindow::openDialogRemoveUser(void)
{
    dialogRemoveUser->refreshWindow();
    dialogRemoveUser->exec();
}

void MainWindow::openDialogAddProfil(void)
{
    dialogAddProfil->refreshWindow();
    dialogAddProfil->exec();
}

void MainWindow::openDialogRemoveProfil(void)
{
    dialogRemoveProfil->refreshWindow();
    dialogRemoveProfil->exec();
}

void MainWindow::deconexion(void)
{
    this->UserControlleur.deconnection();

    ui->TL_errorLogin->setText(0);
    ui->TL_errorCreate->setVisible(0);
    ui->menubar->setVisible(0);

    ui->stackedWidget->setCurrentWidget(ui->pageConection);
}


void MainWindow::on_PB_conexion_clicked()
{
    ui->TL_errorLogin->setText("");
    if(this->UserControlleur.connection(ui->LE_login->text(),ui->LE_password->text()))
    {
        CUser user = UserControlleur.getUserUserConnecter();

        ui->TL_errorLogin->setVisible(0);

        //Menu bar display management
        ui->menubar->setVisible(1);
        if(user.isAdministrator()){
            ui->menuEditUser->setEnabled(1);
        }
        else
        {
            ui->menuEditUser->setEnabled(0);
        }

        //user information display management
        ui->TL_userNameAcceuil->setText(user.get_s_username());
        ui->TL_roleAcceuil->setText(user.get_s_role());

        ui->CB_profile->clear();
        QVector<CProfil> ListProfil = user.get_v_PRF_Profil();
        for (auto it = ListProfil.begin(); it != ListProfil.end(); it++)
        {
            ui->CB_profile->addItem(it->get_s_prfName());
        }

        //home page display
        ui->stackedWidget->setCurrentWidget(ui->pageAcceuil);
    }
    else {
        ui->TL_errorLogin->setVisible(1);
        ui->TL_errorLogin->setText("Login not possible invalid user name or password");
    }

}


void MainWindow::on_PB_cree_clicked()
{
    QVector<CProfil> Profil;
    CUser nouvUser = CUser(ui->LE_userNameCree->text(),ui->LE_passwordCree->text(),"administrator",Profil);
    if(!this->UserControlleur.chek_if_exist(nouvUser) && ui->LE_userNameCree->text() != "" && ui->LE_passwordCree->text() != "")
    {
        CUserController::addUser(nouvUser);
        ui->TL_errorCreate->setVisible(0);

        ui->stackedWidget->setCurrentWidget(ui->pageConection);
    }
    else{
        ui->TL_errorCreate->setVisible(1);
        ui->TL_errorCreate->setText("ths user already exists");
    }

}

