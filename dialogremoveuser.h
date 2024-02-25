#ifndef DIALOGREMOVEUSER_H
#define DIALOGREMOVEUSER_H

#include <QDialog>
#include <vector>
#include "CUser.h"
#include "CProfil.h"
#include "CUserController.h"

namespace Ui {
class DialogRemoveUser;
}

class DialogRemoveUser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRemoveUser(QWidget *parent = nullptr);
    ~DialogRemoveUser();

    void acutaliserCB_user(void);
    void acutaliserInfoUser(int index);
    void refreshWindow(void);

private slots:

    void on_CB_user_highlighted(int index);

    void on_PB_Remove_clicked();

private:
    Ui::DialogRemoveUser *ui;
    vector<CUser> v_USR_ListUsers;
};

#endif // DIALOGREMOVEUSER_H
