#ifndef _CALC_H
#define _CALC_H

#ifndef STACKSIZE
#define STACKSIZE 4
#endif

// OPERATION CONSTANTS
#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4
#define SQRT 5

extern int push(double number);    // Pushes a number onto the stack.
extern void pop();                 // Pops an entry and leave a 0.0 in its place.
extern double get_entry(int flag); // Returns an element from the stack.

//  
// !!!!!!!!!!!!!!!!!! DO NOT TOUCH ANY CODE ABOVE THIS LINE  !!!!!!!!!!!!!!!!!!
// !!!!! YOU WILL NEED TO WRITE THE FUNCTION PROTOTYPES BENEATH THIS LINE !!!!!
//

extern int get_size();

extern double get_tos();

extern void do_oper(int operation);

extern void swap_entry();

extern void rotate_stack();

#endif
