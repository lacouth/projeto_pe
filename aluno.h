#ifndef ALUNO_H
#define ALUNO_H

#include <QObject>

#define CORTE 70

class Aluno
{

private:
    QString nome;
    double media;

public:
    Aluno();
    QString getNome() const;
    void setNome(const QString &value);
    double getMedia() const;
    void setMedia(double value);

    QString getStatus();
};

#endif // ALUNO_H
