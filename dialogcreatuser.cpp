#include "dialogcreatuser.h"
#include "ui_dialogcreatuser.h"

DialogCreatUser::DialogCreatUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogCreatUser)
{
    ui->setupUi(this);
    ui->TL_errorCreate->setVisible(0);

    ui->CB_profil->addItem("administrator");
    ui->CB_profil->addItem("user");

    connect(ui->PB_cree,&QPushButton::clicked,this,&DialogCreatUser::creatUser);
}

DialogCreatUser::~DialogCreatUser()
{
    delete ui;
}

void DialogCreatUser::creatUser(void)
{
    QVector<CProfil> Profil;
    CUser nouvUser = CUser(ui->LE_userNameCree->text(),ui->LE_passwordCree->text(),ui->CB_profil->currentText(),Profil);
    if(!CUserController::chek_if_exist(nouvUser) && ui->LE_userNameCree->text() != "" && ui->LE_passwordCree->text() != "")
    {
        CUserController::addUser(nouvUser);
        ui->TL_errorCreate->setVisible(0);

        close();
    }
    else{
        ui->TL_errorCreate->setVisible(1);
        ui->TL_errorCreate->setText("ths user already exists");
    }
}
