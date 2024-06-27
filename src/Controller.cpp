#include "Controller.h"
#include <Level/Level1.h>
//--------------------------
Controller::Controller()
{
    m_bac.setTexture(Resources::instance().getTexture(ObjIndex::BACKGROUND));
}
//--------------------------
Controller::~Controller()
{
}
//--------------------------
void Controller::run()
{
    m_menu.drawMenu();
    m_level.add("Level1", std::make_unique<Level1>(m_player));
    //m_level.add("Level2", std::make_unique<Level2>(m_player));
    m_level.activate();
}

