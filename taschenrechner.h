/*******************************************************
 * Die Datei taschenrechner.h
*******************************************************/
#ifndef TASCHENRECHNER_H
#define TASCHENRECHNER_H

#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Taschenrechner; }
QT_END_NAMESPACE

class Taschenrechner : public QMainWindow
{
    Q_OBJECT

public:
    Taschenrechner(QWidget *parent = nullptr);
    ~Taschenrechner();

private slots:
    //für die Schaltfläche
    void on_pushButton_clicked();


private:
    Ui::Taschenrechner *ui;

    //Methode zur Prüfung eines Eingabefeldes
    float pruefeEingabe(QLineEdit *feld);
};
#endif // TASCHENRECHNER_H
