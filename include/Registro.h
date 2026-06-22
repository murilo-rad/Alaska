#pragma once
#include "pch.h"

namespace Alaska
{
    class Registro
    {
        private:
            std::string nome;
            int pontos;
            float tempo;

        public:
            Registro();
            Registro(const std::string& nome, int pontos, float tempo);
            ~Registro();

            const std::string& getNome() const;
            int getPontos() const;
            float getTempo() const;

            bool vemAntesDo(const Registro& outro) const;
            std::string gerarLinhaArquivo() const;
            std::string gerarLinhaFormatada(int posicao) const;
    };
}
