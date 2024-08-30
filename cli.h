#ifndef __CLI_H__
#define __CLI_H__

#include "command.h"
#include "flag.h"

/*
 * Cli is the head object of the cli parsing
 * Cli object is meant to parse the top most level of a project
 */
struct Cli {
	unsigned int commandNum, commandSize;
	unsigned int flagNum, flagSize;
	struct Command *commands;
	struct Flag *flags;
};

/*
 * createCli object
 * @param: commandSize - max number of commands in CLI object
 * @param: flagSize - max number of flags in CLI object
 * @returns: empty CLI object with commandSize capacity for commands and flagSize capacity for flags
 */
struct Cli *createCli(unsigned int commandSize, unsigned int flagSize);

/*
 * destroyCli free the allocated memory of CLI object
 * @param: cli - CLI object to destroy
 */
void destroyCli(struct Cli *cli);

/*
 * cliAddCommand to CLI object
 * @param: cli - object to add the command to
 * @param: command - to add to CLI object
 * @returns: 0 on success, errno value otherwise
 */
int cliAddCommand(struct Cli *cli, struct Command command);

/*
 * cliAddFlag to CLI object
 * @param: cli - object to add the flag to
 * @param: flag - to add to CLI object
 * @returns: 0 on success, errno value otherwise
 */
int cliAddFlag(struct Cli *cli, struct Flag flag);

#endif /*__CLI_H__*/
