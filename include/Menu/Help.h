#pragma once
#include "Command.h"

class Help : public Command {
public:
    Help();
    ~Help();
    void execute() override;

private:

};
