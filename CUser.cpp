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

    QJsonDocument Doc = CJesonTool::getData(JsonFilePath);

    if(Doc.isObject()){
        QJsonObject Obj = Doc.object();
        QJsonArray JArray = Obj.value("user").toArray();
        for(auto points : JArray)
        {
            QJsonObject objectpoint = points.toObject();
            Listuser.push_back(CUser(objectpoint.value("username").toString(),objectpoint.value("password").toString(),objectpoint.value("role").toString()));
        }
    }
   //    CJesonTool::setData(Doc,"test.json");
    return Listuser;
}
void CUser::save_list_user(vector<CUser> users, QString path)
{
    QJsonArray array;
    for (auto it = users.begin(); it != users.end(); it++) {
        QJsonObject Temp;
        Temp.insert("username",it->get_s_username());
        Temp.insert("password",it->get_s_password());
        Temp.insert("role",it->get_s_role());
        array.append(Temp);
    }
    QJsonObject object;
    object.insert("user", array);
    QJsonDocument document;
    document.setObject(object);
    CJesonTool::setData(document,path);
}
