//
// Created by Colton Sellers on 3/10/2019.
//

#include <iostream>
#include <bits/stdc++.h>
#include "cpu.h"

//Constructor for CPU, set initial values for accumulator and top of stack
CPU::CPU(){
    accumulator = 0;
    top = -1;
}

//Resets the values of accumulator and top of the stack, then opens the file to be processed.
void CPU::LoadProgram(string file){
    accumulator = 0;
    top = -1;

    program.open(file);
    if (!program.is_open()) {
        cout << "Can't open file" << endl;
    }

}

//Runs the entire file for processing line by line. Returns accumulator.
int CPU::Run(){
    string line;

    while(getline(program, line)) {
        process(line);
    }

    program.close();
    return accumulator;

}

//Calls only the next line in the file for processing returns 0 if line successfully retrieved, 0 if not.
int CPU::Next(){
    string line;
    if(getline(program, line)) {
        process(line);
        return 0;
    } else {
        program.close();
        return -1;
    }
}

//Prints out the stack in its current form
void CPU::Print(){
    if (top >= 0) {
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << " " << stack[i];
        }
        cout << endl;
    }
}

//Tokenize input and call commands to manipulate stack/accumulator.
void CPU::process(string input) {
    string command;
    int var;
    stringstream ss(input);

    ss >> command;
    ss >> var;

    if (command == "PSH")
        push(var);
    else if (command == "POP")
        accumulator = pop();
    else if (command == "ADD")
        accumulator += pop();
    else if (command == "SUB")
        accumulator -= pop();
    else if (command == "CMP")
        CMP();
    else
        cout << "Unrecognized command" << command << endl;
}

//Pushes int onto stack
void CPU::push(int push){
    if(top >= 29){
        cout << "Stack is too full";
    } else {
        stack[++top] = push;
    }
}

//Pops an int off the top of the stack an returns the result.
int CPU::pop(){
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return 0;
    } else {
        int pop = stack[top--];
        return pop;
    }

}

//Compares the top of the stack to the accumulator, pushes -1 if smaller, 0 if equal and 1 if larger.
void CPU::CMP(){
    int compare = pop();

    if(compare < accumulator)
        push(-1);
    else if (compare = accumulator)
        push(0);
    else if (compare > accumulator)
        push(1);
}