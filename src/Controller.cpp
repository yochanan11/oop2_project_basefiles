#include "Controller.h"
#include "Menu/NewGame.h"
#include "Menu/Help.h"
#include "Menu/Records.h"
#include "Level/Level1.h"

Controller::Controller() {
}
//------------------------------------
Controller::~Controller() {}
//------------------------------------
void Controller::run() {
    Resources::instance().getMusic().setLoop(true);
    Resources::instance().getMusic().play();
    Resources::instance().getMusic().setVolume(80);
    m_menu.add("New Game", std::make_unique<NewGame>(this));
    m_menu.add("help", std::make_unique<Help>());
    m_menu.add("records", std::make_unique<Records>());
    m_level.add("Level1", std::make_unique<Level1>(m_player));
    // m_level.add("Level2", std::make_unique<Level2>(m_player)); //For in a example
    runMenu();
    Resources::instance().getMusic().stop();

}
//------------------------------------
void Controller::runMenu() { m_menu.drawMenu(); }
//------------------------------------
void Controller::runGame() {m_level.activate(); }
//------------------------------------
Player& Controller::getPlayer(){return m_player; }
