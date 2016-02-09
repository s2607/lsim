#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define AND 1
#define NOT 2
#define OR 3
#define XOR 4

typedef struct gate{
	int a;
	int b;
	int t;
	int o;
}gate;
gate *gates;
int *wires;
int *oldwires;
int inw;
int ing;
int iterations;

int getnum(int l) {
	int n=0;
	int i=0;
	for(;l>0;l--)
		n=n+((getchar()-'0')*pow(10,l-1));
	//printf("%d \n",n);
	return n;
}
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
	gates[n].a=getnum(1);
	gates[n].b=getnum(1);
	gates[n].t=getnum(1);
	gates[n].o=getnum(1);

}
void readin() {
	int i=0;
	iterations=getnum(2);
	ing=getnum(2);
	inw=getnum(2);
	gates=calloc(sizeof(gate)*ing,sizeof(gate));
	wires=calloc(sizeof(int)*inw,sizeof(int));
	oldwires=calloc(sizeof(int)*inw,sizeof(int));
	
	for(i=0;i<ing;i++){
		getgate(i);
	}
	for(i=0;i<inw;i++){
		wires[i]=getnum(1);
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
