#include "widget.h"
#include "geometric.h"
#include <QMenu>
#include <QAction>
#include <QInputDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(1200, 800);

    QMenu *contextMenu = new QMenu(this);
    QAction *addFigureAction = new QAction("Add geometric figure", this);
    connect(addFigureAction, &QAction::triggered, this, &Widget::addGeomFigure);
    contextMenu->addAction(addFigureAction);

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QWidget::customContextMenuRequested, [this, contextMenu](const QPoint &pos) {
        contextMenu->popup(mapToGlobal(pos));
    });
}

void Widget::addGeomFigure()
{
    GeomFigure *shape = new GeomFigure(this);
    shape->show();
}

Widget::~Widget()
{
}

