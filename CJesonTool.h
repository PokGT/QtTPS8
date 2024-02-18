#ifndef CJESONTOOL_H
#define CJESONTOOL_H
#include <QtCore>
#include <string>
#include <iostream>
#include <QtGui>
using namespace std;

class CJesonTool {

private:

public:

    CJesonTool();
    ~CJesonTool();

    static QJsonDocument getData(QString JsonFilePath);
    static  setData(QJsonDocument document, QString JsonFilePath);
};
#endif // CJESONTOOL_H
