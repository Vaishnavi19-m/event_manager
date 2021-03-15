#include<stdio.h>
#include<stdlib.h>

enum Modules {
	MODULE_1 = 1,
	MODULE_2,
	MODULE_3,
	MODULE_5,
	MODULE_MAX
};

int num_evnt;
int inte_evnt;
void init_module(int num_evnt);
//extern void (*module_func[5])();

void module_1(int evnt);
void module_2(int evnt);
void module_3(int evnt);
void module_4(int evnt);
void module_5(int evnt);

//void (*module_func[5])() = {module_1, module_2, module_3, module_4, module_5 };
