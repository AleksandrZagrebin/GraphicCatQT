#include "polygonwidget.h"
#include <QPainter>

PolygonWidget::PolygonWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(300, 300);
    setAutoFillBackground(true);

    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor(100, 100, 100));
    setPalette(pal);
}

void PolygonWidget::addPolygon(const Polygon &poly)
{
    m_polygons.append(poly);
    update();
}

void PolygonWidget::addTriangle(QPointF a, QPointF b, QPointF c, QColor color)
{
    Polygon p;
    p.points << a << b << c;
    p.fillColor = color;
    addPolygon(p);
}

void PolygonWidget::clear()
{
    m_polygons.clear();
    update();
}

void PolygonWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for (const Polygon &poly : m_polygons) {
        painter.setBrush(poly.fillColor);
        painter.setPen(Qt::NoPen);
        painter.drawPolygon(poly.points);

        if (poly.borderWidth > 0 && poly.borderColor.alpha() > 0) {
            painter.setPen(QPen(poly.borderColor, poly.borderWidth));
            painter.setBrush(Qt::NoBrush);
            painter.drawPolygon(poly.points);
        }
    }
}