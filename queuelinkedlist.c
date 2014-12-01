
// Queue implementation through Linked list 
// 1. Enqueues an element
// 2. Dequeues an element
// 3. Gets Size
// 4. Checks if queue is empty
// 5. Prints the queue

#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>

typedef struct node_type
{
	char data;
	struct node_type *next;
}	node;

typedef node *list; 
list temp, head, tail;

int main()
{
	int action_key = 0;
	do {
	    printf("\nEnter 1: Enqueue, 2: Dequeue, 3: Print, 4: Size, 5: Is Queue empty, 6: Exit \n");
		scanf("%d", &action_key);
		switch(action_key){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				prints_queue();
				break;
			case 4:
				find_size();
			    break;
			case 5:
				is_empty();
			    break;
			case 6:	
				break;
			default:
				break;
		}
	} while(action_key < 6);
	getch();
	return 0;
}

int enqueue()
{
	char c;
	list temp_element = NULL;
	printf("\nEnter a character\n");
    scanf(" %c", &c);
    if(tail == NULL)
	{
		tail = (list) malloc(sizeof(node));
		tail->next = NULL;
		tail->data = c;
		head = tail;
	}
	else
	{
		temp_element = (list) malloc(sizeof(node));
		tail->next = temp_element;
		temp_element->next = NULL;
		temp_element->data = c;
		tail = temp_element;
	}
	prints_queue();
	return 0;
}

int dequeue()
{
    list current_top = NULL;
	current_top = head;
	if(current_top->next != NULL){
		current_top = current_top->next;
		free(head);
		head = current_top;
	}
	else{
		free(head);
		head = NULL;
		tail = NULL;
	}		 
	prints_queue();	
	return 0;
}

int find_size()
{
	list iterator = NULL;
	int size = 0;
	iterator = head;
	while(iterator != NULL){
		iterator = iterator->next;
		size++;
	}
	printf("Queue size is: %d", size);
	return size;
}

int is_empty()
{
	if(head == tail){
		printf("\nThe queue is empty\n");
	}
	else
	{
		printf("\nThe queue is not empty\n");
	}
	return 0;
}

int prints_queue()
{
	list iterator = NULL;
    iterator = head;
    if (iterator == NULL)
    {
        printf("\nThe queue is empty\n");
        return 0;
    }
    printf("\nThe queue is: \n");
    while (iterator != NULL)
    {
        printf("%c \n", iterator->data);
        iterator = iterator->next;
    }    	
	return 0;
}
