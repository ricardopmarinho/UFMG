//~~~~~~~~~~~~~~main~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>
#include "../adt/adt-queue.h"
#include "../adt/adt-stack.h"

int main(){

	// total time between start and end
	int timer;
	printf("1)Digite o tempo total em minutos:\n");
	scanf("%d", &timer);

	// number of students arriving
	int students_arriving;
	printf("2)Digite a quantidade de estudantes que chegam na lanchonete:\n");
	scanf("%d", &students_arriving);

	// number of cashdesk queues
	int cashdesk_queues;
	printf("3)Digite a quantidade de filas para o caixa:\n");
	scanf("%d", &cashdesk_queues);

	// number of tray queues
	int tray_queues;
	printf("4)Digite a quantidade de filas para bandejas:\n");
	scanf("%d", &tray_queues);

	// number of trays stack
	int tray_stack;
	printf("5)Digite a quantidade de pilhas de bandejas:\n");
	scanf("%d", &tray_stack);

	// number of trays
	int tray;
	printf("6)Digite a quantidade de bandejas na pilha:\n");
	scanf("%d", &tray);

	// number of rearrange trays
	int rearrange_tray;
	printf("7)Digite a quantidade de bandejas que serão recolocadas:\n");
	scanf("%d", &rearrange_tray);

	// time to restore trays
	int rearrange_tray_time;
	printf("8)Digite de quanto em quanto tempo as bandejas serão recolocadas em minutos:\n");
	scanf("%d", &rearrange_tray_time);

	// accounting variables
	int total_time = 0, people_attended = 0, current_time = 0, student_index = 0;

	// variables, function and allocation related to queue
	t_queue queue_card, queue_tray;
	t_item_queue *student, *cashdesk = NULL, *rice = NULL, *beans = NULL, *meat = NULL, *salad = NULL;
	createemptyqueue(&queue_card);
	createemptyqueue(&queue_tray);
	student = malloc ((cashdesk_queues * timer * students_arriving) * sizeof(t_item_queue));

	// variables and funtion related to stack
	t_stack stack_tray[tray];
	t_item_stack tray_to_stack[tray];
	createemptystack(stack_tray);
		
	// put itens on the stack
	for (int i = 0; i < tray * tray_stack; ++i){
		tray_to_stack[i].key_stack = i;
		stacks(tray_to_stack[i], stack_tray);
	}

	// loop to put students in order
	while(current_time < timer){

		// check if is time to rearrange trays
		if (current_time%rearrange_tray_time==0){
			// loop to rearrange trays
			for (int i = 0; i < rearrange_tray; ++i){
				stacks(tray_to_stack[i], stack_tray);
			}
		}

		// inconming loop of students in the queues of que cashdesk
		for (int i = 0; i < students_arriving; ++i){
			for (int i = 0; i < cashdesk_queues; ++i){
				student[student_index].key_queue = current_time;
				toqueue(&student[student_index], &queue_card);
				student_index++;
			}
		}

		// check if someone has already passed the cashdesk and should go to queue of trays
		if (cashdesk != NULL){
			for (int i = 0; i < tray_queues; ++i){
			 	toqueue(cashdesk, &queue_tray);
			 	cashdesk = outqueue(&queue_card);
			 } 
			
		}		
		else cashdesk = outqueue(&queue_card);
				
		

		// check if someone should leave the queue of trays and pick up their tray
		for (int i = 0; i < tray_queues; ++i){
			if (!empty_q(&queue_tray)){
				if (!empty_s(stack_tray)){
					t_item_stack bandeja;
					unpack(stack_tray, &bandeja);
				}
			}
		}
		// check if someone has reached the last food and finished his time in the queues
		if (salad != NULL){
				// account the total time spent by students in queues
				total_time += current_time - salad->key_queue + 1;
				// account total people attended
				people_attended++;
		}

		// finish serving meat and start serving salad
		salad = meat;

		// finish serving beans and start serving meat
		meat = beans;

		// finish serving rice and start serving beans
		beans = rice;

		// check if someone is with the tray ready to serve the first food
		if (empty_q(&queue_tray) || empty_s(stack_tray)){
			rice = NULL;
		}
		else rice = outqueue(&queue_tray);

		// current time
		current_time++;
	}	

	// displays the total number of people served
	printf("\nQuantidade de pessoas atendidas: %d\n", people_attended);
	// displays the average service time on the screen
	printf("Tempo medio para atendimento: %d\n", total_time/(people_attended));
		
	return 0;
}