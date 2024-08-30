#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "flag.h"

/*
 * Command for cli program
 * used to select different functionalities of a program
 */
struct Command {
	unsigned int flagNum, flagSize;
	struct Flag* flags;
	void* (*handler)();
};

/*
 * createCommand object
 * @param: flagSize - max number of flags in the command
 * @param: handler - function to execute of the command is selected
 * @returns: pointer to the new Command object
 */
struct Command *createCommand(unsigned int flagSize, void* (*handler)());

/*
 * destroyCommand free the allocated memory of Commnad object
 * @param: command - object to destroy
 */
void destroyCommand(struct Command *command);


void commandAddFlag(struct Command *command, struct Flag flag);

#endif /*__COMMAND_H__*/
