/**
 * Assignment-3
 * CSE30 Username: cs30fa21cep (fill out your username)
 * Class: UCSD CSE30-FA21
 */

#include "calc.h"
#include <math.h>

//  
// !!!!!!!! DO NOT TOUCH ANY CODE ABOVE THIS LINE (not incl. username) !!!!!!!!
// !!!!!!!!            YOU MAY WRITE STATIC VARIABLES BELOW            !!!!!!!!
// 
static int index;
static double stack[STACKSIZE];

static int lastentryexists = 0;
static int lastentry;

/**
 * Push a new value onto the stack.
 * 
 * If the stack is full, do not push anything.
 *
 * @return 1 if push is successful, 0 otherwise
 */
int push(double d)
{
    // 
    //  ---------------------------- TODO: FILL IN ---------------------------- 
	if(index > STACKSIZE-1) {
	    return 0;
	}
	else {
		stack[index] = d;	
		index++;
		return 1;
	}
}

/**
 * Pop the current top of stack and set the prior top of stack to 0.0.
 *
 * Do nothing if there nothing on the stack.
 */
void pop()
{
    // 
    //  ---------------------------- TODO: FILL IN ---------------------------- 
    //
    	 if(index >= 1) {
		 index--;
		 stack[index] = 0.0;
	}
}

/**
 * Get an entry from the stack.
 *
 * If passed a postive number, return the oldest stack entry.
 * If passed a 0, return the next oldest stack entry (with respect to a prior call).
 */
double get_entry(int flag)
{
    // 
    //  ---------------------------- TODO: FILL IN ----------------------------
    //
    
	if(flag > 0) {
		lastentryexists = 1;
		lastentry = 0;
		return stack[lastentry];
	}	
	else {
		if(lastentryexists == 1){
			if((lastentry < index)) {
				lastentry++;
				return stack[lastentry];
			}	
		}
	}
	
}

/**
 * Returns the number of elements in the stack.
 * 
 * @return number of elements in the stack
 */
//  
//  ------------------------- TODO: WRITE get_size()  -------------------------
// 
int get_size() {
	return index;
}



/**
 * Return the element on the top of the stack (the youngest entry).
 * 
 * If the stack is empty, return 0.0.
 * 
 * @return the element on the top of the stack
 */
// 
//  -------------------------- TODO: WRITE get_tos() --------------------------
// 
double get_tos() {
	if(index == 0){
		return 0.0;
	}
	else {
		return stack[index - 1];
	}
}

/**
 * Do an operation on the top two stack elements.
 *
 * Operation may be one of following: ADD, SUBTRACT, MULTIPLY, DIVIDE, SQRT.
 */
// 
//  -------------------------- TODO: WRITE do_oper() -------------------------- 
//
void do_oper(int operation) {
	if(operation == ADD){
		double temp1 = stack[index-1];
		double temp2 = stack[index-2];
		double sum = temp1 + temp2;
		pop();
		pop();
		push(sum);
	}	
	else if(operation == SUBTRACT){
		double temp3 = stack[index-1];
		double temp4 = stack[index-2];
		double diff = temp4 - temp3;
		pop();
		pop();
		push(diff);	
	}
	else if(operation == MULTIPLY){
		double temp5 = stack[index-1];
		double temp6 = stack[index-2];
		double prod = temp5 * temp6;
		pop();
		pop();
		push(prod);	
	}
	else if(operation == DIVIDE){
		double temp7 = stack[index-1];
		double temp8 = stack[index-2];
		double quo = temp8 / temp7;
		pop();
		pop();
		push(quo);
		
	}	
	else if(operation == SQRT){
		double temp9 = stack[index-1];
		double sq = sqrt(temp9);
		pop();
		push(sq);
	}
}


/**
 * Swap the top two stack entries.
 *
 * If the stack has fewer than 2 entries, do nothing.
 */
// 
//  ------------------------ TODO: WRITE swap_entry() ------------------------
//
void swap_entry() {
	double top = stack[index-1];
	double bottom = stack[index-2];
	pop();
	pop();
	push(top);
	push(bottom);

}

/**
 * Makes oldest stack entry becomes the youngest,
 * youngest becomes the second youngest, 
 * second oldest becomes the oldest, etc.
 */
// 
//  ----------------------- TODO: WRITE rotate_stack() -----------------------
//
void rotate_stack() {	
	double temp = stack[0];
	for(int i=1; i<index; i++){
		stack[i-1] = stack[i];
	}
	stack[index-1] = temp;	
}
