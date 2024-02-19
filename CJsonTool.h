#ifndef CJSONTOOL_H
#define CJSONTOOL_H
#include <QtCore>
#include <string>
#include <iostream>
#include <QtGui>
using namespace std;


/**
 * @brief The CJsonTool class
 */
class CJsonTool {

private:

public:

    CJsonTool();
    ~CJsonTool();

    /**
     * @brief gets a json document from a file path
     * @param JsonFilePath
     * @return QJsonDocument
     */
    static QJsonDocument getData(QString JsonFilePath);

    /**
     * @brief sets the data of the Json file wanted
     * @param JsonFilePath
     * @return none
     */
    static  void setData(QJsonDocument document, QString JsonFilePath);
};
#endif // CJSONTOOL_H
