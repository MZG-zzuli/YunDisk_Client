#ifndef SHEZHI_H
#define SHEZHI_H

#include <QWidget>
#include<QLineEdit>
class Shezhi : public QWidget
{
    Q_OBJECT
public:
    explicit Shezhi(QWidget *parent = nullptr);
    QLineEdit* ip;
    QLineEdit* port;

signals:

private:
};

#endif // SHEZHI_H
