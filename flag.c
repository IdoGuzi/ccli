#include "flag.h"
#include <stdlib.h>
#include <string.h>


struct Flag *createFlag(char shortName, char *name, void* (*handler)()) {
	struct Flag *flag = (struct Flag*)malloc(sizeof(struct Flag));
	memset(flag, 0, sizeof(struct Flag));
	flag->name = name;
	flag->shortName = shortName;
	flag->handler = handler;
	return flag;
}
void destroyFlag(struct Flag *flag) {
	free(flag);
}
