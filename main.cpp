#include "mainwindow.h"
#include"CUser.h"
#include <QApplication>
#include <string>
#include <vector>
using namespace std;

void testJSON()
{
    vector<CUser> Listuser = CUser::get_list_user("user.json");
    CUser nouvUser = CUser("jojo","12356","user");
    Listuser.push_back(nouvUser);
    CUser::save_list_user(Listuser,"user.json");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    testJSON();
    return a.exec();
}
