#include "mainwindow.h"
#include "createuser.h"
#include "CUser.h"
#include "CUserController.h"
#include <QApplication>
#include <string>
#include <vector>
using namespace std;

void testJSON()
{
    vector<CUser> Listuser = CUserController::get_list_user("user.json");
    CUser nouvUser = CUser("jojo","12356","user");
    Listuser.push_back(nouvUser);
    CUserController::save_list_user(Listuser,"user.json");
}

void testCUserController()
{
    CUser User1 = CUser("John","12356","user");
    CUser User2 = CUser("loulou","12356","user");

    bool r1 = CUserController::chek_if_exist(User1);
    bool r2 = CUserController::chek_if_exist(User2);

    bool add = CUserController::addUser(User2);
    bool r3 = CUserController::chek_if_exist(User2);

    CUserController controleurUSER;
    bool con = controleurUSER.connection("loulou","12356");
    qDebug()<<con;
    controleurUSER.deconnection();
    qDebug()<<r1<<" "<<r2<<" "<<add<<" "<<r3;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    //w.show();


    //tetJSON();
    testCUserController();
    return a.exec();
}
