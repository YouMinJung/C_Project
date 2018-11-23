#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item
{
	int type;
	int weight;
}item; // 10개까지 저장

typedef struct element
{
	int type;
	int weight;
	struct element *next;
}element; // 5개까지 저장

typedef struct d_item
{
	 int type;
	 int weight;
	 struct d_item *prev;
     struct d_item *next;
}d_item; // 제한 개수 없음

typedef struct circle
{
	int item;
	struct circle *next;
}circle;

item i[10]; // 배열
void i_add();
void i_del();
void i_adjust();
void i_print();
void i_search();
int array_num =0; // 지금까지 저장된 배열의 길이

void linked_list(); // 단일 연결리스트
element *input_item(element *p);
element *search(element *p);
void add_item();
void del(element *p);
void del_form();
void print();
void adjust(element *p);
void adjust_item();
void Search();
element *head = NULL;
int all_weight = 0;

void d_linked_list(); // 이중 연결리스트
void init_list();
void d_add_item();
void d_adjust_item();
void d_del();
void d_print();
void d_Search();
d_item *Head, *Tail;
int item_num =0;

void circle_list();
circle *reverse(circle *p);
circle *point = NULL;

void array_list()
{
	int num;

	while(1)
	{
		printf("<< Array List >>\n\n");
		printf("=========== Menu ===========\n");
		printf("1. Add informaion\n");
		printf("2. Delete informaion\n");
		printf("3. Print all informaion\n");
		printf("4. Adjust information\n");
		printf("5. Search information\n");
		printf("6. Main Page\n");
		printf("============================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			i_add();
		}
		else if(num==2)
		{
			system("cls");
			i_del();
		}
		else if(num==3)
		{
			system("cls");
			i_print();
		}	
		else if(num==4)
		{
			system("cls");
			i_adjust();
		}
		else if(num==5)
		{
			system("cls");
			i_search();
		}
		else if(num==6)
		{
			system("cls");
			main();
		}
		else
		{
			printf("Wrong number\n\n");
		}
	}
}

void i_add()
{
	int num, w=0;
	int j, k, l;
	item tmp;

	printf("<< Add Item >>\n\n");

	for(num=0; num<array_num; num++)
	{
		w += i[num].weight;
		if(w >100)
		{
			printf("List is Full... Can't Add Item..\n");
			printf("Go back page..\n\n");
			array_list();
		}
	}
	printf("Type : ");
	scanf("%d", &i[array_num].type);
	printf("Weight : ");
	scanf("%d", &i[array_num].weight);

	if(w + i[array_num].weight >100)
	{
		printf("\nYour list weight is %dkg... \n", w);
		printf("if you add this item, your weight become %dkg...\n",w + i[array_num].weight);  
		printf("So List becomes Full... Can't Add this Item.. Go back page\n\n");
		array_list();
	}
	array_num++;

	for(j=0; j<array_num-1; j++ ) 
	{ 
		k = j; 
		for(l = j+1 ; l<array_num; l++) 
		{ 
			if(i[k].type > i[l].type || i[k].weight > i[l].weight)
			{
				k = l; 
            } 
			tmp = i[k]; 
			i[k] = i[j]; 
			i[j] = tmp; 
		}
	} 
}

void i_del()
{
	int type, num, sign;

	printf("<< Delete Item >>\n\n");
	if(array_num == 0)
	{
		printf("Array is empty... Can't Delete..\n");
		printf("Go back page... \n\n");
		array_list();
	}
	printf("Input type that you want to delete : ");
	scanf("%d", &type);

	for(num=0; num<array_num; num++)
	{
		if(type == i[num].type)
		{
			printf("Type : %d\n", i[num].type);
			printf("Weight : %dkg\n\n", i[num].weight);
			printf("Do you want to delete this item? (1.yes) : ");
			scanf("%d", &sign);

			if(sign==1)
			{
				for(num; num<array_num+1; num++)
				{
					i[num] = i[num+1];
				}
				array_num--;
				printf("** Complete **\n\n");
			}
			else 
			{
				printf("I got it..Go back page..\n\n");
			}
		}
	}
}

void i_adjust()
{
	int type, num, sign;

	printf("<< Adjust Item >>\n\n");
	if(array_num == 0)
	{
		printf("Array is empty... Can't Adjust..\n");
		printf("Go back page... \n\n");
		array_list();
	}

	printf("Input type that you want to adjust : ");
	scanf("%d", &type);

	for(num=0; num<array_num; num++)
	{
		if(type == i[num].type)
		{
			printf("Type : %d\n", i[num].type);
			printf("Weight : %dkg\n\n", i[num].weight);
			printf("Do you want to adjust this item? (1.yes) : ");
			scanf("%d", &sign);

			if(sign==1)
			{
				printf("Type : ");
				scanf("%d", &i[num].type);
				printf("Weight : ");
				scanf("%d", &i[num].weight);

				printf("** Complete **\n\n");
			}
			else
			{
				printf("I got it.. next item print bellow.. \n\n");
			}
		}
	}
	printf("No more item that type %d\n", type);
	printf("Go back page...\n\n");
}

void i_print()
{
	int num=0, weight=0;
	printf("<< Print All Item >>\n\n");

	for(num=0; num<array_num; num++)
	{
		printf("Type : %d\n", i[num].type);
		printf("Weight : %dkg\n\n", i[num].weight);
		weight += i[num].weight;
	}
	printf("All Weight : %dkg\n\n", weight);
}

void i_search()
{
	int num, type;

	printf("Input type that you want to find : ");
	scanf("%d", &type);

	for(num=0; num<array_num; num++)
	{
		if(i[num].type == type)
		{
			printf("Type : %d\n", i[num].type);
			printf("Weight : %dkg\n\n", i[num].weight);
		}
	}
	printf("** Complete **\n\n");
}

void linked_list()
{
	int num;

	while(1)
	{
		printf("<< Single Linked List >>\n\n");
		printf("=========== Menu ===========\n");
		printf("1. Add informaion\n");
		printf("2. Delete informaion\n");
		printf("3. Print all informaion\n");
		printf("4. Adjust information\n");
		printf("5. Search information\n");
		printf("6. Main Page\n");
		printf("============================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			add_item();
		}
		else if(num==2)
		{
			system("cls");
			del_form();
		}
		else if(num==3)
		{
			system("cls");
			print();
		}	
		else if(num==4)
		{
			system("cls");
			adjust_item();
		}
		else if(num==5)
		{
			system("cls");
			Search();
		}
		else if(num==6)
		{
			system("cls");
			main();
		}
		else
		{
			printf("Wrong number\n\n");
		}
	}
}

element *input_item(element *p)
{
	printf("Type : ");
	scanf("%d", &p->type);
	printf("Weight : ");
	scanf("%d", &p->weight);
	all_weight += p->weight;
}

element *search(element *p)
{
	int type;

	printf("Type : ");
	scanf("%d", &type);

	while(p != NULL)
	{
		if(type == p->type)
		{
			return p;
		}
		p = p->next;
	}
	printf("** No More Find that Item **\n");
	printf("Go Back Page...\n\n");
	linked_list();
}

void add_item()
{
	int num=0;
	element *n = head;
	element *p, *w;
	element *before, *w_before;
	element *new_node = (element*)malloc(sizeof(element));

	printf(" << ADD Item >>\n\n");
    input_item(new_node);

    if(head != NULL)
	{
		if(new_node->type <= head->type)
		{
			if(new_node->weight <= head->weight)
			{
				new_node->next = head;
				head = new_node;
			}
			else
			{
				p = head;

				while(p != NULL && new_node->type <= head->type && new_node->weight > p->weight)
				{
					before = p;
					p = p->next;
				}
				new_node->next = before->next;
				before->next = new_node;
			}
		}
		else
		{
			p = head;
			while(p != NULL && new_node->type > p->type)
			{
				before = p;
				p = p->next;
			}
			
			w = before->next;
			
			if(w == NULL || w->weight > new_node->weight)
			{
				new_node->next = before->next;
				before->next = new_node;
			}
			else if(w->weight == new_node->weight)
			{
				new_node->next = w->next;
				w->next = new_node;
			}
			else
			{
				if(w->weight < new_node->weight)
				{
					if(w->next == NULL)
					{
						w->next = new_node;
						new_node->next = NULL;
					}
					else
					{
						while(w->weight < new_node->weight)
						{
							w_before = w;
							w = w->next;

							if(w_before->next == NULL)
							{
								w_before->next = new_node;
								new_node->next = NULL;
								linked_list();
							}
						}
						new_node->next = w_before->next;
						w_before->next = new_node;
					}
				}
			}
		}
	}
	else
	{
		new_node->next = NULL;
		head = new_node;
	}
	printf("\n** Complete **\n\n");
}

void del(element *p)
{
	element* t1 = head;
	element* t2 = NULL;

	while (t1 != NULL)
	{
		if (t1 == p )
		{
			if(t2 != NULL)
			{
				t2->next = t1->next;
			}
			else
			{
				head = t1->next;
			}
			break;
		}
		t2 = t1;
		t1 = t1->next;
	}
	all_weight -= t1->weight;
	free(t1);
}

void del_form()
{
	int num;
	element *p = head;

	printf("<< Delete Item >>\n\n");
 	printf("input that you want to delete\n");
	while(1)
	{
		p = search(p);

		if(p==NULL)
		{
			printf("** Can't find that Item\n\n");
			system("pasue");
			break;
		}
		printf("\n<< find Item >>\n");
		printf("Type : %d\n", p->type);
		printf("Weight : %dkg\n", p->weight);
		printf("\nDo you want to delete? (1.Yes) : ");
		scanf("%d", &num);

		if(num==1)
		{
			del(p);
			printf("\n** Complete **\n\n");
			break;
		}
		else
		{
			printf("if you find same type but different weight input bellow...\n"); 
			p = p->next;
		}
	}
}

void adjust(element *p)
{
	if(p != NULL)
	{
		del(p);
		add_item();
	}
	else
	{
		printf("** We don't have that book\n\n");
	}
}
void adjust_item()
{
	int num;
	element *p = head;

	printf("<< Adjust Item >>\n\n");
	printf("input that you want to adjust\n");

	while(1)
	{
		p = search(p);

		if(p==NULL)
		{
			printf("** Can't find that Item\n\n");
			system("pasue");
			break;
		}
		printf("\n<< find Item >>\n");
		printf("Type : %d\n", p->type);
		printf("Weight : %dkg\n", p->weight);
		printf("\nDo you want to adjust? (1.Yes) : ");
		scanf("%d", &num);

		if(num==1)
		{
			adjust(p);
			break;
		}
		else
		{
			printf("if you find same type but different weight input bellow...\n"); 
			p = p->next;
		}
	}
}

void print()
{
	element *p = head;

	printf("<< Print All Item >>\n\n");
	printf("** All Weight : %dkg\n", all_weight);
	while(p != NULL)
	{
		printf("Type : %d\n", p->type);
		printf("Weight : %dkg\n", p->weight);
		printf("\n");
		p = p->next;
	}
	printf("** Complete **\n\n");
	system("pause");
}

void Search()
{
	element *p = head;
	int num;

	printf("<< Search Item >>\n\n");
	while(1)
	{
		printf("========= Menu ========\n");
		printf("1. Type\n");
		printf("2. Weight\n");
		printf("=======================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			printf("Input Type that you want to find : ");
			scanf("%d", &num);

			if(p==NULL)
			{
				printf("Nothing\n\n");
			}

			while(p != NULL)
			{
				if(p->type == num)
				{
					printf("Type : %d\n", p->type);
					printf("Weight : %dkg\n\n", p->weight);
				}
				p = p->next;
			}
			printf("\n** Complete **\n\n");
			break;
		}
		else if(num==2)
		{
			printf("Input Weight that you want to find : ");
			scanf("%d", &num);

			if(p==NULL)
			{
				printf("Nothing\n\n");
			}
			while(p != NULL)
			{
				if(p->weight == num)
				{
					printf("Type : %d\n", p->type);
					printf("Weight : %dkg\n\n", p->weight);
				}
				p = p->next;
			}
			printf("\n** Complete **\n\n");
			break;
		}
		else if(num==3)
		{
			linked_list();
		}
		else
		{
			printf("Wrong Input.....go back page\n\n");
			system("pause");
			linked_list();
		}
	}
}

void init_list()
{
	Head = (d_item*)malloc(sizeof(d_item));
	Tail = (d_item*)malloc(sizeof(d_item));
	Head->next = Tail;
	Head->prev = Tail;
	Tail->next = Head;
	Tail->prev = Head;
}

void d_add_item()
{
	d_item *p, *after;
	d_item *new_node = (d_item*)malloc(sizeof(d_item));

	printf("<< Add Item >>\n\n");
	printf("Type : ");
	scanf("%d", &new_node->type);
	printf("Weight : ");
	scanf("%d", &new_node->weight);
	
	if(Head->next == Tail && Tail->prev == Head)
	{
		Tail->prev->next = new_node;
		new_node->prev = Tail->prev;

		new_node->next = Tail;
		Tail->prev = new_node;
	}
	else
	{
		if(Head->next->weight < new_node->weight)
		{
			Tail->prev->next = new_node;
			new_node->prev = Tail->prev;

			new_node->next = Tail;
			Tail->prev = new_node;
		}
		else
		{
			p = Head;
			while(p != Tail && new_node->weight >= p->weight)
			{
				after = p;
				p = p->next;
			}
			new_node->next = after->next;
			new_node->prev = after->next->prev;

			after->next = new_node;
			after->next->prev = new_node;
		}
	}
	item_num++;
	printf("** Complete **\n\n");
}

void d_del()
{
	int num, sign;
	d_item *loof = Head->next;
	d_item *del;

	printf("<< Delete Item >>\n\n");
	printf("Input type that you want to delete : ");
	scanf("%d", &num);

	while(loof != Tail)
	{
		if(loof->type == num)
		{
			printf("Type : %d\n", loof->type);
			printf("Weight : %dkg\n\n", loof->weight);

			printf("Do you want to delete this item? (1. yes) : ");
			scanf("%d", &sign);

			if(sign == 1)
			{
				del = loof;
				del->prev->next = del->next;
				del->next->prev = del->prev;
				free(del);
				item_num--;
				break;
			}
			else
			{
				printf("Go back page...\n\n");
				break;
			}
		}
		loof = loof->next;
	}
}

void d_adjust_item()
{
	int type, sign;
	d_item *loof = Head->next;
	d_item *p, *after;
	d_item *new_node = (d_item*)malloc(sizeof(d_item));
    
	printf("<< Adjust Item >>\n\n");
	printf("input Type that you want to adjust : ");
	scanf("%d", &type);

	while(loof != Tail)
    {
		if(loof->type == type)
        {
			printf("Type : %d\n", loof->type);
			printf("Weight : %dkg\n\n", loof->weight);

			printf("Do you want to adjust this item? (1. yes) : ");
			scanf("%d", &sign);
			if(sign == 1)
			{
				loof->prev->next = loof->next;
				loof->next->prev = loof->prev;
				free(loof);
				
				printf("\nType : ");
				scanf("%d", &new_node->type);
				printf("Weight : ");
				scanf("%d", &new_node->weight);
	
				if(Head->next == Tail && Tail->prev == Head)
				{
					Tail->prev->next = new_node;
					new_node->prev = Tail->prev;

					new_node->next = Tail;
					Tail->prev = new_node;
				}
				else
				{
					if(Head->next->weight < new_node->weight)
					{
						Tail->prev->next = new_node;
						new_node->prev = Tail->prev;

						new_node->next = Tail;
						Tail->prev = new_node;
					}
					else
					{
						p = Head;
						while(p != Tail && new_node->weight >= p->weight)
						{
							after = p;
							p = p->next;
						}
						new_node->next = after->next;
						new_node->prev = after->next->prev;

						after->next = new_node;
						after->next->prev = new_node;
					}
				}
				break;
			}
			else
			{
				printf("Go back page...\\n\n");
				break;
			}
		}
		loof = loof->next;
	}
 }

void d_print()
{
	int num, i;
	int all=0;
	d_item *loof = Head->next;

	printf("<< Print All Item >>\n\n");
	while(loof != Tail)
    {
		printf("Type : %d\n", loof->type);
	    printf("Weight : %dkg\n\n", loof->weight);
		all += loof->weight;
	    loof = loof->next;
	}
	printf("** All Weight : %dkg **\n\n",all);

	printf("Do You want to print REVERSE? (1.yes) : ");
	scanf("%d", &num);

	if(num==1)
	{
		loof = Tail->prev;
		while(loof != Head)
		{
			printf("Type : %d\n", loof->type);
			printf("Weight : %dkg\n\n", loof->weight);
			loof = loof->prev;
		}
		printf("** All Weight : %dkg **\n\n",all);
	}
	printf("** Complete **\n\n");
}

 void d_Search()
 {
	 int type;
	 d_item *loof;
	 loof = Head->next;
	
	 printf("<< Search Item >>\n\n");
	 printf("Input type that you want to find : ");
	 scanf("%d", &type);

	 while(loof != Tail)
	 {
		 if(loof->type == type)
		 {
			 printf("Type : %d\n", loof->type);
			 printf("Weight : %dkg\n\n", loof->weight);
			 return;
		 }
		 loof = loof->next;
	 }
	 printf("Nothing\n\n");
 }

void d_linked_list()
{
	int num;

	init_list();
	while(1)
	{
		printf("<< Double Linked List >>\n\n");
		printf("=========== Menu ===========\n");
		printf("1. Add informaion\n");
		printf("2. Delete informaion\n");
		printf("3. Adjust information\n");
		printf("4. Print all informaion\n");
		printf("5. Search information\n");
		printf("6. Main Page\n");
		printf("============================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			d_add_item();
		}
		else if(num==2)
		{
			system("cls");
			d_del();
		}
		else if(num==3)
		{
			system("cls");
			d_adjust_item();
		}
		else if(num==4)
		{
			system("cls");
			d_print();
		}	
		else if(num==5)
		{
			system("cls");
			d_Search();
		}
		else if(num==6)
		{
			main();
		}
		else
		{
			printf("Wrong number\n\n");
		}
	}
}

circle *reverse()
{
	circle *p, *q, *r;

	p = point;
	q = NULL;

	while(p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	return q;
}

void circle_list()
{
	int r=0;
	int num, i, j;
	circle *p;

	printf("Input Number (10~20) : ");
	scanf("%d", &num);

	r =  rand()%(num*num);
	for(i=0; i<num; i++)
	{
		circle * new_node = (circle*)malloc(sizeof(circle));
		int random = rand()%(num*num);

		printf("%d\n", random);
		new_node->item = random;
		
		if(point == NULL)
		{
			new_node->next = new_node;
			point = new_node;
		}
		else
		{
			new_node->next = point->next->next;
			point->next->next = new_node;
		}
	}
	printf("\nInput List Success!!\n\n");

	printf("How many times turn? : ");
	scanf("%d", &num);

	p = point;
	for(i=0; i<num; i++)
	{
		p = p->next;
	}

	printf("\n** Do you want to Reverse Turn? (1.yes) : ");
	scanf("%d", &num);

	if(num==1)
	{
		p = reverse();
		printf("\nHow mant times do you want to turn? : ");
		scanf("%d", &num);

		for(i=0; i<num; i++)
		{
			p = p->next;
		}

		if(p->item == r)
		{
			printf("Item Number : <%d>\n", p->item);
			printf("Congratulation!! You obtain < Armer >\n\n");
		}
		else if(p->item == r%5+r)
		{
			printf("Item Number : <%d>\n", p->item);
			printf("Congratulation!! You obtain < MP Up >\n\n");
		}
		else if(p->item == r%7+r)
		{
			printf("Item Number : <%d>\n", p->item);
			printf("Congratulation!! You obtain < HP Up >\n\n");
		}
		else if(p->item == r%2+9)
		{
			printf("Item Number : <%d>\n", p->item);
			printf("Congratulation!! You obtain < Sword >\n\n");
		}
		else
		{
			printf("Item Number : <%d>\n", p->item);
			printf("I'm Sorry... You obtain < Nothing >\n\n");
		}
	}
	else
	{
		if(p->item == r)
		{
			printf("Item Number : <%d>\n", p->item);
			printf("Congratulation!! You obtain < Armer >\n\n");
		}
		else if(p->item == r%3+r)
		{
			printf("Item Number : <%d>\n", p->item);
			printf("Congratulation!! You obtain < MP Up >\n\n");
		}
		else if(p->item == r%7+10)
		{
			printf("Item Number : <%d>\n", p->item);
			printf("Congratulation!! You obtain < HP Up >\n\n");
		}
		else if(p->item == r%2+r)
		{
			printf("Item Number : <%d>\n", p->item);
			printf("Congratulation!! You obtain < Sword >\n\n");
		}
		else
		{
			printf("Item Number : <%d>\n", p->item);
			printf("I'm Sorry... You obtain < Nothing >\n\n");
		}
	}
}

int main()
{
	int num;

	while(1)
	{
		printf("=========== Menu ============\n");
		printf("1. Array List\n");
		printf("2. Single Linked List\n");
		printf("3. Double Linked List\n");
		printf("4. Circle List\n");
		printf("=============================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			array_list();
		}
		else if(num==2)
		{
			system("cls");
			linked_list();
		}
		else if(num==3)
		{
			system("cls");
			d_linked_list();
		}
		else if(num==4)
		{
			system("cls");
			circle_list();
		}
		else
		{
			printf("Wrong number....\n\n");
		}
	}
}