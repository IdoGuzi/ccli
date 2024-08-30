#ifndef __FLAG_H__
#define __FLAG_H__

struct Flag {
	char shortName;
	char* name;
	void* (*handler)();
};

struct Flag *createFlag(char shortName, char *name, void* (*handler)());
void destroyFlag(struct Flag *flag);

#endif /*__FLAG_H__*/
