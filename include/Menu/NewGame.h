#pragma once
#include "Command.h"

class NewGame:public Command
{
public:
	NewGame();
	~NewGame();
	void execute() override;
private:

};


