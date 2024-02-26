#include "dialogremoveprofil.h"
#include "ui_dialogremoveprofil.h"

DialogRemoveProfil::DialogRemoveProfil(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogRemoveProfil)
{
    ui->setupUi(this);
    ui->TL_error->setVisible(0);
}

DialogRemoveProfil::~DialogRemoveProfil()
{
    delete ui;
}

void DialogRemoveProfil::acutaliserCB_user(void)
{
    ui->CB_user->clear();
    for (auto it = v_USR_ListUsers.begin(); it != v_USR_ListUsers.end(); it++)
    {
        ui->CB_user->addItem(it->get_s_username());
    }
}

void DialogRemoveProfil::acutaliserInfoUser(int index)
{
    ui->TL_userName->setText(v_USR_ListUsers[index].get_s_username());
    ui->TL_role->setText(v_USR_ListUsers[index].get_s_role());
    ui->TL_profil->setText(v_USR_ListUsers[index].get_listProfil());

    QVector<CProfil> listProfil = v_USR_ListUsers[index].get_v_PRF_Profil();
    ui->CB_profil->clear();
    for (auto it = listProfil.begin(); it != listProfil.end(); it++)
    {
        ui->CB_profil->addItem(it->get_s_prfName());
    }
}

void DialogRemoveProfil::refreshWindow(void)
{
    v_USR_ListUsers.clear();
    v_USR_ListUsers = CUserController::get_list_user();
    acutaliserCB_user();
    acutaliserInfoUser(ui->CB_user->currentIndex());
    ui->TL_error->setVisible(0);
}




void DialogRemoveProfil::on_CB_user_highlighted(int index)
{
    acutaliserInfoUser(index);
}

void DialogRemoveProfil::on_PB_remove_clicked()
{
    if(v_USR_ListUsers[ui->CB_user->currentIndex()].supr_profil(ui->CB_profil->currentText()))
    {
        CUserController::save_list_user(v_USR_ListUsers);
        v_USR_ListUsers.clear();
        v_USR_ListUsers = CUserController::get_list_user();
        acutaliserInfoUser(ui->CB_user->currentIndex());
        ui->TL_error->setVisible(0);
    }else{
        ui->TL_error->setVisible(1);
        ui->TL_error->setText("error during supretion");
    }
}

