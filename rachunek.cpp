#include "rachunek.h"
#include "ui_rachunek.h"
#include "widgetczlonkowie.h"
#include "widgetwydatki.h"
#include "widgetrozliczenia.h"

#include <math.h>
#include <QDebug>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

Rachunek::Rachunek(QString name, QWidget *parent)
    : QWidget(parent), name(name), ui(new Ui::Rachunek)
{
    ui->setupUi(this);
    ui->labelNazwa->setText(name);

    setPodzialy();
    setWidgets();
    setButtons();
    updateWidgets();
}

void Rachunek::updateWidgets(){
    simplify();

    QList<QLabel *> Labels = ui->tabWidget->widget(2)->findChildren<QLabel *>();
    foreach(QLabel * child, Labels){
        if(child->text() == "Uproszczone należności" || child->text() == "Historia rozliczeń" || child->text() == "brak")
        delete child;
    }

    QList<WidgetRozliczenia *> Rozliczenia = ui->tabWidget->widget(2)->findChildren<WidgetRozliczenia *>();
    foreach(WidgetRozliczenia * child, Rozliczenia){
        if(!child->getRozliczony())
            delete child;
    }

    for(int i = 0; i < 3; i++){
        delete ui->tabWidget->widget(i)->layout();
        ui->tabWidget->widget(i)->setLayout(new QVBoxLayout());
        ui->tabWidget->widget(i)->layout()->setAlignment({Qt::AlignTop, Qt::AlignCenter});
    }

    for(int i = 0; i < wydatki.size(); i++){
        ui->tabWidget->widget(0)->layout()->addWidget(wydatki[i]);
        wydatki[i]->lower();
    }

    ui->comboBoxKtoZaplacil->clear();
    ui->comboBoxKomuOddaje->clear();
    ui->comboBoxKtoOddaje->clear();

    for(int i = 0; i < czlonkowie.size(); i++){
        ui->tabWidget->widget(1)->layout()->addWidget(czlonkowie[i]);
        czlonkowie[i]->lower();
        ui->comboBoxKtoZaplacil->addItem(czlonkowie[i]->getName());
        ui->comboBoxKomuOddaje->addItem(czlonkowie[i]->getName());
        ui->comboBoxKtoOddaje->addItem(czlonkowie[i]->getName());
    }

    auto l1 = new QLabel("Uproszczone należności");
    ui->tabWidget->widget(2)->layout()->addWidget(l1);
    l1->lower();
    l1->setFont(QFont("Tahoma", 20, QFont::Bold));
    int c = 0;
    for(int i = 0; i < rozliczenia.size(); i++){
        if(!rozliczenia[i]->getRozliczony()){
            ui->tabWidget->widget(2)->layout()->addWidget(rozliczenia[i]);
            rozliczenia[i]->lower();
            c++;
        }
    }

    if(c == 0){
        auto lb = new QLabel("brak");
        ui->tabWidget->widget(2)->layout()->addWidget(lb);
        lb->lower();
    }

    auto l2 = new QLabel("Historia rozliczeń");
    ui->tabWidget->widget(2)->layout()->addWidget(l2);
    l2->setFont(QFont("Tahoma", 20, QFont::Bold));
    l2->lower();
    c = 0;
    for(int i = 0; i < rozliczenia.size(); i++){
        if(rozliczenia[i]->getRozliczony()){
            ui->tabWidget->widget(2)->layout()->addWidget(rozliczenia[i]);
            rozliczenia[i]->lower();
            c++;
        }
    }
    if(c == 0){
        auto lb = new QLabel("brak");
        ui->tabWidget->widget(2)->layout()->addWidget(lb);
        lb->lower();
    }

    updateSposobRozliczenia();
}

void Rachunek::updateSposobRozliczenia(){
    int i = 0;
    for (auto [key, value] : listPoRowno) {
        if(i < czlonkowie.length()){
            key->setVisible(true);
            value->setVisible(true);
            key->setText(czlonkowie[i]->getName());
        }
        else{
            key->setVisible(false);
            value->setVisible(false);
        }
        i++;
    }

    i = 0;
    for (auto [key, value] : listUdzialy) {
        if(i < czlonkowie.length()){
            key->setVisible(true);
            value->setVisible(true);
            key->setText(czlonkowie[i]->getName());
        }
        else{
            key->setVisible(false);
            value->setVisible(false);
        }
        i++;
    }

    i = 0;
    for (auto [key, value] : listKwoty) {
        if(i < czlonkowie.length()){
            key->setVisible(true);
            value->setVisible(true);
            key->setText(czlonkowie[i]->getName());
        }
        else{
            key->setVisible(false);
            value->setVisible(false);
        }
        i++;
    }
}

void Rachunek::setPodzialy(){
    listPoRowno = QList<QPair<QLabel*, QCheckBox*>>({QPair<QLabel*, QCheckBox*>(ui->label_0_a, ui->checkBox_0_a), QPair<QLabel*, QCheckBox*>(ui->label_0_b, ui->checkBox_0_b), QPair<QLabel*, QCheckBox*>(ui->label_0_c, ui->checkBox_0_c), QPair<QLabel*, QCheckBox*>(ui->label_0_d, ui->checkBox_0_d), QPair<QLabel*, QCheckBox*>(ui->label_0_e, ui->checkBox_0_e), QPair<QLabel*, QCheckBox*>(ui->label_0_f, ui->checkBox_0_f)});
    listUdzialy = QList<QPair<QLabel*, QSpinBox*>>({QPair<QLabel*, QSpinBox*>(ui->label_1_a, ui->spinBox_1_a), QPair<QLabel*, QSpinBox*>(ui->label_1_b, ui->spinBox_1_b), QPair<QLabel*, QSpinBox*>(ui->label_1_c, ui->spinBox_1_c), QPair<QLabel*, QSpinBox*>(ui->label_1_d, ui->spinBox_1_d), QPair<QLabel*, QSpinBox*>(ui->label_1_e, ui->spinBox_1_e), QPair<QLabel*, QSpinBox*>(ui->label_1_f, ui->spinBox_1_f)});
    listKwoty = QList<QPair<QLabel*, QLineEdit*>>({QPair<QLabel*, QLineEdit*>(ui->label_2_a, ui->lineEdit_2_a), QPair<QLabel*, QLineEdit*>(ui->label_2_b, ui->lineEdit_2_b), QPair<QLabel*, QLineEdit*>(ui->label_2_c, ui->lineEdit_2_c), QPair<QLabel*, QLineEdit*>(ui->label_2_d, ui->lineEdit_2_d), QPair<QLabel*, QLineEdit*>(ui->label_2_e, ui->lineEdit_2_e), QPair<QLabel*, QLineEdit*>(ui->label_2_f, ui->lineEdit_2_f)});
}

void Rachunek::setWidgets(){
    this->widgetNowyWydatek = ui->widgetNowyWydatek;
    this->widgetNowyCzlonek = ui->widgetNowyCzlonek;
    this->widgetRozlicz     = ui->widgetRozlicz;

    widgetNowyWydatek->setVisible(false);
    widgetNowyCzlonek->setVisible(false);
    widgetRozlicz->setVisible(false);
}

void Rachunek::setButtons(){
    // Wydatki
    connect(ui->buttonDodajWydatki, &QPushButton::clicked, [this]{
        widgetNowyWydatek->setVisible(true);
    });

    connect(ui->buttonDodajWydatek, &QPushButton::clicked, [this]{
        QMessageBox msgBox;
        msgBox.setStandardButtons(QMessageBox::Ok);

        if(czlonkowie.empty()){
            msgBox.setText("Brak członków w rachunku");
            msgBox.exec();
            return;
        }

        if(ui->nazwa->text().isEmpty()){
            msgBox.setText("Podaj nazwę wydatku");
            msgBox.exec();
            return;
        }

        if(ui->nazwa_2->text().isEmpty()){
            msgBox.setText("Podaj kwotę wydatku");
            msgBox.exec();
            return;
        }

        bool isNumeric = false;
        ui->nazwa_2->text().toDouble(&isNumeric);
        if(!isNumeric){
            msgBox.setText("Nieprawidłowa kwota wydatku");
            msgBox.exec();
            return;
        }


        bool ok = false;
        if(ui->comboBoxSposobPodzialu->currentText() == "Po równo"){
            for(int i = 0; i < czlonkowie.size(); i++){
                if(listPoRowno[i].second->isChecked())
                    ok = true;
            }

            if(!ok){
                msgBox.setText("Wybierz przynajmneij jedą osobę do podziału");
                msgBox.exec();
                return;
            }
        }

        if(ui->comboBoxSposobPodzialu->currentText() == "Udzialy"){ // Kwoty
            for(int i = 0; i < czlonkowie.size(); i++){
                if(listUdzialy[i].second->value() != 0)
                    ok = true;
            }

            if(!ok){
                msgBox.setText("Wybierz przynajmneij jedą osobę do podziału");
                msgBox.exec();
                return;
            }
        }


        if(ui->comboBoxSposobPodzialu->currentText() == "Kwoty"){
            float kwota = 0;
            bool isNumeric = false;
            for(int i = 0; i < czlonkowie.size(); i++){
                if(listKwoty[i].second->text() == "")
                    continue;

                kwota += listKwoty[i].second->text().toFloat(&isNumeric);

                if(!isNumeric){
                    msgBox.setText("Nieprawidłowa kwota to podziału");
                    msgBox.exec();
                    return;
                }

                isNumeric = false;
            }

            if(kwota != ui->nazwa_2->text().toFloat()){
                msgBox.setText("Kwoty muszą dodawać się do pełnej wartości");
                msgBox.exec();
                return;
            }
        }

        addWydatek();
        ui->nazwa->clear();
        ui->nazwa_2->clear();
        wydatki.append(new WidgetWydatki(ui->comboBoxKtoZaplacil->currentText(), ui->nazwa_2->text().toFloat(), ui->nazwa->text(), ui->dateEdit->date()));
        updateWidgets();
        widgetNowyWydatek->setVisible(false);
    });

    connect(ui->buttonWydatkiClose, &QPushButton::clicked, [this]{
        ui->nazwa->clear();
        ui->nazwa_2->clear();
        widgetNowyWydatek->setVisible(false);
    });

    // Sposób podziału
    connect(ui->comboBoxSposobPodzialu, QOverload<int>::of(&QComboBox::currentIndexChanged),
            ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    // Czlonkowie
    connect(ui->buttonDodajCzlonkowie, &QPushButton::clicked, [this]{
        widgetNowyCzlonek->setVisible(true);
    });

    connect(ui->buttonCzlonkowieClose, &QPushButton::clicked, [this]{
        ui->lineEdit_2->clear();
        widgetNowyCzlonek->setVisible(false);
    });

    connect(ui->buttonDodajCzlonek, &QPushButton::clicked, [this]{
        QMessageBox msgBox;
        msgBox.setStandardButtons(QMessageBox::Ok);

        if(ui->lineEdit_2->text().isEmpty()){
            msgBox.setText("Podaj imię członka");
            msgBox.exec();
            return;
        }

        if(czlonkowie.size() >= 6){
            msgBox.setText("Osiągnięto maksymalną liczbę członków");
            msgBox.exec();
            return;
        }

        for(int i = 0; i < czlonkowie.length(); i++){
            if(ui->lineEdit_2->text() == czlonkowie[i]->getName()){
                msgBox.setText("Członek o takim imieniu już istnieje");
                msgBox.exec();
                return;
            }
        }

        czlonkowie.append(new WidgetCzlonkowie(ui->lineEdit_2->text()));
        updateWidgets();
        ui->lineEdit_2->clear();
        widgetNowyCzlonek->setVisible(false);
    });

    // Rozliczenia
    connect(ui->buttonDodajRozliczenia, &QPushButton::clicked, [this]{
        widgetRozlicz->setVisible(true);
    });

    connect(ui->buttonRozliczeniaClose, &QPushButton::clicked, [this]{
        ui->lineEditKwota->clear();
        widgetRozlicz->setVisible(false);
    });

    connect(ui->buttonRozlicz, &QPushButton::clicked, [this]{
        QMessageBox msgBox;
        msgBox.setStandardButtons(QMessageBox::Ok);

        if(czlonkowie.empty()){
            msgBox.setText("Brak członków w rachunku");
            msgBox.exec();
            return;
        }

        if(ui->lineEditKwota->text().isEmpty()){
            msgBox.setText("Wpisz kwotę");
            msgBox.exec();
            return;
        }

        if(ui->comboBoxKomuOddaje->currentText() == ui->comboBoxKtoOddaje->currentText()){
            msgBox.setText("Nie można rozliczyć się z samym sobą");
            msgBox.exec();
            return;
        }

        rozliczenia.append(new WidgetRozliczenia(ui->comboBoxKomuOddaje->currentText(), ui->lineEditKwota->text().toFloat(), ui->comboBoxKtoOddaje->currentText(), true));

        WidgetCzlonkowie* czlonek = getCzlonek(ui->comboBoxKtoOddaje->currentText());
        czlonek->setBalance(czlonek->getBalance() - ui->lineEditKwota->text().toFloat());

        czlonek = getCzlonek(ui->comboBoxKomuOddaje->currentText());
        czlonek->setBalance(czlonek->getBalance() + ui->lineEditKwota->text().toFloat());

        ui->lineEditKwota->clear();
        updateWidgets();
        widgetRozlicz->setVisible(false);
    });

    connect(ui->buttonBack, &QPushButton::clicked, this, &Rachunek::rachunekClose);
}

void Rachunek::addWydatek(){
    if(ui->comboBoxSposobPodzialu->currentText() == "Po równo"){
        int podzial = 0;
        for(int i = 0; i < czlonkowie.size(); i++)
            if(listPoRowno[i].second->isChecked())
                podzial++;

        auto czlonek = getCzlonek(ui->comboBoxKtoZaplacil->currentText());
        czlonek->setBalance(czlonek->getBalance() + ui->nazwa_2->text().toFloat());

        for(int i = 0; i < czlonkowie.size(); i++)
            if(listPoRowno[i].second->isChecked()){
                auto czlonek = getCzlonek(listPoRowno[i].first->text());
                czlonek->setBalance(czlonek->getBalance() - ui->nazwa_2->text().toFloat() / (float)(podzial));
            }
        return;
    }

    if(ui->comboBoxSposobPodzialu->currentText() == "Udzialy"){
        int podzial = 0;
        for(int i = 0; i < czlonkowie.size(); i++)
            podzial += listUdzialy[i].second->value();


        auto czlonek = getCzlonek(ui->comboBoxKtoZaplacil->currentText());
        czlonek->setBalance(czlonek->getBalance() + ui->nazwa_2->text().toFloat());

        for(int i = 0; i < czlonkowie.size(); i++)
            if(listUdzialy[i].second->value() != 0){
                auto czlonek = getCzlonek(listPoRowno[i].first->text());
                czlonek->setBalance(czlonek->getBalance() - ui->nazwa_2->text().toFloat() * (float)listUdzialy[i].second->value() / (float)(podzial));
            }
        return;
    }

    if(ui->comboBoxSposobPodzialu->currentText() == "Kwoty"){
        auto czlonek = getCzlonek(ui->comboBoxKtoZaplacil->currentText());
        czlonek->setBalance(czlonek->getBalance() + ui->nazwa_2->text().toFloat());

        for(int i = 0; i < czlonkowie.size(); i++)
            if(listKwoty[i].second->text() != ""){
                auto czlonek = getCzlonek(listPoRowno[i].first->text());
                czlonek->setBalance(czlonek->getBalance() - listKwoty[i].second->text().toFloat());
            }
        return;
    }
}

void Rachunek::simplify(){
    QList<WidgetRozliczenia*> temp = QList<WidgetRozliczenia*>();
    for(int i = 0; i < rozliczenia.size(); i++)
        if(rozliczenia[i]->getRozliczony())
            temp.append(rozliczenia[i]);
    this->rozliczenia = temp;

    QMap<QString, float> balances = QMap<QString, float>();
    for(auto c : czlonkowie)
        balances.insert(c->getName(), std::ceil(c->getBalance() * 100.0) / 100.0);

    while(true){
        float highest = 0;
        float lowest = 0;
        QString most;
        QString least;

        foreach (const QString &key, balances.keys()){
            if(balances.value(key) >= highest){
                most = key;
                highest = balances.value(key);
            }
            if(balances[key] <= lowest){
                least = key;
                lowest = balances[key];
            }
        }

        if(highest == 0)
            break;

        float value = highest > -lowest ? -lowest : highest;
        balances[least] += value;
        balances[most]  -= value;

        rozliczenia.append(new WidgetRozliczenia(least, value, most, false));
    }
}

QString Rachunek::getName(){
    return name;
}

WidgetCzlonkowie* Rachunek::getCzlonek(QString name){
    for(auto c : czlonkowie){
        if(c->getName() == name)
            return c;
    }

    return nullptr;
}

Rachunek::~Rachunek(){}
