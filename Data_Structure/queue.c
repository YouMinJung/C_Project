#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct woman
{
	char name[10];
}woman;
woman w[5];

typedef struct man
{
	char name[10];
}man;
man m[5];

typedef struct circle_woman
{
	char name[10][10];
	int front;
	int rear;
}circle_woman;
circle_woman *qw;

typedef struct circle_man
{
	char name[10][10];
	int front;
	int rear;
}circle_man;
circle_man *qm;

typedef struct list_w
{
	char name[10];
	char man[10];
	struct list_w *next;
}list_w;
list_w *w_front = NULL;
list_w *w_rear = NULL;

typedef struct list_m
{
	char name[10];
	char woman[10];
	struct list_m *next;
}list_m;
list_m *m_front = NULL;
list_m *m_rear = NULL;

typedef struct list_result
{
	char name[10];
	char couple[10];
	struct list_result *next;
}list_result;
list_result *head = NULL;

typedef struct deque_woman
{
	char name[10];
	struct deque_woman *after;
	struct deque_woman *before;
}deque_woman;
deque_woman *W_Head = NULL;
deque_woman *W_Tail = NULL;

typedef struct deque_man
{
	char name[10];
	struct deque_man *after;
	struct deque_man *before;
}deque_man;
deque_man *M_Head = NULL;
deque_man *M_Tail = NULL;

void circle_queue();
circle_woman *init_w();
circle_man *init_m();
void c_push();
void c_print();
int cw_num=0;
int cm_num=0;

void list_queue();
void l_push();
void l_pop();
void l_print();
void find_woman(list_w *p, list_m *p2);
void find_man(list_m *p, list_w *p2);

void circle_queue2();
void a_push();
void a_print();
int a_woman_num=0;
int a_man_num=0;

void deque();
void d_push();
void d_pop();
void d_print();

int main()
{
	int num;

	while(1)
	{
		printf("======== Menu ========\n");
		printf("1. Circle Queue\n");
		printf("2. Circle Queue (Without front, rear)\n");
		printf("3. List Queue\n");
		printf("4. Deque \n");
		printf("======================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			circle_queue();
		}
		else if(num==2)
		{
			system("cls");
			circle_queue2();
		}
		else if(num==3)
		{
			system("cls");
			list_queue();
		}
		else
		{
			system("cls");
			deque();
		}
	}
}

void circle_queue()
{
	int num,i;

	qm = init_m();
	qw = init_w();
	while(1)
	{
		printf("<< Circle Queue >>\n\n");
		printf("======== Menu ========\n");
		printf("1. Enqueue\n");
		printf("2. Single Print\n");
		printf("3. Go Main Page\n");
		printf("======================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			c_push();
		}
		else if(num==2)
		{
			system("cls");
			c_print();
		}
		else
		{
			system("cls");
			main();
		}
	}
} 

circle_woman *init_w()
{
	circle_woman *queue = (circle_woman *) malloc (sizeof(circle_woman));

	queue->front=0;
	queue->rear=0;

	return queue;
}

circle_man *init_m()
{
	circle_man *queue = (circle_man *) malloc (sizeof(circle_man));

	queue->front=0;
	queue->rear=0;

	return queue;
}


void c_push()
{
	int num;

	printf("<< Circle Enqueue >>\n\n");
	printf("What's your Sex? (1. Woman  2.Man) : ");
	scanf("%d", &num);

	if(num==1)
	{
		if((qw->rear+1)%10 == (qw->front))
		{
			printf("Queue is FULL\n\n");
			circle_queue();
		}
		else
		{
			qw->rear = (qw->rear+1)%10;
			printf("What's your Name? : ");
			scanf("%s",qw->name[qw->rear]);
			cw_num++;

			printf("** Complete Add your Information **\n\n");

			if(cm_num >0)
			{
				printf("we have <%s> Man...\n", qm->name[(qm->front+1)%10]);
				printf("Congratulation!! You be Couple with <%s>.\n\n", qm->name[(qm->front+1)%10]);

				qw->front = (qw->front+1)%10;
				cw_num--;
				qm->front = (qm->front+1)%10;
				cm_num--;
			}
			else
			{
				printf("NOW You can't be Couple... Wait until Next Time\n\n");
			}
		}
	}
	else if(num==2)
	{
		if(qm->front == (qm->rear+1)%10)
		{
			printf("Queue is FULL\n\n");
			circle_queue();
		}
		else
		{
			qm->rear = (qm->rear+1)%10;
			printf("What's your Name? : ");
			scanf("%s",qm->name[qm->rear]);
			cm_num++;
		
			printf("** Complete Add your Information **\n\n");

			if(cw_num >0)
			{
				printf("we have <%s> Woman...\n", qw->name[(qw->front+1)%10]);
				printf("Congratulation!! You be Couple with <%s>.\n\n", qw->name[(qw->front+1)%10]);

				qw->front = (qw->front+1)%10;
				cw_num--;
				qm->front = (qm->front+1)%10;
				cm_num--;
			}
			else
			{
				printf("NOW You can't be Couple... Wait until Next Time\n\n");
			}
		}
	}
	else
	{
		printf("Wrong Input.. Go Back Page\n\n");
	}
}

void c_print()
{
	
	int i=0,num=0;

	printf("<< Circle Single Print >>\n\n");
	
	if(qw->front != qw->rear)
	{
		i = (qw->front+1)%10;
		while(i != (qw->rear+1)%10)
		{
			num++;
			printf("Ms.< %s > is Single\n", qw->name[i]);
			i = (i+1)%10;
		}
	}
	printf("\n");
	if(qm->front != qm->rear)
	{
		i = (qm->front+1)%10;
		while(i != (qm->rear+1)%10)
		{
			num++;
			printf("Mr.< %s > is Single\n", qm->name[i]);
			i = (i+1)%10;
		}
	}
	
	printf("\n** NOW We have %d Single **\n\n", num);
}

void list_queue()
{
	int num;

	while(1)
	{
		printf("<< List Queue >>\n\n");
		printf("======== Menu ========\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Print\n");
		printf("4. Go Main Page\n");
		printf("======================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			l_push();
		}
		else if(num==2)
		{
			system("cls");
			l_pop();
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

void l_push()
{
	int num;
	list_m *m_p = m_front, *before_m;
	list_w *w_p= w_front, *before_w;
	list_result *new_node2;

	printf("<< List Enqueue >>\n\n");
	printf("What's your Sex? (1. Woman  2.Man) : ");
	scanf("%d", &num);

	if(num==1)
	{
		list_w *new_node = (list_w*)malloc(sizeof(list_w));

		printf("What's your Name? : ");
		scanf("%s", new_node->name);

		if(w_front == NULL)
		{
			new_node->next = NULL;
			w_front = new_node;
			w_rear = new_node;
		}
		else 	
		{   
			w_p = w_front;
			while(w_p->next != NULL)
			{
				w_p = w_p->next;
			}
			new_node->next = NULL;
			w_p->next = new_node;
			w_rear = new_node;
        }

		printf("** Complete Add your Information **\n\n");

		m_p = m_front;
		if(m_front != NULL)
		{
			while(m_p != NULL)
			{
				printf("We have <%s> Man...\n", m_p->name);

				printf("Do you want to be couple with him? (1. yes) : ");
				scanf("%d", &num);
				if(num==1)
				{
					printf("\nCongratulation!! You be Couple with Mr.< %s >.\n\n", w_p->name);
					new_node2 = (list_result*)malloc(sizeof(list_result));
					strcpy(new_node2->couple, new_node->name);
					strcpy(new_node2->name, m_p->name);

					if(head == NULL)
					{
						head = new_node2;
						new_node->next = NULL;
					}
					else 
					{          
						new_node2->next = head;
						head = new_node2;
					}

					w_p = w_front;
					w_front = w_p->next;
					m_p = m_front;
					m_front = m_p->next;
					free(w_p);
					free(m_p);
					list_queue();
				}
				else
				{
					printf("I got it....\n");
					m_p = m_p->next;
					if(m_p == NULL)
					{	
						printf("We don't have Man Anymore...\n\n");
						list_queue();
					}
					else
					{
						find_man(m_p, new_node);
					}
				}
			}
		}
		printf("NOW You can't be Couple... Wait until Next Time\n\n");
	}
	else if(num==2)
	{
		list_m *new_node = (list_m*)malloc(sizeof(list_m));

		printf("What's your Name? : ");
		scanf("%s", new_node->name);
		
		if(m_front == NULL)
		{
			m_front = new_node;
			m_rear = new_node;
			new_node->next = NULL;
		}
        else 	
		{   
			m_p = m_front;
			while(m_p->next != NULL)
			{
				m_p = m_p->next;
			}
			new_node->next = NULL;
			m_p->next = new_node;
			m_rear = new_node;
        }
		
		printf("** Complete Add your Information **\n\n");

		w_p = w_front;
		if(w_front != NULL)
		{
			while(w_p != NULL)
			{
				printf("We have <%s> Woman...\n", w_p->name);

				printf("Do you want to be couple with her? (1. yes) : ");
				scanf("%d", &num);
				if(num==1)
				{
					printf("\nCongratulation!! You be Couple with <%s>.\n\n",w_p->name);
					new_node2 = (list_result*)malloc(sizeof(list_result));
					strcpy(new_node2->couple, new_node->name);
					strcpy(new_node2->name, w_p->name);

					if(head == NULL)
					{
						head = new_node2;
						new_node2->next = NULL;
					}
					else 
					{          
						new_node2->next = head;
						head = new_node2;
					}

					w_p = w_front;
					w_front = w_p->next;
					m_p = m_front;
					m_front = m_p->next;
					free(w_p);
					free(m_p);
					list_queue();
				}
				else
				{
					printf("I got it....\n");
					w_p = w_p->next;
					if(w_p == NULL)
					{	
						printf("We don't have Woman Anymore...\n\n");
						list_queue();
					}
					else
					{
						find_woman(w_p, new_node);
					}
				}
			}
		}
		printf("NOW You can't be Couple... Wait until Next Time\n\n");
	}
	else
	{
		printf("Wrong Input.. Go Back Page\n\n");
	}
}

void find_woman(list_w *w_p, list_m *new_node)
{
	int num;
	list_result *new_node2, *p;
	list_w *t1 = w_front;
	list_w *t2 = NULL;
	list_m *m1 = m_front;
	list_m *m2 = NULL;

	if(w_front != NULL)
	{
		while(w_p != NULL)
		{
			printf("\nWe have <%s> Woman...\n", w_p->name);

			printf("Do you want to be couple with her? (1. yes) : ");
			scanf("%d", &num);
			if(num==1)
			{
				printf("Congratulation!! You be Couple with <%s>.\n\n",w_p->name);

				new_node2 = (list_result*)malloc(sizeof(list_result));
				strcpy(new_node2->couple, new_node->name);
				strcpy(new_node2->name, w_p->name);

				if(head == NULL)
				{
					head = new_node2;
					new_node2->next = NULL;
				}
				else 
				{          
					new_node2->next = head;
					head = new_node2;
				}

				while (m1 != NULL)
				{
					if (m1 == new_node)
					{
						if(m2 != NULL)
						{
							m2->next = m1->next;
						}
						else
						{
							m_front = m1->next;
						}
						break;
					}
					m2 = m1;
					m1 = m1->next;
				}
				free(m1);

				while (t1 != NULL)
				{
					if (t1 == w_p)
					{
						if(t2 != NULL)
						{
							t2->next = t1->next;
						}
						else
						{
							w_front = t1->next;
						}
						break;
					}
					t2 = t1;
					t1 = t1->next;
				}
				free(t1);
				list_queue();
			}
			else
			{
				printf("I got it....\n");
				w_p = w_p->next;
				if(w_p == NULL)
				{
					printf("We don't have Woman Anymore...\n\n");
					list_queue();
				}
				else
				{
					find_woman(w_p, new_node);
				}
			}
		}
	}
	printf("NOW You can't be Couple... Wait until Next Time\n\n");
}

void find_man(list_m *m_p, list_w *new_node)
{
	int num;
	list_result *new_node2, *p;
	list_w *t1 = w_front;
	list_w *t2 = NULL;
	list_m *m1 = m_front;
	list_m *m2 = NULL;

	if(m_front != NULL)
	{
		while(m_p != NULL)
		{
			printf("\nWe have <%s> Man...\n", m_p->name);

			printf("Do you want to be couple with him? (1. yes) : ");
			scanf("%d", &num);
			if(num==1)
			{
				printf("Congratulation!! You be Couple with <%s>.\n\n",m_p->name);

				new_node2 = (list_result*)malloc(sizeof(list_result));
				strcpy(new_node2->couple, new_node->name);
				strcpy(new_node2->name, m_p->name);

				if(head == NULL)
				{
					head = new_node2;
					new_node2->next = NULL;
				}
				else 
				{          
					new_node2->next = head;
					head = new_node2;
				}

				while (m1 != NULL)
				{
					if (m1 == m_p)
					{
						if(m2 != NULL)
						{
							m2->next = m1->next;
						}
						else
						{
							m_front = m1->next;
						}
						break;
					}
					m2 = m1;
					m1 = m1->next;
				}
				free(m1);

				while (t1 != NULL)
				{
					if (t1 == new_node)
					{
						if(t2 != NULL)
						{
							t2->next = t1->next;
						}
						else
						{
							w_front = t1->next;
						}
						break;
					}
					t2 = t1;
					t1 = t1->next;
				}
				free(t1);
				list_queue();
			}
			else
			{
				printf("I got it....\n");
				m_p = m_p->next;
				if(m_p == NULL)
				{
					printf("We don't have Man Anymore...\n\n");
					list_queue();
				}
				else
				{
					find_man(m_p, new_node);
				}
			}
		}
	}
	printf("NOW You can't be Couple... Wait until Next Time\n\n");
}

void l_pop()
{
	int num;
	char name[10];
	list_w *w_p = w_front;
	list_m *m_p = m_front;

	printf("<< List Dequeue >>\n\n");

	printf("Input Name : ");
	scanf("%s", name);

	printf("What's your Sex? (1. Woman  2. Man) : ");
	scanf("%d", &num);

	if(num==1)
	{
		while(w_p != NULL)
		{
			if(strcmp(w_p->name , name)==0)
			{
				printf("** Find... Ms.< %s > **\n", w_p->name);
				printf("Do you want to delete this Member? (1. yes) : ");
				scanf("%d", &num);
				if(num==1)
				{
					list_w *t1 = w_front;
					list_w *t2 = NULL;

					while (t1 != NULL)
					{
						if (t1 == w_p)
						{
							if(t2 != NULL)
							{
								t2->next = t1->next;
							}
							else
							{
								w_front = t1->next;
							}
							break;
						}
						t2 = t1;
						t1 = t1->next;
					}
					free(t1);
					printf("** Complete **\n\n");
					list_queue();
				}
				else
				{
					printf("I got it... Go Back Page\n\n");
					list_queue();
				}
			}
			w_p = w_p->next;
		}
	}
	else if(num==2)
	{
		while(m_p != NULL)
		{
			if(strcmp(m_p->name , name)==0)
			{
				printf("** Find... Mr.< %s > **\n", m_p->name);
				printf("Do you want to delete this Member? (1. yes) : ");
				scanf("%d", &num);
				if(num==1)
				{
					list_m *t1 = m_front;
					list_m *t2 = NULL;

					while (t1 != NULL)
					{
						if (t1 == m_p)
						{
							if(t2 != NULL)
							{
								t2->next = t1->next;
							}
							else
							{
								m_front = t1->next;
							}
							break;
						}
						t2 = t1;
						t1 = t1->next;
					}
					free(t1);
					printf("** Complete **\n\n");
					list_queue();
				}
				else
				{
					printf("I got it... Go Back Page\n\n");
					list_queue();
				}
			}
			m_p = m_p->next;
		}
	}
	else
	{
		printf("Worng Input...Go Back Page\n\n");
	}
}

void l_print()
{
	int num=0, num2=0;
	list_result *p = head;
	list_w *w_p = w_front;
	list_m *m_p = m_front;

	printf("<< List Print >>\n\n");
	while(p != NULL)
	{
		printf("< %s> AND < %s > is Couple\n", p->name, p->couple);
		num++;
		p = p->next;
	}
	printf("\n");
	while(w_p != NULL)
	{
		printf("Woman < %s > is Single...\n", w_p->name);
		num2++;
		w_p = w_p->next;
	}
	printf("\n");
	while(m_p != NULL)
	{
		printf("Man < %s > is Single...\n", m_p->name);
		num2++;
		m_p = m_p->next;
	}
	printf("\n** NOW %d Couple AND %d Single exist... **\n\n", num, num2);
}

void circle_queue2()
{
	int num;

	while(1)
	{
		printf("<< Circle2 Queue >>\n\n");
		printf("======== Menu ========\n");
		printf("1. Enqueue\n");
		printf("2. Single Print\n");
		printf("3. Go Main Page\n");
		printf("======================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			a_push();
		}
		else if(num==2)
		{
			system("cls");
			a_print();
		}
		else
		{
			system("cls");
			main();
		}
	}
}

void a_push()
{
	int num,i,j;

	printf("<< Circle2 Enqueue >>\n\n");
	printf("What's your Sex? (1. Woman  2.Man) : ");
	scanf("%d", &num);

	if(num==1)
	{
		if(a_woman_num >10)
		{
			printf("Can't Add More Person.. Go back Page");
			 circle_queue2();
		}
		printf("What's your Name? : ");
		scanf("%s", w[a_woman_num].name);
		a_woman_num++;

		printf("** Complete Add your Information **\n\n");
		if(a_man_num >0)
		{
			for(i=0; i<a_man_num; i++)
			{
				printf("we have <%s> Man...\n", m[i].name);
				printf("Congratulation!! You be Couple with <%s>.\n\n",m[i].name);
				
				for(i; i<a_man_num; i++)
				{
					strcpy(m[i].name, m[i+1].name);
				}
				for(i; i<a_woman_num; i++)
				{
					strcpy(w[i].name, w[i+1].name);
				}
				a_woman_num--;
				a_man_num--;
				circle_queue2();
			}
		}
		printf("NOW You can't be Couple... Wait until Next Time\n\n");
	}
	else if(num==2)
	{
		if(a_man_num >10)
		{
			printf("Can't Add More Person.. Go back Page");
			circle_queue2();
		}
		printf("What's your Name? : ");
		scanf("%s", m[a_man_num].name);
		a_man_num++;

		printf("** Complete Add your Information **\n\n");
		if(a_woman_num >0)
		{
			for(i=0; i<a_woman_num; i++)
			{
				printf("we have <%s> Woman...\n", w[i].name);
				printf("Congratulation!! You be Couple with <%s>.\n\n",w[i].name);
				
				for(i; i<a_woman_num; i++)
				{
					strcpy(w[i].name, w[i+1].name);
				}
				for(i; i<a_man_num; i++)
				{
					strcpy(m[i].name, m[i+1].name);
				}
				a_woman_num--;
				a_man_num--;
				circle_queue2();		
			}
		}
		printf("NOW You can't be Couple... Wait until Next Time\n\n");
	}
	else
	{
		printf("Wrong Input.. Go Back Page\n\n");
	}
}

void a_print()
{
	int i, num=0;

	printf("<< Circle Queue2 Single Print >>\n\n");

	for(i=0; i<a_woman_num; i++)
	{
		num++;
		printf("Ms.<%s> is Single...\n", w[i].name);
	}
	printf("\n");
	for(i=0; i<a_man_num; i++)
	{
		num++;
		printf("Mr.<%s> is Single...\n", m[i].name);
	}
	printf("\n**NOW We have %d Single** \n\n",num);
}

void deque()
{
	int num;

	W_Head = (deque_woman*)malloc(sizeof(deque_woman));
	W_Tail = (deque_woman*)malloc(sizeof(deque_woman));
	M_Head = (deque_man*)malloc(sizeof(deque_man));
	M_Tail = (deque_man*)malloc(sizeof(deque_man));

	W_Head->after = W_Tail;
	W_Head->before = W_Tail;
	W_Tail->after = W_Head;
	W_Tail->before = W_Head;

	M_Head->after = M_Tail;
	M_Head->before = M_Tail;
	M_Tail->after = M_Head;
	M_Tail->before = M_Head;

	while(1)
	{
		printf("<< Deque >>\n\n");
		printf("======== Menu ========\n");
		printf("1. Enqueue\n");
		printf("2. Print Single\n");
		printf("3. Go Main Page\n");
		printf("======================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			d_push();
		}
		else if(num==2)
		{
			system("cls");
			d_print();
		}
		else
		{
			system("cls");
			main();
		}
	}
}

void d_push()
{
	int num;
	deque_woman *del_w;
	deque_man *del_m;

	printf("<< Deque Enqueue >>\n\n");
	printf("What's your Sex? (1. Woman  2.Man) : ");
	scanf("%d", &num);

	if(num==1)
	{
		deque_woman *new_node = (deque_woman*)malloc(sizeof(deque_woman));

		printf("What's your Name? : ");
		scanf("%s", new_node->name);

		if(W_Head->after == W_Tail)
		{
			W_Tail->before->after = new_node;
			new_node->before = W_Tail->before;

			W_Tail->before = new_node;
			new_node->after = W_Tail;
			
			printf("\n** Complete Add your Information **\n");

			if(M_Head->after != M_Tail)
			{
				printf("We have < %s > Man...\n", M_Head->after->name);
				printf("Congratulation!! You be Couple with Mr.< %s >.\n\n", M_Head->after->name);

				del_w = new_node;;
				del_m = M_Head->after;

				del_w->before->after = del_w->after;
				del_w->after->before = del_w->before;
				del_m->before->after = del_m->after;
				del_m->after->before = del_m->before;

				free(del_w);
				free(del_m);
			}
			printf("Wait until Next Time..\n\n");
		}
		else
		{
			printf("Do you want to be Couple Right Now? (1.yes) : ");
			scanf("%d", &num);
			if(num==1)
			{
				W_Head->after->before = new_node;
				new_node->after = W_Head->after;

				W_Head->after = new_node;
				new_node->before = W_Head;

				printf("\n** Complete Add your Information **\n\n");

				if(M_Head->after != M_Tail)
				{
					printf("We have < %s > Man...\n", M_Head->after->name);
					printf("Congratulation!! You be Couple with Mr.< %s >.\n\n", M_Head->after->name);

					del_w = new_node;;
					del_m = M_Head->after;

					del_w->before->after = del_w->after;
					del_w->after->before = del_w->before;
					del_m->before->after = del_m->after;
					del_m->after->before = del_m->before;

					free(del_w);
					free(del_m);
				}
				printf("Wait until Next Time..\n\n");
			}
			else
			{
				W_Tail->before->after = new_node;
				new_node->before = W_Tail->before;

				W_Tail->before = new_node;
				new_node->after = W_Tail;
			
				printf("\n** Complete Add your Information **\n");
				printf("Wait until Next Time..\n\n");
			}
		}
	}
	else if(num==2)
	{
		deque_man *new_node = (deque_man*)malloc(sizeof(deque_man));

		printf("What's your Name? : ");
		scanf("%s", new_node->name);

		if(M_Head->after == M_Tail)
		{
			M_Tail->before->after = new_node;
			new_node->before = M_Tail->before;

			new_node->after = M_Tail;
			M_Tail->before = new_node;

			printf("\n** Complete Add your Information **\n");
			if(W_Head->after != W_Tail)
			{
				printf("We have < %s > Woman...\n", W_Head->after->name);
				printf("Congratulation!! You be Couple with Ms.< %s >.\n\n", W_Head->after->name);

				del_w = W_Head->after;
				del_m = new_node;

				del_w->before->after = del_w->after;
				del_w->after->before = del_w->before;
				del_m->before->after = del_m->after;
				del_m->after->before = del_m->before;

				free(del_w);
				free(del_m);
			}
			printf("Wait until Next Time..\n\n");
		}
		else
		{
			printf("Do you want to be Couple Right Now? (1.yes) : ");
			scanf("%d", &num);
			if(num==1)
			{
				M_Head->after->before = new_node;
				new_node->after = M_Head->after;

				M_Head->after = new_node;
				new_node->before = M_Head;

				printf("\n** Complete Add your Information **\n\n");

				if(W_Head->after != W_Tail)
				{
					printf("We have < %s > Woman...\n", W_Head->after->name);
					printf("Congratulation!! You be Couple with Ms.< %s >.\n\n", W_Head->after->name);

					del_w = W_Head->after;
					del_m = new_node;

					del_w->before->after = del_w->after;
					del_w->after->before = del_w->before;
					del_m->before->after = del_m->after;
					del_m->after->before = del_m->before;

					free(del_w);
					free(del_m);
				}
				printf("Wait until Next Time..\n\n");
			}
			else
			{
				new_node->before = M_Tail->before;
				new_node->after = M_Tail->before->after;
					
				M_Tail->before = new_node;
				M_Tail->before->after = new_node;

				printf("** Complete Add your Information **\n");
				printf("Wait until Next Time..\n\n");
			}
		}
	}
	else
	{
		printf("Wrong Input.. Go Back Page\n\n");
	}
}

void d_print()
{
	int num=0;
	deque_woman *wp = W_Head->after;
	deque_man *mp = M_Head->after;

	printf("<< Deque Single Print >>\n\n");

	while(wp != W_Tail)
	{
		num++;
		printf("Ms.< %s > is Single\n", wp->name);
		wp = wp->after;
	}
	printf("\n");
	while(mp != M_Tail)
	{
		num++;
		printf("Mr.< %s > is Single\n", mp->name);
		mp = mp->after;
	}
	printf("\n** NOW We have %d Single **\n\n", num);
}
