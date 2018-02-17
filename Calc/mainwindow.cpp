#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QAction>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QMenu *info = menuBar()->addMenu("Info");
    QAction *creator = new QAction(tr("Creator"), this);
    creator->setShortcut(tr("Ctrl+K"));
    connect(info, SIGNAL(triggered()), this, SLOT(action()));
    info->addAction(creator);
}

MainWindow::~MainWindow() {
    delete ui;
}


// VARIABLES
double current_digit = 0.0;
double old_digit = 0.0;
double help_var = 0.1; // special variable needs to realize build-up of fractional element
int sign = 0;
char actionSymbol = ' ';
bool doubleFlag = 0;
QString tmpQS1 = "", tmpQS2 = "";

// FUNCTIONs DESCRIBED 0-9 BUTTONs
void MainWindow::on_digit_oneButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    if (!doubleFlag) {
        current_digit *= 10.0;
        current_digit += 1.0;
        help_var = 0.1;
    } else if (doubleFlag) {
        current_digit = current_digit + 1 * help_var;
        help_var *= 0.1;
    }
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_twoButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    if (!doubleFlag) {
        current_digit *= 10.0;
        current_digit += 2.0;
        help_var = 0.1;
    } else if (doubleFlag) {
        current_digit = current_digit + 2 * help_var;
        help_var *= 0.1;
    }
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_threeButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    if (!doubleFlag) {
        current_digit *= 10.0;
        current_digit += 3.0;
        help_var = 0.1;
    } else if (doubleFlag) {
        current_digit = current_digit + 3 * help_var;
        help_var *= 0.1;
    }
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_fourButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    if (!doubleFlag) {
        current_digit *= 10.0;
        current_digit += 4.0;
        help_var = 0.1;
    } else if (doubleFlag) {
        current_digit = current_digit + 4 * help_var;
        help_var *= 0.1;
    }
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_fiveButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    if (!doubleFlag) {
        current_digit *= 10.0;
        current_digit += 5.0;
        help_var = 0.1;
    } else if (doubleFlag) {
        current_digit = current_digit + 5 * help_var;
        help_var *= 0.1;
    }
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_sixButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    if (!doubleFlag) {
        current_digit *= 10.0;
        current_digit += 6.0;
        help_var = 0.1;
    } else if (doubleFlag) {
        current_digit = current_digit + 6 * help_var;
        help_var *= 0.1;
    }
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_sevenButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    if (!doubleFlag) {
        current_digit *= 10.0;
        current_digit += 7.0;
        help_var = 0.1;
    } else if (doubleFlag) {
        current_digit = current_digit + 7 * help_var;
        help_var *= 0.1;
    }
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_eightButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    if (!doubleFlag) {
        current_digit *= 10.0;
        current_digit += 8.0;
        help_var = 0.1;
    } else if (doubleFlag) {
        current_digit = current_digit + 8 * help_var;
        help_var *= 0.1;
    }
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_nineButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    if (!doubleFlag) {
        current_digit *= 10.0;
        current_digit += 9.0;
        help_var = 0.1;
    } else if (doubleFlag) {
        current_digit = current_digit + 9 * help_var;
        help_var *= 0.1;
    }
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_zeroButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    if (!doubleFlag) {
        current_digit *= 10.0;
        current_digit += 0.0;
    } else if (doubleFlag) {
        current_digit += 0.0;
        help_var *= 0.1;
    }
    ui->digitLine->setText(QString::number(current_digit));
}


// FUNCTIONs DESCRIBED SPECIAL BUTTONs
void MainWindow::on_digit_delButton_clicked() {
    doubleFlag = 0;
    ui->warningLabel->setText("");
    tmpQS1 = ui->digitLine->text();
    for (int i = 0; i < tmpQS1.size() - 1; i++) {
        tmpQS2[i] = tmpQS1[i];
    }
    ui->digitLine->setText(tmpQS2);
    current_digit = ui->digitLine->text().toDouble();
    tmpQS1 = tmpQS2 = "";
    if (ui->digitLine->text() == "-") {
        ui->digitLine->setText("");
    }
}

void MainWindow::on_digit_plusButton_clicked() {
    doubleFlag = 0;
    actionSymbol = '+';
    old_digit = current_digit;
    current_digit = 0.0;
    ui->digitLine->setText("");
    ui->resultLabel->setText(QString::number(old_digit));
    ui->warningLabel->setText("");
}

void MainWindow::on_digit_minusButton_clicked() {
    doubleFlag = 0;
    actionSymbol = '-';
    old_digit = current_digit;
    current_digit = 0.0;
    ui->digitLine->setText("");
    ui->resultLabel->setText(QString::number(old_digit));
    ui->warningLabel->setText("");
}

void MainWindow::on_digit_multButton_clicked() {
    doubleFlag = 0;
    actionSymbol = '*';
    old_digit = current_digit;
    current_digit = 0.0;
    ui->digitLine->setText("");
    ui->resultLabel->setText(QString::number(old_digit));
    ui->warningLabel->setText("");
}

void MainWindow::on_digit_divideButton_clicked() {
    doubleFlag = 0;
    actionSymbol = '/';
    old_digit = current_digit;
    current_digit = 0.0;
    ui->digitLine->setText("");
    ui->resultLabel->setText(QString::number(old_digit));
    ui->warningLabel->setText("");
}

void MainWindow::on_digit_eqButton_clicked() {
    doubleFlag = 0;
    ui->warningLabel->setText("");
    double result = 0.0;
    if (actionSymbol == '+') {
        result = old_digit + current_digit;
    } else if (actionSymbol == '-') {
        result = old_digit - current_digit;
    } else if (actionSymbol == '*') {
        result = old_digit * current_digit;
    } else if (actionSymbol == '/') {
        if (current_digit != 0.0) {
            result = old_digit / current_digit;
        } else if (current_digit == 0.0){
            ui->warningLabel->setText("Division by zero!");
        }
    } else {
        result = current_digit;
    }
    actionSymbol = ' ';
    old_digit = 0.0;
    current_digit = result;
    ui->digitLine->setText(QString::number(result));
    ui->resultLabel->setText("");
}

void MainWindow::on_unarButton_clicked() {
    doubleFlag = 0;
    ui->warningLabel->setText("");
    if (!sign) {
        current_digit = -current_digit;
        ui->digitLine->setText(QString::number(current_digit));
        sign = 1;
    } else if (sign) {
        current_digit = -current_digit;
        ui->digitLine->setText(QString::number(current_digit));
        sign = 0;
    }
}

void MainWindow::on_digit_ceButton_clicked() {
    doubleFlag = 0;
    ui->warningLabel->setText("");
    ui->digitLine->setText("");
    current_digit = 0.0;
}

void MainWindow::on_digit_cButton_clicked() {
    doubleFlag = 0;
    ui->warningLabel->setText("");
    ui->digitLine->setText("");
    ui->resultLabel->setText("");
    current_digit = old_digit = 0.0;
}

void MainWindow::on_digit_sqrtButton_clicked() {
    doubleFlag = 0;
    ui->warningLabel->setText("");
    if (current_digit >= 0) {
        double sqrt_var = sqrt(ui->digitLine->text().toDouble());
        ui->digitLine->setText(QString::number(sqrt_var));
        ui->resultLabel->setText(QString::number(current_digit));
        current_digit = sqrt_var;
    } else {
        ui->warningLabel->setText("Negative value!");
    }
}

void MainWindow::on_digit_sqrButton_clicked() {
    doubleFlag = 0;
    ui->warningLabel->setText("");
    double d = ui->digitLine->text().toDouble();
    double sqr = d * d;
    ui->digitLine->setText(QString::number(sqr));
    ui->resultLabel->setText(QString::number(current_digit));
    current_digit = sqr;
}
void MainWindow::on_hypButton_clicked() {
    doubleFlag = 0;
    ui->warningLabel->setText("");
    if (ui->digitLine->text() != "" && ui->digitLine->text() != "0") {
        double cd_clone = ui->digitLine->text().toDouble();
        double hyp = 1.0 / cd_clone;
        ui->digitLine->setText(QString::number(hyp));
        ui->resultLabel->setText(QString::number(current_digit));
        current_digit = hyp;
    } else {
        ui->warningLabel->setText("Value is not correct!");
    }
}

void MainWindow::on_doubleButton_clicked() {
    ui->warningLabel->setText("");
    if (ui->digitLine->text() == "0") {
        help_var = 0.1;
    }
    if (!doubleFlag) {
        doubleFlag = 1;
    } else {
        doubleFlag = 0;
    }
}

void MainWindow::on_digit_percentsButton_clicked() {
    doubleFlag = 0;
    ui->warningLabel->setText("");
    if (old_digit != 0) {
        current_digit = (old_digit / 100) * current_digit;
        ui->digitLine->setText(QString::number(current_digit));
    }
}
