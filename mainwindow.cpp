#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::atualizarDados()
{
    double mediaTurma = 0;
    for(Aluno a : turma){
        mediaTurma += a.getMedia();
    }
    mediaTurma /= turma.size();
    ui->mediaTurma->setText(QString::number(mediaTurma));

    Aluno *maior = std::max_element(turma.begin(),turma.end(),[](Aluno a, Aluno b){return a.getMedia()<b.getMedia();});
    Aluno *menor = std::min_element(turma.begin(),turma.end(),[](Aluno a, Aluno b){return a.getMedia()<b.getMedia();});

    ui->menorMedia->setText(QString::number(maior->getMedia()));
    ui->maiorMedia->setText(QString::number(menor->getMedia()));

}

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

    turma.push_back(aluno);
    atualizarDados();

}
