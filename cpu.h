//
// Created by NEW USER on 3/10/2019.
//

#ifndef ASS5_CPU_H
#define ASS5_CPU_H

#include <string>
#include <fstream>

using namespace std;

class CPU {
public:
    CPU();
    void LoadProgram(string);
    int Run();
    int Next();
    void Print();

private:
    void process(string);
    void push(int);
    int pop();
    void CMP();

    int accumulator;
    int top;
    ifstream program;
    int stack[30];

};


#endif //ASS5_CPU_H
