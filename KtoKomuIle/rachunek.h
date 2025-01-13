#ifndef RACHUNEK_H
#define RACHUNEK_H

#include <QWidget>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Rachunek; }
QT_END_NAMESPACE

class Rachunek : public QWidget
{
    Q_OBJECT

public:
    explicit Rachunek(QWidget *parent = nullptr);
    ~Rachunek();

signals:
    void rachunekClose();

private:
    Ui::Rachunek *ui;
};

#endif // RACHUNEK_H
