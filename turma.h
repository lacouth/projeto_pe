#ifndef TURMA_H
#define TURMA_H

#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>
#include "aluno.h"

class Turma
{
private:
    QVector<Aluno> turma;

public:
    Turma();
    void inserirAluno(Aluno a);
    Aluno operator[](int i);
    int getMedia();
    int getMaiorMedia();
    int getMenorMedia();
    void ordenarPorNome();
    void ordenarPorMedia();
    int size();
    bool salvarTurma(QString arquivo);
    bool carregarTurma(QString arquivo);
};

bool compararPorMedia(Aluno a, Aluno b);
bool compararPorNome(Aluno a, Aluno b);

#endif // TURMA_H
