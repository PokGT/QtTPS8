#ifndef DIALOGCREATUSER_H
#define DIALOGCREATUSER_H

#include <QDialog>
#include <QtCore>
#include <CUser.h>
#include "CUserController.h"
namespace Ui {
class DialogCreatUser;
}

class DialogCreatUser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreatUser(QWidget *parent = nullptr);
    ~DialogCreatUser();

    void creatUser(void);

private:
    Ui::DialogCreatUser *ui;
};

#endif // DIALOGCREATUSER_H
