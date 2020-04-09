#include<iostream>
#include "cpu.h"

using namespace std;

int main () {

	CPU myCPU;

	myCPU.LoadProgram("Prog1.asm");
	cout << "Accumulator: " << myCPU.Run() << endl;
	myCPU.LoadProgram("Prog1.asm");
	while (myCPU.Next() == 0) {
		myCPU.Print();
	}
		
	myCPU.LoadProgram("Prog2.asm");
	cout << "Accumulator: " <<  myCPU.Run() << endl;
	myCPU.LoadProgram("Prog2.asm");
	while (myCPU.Next() == 0) {
		myCPU.Print();
	}
	
	return 0;
}
		
