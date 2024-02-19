#include "CJsonTool.h"

QJsonDocument CJsonTool::getData(QString JsonFilePath)
{
    QJsonDocument Document;

    QFile file(JsonFilePath);
    if(file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        QByteArray Bytes = file.readAll();
        file.close();

        QJsonParseError JsonError;
        QJsonDocument Document = QJsonDocument::fromJson(Bytes, &JsonError);

        if(JsonError.error != QJsonParseError::NoError){
            qDebug()<<"Error in Json Data : "<<JsonError.errorString();
            return Document;
        }
        else{
            return Document;
        }
    }
    qDebug()<<"nous ne parvenons pas à ouvrir : "<<JsonFilePath;
    return Document;
}

void CJsonTool::setData(QJsonDocument document, QString JsonFilePath)
{
    QByteArray bytes = document.toJson( QJsonDocument::Indented );
    QFile file(JsonFilePath);
    if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        QTextStream iStream(&file);
        iStream << bytes;
        file.close();
    }
    else
    {
        cout << "file open failed: " << JsonFilePath.toStdString() << endl;
    }
}
