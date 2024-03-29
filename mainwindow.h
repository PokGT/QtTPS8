#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <CUserController.h>
#include <CUser.h>
#include <QMainWindow>
#include <vector>
#include "dialogcreatuser.h"
#include "CUserController.h"
#include "dialogremoveuser.h"
#include "dialogaddprofil.h"
#include "dialogremoveprofil.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /** The following functions trigger the opening of the various dialog windows **/
    void deconexion(void);
    void openDialogCreatUser(void);
    void openDialogRemoveUser(void);
    void openDialogAddProfil(void);
    void openDialogRemoveProfil(void);

    /* This function refreshes the profile list display */
    void refreshesListProfile();

private slots :

    /**
     * @brief on_PB_conexion_clicked : action performed by the connection button
     */
    void on_PB_conexion_clicked();

    /**
     * @brief on_PB_cree_clicked : action performed by the button "create"
     */
    void on_PB_cree_clicked();

private:
    Ui::MainWindow *ui;

    CUserController UserControlleur;

    /** Pointer that stores the dialog window **/
    DialogCreatUser *dialogCreatUser;
    DialogRemoveUser *dialogRemoveUser;
    DialogAddProfil *dialogAddProfil;
    DialogRemoveProfil *dialogRemoveProfil;
};
#endif // MAINWINDOW_H
