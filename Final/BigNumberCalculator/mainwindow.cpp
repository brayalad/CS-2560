#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->displayPanel->clear();

    operatorClicked = false;
    hasStoredNumber = false;

    ui->numberGroup->connect(ui->numberGroup,SIGNAL(buttonClicked(QAbstractButton*)),this, SLOT(numberGroup_clicked(QAbstractButton*)));

    ui->actionGroup->connect(ui->actionGroup,SIGNAL(buttonClicked(QAbstractButton*)),this, SLOT(actionGroup_clicked(QAbstractButton*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberGroup_clicked(QAbstractButton* button)
{
    QString displayLabel = ui->displayPanel->text();

    if (operatorClicked)
    {
        displayLabel.clear();
        operatorClicked = false;
    }

    if (displayLabel.length() >= BIG_NUMBER_DIGIT_LIMIT) {
        return;
    }

    displayLabel.append(button->text());

    ui->displayPanel->setText(displayLabel);
}

void MainWindow::actionGroup_clicked(QAbstractButton* button)
{
    if (operatorClicked)
    {
        storedOperator = button->text().at(0);
    }
    else
    {
        if (hasStoredNumber)
        {
            calculate_result();
        }
        else
        {
            hasStoredNumber = true;

            QString displayLabel = ui->displayPanel->text();

            storedNumber = BigNums::BigNumber(displayLabel.toStdString());
        }

        operatorClicked = true;

        storedOperator = button->text().at(0);
    }
}

void MainWindow::on_actionDel_clicked()
{
    QString displayLabel = ui->displayPanel->text();

    if (displayLabel.length() == 0)
    {
        return;
    }

    displayLabel.QString::chop(1);

    ui->displayPanel->setText(displayLabel);
}

void MainWindow::on_actionCalc_clicked()
{

    QString displayLabel = ui->displayPanel->text();

    if (!hasStoredNumber || displayLabel.length() < 1 || operatorClicked)
    {
        return;
    }

    calculate_result();

    hasStoredNumber = false;

}

void MainWindow::on_actionClear_clicked()
{
    ui->displayPanel->clear();
    operatorClicked = false;
    hasStoredNumber = false;
}

void MainWindow::on_actionSign_clicked()
{
    QString displayLabel = ui->displayPanel->text();

    BigNums::BigNumber currentNumber = BigNums::BigNumber(displayLabel.toStdString());

    currentNumber *= BigNums::BigNumber("-1");

    displayLabel = QString::fromStdString(currentNumber.GetString());

    ui->displayPanel->setText(displayLabel);
}

void MainWindow::calculate_result()
{
    QString displayLabel = ui->displayPanel->text();


     if (storedOperator == '+')
     {
         storedNumber += BigNums::BigNumber(displayLabel.toStdString());
     }
     else if (storedOperator == '-')
     {
         storedNumber -= BigNums::BigNumber(displayLabel.toStdString());
     }
     else if (storedOperator == 'x')
     {
         storedNumber *= BigNums::BigNumber(displayLabel.toStdString());
     }
     else if (storedOperator == '/')
     {
         storedNumber /= BigNums::BigNumber(displayLabel.toStdString());
     }
     else if (storedOperator == '%')
     {
        storedNumber %= BigNums::BigNumber(displayLabel.toStdString());
     }

     displayLabel = QString::fromStdString(storedNumber.GetString());

     ui->displayPanel->setText(displayLabel);
}


void MainWindow::keyPressEvent(QKeyEvent *event) {

        if(event->key() == Qt::Key_1)
        {
            numberGroup_clicked(ui->num1);
        }
        else if(event->key() == Qt::Key_2)
        {
            numberGroup_clicked(ui->num2);
        }
        else if(event->key() == Qt::Key_3)
        {
            numberGroup_clicked(ui->num3);
        }
        else if(event->key() == Qt::Key_4)
        {
            numberGroup_clicked(ui->num4);
        }
        else if(event->key() == Qt::Key_5)
        {
            numberGroup_clicked(ui->num5);
        }
        else if(event->key() == Qt::Key_6)
        {
            numberGroup_clicked(ui->num6);
        }
        else if(event->key() == Qt::Key_7)
        {
            numberGroup_clicked(ui->num7);
        }
        else if(event->key() == Qt::Key_8)
        {
            numberGroup_clicked(ui->num8);
        }
        else if(event->key() == Qt::Key_9)
        {
            numberGroup_clicked(ui->num9);
        }
        else if(event->key() == Qt::Key_0)
        {
            numberGroup_clicked(ui->num0);
        }
        else if(event->key() == Qt::Key_Plus)
        {
            actionGroup_clicked(ui->actionPlus);
        }
        else if(event->key() == Qt::Key_Minus)
        {
            actionGroup_clicked(ui->actionMinus);
        }
        else if(event->key() == Qt::Key_Asterisk)
        {
            actionGroup_clicked(ui->actionMul);
        }
        else if(event->key() == Qt::Key_Slash)
        {
            actionGroup_clicked(ui->actionDiv);
        }
        else if(event->key() == Qt::Key_Percent)
        {
            actionGroup_clicked(ui->actionPercent);
        }
        else if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        {
            on_actionCalc_clicked();
        }
        else if(event->key() == Qt::Key_Backspace)
        {
            on_actionDel_clicked();
        }
        else if(event->key() == Qt::Key_Delete)
        {
            on_actionClear_clicked();
        }


}
