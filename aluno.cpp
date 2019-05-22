#include "aluno.h"

QString Aluno::getNome() const
{
    return nome;
}

void Aluno::setNome(const QString &value)
{
    nome = value;
}

double Aluno::getMedia() const
{
    return media;
}

void Aluno::setMedia(double value)
{
    media = value;
}

QString Aluno::getStatus()
{
    return media >= CORTE ? "Aprovado" : "Reprovado";
}

Aluno::Aluno()
{

}
