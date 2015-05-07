#include "renderarea.h"

#include <QPainter>
#include <QPaintEvent>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    QFont newFont = font();
    newFont.setPixelSize(12);
    setFont(newFont);

    QFontMetrics fontMetrics(newFont);
    xBoundingRect = fontMetrics.boundingRect(tr("x"));
    yBoundingRect = fontMetrics.boundingRect(tr("y"));
}

void RenderArea::setOperations(const QList<Operation> &operations)
{
    this->operations = operations;
    update();
}

void RenderArea::setShape(const QPainterPath &shape)
{
    this->shape = shape;
    update();
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(182, 182);
}

QSize RenderArea::sizeHint() const
{
    return QSize(232, 232);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), QBrush(Qt::white));

    painter.translate(this->width()/3, this->height()/2.5);
    painter.save();
    transformPainter(painter);
    drawShape(painter);
    painter.restore();
    drawOutline(painter);
    transformPainter(painter);
    drawCoordinates(painter);
}

void RenderArea::drawCoordinates(QPainter &painter)
{
    painter.setPen(Qt::red);

    painter.drawLine(0, 0, 50, 0);
    painter.drawLine(48, -2, 50, 0);
    painter.drawLine(48, 2, 50, 0);
    painter.drawText(60 - xBoundingRect.width() / 2,
                     0 + xBoundingRect.height() / 2, tr("x"));

    painter.drawLine(0, 0, 0, 50);
    painter.drawLine(-2, 48, 0, 50);
    painter.drawLine(2, 48, 0, 50);
    painter.drawText(0 - yBoundingRect.width() / 2,
                     60 + yBoundingRect.height() / 2, tr("y"));
}

void RenderArea::drawOutline(QPainter &painter)
{
    painter.setPen(Qt::darkGreen);
    painter.setPen(Qt::DashLine);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(0, 0, 100, 100);
}

void RenderArea::drawShape(QPainter &painter)
{
    painter.fillPath(shape, Qt::green);
}

void RenderArea::transformPainter(QPainter &painter)
{
    //double x;

    for (int i = 0; i < operations.size(); ++i)
    {
        switch (operations[i])
        {
        case Translate:
            painter.translate(50, 50);
            break;
        case Scale:
            //x = escala();
            painter.scale(2,2);
            break;
        case Rotate:
            painter.rotate(50);
            break;
        case Reflection:
            //painter.translate (100,0);
            painter.scale(-1,-1);
            break;
        case NoTransformation:
        default:
            ;
        }
    }
}


double RenderArea::translateX()
{
    double uno;

    uno = QInputDialog::getDouble(this, tr("Input"), tr("Ingresa a donde lo quieres trasladar en x 1-100"),
                                1, 1, 101, 1);

    return uno;
}

double RenderArea::translateY()
{
    double dos;

    dos = QInputDialog::getDouble(this, tr("Input"), tr("Ingresa a donde lo quieres trasladar en y 1-100"),
                                1 ,1, 101, 1);

    return dos;
}

int RenderArea::rotation()
{
    int rot;

    rot = QInputDialog::getInt(this, tr("Input"), tr("Ingresa lo quieres rotar 1-360"),
                                1 ,1, 361, 1);

    return rot;
}

double RenderArea::escala()
{
    double esc;

    esc = QInputDialog::getDouble(this, tr("Input"), tr("Ingresa la escala que quieres 1-200"),
                                  1 ,1, 201, 1);

    return (esc/100);
}
