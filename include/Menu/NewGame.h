#pragma once
#include "Command.h"
#include "Controller.h"

class NewGame : public Command {
public:
    NewGame(Controller* controller); // קבל מצביע ל-Controller
    ~NewGame();
    void execute() override;

private:
    Controller* m_controller; // שמירת מצביע ל-Controller
    std::string getPlayerName();

};
