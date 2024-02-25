#ifndef DIALOGADDPROFIL_H
#define DIALOGADDPROFIL_H

#include <QDialog>
#include <vector>
#include "CUser.h"
#include "CProfil.h"
#include "CUserController.h"

namespace Ui {
class DialogAddProfil;
}

class DialogAddProfil : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddProfil(QWidget *parent = nullptr);
    ~DialogAddProfil();

    void acutaliserCB_user(void);
    void acutaliserInfoUser(int index);
    void refreshWindow(void);

private slots:
    void on_CB_user_highlighted(int index);

    void on_PB_add_clicked(bool checked);

private:
    Ui::DialogAddProfil *ui;
    vector<CUser> v_USR_ListUsers;
};

#endif // DIALOGADDPROFIL_H
