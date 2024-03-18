#include "dialogquery.h"
#include "ui_dialogquery.h"

DialogQuery::DialogQuery(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogQuery)
{
    ui->setupUi(this);
}

DialogQuery::~DialogQuery()
{
    delete ui;
}
