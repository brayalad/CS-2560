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
    /**
     *Pointer to the user interface
     */
    Ui::MainWindow *ui;
    /**
     *Pointer to the user interface
     */
    const long long BIG_NUMBER_DIGIT_LIMIT = 4294967291; 
    /**
     *Pointer to the user interface
     */
    bool operatorClicked; 
        /**
     *Pointer to the user interface
     */
    QChar storedOperator;
    /**
     *Pointer to the user interface
     */
    bool hasStoredNumber;
    /**
     *Pointer to the user interface
     */
    BigNums::BigNumber storedNumber;
    /**
     *Calulates the results
     */
    void calculate_result();

private slots:
    /**
     * All number buttons are grouped together
     */
    void numberGroup_clicked(QAbstractButton*);
    /**
     * All action buttons are grouped together
     */ 
    void actionGroup_clicked(QAbstractButton*);

    /**
     * Runs when delete button is clicked. Deletes a digit from the number
     */ 
    void on_actionDel_clicked();
    /**
     * Runs when equals/calculation button is clicked. Calculates the math
     */ 
    void on_actionCalc_clicked();
    /**
     * Runs when AC/Clear button is clicked. Clears the number
     */ 
    void on_actionClear_clicked();
    /**
     * Runs when sign button is clicked. Negates the number
     */ 
    void on_actionSign_clicked();

protected:
    /**
     * Handles claculator when a key on the keyboard is pressed
     */ 
    void keyPressEvent(QKeyEvent *e);

public:
    /**
     * Constructor
     */ 
    explicit MainWindow(QWidget *parent = nullptr);
    /**
     * Destructor
     */ 
    ~MainWindow();

};

