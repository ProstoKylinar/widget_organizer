#ifndef GEOMETRIC_H
#define GEOMETRIC_H
#include <QWidget>
#include <QMouseEvent>

class GeomFigure : public QWidget
{
    Q_OBJECT

    int x,y;
    int angle;
    double scale_f;
public:
    GeomFigure(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void showContextMenu(const QPoint &pos);
    void rotate();
    void resize();
};
#endif // GEOMETRIC_H
