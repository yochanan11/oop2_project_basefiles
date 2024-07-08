#pragma once
#include "Command.h"
#include "Controller.h"

class NewGame : public Command {
public:
    NewGame(Controller* controller); // ��� ����� �-Controller
    ~NewGame();
    void execute() override;

private:
    Controller* m_controller; // ����� ����� �-Controller
    std::string getPlayerName();

};
