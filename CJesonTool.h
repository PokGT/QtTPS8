#ifndef CJESONTOOL _H
#define CJESONTOOL _H
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
    static  setData(QJsonDocument Document);
};
#endif // CJESONTOOL _H
