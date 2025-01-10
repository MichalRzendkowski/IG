#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "homepage.h"
#include "rachunek.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);
    HomePage *homePage = new HomePage();
    Rachunek *rachunek = new Rachunek();

    stackedWidget->addWidget(homePage);
    stackedWidget->addWidget(rachunek);

    setCentralWidget(stackedWidget);

    connect(homePage, &HomePage::rachunekOpen, [this, rachunek]() {
        stackedWidget->setCurrentWidget(rachunek);
    });

    connect(rachunek, &Rachunek::rachunekClose, [this, homePage]() {
        stackedWidget->setCurrentWidget(homePage);
    });
}


MainWindow::~MainWindow()
{
    delete ui;
}
