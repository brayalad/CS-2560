#pragma once

#include <QMainWindow>
#include <QAbstractButton>
#include <QKeyEvent>
#include <BigNumber.h>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    //Digit limit
    const long long BIG_NUMBER_DIGIT_LIMIT = 4294967291;
    bool operatorClicked;
    QChar storedOperator;
    bool hasStoredNumber;
    BigNums::BigNumber storedNumber;
    void calculate_result();

private slots:
    void numberGroup_clicked(QAbstractButton*);
    void actionGroup_clicked(QAbstractButton*);

    void on_actionDel_clicked();
    void on_actionCalc_clicked();
    void on_actionClear_clicked();
    void on_actionSign_clicked();

protected:
    void keyPressEvent(QKeyEvent *e);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};

