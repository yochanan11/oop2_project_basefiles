#pragma once
#include "Command.h"
#include "Controller.h"

class NewGame : public Command {
public:
    NewGame(Controller* controller); 
    ~NewGame();
    void execute() override;

private:
    Controller* m_controller; 
    std::string getPlayerName();

};
