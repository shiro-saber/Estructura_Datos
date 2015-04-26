#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QList>
#include <QPainterPath>
#include <QRect>
#include <QWidget>
#include <QString>
#include <QInputDialog>

using namespace std;

QT_BEGIN_NAMESPACE
class QPaintEvent;
QT_END_NAMESPACE

enum Operation { NoTransformation, Translate, Rotate, Scale, Reflection };

class RenderArea : public QWidget
{

    Q_OBJECT

public:
    RenderArea(QWidget *parent = 0);

    void setOperations(const QList<Operation> &operations);
    void setShape(const QPainterPath &shape);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);

private:
    void drawCoordinates(QPainter &painter);
    void drawOutline(QPainter &painter);
    void drawShape(QPainter &painter);
    void transformPainter(QPainter &painter);

    QList<Operation> operations;
    QPainterPath shape;
    QRect xBoundingRect;
    QRect yBoundingRect;

    double translateX();
    double translateY();
    int rotation();
    double escala();
};
#endif // RENDERAREA_H
