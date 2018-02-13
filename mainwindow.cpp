#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


// VARIABLES
int current_digit = 0;
int old_digit = 0;
int sign = 0;
char actionSymbol = ' ';

// FUNCTIONs DESCRIBED 0-9 BUTTONs
void MainWindow::on_digit_oneButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    current_digit *= 10;
    current_digit += 1;
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_twoButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    current_digit *= 10;
    current_digit += 2;
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_threeButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    current_digit *= 10;
    current_digit += 3;
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_fourButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    current_digit *= 10;
    current_digit += 4;
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_fiveButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    current_digit *= 10;
    current_digit += 5;
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_sixButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    current_digit *= 10;
    current_digit += 6;
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_sevenButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    current_digit *= 10;
    current_digit += 7;
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_eightButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    current_digit *= 10;
    current_digit += 8;
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_nineButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    current_digit *= 10;
    current_digit += 9;
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_zeroButton_clicked() {
    if (ui->digitLine->text() == "0") {
        ui->digitLine->setText("");
    }
    current_digit *= 10;
    current_digit += 0;
    ui->digitLine->setText(QString::number(current_digit));
}


// FUNCTIONs DESCRIBED SPECIAL BUTTONs
void MainWindow::on_digit_delButton_clicked() {
    current_digit /= 10;
    ui->digitLine->setText(QString::number(current_digit));
}

void MainWindow::on_digit_plusButton_clicked() {
    actionSymbol = '+';
    old_digit = current_digit;
    current_digit = 0;
    ui->digitLine->setText("");
    ui->resultLabel->setText(QString::number(old_digit));
    ui->warningLabel->setText("");
}

void MainWindow::on_digit_minusButton_clicked() {
    actionSymbol = '-';
    old_digit = current_digit;
    current_digit = 0;
    ui->digitLine->setText("");
    ui->resultLabel->setText(QString::number(old_digit));
    ui->warningLabel->setText("");
}

void MainWindow::on_digit_multButton_clicked() {
    actionSymbol = '*';
    old_digit = current_digit;
    current_digit = 0;
    ui->digitLine->setText("");
    ui->resultLabel->setText(QString::number(old_digit));
    ui->warningLabel->setText("");
}

void MainWindow::on_digit_divideButton_clicked() {
    actionSymbol = '/';
    old_digit = current_digit;
    current_digit = 0;
    ui->digitLine->setText("");
    ui->resultLabel->setText(QString::number(old_digit));
    ui->warningLabel->setText("");
}

void MainWindow::on_digit_eqButton_clicked() {
    int result = 0;
    if (actionSymbol == '+') {
        result = old_digit + current_digit;
    } else if (actionSymbol == '-') {
        result = old_digit - current_digit;
    } else if (actionSymbol == '*') {
        result = old_digit * current_digit;
    } else if (actionSymbol == '/') {
        if (current_digit != 0) {
            result = old_digit / current_digit;
        } else if (current_digit == 0){
            ui->warningLabel->setText("Division by zero!");
        }
    } else {
        result = current_digit;
    }
    actionSymbol = ' ';
    old_digit = 0;
    current_digit = result;
    ui->digitLine->setText(QString::number(result));
    ui->resultLabel->setText("");
}

void MainWindow::on_unarButton_clicked() {
    if (!sign) {
        current_digit = -current_digit;
        ui->digitLine->setText("-" + QString::number(current_digit));
        sign = 1;
    } else if (sign) {
        current_digit = -current_digit;
        ui->digitLine->setText(QString::number(current_digit));
        sign = 0;
    }
}

void MainWindow::on_digit_ceButton_clicked() {
    ui->digitLine->setText("");
    current_digit = 0;
}

void MainWindow::on_digit_cButton_clicked() {
    ui->digitLine->setText("");
    ui->resultLabel->setText("");
    current_digit = old_digit = 0;
}

void MainWindow::on_digit_sqrtButton_clicked() {
    int sqrt_var = sqrt(ui->digitLine->text().toInt());
    ui->digitLine->setText(QString::number(sqrt_var));
    ui->resultLabel->setText(QString::number(current_digit));
    current_digit = sqrt_var;
}

void MainWindow::on_digit_sqrButton_clicked() {
    int d = ui->digitLine->text().toInt();
    int sqr = d * d;
    ui->digitLine->setText(QString::number(sqr));
    ui->resultLabel->setText(QString::number(current_digit));
    current_digit = sqr;
}
