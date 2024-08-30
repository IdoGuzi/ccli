#include "command.h"
#include <stdlib.h>
#include <string.h>


struct Command *createCommand(unsigned int flagSize, void* (handler)()) {
	struct Command *command = (struct Command*)malloc(sizeof(struct Command));
	memset(command, 0, sizeof(struct Command));
	command->flagSize = flagSize;
	command->flagNum = 0;
	command->flags = (struct Flag*)malloc(command->flagSize * sizeof(struct Flag));
	command->handler = handler;
	return command;
}
void destroyCommand(struct Command *command) {
	free(command->flags);
	free(command);
}

void commandAddFlag(struct Command *command, struct Flag flag);
