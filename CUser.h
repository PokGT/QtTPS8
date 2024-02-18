#ifndef CUSER_H
#define CUSER_H
#include "CJesonTool.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class CUser {
private:

    QString s_username;
    QString s_password;
    QString s_role;

public:

    CUser(QString username, QString password, QString role);
    CUser(const CUser& Objet);
    ~CUser();

    QString get_s_username() const;
    QString get_s_password() const;
    QString get_s_role() const;

    static vector<CUser> get_list_user(QString JsonFilePath);
    static void save_list_user(vector<CUser> users, QString path);
};
#endif // CUSER_H
