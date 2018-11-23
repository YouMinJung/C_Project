#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct a_element
{
	int element;
	char word[10];
}a_element;

typedef struct circular_str
{
	char cir;
}circular_str;
circular_str cir[100]; // 회문 시 이용

typedef struct element
{
	int element;
	char word[10];
	struct element *next;
}element;

typedef struct circular_str2
{
	char cir;
	struct circular_str2 *next;
}circular_str2;

void stack();
void s_add();
void s_del();
void s_print();
a_element s[10];
int s_num=0;

void list();
void l_add();
void l_del();
void l_print();
element *top = NULL;

void time_c();
void circular();

void stack()
{
	int num;

	while(1)
	{
		printf("======== Menu =======\n");
		printf("1. Add\n");
		printf("2. Delete\n");
		printf("3. Print\n");
		printf("4. Go Main Page\n");
		printf("=====================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			s_add();
		}
		else if(num==2)
		{
			system("cls");
			s_del();
		}
		else if(num==3)
		{
			system("cls");
			s_print();
		}
		else
		{
			system("cls");
			main();
		}
	}
}

void s_add()
{
	printf("<< Push Stack >>\n\n");

	if(s_num == 10)
	{
		printf("Stack is full..Can't Push...Go Back Page\n\n");
		stack();
	}

	s_num++;
	printf("Number : ");
	scanf("%d", &s[s_num].element);
	printf("Word : ");
	scanf("%s", s[s_num].word);

	printf("\n** Complete **\n\n");
}

void s_del()
{
	printf("<< Pop Stack >>\n\n");

	if(s_num==0)
	{
		printf("Stack is empty.. Can't Pop... Go back page\n\n");
		stack();
	}
	s_num--;

	printf("** Complete **\n\n");
}

void s_print()
{
	int i;

	printf("<< Stack Print >>\n\n");

	for(i=s_num; i>0; i--)
	{
		printf(" %d, %s", s[i].element, s[i].word);

		if(i==s_num)
		{
			printf("  <<- Top");
		}
		printf("\n");
	}
	
	printf("\n** Complete **\n\n");
}

void list()
{
	int num;

	while(1)
	{
		printf("======== Menu =======\n");
		printf("1. Add\n");
		printf("2. Delete\n");
		printf("3. Print\n");
		printf("4. Go Main Page\n");
		printf("=====================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			l_add();
		}
		else if(num==2)
		{
			system("cls");
			l_del();
		}
		else if(num==3)
		{
			system("cls");
			l_print();
		}
		else
		{
			system("cls");
			main();
		}
	}
}

void l_add()
{
	element *new_node = (element*)malloc(sizeof(element));

	printf("<< Push Stack >>\n\n");

	printf("Number : ");
	scanf("%d", &new_node->element);
	printf("Word : ");
	scanf("%s", new_node->word);

	if(top == NULL)
	{
		new_node->next = NULL;
		top = new_node;
	}
	else
	{
		new_node->next = top;
		top = new_node;
	}

	printf("** Complete **\n\n");
}

void l_del()
{
	element *p = top;

	printf("<< Pop Stack >>\n\n");

	if(top == NULL)
	{
		printf("Stack is empty.. Can't Pop... Go back page\n\n");
		list();
	}

	top = p->next;
	free(p);

	printf("** Complete **\n\n");
}

void l_print()
{
	element *p = top;

	printf("<< Stack Print >>\n\n");

	while(p != NULL)
	{
		printf(" %d, %s", p->element, p->word);
		if(p == top)
		{
			printf("  <<- Top");
		}
		printf("\n");
		p = p->next;
	}
	printf("\n** Complete **\n\n");
}

void time_c()
{
	clock_t start, finish;
	double duration;
	int i;
	int j=1;

	printf("<< Array Stack & List Stack 's Time Circulate >>\n\n");
	
	printf("** Array Stack TIME **\n");
	start = clock();
	for(i=0; i<10000000; i++)
	{
		s[j].element = i; 
	}
	finish = clock();
	duration = (double)(finish-start);
	printf("=> %f second\n\n", duration);

	printf("** List Stack TIME **\n");
	start = clock();
	for(i=0; i<10000000; i++)
	{
		element * new_node = (element*)malloc(sizeof(element));
		element *p = top;

		new_node->element = i;
		top = new_node; 
		new_node->next = NULL;
		free(p);
	}
	finish = clock();
	duration = (double)(finish-start);
	printf("=> %f second\n\n", duration);

	printf("** Complete **\n\n");
}

void circular()
{
	circular_str2 *cir_top = NULL;
	circular_str2 *p;

	int num=0, space=0, count=0;
	char str[100], str2[100];
	int i, len;

	printf("<< Circular Sentence >>\n\n");

	fflush(stdin);
	printf("** Array Stack **\n");
	printf("Input Circular : ");
	scanf("%[^\n]s", str);
	len = strlen(str);

	for(i=0; i<len; i++)
	{
		if(str[i] == ' ' || str[i] == ',' || str[i] == '.')
		{
			space++;
			continue;
		}
		else
		{
			cir[i].cir = tolower(str[i]);
			num++;
		}
	}
	
	if(cir[num+space-1].cir == cir[0].cir)
	{
		printf("First : %c     Last : %c\n", cir[0].cir, cir[num+space-1].cir);
		printf("\n** It is Palindrome\n\n");
	}
	else
	{
		printf("First : %c     Last : %c\n", cir[0].cir, cir[num+space-1].cir);
		printf("\n** It isn't Palindrome\n\n");
	}

	fflush(stdin);
	num = 0;
	printf("\n** List Stack **\n");
	printf("Input Circular : ");
	scanf("%[^\n]s", str2);
	len = strlen(str2);

	for(i=0; i<len; i++)
	{
		if(str2[i] == ' ' || str2[i] == ',' || str2[i] == '.')
		{
			continue;
		}
		else
		{
			circular_str2 *new_node = (circular_str2*)malloc(sizeof(circular_str2));
			new_node->cir = tolower(str2[i]);

			num++;
			if(cir_top == NULL)
			{
				new_node->next = NULL;
				cir_top = new_node;
			}
			else
			{
				new_node->next = cir_top;
				cir_top = new_node;
			}
		}
	}

	p = cir_top;
	for(i=0; i <num-1; i++)
	{
		p = p->next;
	}
		
	if(p->cir == cir_top->cir)
	{
		printf("First : %c     Last : %c\n", p->cir, cir_top->cir);
		printf("\n** It is Palindrome\n\n");
	}
	else
	{
		printf("First : %c     Last : %c\n", p->cir, cir_top->cir);
		printf("\n** It isn't Palindrome\n\n");
	}
		
	printf("** Complete **\n\n");
}

int main(void)
{
	int num;

	while(1)
	{
		printf("======== Menu =======\n");
		printf("1. Array\n");
		printf("2. Linked List\n");
		printf("3. Time Comparison\n");
		printf("4. Circular Letter\n");
		printf("=====================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			stack();
		}
		else if(num==2)
		{
			system("cls");
			list();
		}
		else if(num==3)
		{
			system("cls");
			time_c();
		}
		else
		{
			system("cls");
			circular();
		}
	}
}