#include "mainwindow.h"
#include "CUser.h"
#include "CProfil.h"
#include "CUserController.h"
#include <QApplication>
#include <string>
#include <vector>
using namespace std;

void testJSON()
{
    QVector<CProfil> Profil;
    Profil.push_back(CProfil("Profe"));

    //vector<CUser> Listuser;
    QVector<CUser> Listuser = CUserController::get_list_user();


    CUser nouvUser = CUser("titi","12345","user",Profil);
    Listuser.push_back(nouvUser);

    CUserController::save_list_user(Listuser);
}

void testCUserController()
{
    QVector<CProfil> Profil;
    CUser User1 = CUser("John","12356","user",Profil);
    CUser User2 = CUser("loulou","12356","user",Profil);

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
    w.show();


    //testJSON();
    //testCUserController();
    return a.exec();
}
