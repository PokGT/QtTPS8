#ifndef CBDD_H
#define CBDD_H
#include <QList>
#include <QVector>
/*
 * N = 0
 * L = 1
 * LW = 2
 */
class CBDD
{

protected:
    static CBDD* CBDD_singleton;
    CBDD();
public:

/* Méthode liée au fonctionnement du singleton */
//CBDD(CBDD &other) = delete;
//void operator=(const CBDD &) = delete;

static CBDD* GetInstance();

/* Méthode liée à la logique métier  */
/*
QList<QString> get_list_BDD();

QList<QString> get_list_Table_name();

QVector<QString> get_Table_content(QString& TableName);

bool chek_if_BDDexist(QString& BDDname);

bool connect_BDD(QString& BDDname);

int getDroit(QString& BDDname,QString& UserNam);
*/
};

#endif // CBDD_H
