#ifndef DIALOGREMOVEPROFIL_H
#define DIALOGREMOVEPROFIL_H

#include <QDialog>
#include <vector>
#include "CUser.h"
#include "CProfil.h"
#include "CUserController.h"

namespace Ui {
class DialogRemoveProfil;
}

class DialogRemoveProfil : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRemoveProfil(QWidget *parent = nullptr);
    ~DialogRemoveProfil();

    void acutaliserCB_user(void);
    void acutaliserInfoUser(int index);
    void refreshWindow(void);

private slots:
    void on_CB_user_highlighted(int index);

    void on_PB_remove_clicked();

private:
    Ui::DialogRemoveProfil *ui;
    vector<CUser> v_USR_ListUsers;
};

#endif // DIALOGREMOVEPROFIL_H
