#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    void on_digit_oneButton_clicked();

    void on_digit_twoButton_clicked();

    void on_digit_threeButton_clicked();

    void on_digit_fourButton_clicked();

    void on_digit_fiveButton_clicked();

    void on_digit_sixButton_clicked();

    void on_digit_sevenButton_clicked();

    void on_digit_eightButton_clicked();

    void on_digit_nineButton_clicked();

    void on_digit_zeroButton_clicked();

    void on_digit_delButton_clicked();

    void on_digit_plusButton_clicked();

    void on_digit_minusButton_clicked();

    void on_digit_multButton_clicked();

    void on_digit_divideButton_clicked();

    void on_digit_eqButton_clicked();

    void on_unarButton_clicked();

    void on_digit_ceButton_clicked();

    void on_digit_cButton_clicked();

    void on_digit_sqrtButton_clicked();

    void on_digit_sqrButton_clicked();

    void on_hypButton_clicked();

    void on_doubleButton_clicked();

    void on_digit_percentsButton_clicked();

};

#endif // MAINWINDOW_H
