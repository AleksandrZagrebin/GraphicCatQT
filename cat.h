#ifndef CAT_H
#define CAT_H
#include<QWidget>
#include<QPoint>
class Cat : public QWidget
{
    Q_OBJECT

public:
    explicit Cat(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawPair(QPainter &painter, int p1, int p2, int p3, const QColor &color);
    void drawPair(QPainter &painter, int p1, int p2, int p3, int p4, const QColor &color);
    void drawPair(QPainter &painter, int p1, int p2, int p3, int p4, int p5, int p6, int p7, const QColor &color);
private:
    QPoint points1[17];
    QPoint points2[17];
};

#endif // CAT_H
