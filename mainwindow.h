#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <CUserController.h>
#include <CUser.h>
#include <QMainWindow>
#include <vector>
#include "CUserController.h"
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
    CUserController UserControlleur;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void deconexion(void);

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
};
#endif // MAINWINDOW_H
