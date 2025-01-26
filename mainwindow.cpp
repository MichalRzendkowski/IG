#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "homepage.h"
#include "rachunek.h"
#include "widgetrachunek.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);
    homePage = new HomePage();
    Rachunek *rachunek = new Rachunek("Rachunek 1");

    stackedWidget->addWidget(homePage);
    stackedWidget->addWidget(rachunek);

    setCentralWidget(stackedWidget);

    connect(homePage, &HomePage::rachunekOpen, this, &MainWindow::changeRachunek);

    connect(rachunek, &Rachunek::rachunekClose, [this]() {
        stackedWidget->setCurrentWidget(homePage);
    });
}

void MainWindow::changeRachunek(Rachunek *rachunek){
    stackedWidget->addWidget(rachunek);
    stackedWidget->setCurrentWidget(rachunek);
    connect(rachunek, &Rachunek::rachunekClose, [this]() {
        stackedWidget->setCurrentWidget(homePage);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
