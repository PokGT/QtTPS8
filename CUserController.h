#ifndef CUSERCONTROLLER_H
#define CUSERCONTROLLER_H
#include "CJsonTool.h"
#include "CUser.h"
#include <vector>
#include <iostream>
using namespace std;
class CUserController {
private:
    CUser *UserConnecter;
public:
    CUserController();
    CUserController(const CUserController& Objet);
    ~CUserController();

    bool connection(QString username, QString password);
    void deconnection();

    static vector<CUser> get_list_user(QString JsonFilePath);
    static void save_list_user(vector<CUser> users, QString path);
    static bool chek_if_exist(CUser& user);
    static bool addUser(CUser user);

};
#endif // CUSERCONTROLLER_H
