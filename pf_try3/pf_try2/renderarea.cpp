#include "renderarea.h"

#include <QPainter>
#include <QIntValidator>
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

    painter.translate(66, 66);
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
    painter.fillPath(shape, Qt::blue);
}

void RenderArea::transformPainter(QPainter &painter)
{
    /*QTextStream streamIn(stdin);
    QString uno;
    QString dos;
    int pos = 0;
    QIntValidator v(10, 900, this);
    uno = streamIn.readLine();
    v.validate(uno,pos);
    dos = streamIn.readLine();
    v.validate(dos, pos);*/
    bool ok = false;
    int uno;
    int dos;

    for (int i = 0; i < operations.size(); ++i) {
        switch (operations[i]) {
        case Translate:
            uno = QInputDialog::getInt(this, tr("Input"), tr("Ingresa a donde lo quieres trasladar en x 1-100"),
                                        25, 0, 101, 1, &ok);
            dos = QInputDialog::getInt(this, tr("Input"), tr("Ingresa a donde lo quieres trasladar en y 1-100"),
                                        25 ,0, 101, 1, &ok);
            painter.translate(uno, dos);
            break;
        case Scale:
            painter.scale(0.75, 0.75);
            break;
        case Rotate:
            painter.rotate(60);
            break;
        case NoTransformation:
        default:
            ;
        }
    }
}
