#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <Command.h>

class Menu {
public:
    Menu();
    void add(std::string name, std::unique_ptr<Command> c);
    void activate();
    ~Menu();

private:
    typedef std::pair<std::string, std::unique_ptr<Command>> m_option;
    std::vector<m_option> m_options;
    //---------------------------
    void show();
    int getOptionFromUser();
    bool performAction(unsigned n);
};