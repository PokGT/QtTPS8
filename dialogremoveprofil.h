#ifndef DIALOGREMOVEPROFIL_H
#define DIALOGREMOVEPROFIL_H

#include <QDialog>
#include <QVector>
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

    /** The following 3 functions update the window display **/
    void acutaliserCB_user(void);
    void acutaliserInfoUser(int index);
    void refreshWindow(void);

private slots:
    /**
     * @brief Event triggered when hey administrator selects a user from the combo box
     * @param v_USR_ListUsers vector index representing the currently selected user
     */
    void on_CB_user_highlighted(int index);

    void on_PB_remove_clicked();

private:
    Ui::DialogRemoveProfil *ui;
    QVector<CUser> v_USR_ListUsers;
};

#endif // DIALOGREMOVEPROFIL_H
