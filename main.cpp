#include <QApplication>
#include "polygonwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создаём наш виджет как отдельное окно(Димас)
    PolygonWidget w;
    w.resize(500, 500);
    w.setWindowTitle("Полигоны");

    // Добавляем треугольник
    w.addTriangle(
        QPointF(250, 100),   // верхняя вершина
        QPointF(100, 400),   // левая нижняя
        QPointF(400, 400),   // правая нижняя
        Qt::yellow
        );

    // Показываем
    w.show();

    return a.exec();
}
