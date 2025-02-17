#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include "widgetrachunek.h"
#include "homepage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeRachunek(Rachunek *rachunek);

private:
    HomePage* homePage;
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    QList<WidgetRachunek*> rachunki;

};
#endif // MAINWINDOW_H
