//~~~~~~~~~~~~~~library stack~~~~~~~~~~~~~~

#define MAX 1000

// create a pointer to stack
typedef int t_pointer_stack;

// create a key to stack
typedef int t_key_stack;

// create a structure of itens to tue stack
typedef struct {
	t_key_stack key_stack;
}t_item_stack;

// create the structure of stack with iten and the top
typedef	struct {
	t_item_stack item_stack[MAX];
	t_pointer_stack top;
}t_stack;

//~~~~~~~~~functions of stack~~~~~~~~~
void createemptystack(t_stack *stack);
int empty_s(t_stack *stack);
void stacks(t_item_stack x, t_stack *stack);
void unpack(t_stack *stack, t_item_stack *item_stack);
int size(t_stack *stack);