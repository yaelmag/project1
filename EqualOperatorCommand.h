//
// Created by adi on 18/12/18.
//

#ifndef PROJECT1_EQUALOPERATORCOMMAND_H
#define PROJECT1_EQUALOPERATORCOMMAND_H
#include "Command.h"
#include "VarBindMap.h"
#include "SymbolTable.h"

class EqualOperatorCommand : public Command {
public:
    EqualOperatorCommand();
    int doCommand(vector<string> info, int index);
};


#endif //PROJECT1_EQUALOPERATORCOMMAND_H
