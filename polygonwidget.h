#ifndef POLYGONWIDGET_H
#define POLYGONWIDGET_H

#include <QWidget>
#include <QPolygonF>
#include <QColor>
#include <QVector>

struct Polygon
{
    QPolygonF points;
    QColor fillColor   = Qt::gray;
    QColor borderColor = Qt::transparent;
    qreal  borderWidth = 0;
};

class PolygonWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PolygonWidget(QWidget *parent = nullptr);

    void addPolygon(const Polygon &poly);
    void addTriangle(QPointF a, QPointF b, QPointF c,QPointF d, QColor color);
    void clear();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<Polygon> m_polygons;
};

#endif // POLYGONWIDGET_H