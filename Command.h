//
// Created by adi on 17/12/18.
//

#ifndef PROJECT1_COMMAND_H
#define PROJECT1_COMMAND_H

#include <string>
#include <vector>
#include "CheckExpressions.h"
#include "ShuntingYard.h"
#include "SymbolsTable.h"

using namespace std;

class Command {

public:
    virtual int doCommand(vector<string> info, int index) = 0;

    virtual ~Command() = default;
};
#endif //PROJECT1_COMMAND_H
