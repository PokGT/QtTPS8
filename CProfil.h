#ifndef CPROFIL_H
#define CPROFIL_H
#include <QString>

class CProfil {
private:

    QString s_prfName;

public:
    CProfil(QString prfName);
    CProfil(const CProfil& Objet);
    ~CProfil();

    //getters
    QString get_s_prfName() const;

    bool operator==(CProfil& Profil);

};
#endif // CPROFIL_H
