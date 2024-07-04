#include "Level/ControllerLevel.h"

ControllerLevel::ControllerLevel(){}
//-------------------------------------
ControllerLevel::~ControllerLevel(){}
//-------------------------------------
void ControllerLevel::activate()
{
    for (auto& level : m_levels)
        level.second->run();
}
//-------------------------------------
void ControllerLevel::add(std::string name, std::unique_ptr<Level> c)
{
    m_levels.emplace_back(m_level(name, move(c)));
}
//------------------------------------
