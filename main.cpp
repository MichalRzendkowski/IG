#include "mainwindow.h"
#include "widget.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    app.setFont(QFont("Tahoma", 20));
    MainWindow mainWindow;
    mainWindow.setWindowTitle("KtoKomuIle");
    mainWindow.setStatusBar(nullptr);
    mainWindow.show();
    return app.exec();
}
