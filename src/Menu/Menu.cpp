#include "Menu.h"
//--------------------------
Menu::Menu():m_bac(Resources::instance().getTexture(ObjIndex::MENU)){}
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
//-----------------------------
void Menu::drawMenu()
{
    auto window = sf::RenderWindow(sf::VideoMode(989, 950), "Menu");
    m_window = &window;
    while (m_window->isOpen())
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }
        m_window->clear();
        m_window->draw(m_bac);
        m_window->display();
    }
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