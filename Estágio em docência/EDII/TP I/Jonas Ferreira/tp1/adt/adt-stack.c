//~~~~~~~~~~~~~~adt stack~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>
#include "adt-stack.h"

// create empty stack
void createemptystack(t_stack *stack){
	stack->top = 0;
}

// check if stack is empty
int empty_s(t_stack *stack){
	return(stack->top == 0);
}

// stacks
void stacks(t_item_stack x, t_stack *stack){
	if (stack->top == MAX){
		fprintf(stderr, "Error: full stack\n");
		exit(-1);
	}
	else{
		stack->item_stack[stack->top] = x;
		stack->top++;
	}	
}

// unpack
void unpack(t_stack *stack, t_item_stack *item_stack){
	if (empty_s(stack)){
		fprintf(stderr, "Error: empty stack\n");
		exit(-1);
	}
	else{
		*item_stack = stack->item_stack[stack->top -1];
		stack->top--;
	}
}

// checks stack size
int size(t_stack *stack){
	return stack->top;
}