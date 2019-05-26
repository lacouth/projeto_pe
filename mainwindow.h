#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QDebug>
#include <QFileDialog>
#include "turma.h"
#include "aluno.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Turma turma;
    void atualizarDados();
    void atualizarTabela();
    void inserirAlunoNaTabela(Aluno a, int linha);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnInserir_clicked();

    void on_btnOrdenarNome_clicked();

    void on_btnOrdenarMedia_clicked();

    void salvar();

    void carregar();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
