#include <stdio.h>
#define W 10
#define AND 1
#define NOT 2
#define OR 3
#define XOR 4
#define MAX_ITER 2
#define MAX_ING 1
#define MAX_INW 10

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
void pg(int n){
	printf("gate %d a %d b %d t %d o %d\n",n,gates[n].a,gates[n].b,gates[n].t,gates[n].o);
}
void printlogic() {
	int i=0;
	for(i=0;i<W;i++){
		pg(i);
	}
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
	wires[0]=0;
	wires[1]=1;
	gates[0].a=0;
	gates[0].b=1;
	gates[0].o=2;
	gates[0].t=NOT;
	status();
}
void getgate(int n) {
	gates[n].a=getchar()-'0';
	gates[n].b=getchar()-'0';
	gates[n].t=getchar()-'0';
	gates[n].o=getchar()-'0';
}
void readin() {
	int i=0;
	int ing=getchar()-'0';
	for(i=0;i<ing;i++){
		getgate(i);
	}
	for(i=0;i<MAX_INW;i++){
		wires[i]=getchar()-'0';
	}
	printf("wires:");
	for(i=0;i<W;i++){
		printf(" %d",wires[i]);
	}
	printf("\n");
	printlogic();
}
int main() {
	int i=0;
//	init();
	readin();
	status();
	for(i=0;i<MAX_ITER;i++){
		evaluate();
		status();
	}

	return 0;
}
