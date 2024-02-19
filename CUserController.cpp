#include "CUserController.h"

CUserController::CUserController()
{
    UserConnecter = nullptr;
}

CUserController::CUserController(const CUserController& Objet)
{
    UserConnecter = new CUser(*Objet.UserConnecter);
}

CUserController::~CUserController()
{
    if( UserConnecter != nullptr)
    {
        delete UserConnecter;
    }
}

bool CUserController::connection(QString username, QString password)
{
    if( UserConnecter != nullptr)
    {
        delete UserConnecter;
    }
    vector<CUser> Listuser = CUserController::get_list_user("user.json");
    for (auto it = Listuser.begin(); it != Listuser.end(); it++) {
        if(it->get_s_username() == username && it->get_s_password() == password)
        {
            UserConnecter = new CUser(*it);
            return true;
        }
    }
    return false;
}

void CUserController::deconnection()
{
    if( UserConnecter != nullptr)
    {
        delete UserConnecter;
    }
    UserConnecter = nullptr;
}

vector<CUser> CUserController::get_list_user(QString JsonFilePath)
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

    return Listuser;
}

void CUserController::save_list_user(vector<CUser> users, QString path)
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

bool CUserController::chek_if_exist(CUser& user)
{
    vector<CUser> Listuser = CUserController::get_list_user("user.json");
    for (auto it = Listuser.begin(); it != Listuser.end(); it++) {
        if(*it == user){
            return true;
        }
    }
    return false;
}

bool CUserController::addUser(CUser user)
{
    vector<CUser> ListUser = CUserController::get_list_user("user.json");
    if(!chek_if_exist(user)){
        ListUser.push_back(user);
        save_list_user(ListUser, "user.json");
        return true;
    }
    return false;
}
