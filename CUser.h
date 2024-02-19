#ifndef CUSER_H
#define CUSER_H
#include <QString>
class CUser {
private:

    QString s_username;
    QString s_password;
    QString s_role;

public:

    CUser(QString username, QString password, QString role);
    CUser(const CUser& Objet);
    ~CUser();

    QString get_s_username() const;
    QString get_s_password() const;
    QString get_s_role() const;

    bool operator==(CUser& usercomp);

};
#endif // CUSER_H
