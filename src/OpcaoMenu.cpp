#include "Menu.h"

Alaska::Menu::OpcaoMenu::OpcaoMenu()
    : texto(""), acao(nullptr)
{
}

Alaska::Menu::OpcaoMenu::OpcaoMenu(const std::string& texto, void (Menu::*acao)())
    : texto(texto), acao(acao)
{
}

Alaska::Menu::OpcaoMenu::~OpcaoMenu()
{
}

const std::string& Alaska::Menu::OpcaoMenu::getTexto() const
{
    return texto;
}

void Alaska::Menu::OpcaoMenu::executar(Menu* pMenu) const
{
    if (pMenu && acao)
        (pMenu->*acao)();
}
