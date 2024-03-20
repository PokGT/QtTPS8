#include "dialogquery.h"
#include "ui_dialogquery.h"

dialogquery::dialogquery(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialogquery)
{
    ui->setupUi(this);
}

dialogquery::~dialogquery()
{
    delete ui;
}
