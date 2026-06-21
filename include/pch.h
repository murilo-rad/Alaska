#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <windows.h>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif
#include <string.h>
#include <sstream>
#include <fstream>
#include <map>
#include <exception>
#include <iomanip>
#include <algorithm>
#include <stdio.h>


#define GRAVIDADE 0.50f
#define MAX_INI 5
#define MIN 3

#define L_CHAO 1388.0f
#define A_CHAO 50.0f

#define L_FUNDO 1388.0f
#define A_FUNDO 768.0f

#define L_PLAT 200.0f
#define A_PLAT 30.0f
#define MAX_OBS 5

#define L_GELO 200.0f
#define A_GELO 30.0f
#define MAX_GELO 5

#define L_MITE 200.0f
#define A_MITE 30.0f
#define MAX_MITE 5

#define T_NEVOSO 50.0f
#define T_LOBO 60.0f
#define T_ABO 120.0f
#define T_BOLA 20.0f
#define T_JOG 50.0f

#define A_MAX_GERAL 719.0f

#define L_TELA 1366.0f
#define A_TELA 768.0f

#define IND_CHAO 1
#define IND_PLAT 2
#define IND_GELO 3
#define IND_MITE 4
#define IND_NEV 5
#define IND_LOBO 6
#define IND_ABM 7
#define IND_BOLA 8
#define IND_JOG 9

#define CAMINHO_SAVE "save/arquivo_de_salvamento.csv"
#define CAMINHO_META_SAVE "save/meta_save.csv"
#define CAMINHO_LEADERBOARD "save/leaderboard.csv"
#define MAX_LEADERBOARD 10

inline void garantirPastaSaveAlaska()
{
#ifdef _WIN32
    _mkdir("save");
#else
    mkdir("save", 0755);
#endif
}
