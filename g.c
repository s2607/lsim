#include <stdio.h>
#define W 10
#define AND 1
#define NOT 2
#define OR 3
#define XOR 4
#define MAX_ITER 2

typedef struct gate{
	int a;
	int b;
	int o;
	int t;
}gate;
gate gates[W];
int wires[W];
int oldwires[W];
void status() {
	int i=0;
	printf("STATUS:\n");
	for(i=0;i<W;i++){
		printf(" %d",i);
	}
	printf("\n");
	for(i=0;i<W;i++){
		printf(" %d",wires[i]);
	}
	printf("\n");
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
	for(i=0; i<W;i++) {
		eg(i);
	}
	for(i=0;i<W;i++){
		oldwires[i]=wires[i];
	}
}
void init() {
	wires[0]=1;
	gates[0].a=0;
	gates[0].b=1;
	gates[0].o=2;
	gates[0].t=OR;
	status();
}
int main() {
	int i=0;
	init();
	for(i=0;i<MAX_ITER;i++){
		evaluate();
		status();
	}

	return 0;
}
