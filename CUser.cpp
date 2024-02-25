#include "CUser.h"

CUser::CUser(QString username, QString password, QString role, QVector<CProfil> Profil)
{
    s_username = username;
    s_password = password;
    s_role = role;

    v_PRF_Profil = Profil;
}

CUser::CUser(const CUser& Objet)
{
    s_username = Objet.get_s_username();
    s_password = Objet.get_s_password();
    s_role = Objet.get_s_role();

    QVector<CProfil> ListProfil = Objet.get_v_PRF_Profil();
    for (auto it = ListProfil.begin(); it != ListProfil.end(); it++) {
        v_PRF_Profil.push_back(*it);
    }
}

CUser::~CUser()
{
    v_PRF_Profil.clear();
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

QVector<CProfil> CUser::get_v_PRF_Profil() const
{
    return v_PRF_Profil;
}

bool CUser::isAdministrator()
{
    if(this->get_s_role() == "administrator")
    {
        return true;
    }
    else{
        return false;
    }
}

bool CUser::operator==(CUser& usercomp)
{
    if (this->get_s_username() == usercomp.get_s_username())
    {
        return true;
    }
    else
    {
        return false;
    }
}
