#include "dialogremoveuser.h"
#include "ui_dialogremoveuser.h"

DialogRemoveUser::DialogRemoveUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogRemoveUser)
{
    ui->setupUi(this);

    v_USR_ListUsers = CUserController::get_list_user();
    acutaliserCB_user();
    acutaliserInfoUser(ui->CB_user->currentIndex());


}

DialogRemoveUser::~DialogRemoveUser()
{
    v_USR_ListUsers.clear();
    delete ui;
}

void DialogRemoveUser::acutaliserCB_user(void)
{
    ui->CB_user->clear();
    for (auto it = v_USR_ListUsers.begin(); it != v_USR_ListUsers.end(); it++)
    {
        ui->CB_user->addItem(it->get_s_username());
    }
}

void DialogRemoveUser::acutaliserInfoUser(int index)
{
    ui->TL_userName->setText(v_USR_ListUsers[index].get_s_username());
    ui->TL_role->setText(v_USR_ListUsers[index].get_s_role());
    ui->TL_profil->setText(v_USR_ListUsers[index].get_listProfil());
}

void DialogRemoveUser::refreshWindow(void)
{
    v_USR_ListUsers.clear();
    v_USR_ListUsers = CUserController::get_list_user();
    acutaliserCB_user();
    acutaliserInfoUser(ui->CB_user->currentIndex());
}




void DialogRemoveUser::on_CB_user_highlighted(int index)
{
    acutaliserInfoUser(index);
}


void DialogRemoveUser::on_PB_Remove_clicked()
{
    v_USR_ListUsers.erase(v_USR_ListUsers.begin() + ui->CB_user->currentIndex());
    CUserController::save_list_user(v_USR_ListUsers);
    refreshWindow();
}

