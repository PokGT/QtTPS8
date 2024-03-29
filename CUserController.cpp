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
    QVector<CUser> Listuser = CUserController::get_list_user();
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

CUser CUserController::getUserUserConnecter()
{
    return CUser(*UserConnecter);
}



QVector<CUser> CUserController::get_list_user()
{
    QVector<CUser> Listuser;

    QJsonDocument Doc = CJsonTool::getData("user.json");

    if(Doc.isObject()){
        QJsonObject Obj = Doc.object();

        QJsonArray JArrayUser = Obj.value("user").toArray();
        for(auto user : JArrayUser)
        {
            QJsonObject objectpointUser = user.toObject();

            QVector<CProfil> Profil;
            QJsonArray JArrayProfil = objectpointUser.value("profil").toArray();
            for(auto profil : JArrayProfil)
            {
                QJsonObject objectpointProfil = profil.toObject();
                Profil.push_back(CProfil(objectpointProfil.value("prfName").toString()));
            }

            Listuser.push_back(CUser(objectpointUser.value("username").toString(),objectpointUser.value("password").toString(),objectpointUser.value("role").toString(),Profil));
            Profil.clear();
        }
    }

    return Listuser;
}

void CUserController::save_list_user(QVector<CUser> users)
{
    QJsonArray array;
    for (auto it = users.begin(); it != users.end(); it++) {
        QJsonObject Temp;
        Temp.insert("username",it->get_s_username());
        Temp.insert("password",it->get_s_password());
        Temp.insert("role",it->get_s_role());

        QVector<CProfil> Profil = it->get_v_PRF_Profil();
        QJsonArray arrayProfil;
        for (auto itProfil = Profil.begin(); itProfil != Profil.end(); itProfil++){
            QJsonObject Jprofil;
            Jprofil.insert("prfName",itProfil->get_s_prfName());
            arrayProfil.append(Jprofil);
        }

        Temp.insert("profil",arrayProfil);

        array.append(Temp);
    }
    QJsonObject object;
    object.insert("user", array);
    QJsonDocument document;
    document.setObject(object);
    CJsonTool::setData(document,"user.json");
}

bool CUserController::chek_if_exist(CUser& user)
{
    QVector<CUser> Listuser = CUserController::get_list_user();
    for (auto it = Listuser.begin(); it != Listuser.end(); it++) {
        if(*it == user){
            return true;
        }
    }
    return false;
}

bool CUserController::addUser(CUser user)
{
    QVector<CUser> ListUser = CUserController::get_list_user();
    if(!chek_if_exist(user)){
        ListUser.push_back(user);
        save_list_user(ListUser);
        return true;
    }
    return false;
}
