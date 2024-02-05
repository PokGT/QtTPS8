#ifndef USERPAGE_H
#define USERPAGE_H

#include <QDialog>

namespace Ui {
class userPage;
}

class userPage : public QDialog
{
    Q_OBJECT

public:
    explicit userPage(QWidget *parent = nullptr);
    ~userPage();

private:
    Ui::userPage *ui;
};

#endif // USERPAGE_H
