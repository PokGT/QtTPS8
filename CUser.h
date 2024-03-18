#ifndef CUSER_H
#define CUSER_H
#include <QString>
#include <QVector>
#include "CProfil.h"
/**
 * @brief The CUser class
 */
class CUser {
private:

    QString s_username;
    QString s_password;
    QString s_role;

    QVector<CProfil> v_PRF_Profil;

public:
    /**
     * @brief CUser confort constructor
     * @param username
     * @param password
     * @param role
     */
    CUser(QString username, QString password, QString role, QVector<CProfil> Profil);
    CUser(const CUser& Objet);
    ~CUser();

    //getters
    QString get_s_username() const;
    QString get_s_password() const;
    QString get_s_role() const;
    QString get_listProfil() const;

    QVector<CProfil> get_v_PRF_Profil() const;

    /**
     * @brief add Profile to vector v_PRF_Profile
     * @param prfName
     * @return 1 if profile added otherwise 0
     */
    int add_Profil(CProfil profil);

    /**
     * @brief Deletes profile from vector v_PRF_Profile
     * @param prfName
     * @return 1 if profile deleted otherwise 0
     */
    int supr_profil(CProfil prfName);

    /**
     * @brief have_profil
     * @param prfName
     * @return 1 if profile already exists otherwise 0
     */
    bool have_profil(CProfil prfName);

    /**
     * @brief isAdministrator
     * @return 1 if administrator otherwise 0
     */
    bool isAdministrator();


    /**
     * @brief operator == overloaded to compare CUser objects
     * @param usercomp
     * @return
     */
    bool operator==(CUser& usercomp);

};
#endif // CUSER_H
