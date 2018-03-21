//~~~~~~~~~~~~~~adt queue~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>
#include "adt-queue.h"

// create empty queue
void createemptyqueue (t_queue *queue) {
	queue->back = queue->front = NULL;
}

// check if queue is empty
int empty_q (t_queue *queue) {
	return (queue->front == NULL && queue->back == NULL);
}

// put itens in the queue
void toqueue (t_item_queue* x, t_queue *queue) {
	if (empty_q(queue))
	{
		queue->front = queue->back = malloc(sizeof(t_cell));
		queue->front->item_queue = x;
		queue->front->next = NULL;
		return;
	}
	queue->back->next = malloc(sizeof(t_cell));
	queue->back = queue->back->next;
	queue->back->item_queue = x;
	queue->back->next = NULL;
}

// put itens out of the queue
t_item_queue * outqueue (t_queue *queue) {
	if (empty_q(queue)) {
		fprintf(stderr, "Erro: fila vazia\n");
		return NULL;
	}

	t_pointer_queue q = queue->front;
	queue->front = queue->front->next;
	t_item_queue *item_queue = q->item_queue;
	free(q);

	if (queue->front == NULL)
		queue->back = NULL;

	return item_queue;
}