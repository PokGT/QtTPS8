#ifndef DIALOGQUERY_H
#define DIALOGQUERY_H

#include <QDialog>

namespace Ui {
class dialogquery;
}

class dialogquery : public QDialog
{
    Q_OBJECT

public:
    explicit dialogquery(QWidget *parent = nullptr);
    ~dialogquery();

private:
    Ui::dialogquery *ui;
};

#endif // DIALOGQUERY_H
