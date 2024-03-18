#include "dialogaddprofil.h"
#include "ui_dialogaddprofil.h"

DialogAddProfil::DialogAddProfil(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAddProfil)
{
    ui->setupUi(this);
    ui->TL_error->setVisible(0);
}

DialogAddProfil::~DialogAddProfil()
{
    delete ui;
}
void DialogAddProfil::acutaliserCB_user(void)
{
    ui->CB_user->clear();
    for (auto it = v_USR_ListUsers.begin(); it != v_USR_ListUsers.end(); it++)
    {
        ui->CB_user->addItem(it->get_s_username());
    }
}

void DialogAddProfil::acutaliserInfoUser(int index)
{
    ui->TL_userName->setText(v_USR_ListUsers[index].get_s_username());
    ui->TL_role->setText(v_USR_ListUsers[index].get_s_role());
    ui->TL_profil->setText(v_USR_ListUsers[index].get_listProfil());
}

void DialogAddProfil::refreshWindow(void)
{
    v_USR_ListUsers.clear();
    v_USR_ListUsers = CUserController::get_list_user();
    acutaliserCB_user();
    acutaliserInfoUser(ui->CB_user->currentIndex());
    ui->TL_error->setVisible(0);
}




void DialogAddProfil::on_CB_user_highlighted(int index)
{
    acutaliserInfoUser(index);
}
void DialogAddProfil::on_PB_add_clicked(bool checked)
{
    if(v_USR_ListUsers[ui->CB_user->currentIndex()].add_Profil(ui->LE_newProfil->text()) && ui->LE_newProfil->text()!=""){
        CUserController::save_list_user(v_USR_ListUsers);

        acutaliserInfoUser(ui->CB_user->currentIndex());
        ui->TL_error->setVisible(0);
    }
    else
    {
        ui->TL_error->setVisible(1);
        ui->TL_error->setText("Add imposiple, profile already existing");
    }
}

void DialogAddProfil::setUserControlleur(CUserController Controller)
{
    UserControlleur = Controller;
}

void  DialogAddProfil::initV_USR_ListUsers()
{
    v_USR_ListUsers.clear();
    if(UserControlleur.getUserUserConnecter().isAdministrator()){
        v_USR_ListUsers = CUserController::get_list_user();
    }
    else{
        v_USR_ListUsers.push_back(UserControlleur.getUserUserConnecter());
    }

}

