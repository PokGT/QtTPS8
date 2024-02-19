#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots :
    /**
     * @brief on_PB_deconexion_clicked : action performed by the deconnexion button
     */
    void on_PB_deconexion_clicked();

    /**
     * @brief on_pushButton_clicked : action performed by the connection button
     */
    void on_pushButton_clicked();

    /**
     * @brief on_PB_cree_clicked : action performed by the button "create"
     */
    void on_PB_cree_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
