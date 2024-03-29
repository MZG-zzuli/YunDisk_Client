#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
class title : public QWidget
{
    Q_OBJECT
public:
    explicit title(QWidget *parent = nullptr);

public:signals:
    void closeWin();
    void she();
private:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    QPoint pt;
    QWidget* fu;

};

#endif // TITLE_H
