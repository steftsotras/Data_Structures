//Tsotras Stefanos icsd13189
#include <stdio.h>
#include <stdlib.h>


struct data
{
	double num;
	struct data *next;
};

struct data* head;
struct data* array[10];


void insert(double dt);
struct data* createNode();
void print();


int main(){


}


//DHMIOURGIA KOMVOU
struct data* createNode()
{
	struct data* tmp;
	tmp = (struct data*) malloc(sizeof(struct data));
	tmp->next = NULL;
	return tmp;

}

//EISAGWGH STOIXEIWN
void insert(char *nam,char *pas)
{
	struct data* head;
	struct data* newnode;
	int tmp;
	tmp = (int) dt;
	if (array[tmp] == NULL)
	{
		head = createNode();
		head->num = dt;
		array[tmp] = head;
	}
	else if(array[tmp]->next  == NULL)
	{
		newnode = createNode();
		array[tmp]->next = newnode;
		newnode->num = dt;
	}
	else
	{
		struct data* node;
		node = array[tmp];
		while (node->next != NULL)
		{
			node = node->next;
		}
		newnode = createNode();
		newnode->name = nam;
		newnode->pass = pas;
		node->next = newnode;
	}
}


//EMFANISH ANA THESH STON PINAKA
void print()
{
	int i;
	struct data* tempnode ;
	struct data* nextnode;
	for (i = 0; i < 10; i++)
	{
		nextnode = (struct data*) malloc(sizeof(struct data));
		printf("\nfor %d:\n", i);
		tempnode = array[i];
		nextnode = array[i]->next;
		while (tempnode != NULL)
		{

			printf("%s\n", tempnode->name);
			printf("%s\n", tempnode->pass);
			nextnode = tempnode->next;
			tempnode = nextnode;

		}
	}
}

