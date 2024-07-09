#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Level/Level.h"

class ControllerLevel
{
public:
    ControllerLevel();
    void add(std::string name, std::unique_ptr<Level> c);
    void activate();
    //void drawMenu();
    ~ControllerLevel();

private:
    typedef std::pair<std::string, std::unique_ptr<Level>> m_level;
    std::vector<m_level> m_levels;
};