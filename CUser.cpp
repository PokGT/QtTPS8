#include "CUser.h"

CUser::CUser(QString username, QString password, QString role)
{
    s_username = username;
    s_password = password;
    s_role = role;
}

CUser::CUser(const CUser& Objet)
{
    s_username = Objet.get_s_username();
    s_password = Objet.get_s_password();
    s_role = Objet.get_s_role();
}

CUser::~CUser()
{
}

QString CUser::get_s_username() const
{
    return s_username;
}

QString CUser::get_s_password() const
{
    return s_password;
}
QString CUser::get_s_role() const
{
    return s_role;
}

vector<CUser> CUser::get_list_user(QString JsonFilePath)
{
    vector<CUser> Listuser;

    QJsonDocument Doc = CJesonRead::getData("user.json");

    if(Doc.isObject()){
        QJsonObject Obj = Doc.object();
        QJsonArray JArray = Obj.value("user").toArray();
        for(auto points : JArray)
        {
            QJsonObject objectpoint = points.toObject();
            Listuser.push_back(CUser(objectpoint.value("username").toString(),objectpoint.value("password").toString(),objectpoint.value("role").toString()));
        }
    }

    return Listuser;
}
