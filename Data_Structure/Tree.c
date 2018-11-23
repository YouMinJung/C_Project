#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct ex
{
	int data;
	struct ex *right;
	struct ex *left;
}ex;
ex *root_ex = NULL;

typedef struct Tree
{
	int data;
	struct Tree *right;
	struct Tree *left;
}Tree;
Tree *t = NULL;

typedef struct student
{
	int ID;
	char major[10];
	char name[10];
	char address[10];
	struct student *right;
	struct student *left;
}student;
student *root = NULL;
int s_id = 160000;
int s_num=0;

void number1();
void add();

void number2();
void add_node();
void del_node();
void search_node();
void preorder(Tree *p);
void inorder(Tree *p);
void postorder(Tree *p);
int height(Tree *p);
int node_num(Tree *p);
int terminal_num(Tree *p);
void max_min();
void del_all(Tree *p);

void number3();
void add_student();
void del_student();
void search_student();
void s_name(student *p, char name[10]);
void s_major(student *p, char major[10]);
void s_address(student *p, char address[10]);
void print_student(student *p);
int total_num(student *p);
void del_all_student(student *p);

int main(void)
{
	int num;

	while(1)
	{
		printf("====== Menu ======\n");
		printf("1. Number1\n");
		printf("2. Number2\n");
		printf("3. Number3\n");
		printf("==================\n");
		printf("Choose : ");
		scanf("%d", &num);
		
		if(num==1)
		{
			system("cls");
			number1();
		}
		else if(num==2)
		{
			system("cls");
			number2();
		}
		else
		{
			system("cls");
			number3();
		}
	}
}

void number1()
{
	int list[10000];
	int i, num;
	ex *p;
	time_t start=0, finish=0;
	time_t s_t=0, f_t=0;

	printf("1 ~ 10000 Number\n\n");
	printf("Input Num : ");
	scanf("%d", &num);

	start = clock();
	for(i=0; i<10000; i++)
	{
		list[i] = rand()+1;
	}
	for(i=0; i<10000; i++)
	{
		printf("Array : %d\n", list[i]);
		if(list[i]==num)
		{
			printf("* Find * %d\n\n", num);
			break;
		}
	}
	finish = clock();

	s_t = clock();
	for(i=0; i<10000; i++)
	{
		add();
	}

	p = root_ex;
	while(p != NULL)
	{
		printf("Tree : %d\n", p->data);
		if(num == p->data)
		{
			printf("\n **Find** %d\n\n", p->data);
			break;
		}
		else if(num < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	f_t = clock();

	printf("Array Result : %d\n", finish - start);
	printf("Tree Result : %d\n\n", f_t - s_t);
}

void add()
{
	int gap=0;
	ex *p = root_ex;
	ex *new_node=NULL;

	new_node = (ex*)malloc(sizeof(ex)); 
	new_node->data = rand()+1;

	new_node->left = NULL;
	new_node->right = NULL;

	if(root_ex == NULL)
	{
		root_ex = new_node;
	}
	else
	{
		while(1)
		{
			gap = p->data - new_node->data;
			if(gap>0)
			{
				if (p->left)
				{
					p = p->left;
				}
				else
				{
					p->left = new_node;
					break;
				}
			}
			else
			{
				if (p->right)
				{
					p = p->right;
				}
				else
				{
					p->right = new_node;
					break;
				}
			}	
		}
	}
}

void number2()
{
	int num;

	while(1)
	{
		int c=0;

		printf("============== Menu ===========\n");
		printf("1. Add Node\n");
		printf("2. Delete Node\n");
		printf("3. Search Node\n");
		printf("4. Traversal Node\n");
		printf("5. Height of Node\n");
		printf("6. The Number of Node\n");
		printf("7. The Number of Terminal Node\n");
		printf("8. Maximum / Minimum Value\n");
		printf("9. Delete All Nodes\n");
		printf("10. Go Back Main Page\n");
		printf("===============================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			add_node();
		}
		else if(num==2)
		{
			system("cls");
			del_node();
		}
		else if(num==3)
		{
			system("cls");
			search_node();
		}
		else if(num==4)
		{
			system("cls");
			printf("====== Menu ======\n");
			printf("1. Preorder Traversal\n");
			printf("2. Inorder Traversal\n");
			printf("3. Postorder Traversal\n");
			printf("==================\n");
			printf("Choose : ");
			scanf("%d", &num);

			if(num==1)
			{
				system("cls");
				preorder(t);
			}
			else if(num==2)
			{
				system("cls");
				inorder(t);
			}
			else
			{
				system("cls");
				postorder(t);
			}
		}
		else if(num==5)
		{
			system("cls");
			c = height(t);
			printf("The Height of Tree is %d\n\n", c);
		}
		else if(num==6)
		{
			system("cls");
			c = node_num(t);
			printf("The Number of Nodes is %d\n\n", c);
		}
		else if(num==7)
		{
			system("cls");
			c = terminal_num(t);
			printf("The Number of Terminal Nudes is %d\n\n", c);
		}
		else if(num==8)
		{
			system("cls");
			max_min();
		}
		else if(num==9)
		{
			system("cls");
			del_all(t);
			t=NULL;
			printf("** Complete Delete All Nodes **\n\n");
		}
		else
		{
			system("cls");
			main();
		}
	}
}

void add_node()
{
	int gap=0;
	Tree *p = t;
	Tree *new_node = (Tree*)malloc(sizeof(Tree)); 

	printf("<< Add Node >>\n\n");
	printf("Input Number: ");
	scanf("%d", &new_node->data);

	new_node->left = NULL;
	new_node->right = NULL;

	if(t == NULL)
	{
		t = new_node;
	}
	else
	{
		while(1)
		{
			gap = p->data - new_node->data;
			if (gap == 0)
			{
				printf("\nAlready Exist...\n\n");
				break;
			}
			if (gap>0)
			{
				if (p->left)
				{
					p = p->left;
				}
				else
				{
					p->left = new_node;
					break;
				}
			}
			else
			{
				if (p->right)
				{
					p = p->right;
				}
				else
				{
					p->right = new_node;
					break;
				}
			}	
		}
	}
	printf("\n** Complete **\n\n");
}

void del_node()
{
	int num;
	Tree *p = t;
	Tree *node = NULL; // 부모노드
	Tree *child = NULL; // 자식노드
	Tree *s, *s_p;

	printf("<< Search Node >>\n\n");
	printf("Input Number : ");
	scanf("%d", &num);

	while(p != NULL && p->data != num)
	{
		node = p;
		if(num == p->data)
		{
			printf("\n **Find** Data Number : %d\n\n", p->data);
			break;
		}
		else if(num < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}

	printf("\nData Number : %d\n\n", p->data);
	printf("Do you want to Delete this node? (1. yes) : ");
	scanf("%d", &num);

	if(num==1)
	{
		if(p->left==NULL && p->right==NULL)
		{
			if(node != NULL)
			{
				if(node->left == p)
				{
					node->left = NULL;
				}
				else
				{
					node->right = NULL;
				}
			}
			else
			{
				t = NULL;
			}
		}
		else if(p->left==NULL || p->right==NULL)
		{
			child = (p->left != NULL) ? p->left : p->right;

			if(node != NULL)
			{
				if(node->left == p)
				{
					node->left = child;
				}
				else
				{
					node->right = child;
				}
			}
			else
			{
				t = child;
			}
		}
		else
		{
			s_p = p;
			s = p->right;

			while(s->left != NULL)
			{
				s_p = s;
				s = s->left;
			}
			
			if(s_p->left == s)
			{
				s_p->left = s->right;
			}
			else
			{
				s_p->right = s->right;
			}
			p->data = s->data;
			p = s;
		}
		free(p);
		printf("\n** Complete **\n\n");
	}
	else
	{
		printf("I got it.. Go Back Page\n\n");
		number2();
	}
}

void search_node()
{
	int num;
	Tree *p = t;

	printf("<< Search Node >>\n\n");
	printf("Input Number : ");
	scanf("%d", &num);

	while(p != NULL)
	{
		if(num == p->data)
		{
			printf("\n **Find** Data Number : %d\n\n", p->data);
			number2();
		}
		else if(num < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	printf("\n** No Data **\n\n");
}

void preorder(Tree *p)
{
	if(p)
	{
		printf("Data : %d\n", p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(Tree *p)
{
	if(p)
	{
		inorder(p->left);
		printf("Data : %d\n", p->data);
		inorder(p->right);
	}
}

void postorder(Tree *p)
{
	if(p)
	{
		postorder(p->left);
		postorder(p->right);
		printf("Data : %d\n", p->data);
	}
}

int height(Tree *p)
{
	int num1=0;
	int num2=0;

	if(p != NULL)
	{
		num1 = 1+height(p->left);
		num2 = 1+height(p->right);
	}

	if(num1 > num2)
	{
		return num1;
	}
	else 
	{
		return num2;
	}
}

int node_num(Tree *p)
{
	int count=0;

	if(p != NULL)
	{
		count = 1 + node_num(p->left) + node_num(p->right);
	}
	return count;
	
}

int terminal_num(Tree *p)
{
	int count = 0;
		
	if(p != NULL)
	{
		if(p->left==NULL && p->right==NULL)
		{
			return 1;
		}
		else
		{
			count = terminal_num(p->left) + terminal_num(p->right);
		}
	}
	return count;
}

void max_min()
{
	Tree *p = t;

	while(p->right != NULL)
	{
		p = p->right;
	}
	printf("Max : %d\n", p->data);

	p = t;
	while(p->left != NULL)
	{
		p = p->left;
	}
	printf("Min : %d\n\n", p->data);
}

void del_all(Tree *p)
{
	if(p)
    {
        del_all(p->left);
        del_all(p->right);
        free(p);
    }
}

void number3()
{
	int num;

	while(1)
	{
		printf("=============== Menu ============\n");
		printf("1. Add information of Student\n");
		printf("2. Delete information of Student\n");
		printf("3. Search information of Student\n");
		printf("4. Print with ID Number of Student\n");
		printf("5. Total Number of Students\n");
		printf("6. Delete All informations\n");
		printf("7. Go Back Main Page\n");
		printf("=================================\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			system("cls");
			add_student();
		}
		else if(num==2)
		{
			system("cls");
			del_student();
		}
		else if(num==3)
		{
			system("cls");
			search_student();
		}
		else if(num==4)
		{
			system("cls");
			print_student(root);
		}
		else if(num==5)
		{
			system("cls");
			num = total_num(root);
			printf("Total %d Students Exist...\n\n", num);
		}
		else if(num==6)
		{
			system("cls");
			del_all_student(root);
		}
		else
		{
			system("cls");
			main();
		}
	}
}

void add_student()
{
	int gap=0;
	student *p = root;
	student *new_node = (student*)malloc(sizeof(student)); 

	printf("<< Add Node >>\n\n");
	printf("Input Name : ");
	scanf("%s", new_node->name);
	printf("Input Address : ");
	scanf("%s", new_node->address);
	printf("Input Major : ");
	scanf("%s", new_node->major);

	s_id++;
	s_num++;

	if(strcmp(new_node->major, "computer")==0)
	{
		new_node->ID = s_id + 1100;
	}
	else if(strcmp(new_node->major, "math")==0)
	{
		new_node->ID = s_id + 2200;
	}
	else if(strcmp(new_node->major, "science")==0)
	{
		new_node->ID = s_id + 3300;
	}
	else if(strcmp(new_node->major, "robot")==0)
	{
		new_node->ID = s_id + 4400;
	}
	else if(strcmp(new_node->major, "korean")==0)
	{
		new_node->ID = s_id + 5000;
	}
	else if(strcmp(new_node->major, "english")==0)
	{
		new_node->ID = s_id + 6000;
	}
	else
	{
		new_node->ID = s_id + 9900;
	}

	new_node->left = NULL;
	new_node->right = NULL;

	if(root == NULL)
	{
		root = new_node;
	}
	else
	{
		while(1)
		{
			gap = p->ID - new_node->ID;
			if (gap == 0)
			{
				printf("\nAlready Exist...\n\n");
				break;
			}
			if (gap>0)
			{
				if (p->left)
				{
					p = p->left;
				}
				else
				{
					p->left = new_node;
					break;
				}
			}
			else
			{
				if (p->right)
				{
					p = p->right;
				}
				else
				{
					p->right = new_node;
					break;
				}
			}	
		}
	}
	printf("\n** Complete **\n\n");
}

void del_student()
{
	int num;
	student *p = root;
	student *node = NULL; // 부모노드
	student *child = NULL; // 자식노드
	student *s, *s_p;

	printf("<< Search Node >>\n\n");
	printf("Input ID : ");
	scanf("%d", &num);

	while(p != NULL && p->ID != num)
	{
		node = p;
		if(num == p->ID)
		{
			printf("ID : %d\n", p->ID);
			printf("Major : %s\n", p->major);
			printf("Name : %s\n", p->name);
			printf("Address : %s\n\n", p->address);
			break;
		}
		else if(num < p->ID)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}

	printf("\nID : %d\n", p->ID);
	printf("Major : %s\n", p->major);
	printf("Name : %s\n", p->name);
	printf("Address : %s\n\n", p->address);
	printf("Do you want to Delete this Student? (1. yes) : ");
	scanf("%d", &num);

	if(num==1)
	{
		if(p->left==NULL && p->right==NULL)
		{
			if(node != NULL)
			{
				if(node->left == p)
				{
					node->left = NULL;
				}
				else
				{
					node->right = NULL;
				}
			}
			else
			{
				root = NULL;
			}
		}
		else if(p->left==NULL || p->right==NULL)
		{
			child = (p->left != NULL) ? p->left : p->right;

			if(node != NULL)
			{
				if(node->left == p)
				{
					node->left = child;
				}
				else
				{
					node->right = child;
				}
			}
			else
			{
				root = child;
			}
		}
		else
		{
			s_p = p;
			s = p->right;

			while(s->left != NULL)
			{
				s_p = s;
				s = s->left;
			}
			
			if(s_p->left == s)
			{
				s_p->left = s->right;
			}
			else
			{
				s_p->right = s->right;
			}
			p->ID = s->ID;
			p = s;
		}
		free(p);
		printf("\n** Complete **\n\n");
	}
	else
	{
		printf("I got it.. Go Back Page\n\n");
		number3();
	}
}

void s_name(student *p, char name[10])
{
	if(p)
	{
		s_name(p->left, name);
		if(strcmp(name, p->name)==0)
		{
			printf("ID : %d\n", p->ID);
			printf("Major : %s\n", p->major);
			printf("Name : %s\n", p->name);
			printf("Address : %s\n\n", p->address);
		}
		s_name(p->right, name);
	}
}

void s_major(student *p, char major[10])
{
	if(p)
	{
		s_major(p->left, major);
		if(strcmp(major, p->major)==0)
		{
			printf("ID : %d\n", p->ID);
			printf("Major : %s\n", p->major);
			printf("Name : %s\n", p->name);
			printf("Address : %s\n\n", p->address);
		}
		s_major(p->right, major);
	}
}

void s_address(student *p, char address[10])
{
	if(p)
	{
		s_address(p->left, address);
		if(strcmp(address, p->address)==0)
		{
			printf("ID : %d\n", p->ID);
			printf("Major : %s\n", p->major);
			printf("Name : %s\n", p->name);
			printf("Address : %s\n\n", p->address);
		}
		s_address(p->right, address);
	}
}

void search_student()
{
	int num,i;
	student *p = root;

	printf("<< Search Node >>\n\n");
	printf("===== Menu =====\n");
	printf("1. ID\n");
	printf("2. Name\n");
	printf("3. Major\n");
	printf("4. Address\n");
	printf("================\n");
	printf("Input Number : ");
	scanf("%d", &num);
	printf("\n");

	if(num==1)
	{
		int id=0;

		printf("Input ID : ");
		scanf("%d", &id);
		printf("\n");

		while(p != NULL)
		{
			if(id == p->ID)
			{
				printf("ID : %d\n", p->ID);
				printf("Major : %s\n", p->major);
				printf("Name : %s\n", p->name);
				printf("Address : %s\n\n", p->address);
			}
			else if(id < p->ID)
			{
				p = p->left;
			}
			else
			{
				p = p->right;
			}
		}
		printf("\n** No Data **\n\n");
	}
	else if(num==2)
	{
		char name[10];

		printf("Input Name : ");
		scanf("%s", name);
		printf("\n");

		s_name(p, name);
	}
	else if(num==3)
	{
		char major[10];

		printf("Input Major : ");
		scanf("%s", major);
		printf("\n");

		s_major(root, major);
	}
	else
	{
		char address[10];

		printf("Input Address : ");
		scanf("%s", address);
		printf("\n");

		s_address(p, address);	
	}
}

void print_student(student *p)
{
	if(p)
	{
		print_student(p->left);
		printf("ID : %d\n", p->ID);
		printf("Major : %s\n", p->major);
		printf("Name : %s\n", p->name);
		printf("Address : %s\n\n", p->address);
		print_student(p->right);
	}
}

int total_num(student *p)
{
	int count=0;

	if(p != NULL)
	{
		count = 1 + total_num(p->left) + total_num(p->right);
	}
	return count;
}

void del_all_student(student *p)
{
	if(p)
    {
        del_all_student(p->left);
        del_all_student(p->right);
        free(p);
    }
}
