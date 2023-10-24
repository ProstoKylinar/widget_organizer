#include "geometric.h"
#include <QPainter>
#include <QMenu>
#include <QInputDialog>
#include <QTransform>

GeomFigure::GeomFigure(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1200, 1200);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QWidget::customContextMenuRequested, this, &GeomFigure::showContextMenu);
    angle = 0; scale_f = 1.0;
}

void GeomFigure::paintEvent(QPaintEvent *event)
{
  QPainter p(this);
  QTransform orig = p.transform();
  QPointF center(width()/2, height()/2);
  p.translate(center);
  p.rotate(angle);
  p.scale(scale_f, scale_f);

  p.drawLine(20, 10, 190, 10);
  p.drawLine(200, 20, 200, 40);
  p.drawLine(190, 50, 20, 50);
  p.drawLine(10, 40, 10, 20);
  p.drawArc(10,10,20,20,90*16,90*16);
  p.drawArc(10,30,20,20,180*16,90*16);
  p.drawArc(180,30,20,20,270*16,90*16);
  p.drawArc(180,10,20,20,  0*16,90*16);

  p.setTransform(orig);
  p.resetTransform();
}

void GeomFigure::mousePressEvent(QMouseEvent *event)
{
    x = event->pos().x();
    y = event->pos().y();
}

void GeomFigure::mouseMoveEvent(QMouseEvent *event)
{
    int delta_x = event->pos().x() - x;
    int delta_y = event->pos().y() - y;
    move(pos().x()+delta_x, pos().y()+delta_y);
}

void GeomFigure::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(this);
    QAction rotateAction("Rotate", this);
    connect(&rotateAction, &QAction::triggered, this, &GeomFigure::rotate);
    contextMenu.addAction(&rotateAction);

    QAction resizeAction("Resize", this);
    connect(&resizeAction, &QAction::triggered, this, &GeomFigure::resize);
    contextMenu.addAction(&resizeAction);

    contextMenu.exec(mapToGlobal(pos));
}

void GeomFigure::rotate()
{
    bool flag;
    int a = QInputDialog::getInt(this, "Rotate", "Enter the angle of rotation of the figure in degrees:", 0, -360, 360, 1, &flag);
    if (flag) {
        angle = a;
        update();
    }
}

void GeomFigure::resize()
{
    bool flag;
    int size = QInputDialog::getInt(this, "Resize", "Enter a new figure size:", 100, 10, 150, 1, &flag);
    if (flag) {
        scale_f = static_cast<double>(size) / 100.0;
        update();
    }
}
