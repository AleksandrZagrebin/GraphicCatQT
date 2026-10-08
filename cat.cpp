#include "cat.h"
#include <QPainter>
#include <QPolygon>

Cat::Cat(QWidget *parent) : QWidget(parent)
{
    points1[0]  = QPoint(20,  -60);
    points1[1]  = QPoint(30,  -50);
    points1[2]  = QPoint(50,  -20);
    points1[3]  = QPoint(20,  -10);
    points1[4]  = QPoint(10,   0);
    points1[5]  = QPoint(10, 30);
    points1[6]  = QPoint( 0, 40);
    points1[7]  = QPoint(20, 60);
    points1[8]  = QPoint(30, 40);
    points1[9]  = QPoint(70, 20);
    points1[10] = QPoint(80,  -20);
    points1[11] = QPoint(50, 10);
    points1[12] = QPoint(30, 20);
    points1[13] = QPoint(10, 20);
    points1[14] = QPoint(30,   0);
    points1[15] = QPoint(70,  -50);
    points1[16] = QPoint(60, -110);

    for (int i = 0; i < 17; ++i)
        points2[i] = QPoint(-points1[i].x(), points1[i].y());
}

void Cat::drawPair(QPainter &painter, int p1, int p2, int p3, const QColor &color)
{
    painter.setBrush(color);
    painter.setPen(Qt::black);

    QPolygon pol1, pol2;
    pol1 << points1[p1] << points1[p2] << points1[p3];
    pol2 << points2[p1] << points2[p2] << points2[p3];

    painter.drawPolygon(pol1);
    painter.drawPolygon(pol2);
}

void Cat::drawPair(QPainter &painter, int p1, int p2, int p3, int p4, const QColor &color)
{
    painter.setBrush(color);
    painter.setPen(Qt::black);

    QPolygon pol1, pol2;
    pol1 << points1[p1] << points1[p2] << points1[p3] << points1[p4];
    pol2 << points2[p1] << points2[p2] << points2[p3] << points2[p4];

    painter.drawPolygon(pol1);
    painter.drawPolygon(pol2);
}

void Cat::drawPair(QPainter &painter, int p1, int p2, int p3, int p4, int p5, int p6, int p7, const QColor &color)
{
    painter.setBrush(color);
    painter.setPen(Qt::black);

    QPolygon pol1, pol2;
    pol1 << points1[p1] << points1[p2] << points1[p3] << points1[p4] <<points1[p5]<< points1[p6]<< points1[p7] ;
    pol2 << points2[p1] << points2[p2] << points2[p3] << points2[p4]<< points2[p5]<< points2[p6]<< points2[p7];

    painter.drawPolygon(pol1);
    painter.drawPolygon(pol2);
}

void Cat::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.translate(width() / 2, height() / 2);

    drawPair(painter, 0,  1, 16, QColor(255, 140, 0));
    drawPair(painter, 1, 15, 16, QColor(255, 140, 100));
    drawPair(painter, 1, 15,  2, QColor(150, 150, 150));
    drawPair(painter, 2, 15, 10, QColor(130, 130, 130));
    drawPair(painter, 7,  8,  9, Qt::white);

    drawPair(painter, 4,  3,  2, 14, QColor(100, 180, 255));
    drawPair(painter, 6,  5,  8, 7, QColor(200,200,200));

    drawPair(painter, 13, 4, 14, 2, 10, 11, 12,QColor(100, 100, 100));
    drawPair(painter,  8, 9, 10, 11, 12, 13, 5, QColor(140, 140, 140));

    QPolygon pol1, pol2, pol3;
    pol1 << points1[0]<< points1[1]<< points1[2]<< points1[3]<< points1[4]<< points1[5]
         << points2[5]<< points2[4]<< points2[3]<< points2[2]<< points2[1]<< points2[0];
    pol2 << points2[7] << points1[7]<< points1[6];
    pol3 << points2[5]<< points1[7]<< points1[6];
    painter.drawPolygon(pol1);
    painter.drawPolygon(pol2);
    painter.setBrush(QColor(200,200,200));
    painter.drawPolygon(pol3);

}