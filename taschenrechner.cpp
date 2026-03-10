/*******************************************************
 * Die Datei taschenrechner.cpp
*******************************************************/
#include "taschenrechner.h"
#include "ui_taschenrechner.h"
#include <QMessageBox>

Taschenrechner::Taschenrechner(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Taschenrechner)
{
    ui->setupUi(this);
}

Taschenrechner::~Taschenrechner()
{
    delete ui;
}

// Methode zur Ueberprüfung eines Eingabefeldes
float Taschenrechner::pruefeEingabe(QLineEdit *feld)
{
    bool ok;
    float wert = locale().toFloat(feld->text(), &ok);

    if (!ok)
    {
        QMessageBox::warning(
            this,
            "Eingabefehler",
            "Ungültige Eingabe: \"" + feld->text() + "\""
            );

        feld->setFocus();
        throw 1;
    }

    return wert;
}

//der Slot für die Schaltfläche
void Taschenrechner::on_pushButton_clicked()
{
    float zahl1, zahl2, ergebnis = 0;
    bool flag = false;
    //für die Ausgabe
    QString ausgabe;

    try
    {
    //die Zahlen einlesen und Eingaben pruefen.
    zahl1 = pruefeEingabe(ui->lineEdit);
    zahl2 = pruefeEingabe(ui->lineEdit_2);
    }
    catch (int)
    {
        //keine Berechnung durchfuehren
        return;
    }

    //welche Rechenoperation ist ausgewählt?
    //die Addition
    if (ui->radioButtonAddition->isChecked() == true)
        ergebnis = zahl1 + zahl2;
    //die Subtraktion
    if (ui->radioButtonSubtraktion->isChecked() == true)
        ergebnis = zahl1 - zahl2;
    //die Division
    if (ui->radioButtonDivision->isChecked() == true)
    {
        //ist die zweite Zahl ungleich 0?
        if (zahl2 != 0)
            ergebnis = zahl1 / zahl2;
        else
            flag = true;
    }
    //die Multiplikation
    if (ui->radioButtonMultiplikation->isChecked() == true)
        ergebnis = zahl1 * zahl2;

    //die Ausgabe setzen
    //wurde eine Division durch 0 versucht?
    if (flag == true)
        ausgabe = "Nicht definiert!";
    else
        ausgabe = locale().toString(ergebnis);

    //das Ergebnis anzeigen
    ui->label->setText(ausgabe);
    //und auch in der LCD-Anzeige
    ui->lcdNumber->display(ergebnis);
}
