#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void addGeomFigure();
};
#endif // MAINWINDOW_H
