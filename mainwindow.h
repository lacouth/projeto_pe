#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "aluno.h"
#include <algorithm>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Aluno aluno;
    QVector<Aluno> turma;
    void atualizarDados();


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnInserir_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
