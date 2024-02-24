#ifndef CUSER_H
#define CUSER_H
#include <QString>
/**
 * @brief The CUser class
 */
class CUser {
private:

    QString s_username;
    QString s_password;
    QString s_role;

public:
    /**
     * @brief CUser confort constructor
     * @param username
     * @param password
     * @param role
     */
    CUser(QString username, QString password, QString role);
    CUser(const CUser& Objet);
    ~CUser();

    //getters
    QString get_s_username() const;
    QString get_s_password() const;
    QString get_s_role() const;

    bool isAdministrator();


    /**
     * @brief operator == overloaded to compare CUser objects
     * @param usercomp
     * @return
     */
    bool operator==(CUser& usercomp);

};
#endif // CUSER_H
