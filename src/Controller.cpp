#include "Controller.h"
#include "Menu/NewGame.h"
#include <Level/Level1.h>

Controller::Controller() {
    m_bac.setTexture(Resources::instance().getTexture(ObjIndex::BACKGROUND));
}
//------------------------------------
Controller::~Controller() {}
//------------------------------------
void Controller::run() {
    Resources::instance().getMusic().setLoop(true);
    Resources::instance().getMusic().play();
    Resources::instance().getMusic().setVolume(80);
    m_menu.add("New Game", std::make_unique<NewGame>(this)); // העברת מצביע ל-Controller
    m_level.add("Level1", std::make_unique<Level1>(m_player));
    // m_level.add("Level2", std::make_unique<Level2>(m_player));
    runMenu();
    Resources::instance().getMusic().stop();

}
//------------------------------------
void Controller::runMenu() {
    
    m_menu.drawMenu();
}
//------------------------------------
void Controller::runGame() {
    m_level.activate();
}
