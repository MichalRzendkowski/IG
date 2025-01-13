#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.setWindowTitle("KtoKomuIle");
    mainWindow.setStatusBar(nullptr);
    mainWindow.show();
    return app.exec();
}
