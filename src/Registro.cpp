#include "Alaskapp.h"

Alaska::Alaskapp::Registro::Registro()
    : nome(""), pontos(0), tempo(0.0f)
{
}

Alaska::Alaskapp::Registro::Registro(const std::string& nome, int pontos, float tempo)
    : nome(nome), pontos(pontos), tempo(tempo)
{
}

Alaska::Alaskapp::Registro::~Registro()
{
}

const std::string& Alaska::Alaskapp::Registro::getNome() const
{
    return nome;
}

int Alaska::Alaskapp::Registro::getPontos() const
{
    return pontos;
}

float Alaska::Alaskapp::Registro::getTempo() const
{
    return tempo;
}

bool Alaska::Alaskapp::Registro::vemAntesDo(const Registro& outro) const
{
    if (pontos != outro.pontos)
        return pontos > outro.pontos;

    return tempo < outro.tempo;
}

std::string Alaska::Alaskapp::Registro::gerarLinhaArquivo() const
{
    std::stringstream ss;
    ss << nome << ';' << pontos << ';' << tempo << ";\n";
    return ss.str();
}

std::string Alaska::Alaskapp::Registro::gerarLinhaFormatada(int posicao) const
{
    const int minutos = static_cast<int>(tempo) / 60;
    const int segundos = static_cast<int>(tempo) % 60;

    std::stringstream linhaFormatada;
    linhaFormatada << posicao << ". " << nome
                   << " - " << pontos << " pts - "
                   << std::setw(2) << std::setfill('0') << minutos << ':'
                   << std::setw(2) << std::setfill('0') << segundos;

    return linhaFormatada.str();
}
