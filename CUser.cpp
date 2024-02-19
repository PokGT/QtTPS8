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
