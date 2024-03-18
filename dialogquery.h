#ifndef DIALOGQUERY_H
#define DIALOGQUERY_H

#include <QDialog>

namespace Ui {
class DialogQuery;
}

class DialogQuery : public QDialog
{
    Q_OBJECT

public:
    explicit DialogQuery(QWidget *parent = nullptr);
    ~DialogQuery();

private:
    Ui::DialogQuery *ui;
};

#endif // DIALOGQUERY_H
