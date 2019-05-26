#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSalvar,SIGNAL(triggered()),this,SLOT(salvar()));
    connect(ui->actionCarregar,SIGNAL(triggered()),this,SLOT(carregar()));
}

void MainWindow::atualizarDados()
{
    int mediaTurma = turma.getMedia();
    int menorMedia = turma.getMenorMedia();
    int maiorMedia = turma.getMaiorMedia();

    ui->mediaTurma->setText(QString::number(mediaTurma));
    ui->menorMedia->setText(QString::number(menorMedia));
    ui->maiorMedia->setText(QString::number(maiorMedia));

}

void MainWindow::atualizarTabela()
{
    ui->tabelaDados->clearContents();
    for(int i=0; i<turma.size();i++){
        inserirAlunoNaTabela(turma[i],i);
    }

}

void MainWindow::inserirAlunoNaTabela(Aluno a, int linha)
{
    ui->tabelaDados->setItem(linha,0,new QTableWidgetItem(a.getNome()));
    ui->tabelaDados->setItem(linha,1,new QTableWidgetItem(QString::number(a.getMedia())));
    ui->tabelaDados->setItem(linha,2,new QTableWidgetItem(a.getStatus()));
}

void MainWindow::salvar()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,
                                                       "Lista de aluno",
                                                       "",
                                                       "CSV(*.csv)");
    turma.salvarTurma(nomeArquivo);
}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,
                                                       "Lista de aluno",
                                                       "",
                                                       "CSV(*.csv)");
    turma.carregarTurma(nomeArquivo);
    for(int i=0;i<turma.size();i++){
        ui->tabelaDados->insertRow(i);
        inserirAlunoNaTabela(turma[i],i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnInserir_clicked()
{
    Aluno aluno;
    aluno.setNome(ui->entradaNome->text());
    aluno.setMedia(ui->entradaMedia->text().toDouble());

    int linha = ui->tabelaDados->rowCount();
    ui->tabelaDados->insertRow(linha);
    inserirAlunoNaTabela(aluno,linha);


    turma.inserirAluno(aluno);
    atualizarDados();

}

void MainWindow::on_btnOrdenarNome_clicked()
{
    turma.ordenarPorNome();
    atualizarTabela();
}

void MainWindow::on_btnOrdenarMedia_clicked()
{
    turma.ordenarPorMedia();
    atualizarTabela();
}
