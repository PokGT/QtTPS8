#include "userpage.h"
#include "ui_userpage.h"

userPage::userPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userPage)
{
    ui->setupUi(this);
}

userPage::~userPage()
{
    delete ui;
}
