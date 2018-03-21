//~~~~~~~~~~~~~~library queue~~~~~~~~~~~~~~

// create a key to queue
typedef int t_key_queue;

// create the structure of itens to the queue
typedef struct t_item_queue {
	t_key_queue key_queue;
}t_item_queue;

// create the pointer to use in the cells
typedef struct cell
	*t_pointer_queue;

// create the structure of cell with itens and the next of the queue
typedef struct cell {
	t_item_queue* item_queue;
	t_pointer_queue next;
}t_cell;

// create structute of queue with front and back
typedef struct {
	t_pointer_queue front;
	t_pointer_queue back;
}t_queue;

//~~~~~~~~~functions of stack~~~~~~~~~
void createemptyqueue (t_queue *queue);
int empty_q (t_queue *queue);
void toqueue (t_item_queue* x, t_queue *queue);
t_item_queue * outqueue (t_queue *queue);	