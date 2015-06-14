#include "widget.h"
#include <QApplication>

#include "bourse.h"
#include "graph.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Bourse* bourse = new Bourse(":/terre_rare/data/terre_rare/cours_terres_rares.csv");
    Graph graph(bourse);

    graph.show();
    graph.showMaximized();
//    Widget w;
//    w.show();

    return a.exec();
}
