#include "cli.h"
#include "command.h"
#include "flag.h"
#include <cerrno>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


struct Cli *createCli(unsigned int commandSize, unsigned int flagSize) {
	struct Cli *cli = (struct Cli *)malloc(sizeof(struct Cli));
	memset(cli, 0, sizeof(struct Cli));
	cli->commandSize = commandSize;
	cli->flagSize = flagSize;
	cli->commands = (struct Command*)malloc(cli->commandSize * sizeof(struct Command));
	cli->flags = (struct Flag*)malloc(cli->flagSize * sizeof(struct Flag));
	return cli;
}
void destroyCli(struct Cli *cli) {
	free(cli->flags);
	free(cli->commands);
	free(cli);
}

int cliAddCommand(struct Cli *cli, struct Command command) {
	if (cli->commandNum == cli->commandSize) {
		return ENOMEM;
	}
	cli->commands[cli->commandNum] = command;
	cli->commandNum++;
}
int cliAddFlag(struct Cli *cli, struct Flag flag) {
	if (cli->flagNum == cli->flagSize) {
		return ENOMEM;
	}
	cli->flags[cli->flagNum] = flag;
	cli->flagNum++;
}
