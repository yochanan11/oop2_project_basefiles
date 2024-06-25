#include "Menu.h"
//--------------------------
Menu::Menu(){}
//---------------------------
void Menu::add(std::string name, std::unique_ptr<Command> c)
{
    m_options.emplace_back(m_option(name, move(c)));
}
//---------------------------
void Menu::activate() {
    int n;
    do {
        show();
        n = getOptionFromUser();
    } while (performAction(n));
}

//---------------------------
Menu::~Menu(){}
//---------------------------
void Menu::show() {
    for (unsigned i = 0; i < m_options.size(); i++)
        std::cout << i << " - " << m_options[i].first << " \n";
    std::cout << m_options.size() << "- Exit\n";
}

//---------------------------
int Menu::getOptionFromUser() {
    std::cout << "your choice: ";
    int n;
    std::cin >> n;
    return n;
}
//---------------------------
bool Menu::performAction(unsigned n) {
    if (n >= m_options.size())
        return false;
    m_options[n].second->execute();
    return true;
}