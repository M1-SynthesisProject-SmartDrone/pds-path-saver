#ifndef __OPTIONS_PARSER_H__
#define __OPTIONS_PARSER_H__

#include "structs/DatabaseInfos.h"
#include "structs/InputInfos.h"

void parseOptions(int argc, char *argv[], DatabaseInfos& dbInfos, InputInfos& inputInfos);

#endif // __OPTIONS_PARSER_H__