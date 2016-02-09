#include <stdio.h>
#include <malloc.h>
#define AND 1
#define NOT 2
#define OR 3
#define XOR 4
#define MAX_ITER 2
#define MAX_INW 10

typedef struct gate{
	int a;
	int b;
	int t;
	int o;
}gate;
/*gate gates[W];
int wires[W];
int oldwires[W];
*/
gate *gates;
int *wires;
int *oldwires;
int inw;
int ing;
int iterations;
void status() {
	int i=0;
	for(i=0;i<inw;i++){
		printf(" %d",wires[i]);
	}
	printf("\n");
}
void pg(int n){
	printf("gate %d a %d b %d t %d o %d\n",n,gates[n].a,gates[n].b,gates[n].t,gates[n].o);
}
void eg(int n) {
	gate g=gates[n];
	switch(g.t) {
		case AND: wires[g.o]=oldwires[g.a]&&oldwires[g.b];break;
		case NOT: wires[g.o]=!wires[g.a];break;
		case OR: wires[g.o]=oldwires[g.a]||oldwires[g.b];break;
		case XOR: wires[g.o]=oldwires[g.a]^oldwires[g.b];break;
	}
}
void evaluate() {
	int i=0;
	for(i=0; i<ing;i++) {
		eg(i);
	}
	for(i=0;i<inw;i++){
		oldwires[i]=wires[i];
	}
}
void getgate(int n) {
	gates[n].a=getchar()-'0';
	gates[n].b=getchar()-'0';
	gates[n].t=getchar()-'0';
	gates[n].o=getchar()-'0';
}
void readin() {
	int i=0;
	iterations=getchar()-'0';
	iterations=iterations+(getchar()-'0')*10;
	ing=getchar()-'0';
	ing=ing+(getchar()-'0')*10;
	inw=getchar()-'0';
	inw=inw+(getchar()-'0')*10;
	gates=calloc(sizeof(gate)*ing,sizeof(gate));
	wires=calloc(sizeof(int)*inw,sizeof(int));
	oldwires=calloc(sizeof(int)*inw,sizeof(int));
	
	for(i=0;i<ing;i++){
		getgate(i);
	}
	for(i=0;i<inw;i++){
		wires[i]=getchar()-'0';
	}
	printf("wires:");
	status();
	for(i=0;i<ing;i++){
		pg(i);
	}
}
int main() {
	int i=0;
//	init();
	readin();
	status();
	for(i=0;i<iterations;i++){
		evaluate();
		status();
	}

	return 0;
}
