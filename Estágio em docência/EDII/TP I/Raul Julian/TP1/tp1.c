#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_MESSAGES 10
#define MAX_TRAYS 30
#define RESTITUTION_AMOUNT_FOOD 10
#define CLIENTS_PER_TIME 2
#define RESTITUTION_INTERVAL_SERVICE 12
#define SYSTEM_INTERVAL_TIME 240
#define SERVICE_INTERVAL_TIME 1
#define FOOD_INTERVAL_TIME 1

//VARIABLES TO CONTROL
#define AMOUNT_TAB_QUEUE 1
#define AMOUNT_SERVICE_QUEUE 1

int elemId = 1;
int stackId = 1;
int people_attended = 0;
int ind_tab_queue = 0;
int ind_service_queue = 0;
const char messages[MAX_MESSAGES][100] = {
    "SYSTEM MESSAGE: ",
    "NO MEMÓRY AVAILABLE.",
    "THE LIST IS EMPTY.",
    "THE STACK IS EMPTY.",
    "THE STACK IS FULL.",
};

typedef struct stack {
    int
        top,
        rows[MAX_TRAYS];
} Stack;

typedef struct node {
    int id,
        count_sTime;
    struct node *prox;
} Node;

//Clients Served
Node *clients_served = NULL;

bool stack_full(Stack *stack) {
    return (stack->top == (MAX_TRAYS - 1));
}

bool stack_empty(Stack *stack) {
    return (stack->top == 0);
}

Stack* stack_create() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));

    if (!stack) {
        printf("%s %s\n", messages[0], messages[1]);
        exit(1);
    }

    stack->top = 0;
    return stack;
}

void stack_up(Stack *stack) {
    if (stack_full(stack)) {
        printf("%s %s\n", messages[0], messages[4]);
        return;
    } else stack->rows[stack->top++] = stackId++;
}

void stack_remove(Stack *stack) {
    if (stack_empty(stack)) {
        printf("Vazia!");
    } else stack->top--;
}

void stack_print(Stack *stack) {
    int i = 0;
    Stack *aux = stack;

    for (; i < stack->top; i++)
        printf("Stack %d\n", stack->rows[i]);
}

Node* queue_createHead() {
    Node *head = (Node *) malloc(sizeof(Node));

    if (!head) {
        printf("%s %s\n", messages[0], messages[1]);
        exit(1);
    }

    head->id = -1;
    head->prox = NULL;

    return head;
}

void queue_createRandomNode(Node *head) {
    if (!head) {
        printf("%s %s\n", messages[0], messages[2]);
        exit(1);
    } else {
        Node
            *node = (Node *) malloc(sizeof(Node)),
            *aux = head;

        if (!node) {
            printf("%s %s\n", messages[0], messages[1]);
            exit(1);
        }

        while (aux->prox != NULL)
            aux = aux->prox;

        node->id = elemId++;
        node->count_sTime = -1;
        node->prox = NULL;
        aux->prox = node;
    }
}

void queue_addNewNode(Node *head, Node *node) {
    if (!head) {
        printf("%s %s\n", messages[0], messages[2]);
        exit(1);
    } else {
        Node *aux = head;

        if (!node) {
            printf("%s %s\n", messages[0], messages[1]);
            exit(1);
        }

        while (aux->prox != NULL)
            aux = aux->prox;

        node->prox = NULL;
        aux->prox = node;
    }
}

Node* queue_removeNode(Node *head) {
    if (!head->prox) {
        printf("%s %s\n", messages[0], messages[2]);
        exit(0);
    } else {
        Node *exclude = head->prox;
        head->prox = head->prox->prox;
        exclude->prox = NULL;

        return exclude;
    }
}

void queue_printList(Node *head) {
    Node *aux = head->prox;

    if (aux == NULL) {
        printf("%s\n", messages[2]);
        return;
    }

    while (aux != NULL) {
        printf("Client %d\n", aux->id);
        aux = aux->prox;
    }
}

float queue_length(Node *head) {
    float plus = 0;
    Node *aux = head->prox;

    while (aux) {
        plus++;
        aux = aux->prox;
    }

    return plus;
}

void checkServiceQueue(Node *head, Stack *p) {
    Node *aux = head->prox;

    while (aux) {
        //Client is moving to get plate
        if (aux->count_sTime == -1) {
            printf("Client %d is moving to get plate\n", aux->id);
            aux->count_sTime++;
            aux = aux->prox;
            continue;
        }

        //Client is geting plate
        if (aux->count_sTime == 0) {
            if (stack_empty(p)) {
                printf("Client %d can't get plate because the stack is empty!\n", aux->id);
            } else {
                printf("Removing one plate of the stack of Client %d\n", aux->id);
                stack_remove(p);
                aux->count_sTime++;
            }

            aux = aux->prox;
            continue;
        }

        //Client finished to service food
        if ((aux->count_sTime % FOOD_INTERVAL_TIME) == 0) {
            printf("The client %d was served!\n", aux->id);

            aux = aux->prox;

            //adding this client to clients_served queue
            queue_addNewNode(clients_served, queue_removeNode(head));

            continue;
        } else printf("The client %d is servicing at step %d!\n", aux->id, aux->count_sTime++);

        aux = aux->prox;
    }
}

void checkSystem(int cTime, Node **f1, Node **f2, Stack *p) {

    printf("\n\nTIME %d\n", cTime);

    int i = 0;

    //Adding 2 peoples to tab_queue
    printf("Adding %d new peoples to tab queue...\n", CLIENTS_PER_TIME);

    for(i = 0; i < CLIENTS_PER_TIME; i++) {
        queue_createRandomNode(f1[ind_tab_queue++ % AMOUNT_TAB_QUEUE]);
    }

    //If it's the time to service a new client
    if ((cTime % SERVICE_INTERVAL_TIME) == 0) {
        for (i = 0; i < AMOUNT_TAB_QUEUE; i++) {
            if (!f1[i]->prox)
                continue;

            Node *currentClient = queue_removeNode(f1[i]);

            printf("Attending the Client %d from queue %d and add him to service queue...\n", currentClient->id, i + 1);

            queue_addNewNode(f2[ind_service_queue++ % AMOUNT_SERVICE_QUEUE], currentClient);

        }
    }

    //Checking all service queues
    for (i = 0; i < AMOUNT_SERVICE_QUEUE; i++)
        checkServiceQueue(f2[i], p);


    if ((cTime % RESTITUTION_INTERVAL_SERVICE) == 0) {
        printf("Puting %d plates on stack", RESTITUTION_AMOUNT_FOOD);

        for(; i < RESTITUTION_AMOUNT_FOOD; i++) {
            if (!stack_full(p))
                stack_up(p);
        }
    }
}

int main() {

    Node **tab_queue = (Node **) malloc(sizeof(Node *));
    Node **service_queue =  (Node **) malloc(sizeof(Node *));
    Stack *plates_stack = stack_create();
    clients_served = queue_createHead();

    int
        i = 0,
        n = 2;

    for (i = 0; i < AMOUNT_TAB_QUEUE; i++)
        tab_queue[i] = queue_createHead();

    for (i = 0; i < AMOUNT_SERVICE_QUEUE; i++)
        service_queue[i] = queue_createHead();

    for (i = 1; i <= SYSTEM_INTERVAL_TIME; i++)
        checkSystem(i, tab_queue, service_queue, plates_stack);

    for (i = 0; i < AMOUNT_TAB_QUEUE; i++) {
        printf("\nTAB QUEUE %d\n\n", i + 1);
        queue_printList(tab_queue[i]);
    }

    for (i = 0; i < AMOUNT_SERVICE_QUEUE; i++) {
        printf("\nSERVICE QUEUE %d\n\n", i + 1);
        queue_printList(service_queue[i]);
    }

    printf("\nCLIENTS SERVED QUEUE\n\n");
    queue_printList(clients_served);

    printf("\n============= DATA ANALYSIS =============\n\n");

    for (i = 0; i < AMOUNT_TAB_QUEUE; i++)
        printf("\nTAB QUEUE %d LENGTH: %0.f\n", i + 1, queue_length(tab_queue[i]));

    for (i = 0; i < AMOUNT_SERVICE_QUEUE; i++)
        printf("\nSERVICE QUEUE %d LENGTH: %.0f\n", i + 1, queue_length(service_queue[i]));

    printf("\nCLIENTS SERVED QUEUE LENGTH: %.0f\n", queue_length(clients_served));
    printf("\n\nTIME TO ATTEND 1 CLIENT: %.1f minutes\n", (double) (1 / ((queue_length(clients_served) / SYSTEM_INTERVAL_TIME))));

    return 0;
}