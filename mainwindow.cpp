#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnInserir_clicked()
{
    aluno.setNome(ui->entradaNome->text());
    aluno.setMedia(ui->entradaMedia->text().toDouble());

    int linha = ui->tabelaDados->rowCount();
    ui->tabelaDados->insertRow(linha);
    ui->tabelaDados->setItem(linha,0,new QTableWidgetItem(aluno.getNome()));
    ui->tabelaDados->setItem(linha,1,new QTableWidgetItem(QString::number(aluno.getMedia())));
    ui->tabelaDados->setItem(linha,2,new QTableWidgetItem(aluno.getStatus()));

}
