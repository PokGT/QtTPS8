#include "CProfil.h"

CProfil::CProfil(QString prfName)
{
    s_prfName = prfName;
}

CProfil::CProfil(const CProfil& Objet)
{
    s_prfName = Objet.get_s_prfName();
}

CProfil::~CProfil()
{
}

QString CProfil::get_s_prfName() const
{
    return s_prfName;
}

bool CProfil::operator==(CProfil& Profil)
{
    if (this->get_s_prfName() == Profil.get_s_prfName())
    {
        return true;
    }
    else
    {
        return false;
    }
}
