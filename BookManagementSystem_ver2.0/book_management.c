#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct book
{
	char field[20];
	char title[20];
	char writer[20];
	char publ[20];
	char year[20];
	int price;
	int borrow_flag;
	int buy_flag;
	struct book *b_next;
}book;

typedef struct best_seller
{
	char title[20];
	char writer[20];
	int buy;
}best_seller;

typedef struct member
{
	char grade[10];
	char name[10];
	char ID[10];
	char password[10];
	int buy_price;
	int borrow_check;
	int join_event;
	struct member *m_next;
}member;

book *b_head = NULL;
member *m_head = NULL;
	// pointers
int member_num = 0; // now member's number
int book_num = 0; // now book's number
char MEMBER_NAME[10]; // who login?

void guest_menu();
void manager_menu();
void members_menu();
	// Menu
member *login();

book *b_search();
void search();
void add_book();
void del_book();
void adjust_book();
void pur_bor_book();
void re_book();
void print_all_book();
	// books
member *m_search();
void grade();
void add_member();
void member_lev();
void adjust_own();
void print_all_member();
void print_own();
	// members
void print_best();
void add_best();
void sale();
	// best list
int MAX_event = 0; 
int *eve_cord;
void eve_join();
void eve_manage();
	// event
void save_member();
void load_member();
void save_book();
void load_book();
	// save & load

int main(void)
{
	load_book();
	load_member();

	guest_menu();
}

void guest_menu()
{
	char fi;
	int num;
	int i;
	
	while(1)
	{
		system("clear");
		printf("<< Welcome to library program!! >> \n\n");

		printf("** Best Seller LIST **\n");
		print_best();

		printf("\n\n======= MENU =======\n\n");
		printf("1. Print all book \n");
		printf("2. Book search \n");
		printf("3. Register \n");
		printf("4. Login \n");
		printf("5. Exit\n");
		printf("====================\n\n");

		printf("Choice : ");
		scanf("%d", &num);
		printf("\n");

		if(num==1)
		{
			print_all_book();
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==2)
		{
			search();
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==3)
		{
			add_member();
		}
		else if(num==4)
		{
			login();
		}
		else if(num==5)
		{
			printf("** Save all information **\n\n");
			printf("Thank you.. Bye..\n");
			sleep(1);
			save_book();
			save_member();
			exit(1);
		}
		else 
		{
			scanf("%c", &fi);
                        if(fi)
                        {
				printf("There is no comformed informaion.\n");
				printf("Try again..\n\n");
				sleep(1);
                        	guest_menu();
                        }	
	    	}
	}
}

void manager_menu()
{
	int num;
	char fi;
	
	while(1)
	{
		system("clear");
		printf("========== Manager's Menu =========\n"); 
		printf("1. Add book's informaion\n");
		printf("2. Delete Book's informaion\n");
		printf("3. Adjust Book's informaion\n");
		printf("4. Search Book's informaion\n");
		printf("5. Print Informatin\n");
		printf("6. Sale's Reports\n");
		printf("7. Best Manage / List\n");
		printf("8. Event Manage\n");
		printf("9. Go to start Menu\n");
		printf("0. Exit Program\n");
		printf("===================================\n\n");
		printf("Choose number : ");
		scanf("%d", &num);
		printf("\n");

		if(num==1)
		{
			add_book();
			printf("\n\n=========== [ After 1 sec, disappear this info ] ==========\n");
			sleep(1);
		}
		else if(num==2)
		{
			del_book();
			printf("\n\n=========== [ After 1 sec, disappear this info ] ==========\n");
			sleep(1);
		}
		else if(num==3)
		{
			adjust_book();
			printf("\n\n=========== [ After 1 sec, disappear this info ] ==========\n");
			sleep(1);
		}
		else if(num==4)
		{
			search();
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==5)
		{
			printf("================== Menu ====================\n");
			printf("1. Print All Book   2. Print All Members\n\n");
			printf("Choose : ");
			scanf("%d", &num);

			if(num==1)
			{
				print_all_book();
			}
			else if(num==2)
			{
				print_all_member();
			}
			else
			{
				printf("There is no comformed informaion.\n\n");
			}
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==6)
		{
			sale();
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==7)
		{
			printf("================== Menu ====================\n");
			printf("1. Manage Best Seller   2. Print Best List\n");
			printf("Choose : ");
			scanf("%d", &num);

			if(num==1)
			{	
				printf("\n");					
				add_best();
			}
			else if(num==2)
			{
				printf("\n** Best Seller LIST **\n");
				print_best();
			}
			else
			{
				printf("There is no comformed informaion.\n\n");
			}
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==8)
		{
			eve_manage();
			printf("\n\n=========== [ After 1 sec, disappear this info ] ==========\n");
			sleep(1);
		}
		else if(num==9)
		{
			guest_menu();
		}
		else if(num==0)
		{
			printf("** Save all information **\n\n");
			printf("Thank you.. Bye..\n");
			sleep(1);
			save_book();
			save_member();
			exit(1);
		}
		else
		{
			scanf("%c", &fi);
                        if(fi)
                        {
				printf("There is no comformed informaion.\n");
				printf("Try again..\n\n");
				sleep(1);
                        	manager_menu();
                        }
		}
	}
}

void members_menu()
{	
	char fi;
	int num;
	char str[10] = "empty";
	
	while(1)
	{
		system("clear");
		printf("========== Member < %s >'s Menu =========\n", MEMBER_NAME); 
		printf("1. Search Book's informaion\n");
		printf("2. Purchase or Borrow book\n");
		printf("3. Refund or Return book\n");
		printf("4. Print All Books\n");
		printf("5. Join Event\n");
		printf("6. Adjust Own informaion\n");
		printf("7. print Own informaion\n");
		printf("8. Member Leave\n");
		printf("9. Go to start Menu\n");
		printf("0. Exit Program\n");
		printf("========================================\n\n");
		printf("Choose number : ");
		scanf("%d", &num);
		printf("\n");

		if(num==1)
		{
			search();
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==2)
		{
			pur_bor_book();
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==3)
		{
			re_book();
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==4)
		{
			print_all_book();
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==5)
		{
			eve_join();
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==6)
		{
			adjust_own();
			printf("\n\n=========== [ After 1 sec, disappear this info ] ==========\n");
			sleep(1);
		}
		else if(num==7)
		{
			print_own();
			printf("\n\n=========== [ After 3 sec, disappear this info ] ==========\n");
			sleep(3);
		}
		else if(num==8)
		{
			member_lev();
			printf("\n\n=========== [ After 1 sec, disappear this info ] ==========\n");
			sleep(1);
		}
		else if(num==9)
		{
			strcpy(MEMBER_NAME, str);
			guest_menu();
		}
		else if(num==0)
		{
			printf("** Save all information **\n\n");
			printf("Thank you.. Bye..\n");
			sleep(1);
			save_book();
			save_member();
			exit(1);
		}
		else
		{
			scanf("%c", &fi);
                        if(fi)
                        {
				printf("There is no comformed informaion.\n");
				printf("Try again..\n\n");
				sleep(1);
                        	members_menu();
                        }
		}
	}
}

member *login()
{
	member *p = m_head;
	char ID[]= "manager";
	char password[]= "0000";
	char id[10];
	char Password[10];
	int i;

	printf("<< Login limits three times.>>\n\n");

	for(i=0; i<3; i++)
	{
		printf("ID : ");
		scanf("%s", id);
		printf("Password : ");
		scanf("%s", Password);

		if(strcmp(ID, id)==0 && strcmp(password, Password)==0)
		{
			system("clear");
			printf("** Wellcome. < Manager >\n\n");
			printf("** Move to Manager's Menu. ** \n");
			manager_menu();
		}

		while(p != NULL)
		{
			if(strcmp(p->ID, id)==0 && strcmp(p->password, Password)==0)
			{
				strcpy(MEMBER_NAME, p->name);
				system("clear");
				printf("** Wellcome. < %s >\n\n", MEMBER_NAME);
				printf("** Move to Member's Menu. ** \n");
				members_menu();
			}
			p = p->m_next;
		}
		printf("We don't have that Member\n");
	}
	guest_menu();
}

member *m_search()
{
	int num;
	member *p = m_head;

	grade();
	while(p != NULL)
	{
		if(strcmp(MEMBER_NAME, p->name)==0)
		{
			return p;
		}
		p = p->m_next;
	}
}

void add_member()
{
	member *new_node = (member*)malloc(sizeof(member));
	new_node->m_next=NULL;
	
	printf("\n== Write your information ==\n\n");
	printf("NAME : ");
	scanf("%s", new_node->name);
	__fpurge(stdin);
	printf("ID : ");
	scanf("%s", new_node->ID);
	__fpurge(stdin);
	printf("PASSWORD : ");
	scanf("%s", new_node->password);
	__fpurge(stdin);

	new_node->buy_price=0;
	new_node->borrow_check=0;
	grade();

	if(m_head != NULL)	
	{
		new_node->m_next = m_head;
		m_head = new_node;
	}
	else
	{
		new_node->m_next = NULL;
		m_head = new_node;
	}
	member_num++;
	printf("\n** Complete **\n");
}

void adjust_own()
{
	char fi;
        int num;
        member *p = m_head;

        p = m_search();
	printf("\n<< Your information>>\n");
	printf("Grade : %s\n", p->grade);
	printf("Name : %s\n", p->name);
	printf("ID : %s\n", p->ID);
	printf("Password : %s\n", p->password);

        printf("\nDo you want to Adjust this information?\n");
        printf("1. Yes   2.No\n");
        printf("Choose : ");
        scanf("%d", &num);
	printf("\n");

        if(num==1)
        {
                printf("Name : ");
                scanf("%s", p->name);
                printf("ID : ");
                scanf("%s", p->ID);
                printf("Password : ");
                scanf("%s", p->password);
		printf("\n** Complete **\n");
		printf("** Go to FIRST page. Wait 1 sec **\n\n");
		sleep(1);
		strcmp(MEMBER_NAME, p->name);
		guest_menu();
        }
        else if(num==2)
        {
                printf("I got it. Go BACK page\n\n");
        }
        else
        {
                scanf("%c", &fi);
                if(fi)
                {
			printf("There is no comformed informaion.\n");
			printf("Go back page..\n\n");
			sleep(1);
                }
        }
}

void print_own()
{
        member *p = m_head;

	grade();
        while(p != NULL)
        {
                if(strcmp(p->name, MEMBER_NAME)==0)
                {
                        printf("<< Your information >>\n");
			printf("Grade : %s\n", p->grade);
                        printf("Name : %s\n", p->name);
                        printf("ID : %s\n", p->ID);
                        printf("Password : %s\n", p->password);
                }
                p = p->m_next;
        }
}

void print_all_member()
{
        member *p = m_head;

	grade();
        printf("** We have %d members NOW\n\n", member_num);
        while(p != NULL)
        {
		printf("Grade : %s\n", p->grade);
                printf("Name : %s\n", p->name);
                printf("ID : %s\n", p->ID);
                printf("Password : %s\n", p->password);
                printf("\n");
                p = p->m_next;
        }
}

void member_lev()
{
	char fi;
        int num;
	member *node = m_head;
	member *p;
        member *remove;

        remove = m_search();
	printf("\n<< Your information>>\n");
	printf("Grade : %s\n", remove->grade);
	printf("Name : %s\n", remove->name);
	printf("ID : %s\n", remove->ID);
	printf("Password : %s\n", remove->password);

        printf("\nREALLY  do you want to Delete this information?\n");
        printf("1. Yes   2.No\n");
        printf("Choose : ");
        scanf("%d", &num);

        if(num==1)
        {
                if(node == NULL)
		{
			return;
		}
		else
		{
			if(m_head == remove)		
			{
				m_head = m_head->m_next;
				free(remove);
			}
			else
			{
				while(node != NULL)
				{
					if(node == remove)
					{
						p->m_next = remove->m_next;	
						free(remove);
						return;
					}
					p = node;
					node = node->m_next;
				}
			}
                	member_num--;
			printf("\n** Complete **\n");
			printf("** Go to FIRST page. Wait 1 sec **\n\n");
			sleep(1);
			guest_menu();
		}
        }
        else if(num==2)
	{
                printf("\nI got it. Go BACK page\n\n");
        }
    	else
        {
                scanf("%c", &fi);
                if(fi)
                {
			printf("There is no comformed informaion.\n");
			printf("Go back page..\n\n");
			sleep(1);
                }
        }
}

void grade()
{
	member *p = m_head;

	while(p != NULL)
	{
		if(p->buy_price >= 100000)
		{
			strcpy(p->grade, "VVIP");
		}
		else if(p->buy_price >= 80000 && p->buy_price < 100000)
		{
			strcpy(p->grade, "VIP");
		}
		else if(p->buy_price >= 50000 && p->buy_price < 80000)
		{
			strcpy(p->grade, "GOLD");
		}
		else if(p->buy_price >= 10000 && p->buy_price < 50000)
		{
			strcpy(p->grade, "SILVER");
		}
		else
		{
			strcpy(p->grade, "BRONZE");
		}
		p =p->m_next;
	}
}

void save_member()
{
        FILE *fp = fopen("member's info.txt", "w");
        member *p = m_head;

        while(p != NULL)
        {
                fprintf(fp, "%s\n", p->name);
                fprintf(fp, "%s\n", p->ID);
                fprintf(fp, "%s\n", p->password);
		fprintf(fp, "%d\n", p->buy_price);
		fprintf(fp, "%d\n", p->borrow_check);
		
                p = p->m_next;
        }
        fclose(fp);
}

void load_member()
{
	member *new_node = NULL;
        FILE *fp = fopen("member's info.txt", "r+");
	
        if(fp == NULL)
        {
                return;
        }

        while(!feof(fp))
        {
                new_node = (member*)malloc(sizeof(member));
                new_node->m_next = NULL;

                fscanf(fp, "%s\n", new_node->name);
                fscanf(fp, "%s\n", new_node->ID);
                fscanf(fp, "%s\n", new_node->password);
		fscanf(fp, "%d\n", &new_node->buy_price);
		fscanf(fp, "%d\n", &new_node->borrow_check);

                if(m_head != NULL)	
		{
			new_node->m_next = m_head;
			m_head = new_node;
		}
		else
		{
			new_node->m_next = NULL;
			m_head = new_node;
		}	
		member_num++;
        }
        fclose(fp);
}

book *b_search()
{
	char fi;
        int num;
        book *p = b_head;

        printf("====== Menu ======\n");
        printf("1. Field   2. Title   3. Writer\n");
        printf("Choose : ");
        scanf("%d", &num);
	printf("\n");

        if(num==1)
        {
                char field[20];

                printf("Field : ");
                scanf("%s", field);

                while(p != NULL)
                {
                        if(strcmp(field, p->field)==0)
                        {
				return p;
                        }
                        p = p->b_next;
                }
		printf("\n** We don't have that book **\n\n");
		return 0;
     	}
	else if(num==2)
        {
                char title[20];

                printf("Title : ");
                scanf("%s", title);

                while(p != NULL)
                {
                        if(strcmp(title, p->title)==0)
                        {
				return p;
                        }
                        p = p->b_next;
                }
		printf("\n** We don't have that book **\n\n");
		return 0;
        }
	else if(num==3)
        {
                char writer[20];

                printf("Writer : ");
                scanf("%s", writer);

                while(p != NULL)
                {
                        if(strcmp(writer, p->writer)==0)
                        {
				return p;
                        }
                        p = p->b_next;
                }
		printf("\n** We don't have that book **\n\n");
		return 0;
        }
        else
        {
                scanf("%c", &fi);
                if(fi)
                {
			printf("There is no comformed informaion.\n");
			printf("Go back page..\n\n");
			sleep(1);
                }
        }
}

void add_book()
 {
	book *p;
	book *node = b_head;

	book *new_node = (book*)malloc(sizeof(book));	
	new_node->b_next=NULL;

	printf("Field : ");
	scanf("%s", new_node->field);
	__fpurge(stdin);
	printf("Title : ");
	scanf("%s", new_node->title);
	__fpurge(stdin);
	printf("Writer : ");
	scanf("%s", new_node->writer);
	__fpurge(stdin);
	printf("Publisher : ");
	scanf("%s", new_node->publ);
	__fpurge(stdin);
	printf("Year : ");
	scanf("%s", new_node->year);
	__fpurge(stdin);
	printf("Price : ");
	scanf("%d", &new_node->price);
	__fpurge(stdin);

	new_node->buy_flag=0;
	new_node->borrow_flag=0;
	 	
	if(b_head != NULL)	
	{
		new_node->b_next = b_head;
		b_head = new_node;
	}
	else
	{
		new_node->b_next = NULL;
		b_head = new_node;
	}	
	book_num++;	
 }

void del_book()
{
	char fi;
        int num;
	book *node = b_head;
        book *p;

        printf("** Input that you want to Delete **\n");
        book *remove = b_search();
	if(remove == NULL)
	{
		sleep(1);
		manager_menu();
	}

	printf("\n<< Book informaion that you input>>\n");
        printf("\nField : %s\n", remove->field);
        printf("Title : %s\n", remove->title);
        printf("Writer : %s\n", remove->writer);
        printf("Publisher : %s\n", remove->publ);
        printf("Year : %s\n", remove->year);
        printf("Price : %d\n", remove->price);

        printf("\nDo you want to Delete this book?\n");
        printf("1. Yes   2.No\n");
        printf("Choose : ");
        scanf("%d", &num);

        if(num==1)
        {
                if(node == NULL)
		{
			return;
		}
		else
		{
			if(b_head == remove)		
			{
				b_head = b_head->b_next;
				free(remove);
			}
			else
			{
				while(node != NULL)
				{
					if(node == remove)
					{
						p->b_next = remove->b_next;
						free(remove);
						return;
					}
					p = node;
					node = node->b_next;
				}
			}
		}
                book_num--;
		printf("\n** Complete **\n");
        }
        else if(num==2)
        {
                printf("\nI got it. Go BACK page\n\n");
        }
    	else
	{
                scanf("%c", &fi);
                if(fi)
                {
			printf("There is no comformed informaion.\n");
			printf("Go back page..\n\n");
			sleep(1);
                }
        }
}

void adjust_book()
{
	char fi;
        int num;
        book *p = NULL;

        printf("** Input that you want to Adjust **\n");
        p = b_search();
	if(p == NULL)
	{
		sleep(1);
		manager_menu();
	}

	printf("\n<< Book informaion that you input>>\n");
        printf("\nField : %s\n", p->field);
        printf("Title : %s\n", p->title);
        printf("Writer : %s\n", p->writer);
        printf("Publisher : %s\n", p->publ);
        printf("Year : %s\n", p->year);
        printf("Price : %d\n", p->price);

        printf("\nDo you want to Adjust this book?\n");
        printf("1. Yes   2.No\n");
        printf("Choose : ");
        scanf("%d", &num);
	printf("\n");

        if(num==1)
        {
                printf("Field : ");
                scanf("%s", p->field);
                printf("Title : ");
                scanf("%s", p->title);
                printf("Writer : ");
                scanf("%s", p->writer);
                printf("Publisher : ");
                scanf("%s", p->publ);
                printf("Year : ");
                scanf("%s", p->year);
                printf("Price : ");
                scanf("%d", &p->price);
		printf("\n** Complete **\n");
        }
        else if(num==2)
        {
                printf("\nI got it. Go BACK page\n\n");
        }
        else
        {
                scanf("%c", &fi);
                if(fi)
                {
			printf("There is no comformed informaion.\n");
			printf("Go back page..\n\n");
			sleep(1);
                }
        }
}

void search()
{
	book *p = NULL;

	printf("** Input that you want to Find **\n");
    	p = b_search();
	
	if(p != NULL)
	{
		printf("\n<< Book informaion that you input>>\n");
		printf("\nField : %s\n", p->field);
     		printf("Writer : %s\n", p->writer);
        	printf("Publisher : %s\n", p->publ);
        	printf("Year : %s\n", p->year);
        	printf("Price : %d\n", p->price);
	}
}

void print_all_book()
{
        book *p = b_head;

        printf("\n** We have %d books NOW\n\n", book_num);
        while(p != NULL)
        {
                printf("Field : %s\n", p->field);
                printf("Title : %s\n", p->title);
                printf("Writer : %s\n", p->writer);
                printf("Publisher : %s\n", p->publ);
                printf("Year : %s\n", p->year);
                printf("Price : %d\n", p->price);
                printf("\n");
                p = p->b_next;
        }
}

void pur_bor_book()
{
	char fi;
	char name[10];
	book *t = NULL;
	member *p = m_head;
	int num;

	system("clear");
	printf("============= Menu ============\n");
	printf("1. Buy book   2. Borrow book\n");
	printf("Choose : ");
	scanf("%d", &num);

	if(num==1)
	{
		t=b_search();
		if(t == NULL)
		{
			sleep(1);
			members_menu();
		}

		printf("\n<< Book informaion that you input>>\n");
        	printf("\nField : %s\n", t->field);
        	printf("Title : %s\n", t->title);
        	printf("Writer : %s\n", t->writer);
        	printf("Publisher : %s\n", t->publ);
        	printf("Year : %s\n", t->year);
        	printf("Price : %d\n", t->price);

		printf("\n\nIs this book you want to buy?\n");
		printf("1.Yes   2.No : ");
		scanf("%d", &num);

		if(num==1)
		{
			t->buy_flag++;
			while(p != NULL)
			{
				if(strcmp(MEMBER_NAME, p->name)==0)
				{
					printf("\nI'll buy this book. Thanks\n");
					p->buy_price = p->buy_price + t->price;
					break;
				}
				p = p->m_next;
			}
		}
		else if(num==2)
		{
			printf("\nI got it. I don't buy this book.\n");
			printf("** Go to first page\n");
		}
		else
		{
			scanf("%c", &fi);
                	if(fi)
                	{
				printf("There is no comformed informaion.\n");
				printf("Go back page..\n\n");
				sleep(1);
                	}
		}
	}
	else if(num==2)
	{
		t=b_search();
		if(t == NULL)
		{
			sleep(1);
			members_menu();
		}

		printf("\n<< Book informaion that you input>>\n");
        	printf("\nField : %s\n", t->field);
        	printf("Title : %s\n", t->title);
        	printf("Writer : %s\n", t->writer);
        	printf("Publisher : %s\n", t->publ);
        	printf("Year : %s\n", t->year);
        	printf("Price : %d\n", t->price);

		printf("\n\nIs this book you want to borrow?\n");
		printf("1.Yes   2.No : ");
		scanf("%d", &num);

		if(num==1)
		{
			while(p != NULL)
			{
				t->borrow_flag++;
				if(strcmp(MEMBER_NAME, p->name)==0)
				{
					printf("\nI'll borrow this book. Thanks\n");
					p->borrow_check++;
					break;
				}
				p = p->m_next;
			}
		}
		else if(num==2)
		{
			printf("I got it. I don't borrow this book.\n");
			printf("** Go to first page\n");
		}
		else
		{
			printf("There is no comformed informaion.\n\n");
		}
	}
	else
	{
		scanf("%c", &fi);
                if(fi)
                {
			printf("There is no comformed informaion.\n");
			printf("Go back page..\n\n");
			sleep(1);
                }
	}
}

void re_book()
{
	char fi;
	char name[10];
	book *t = NULL;
	member *p = m_head;
	int num;

	system("clear");
	printf("=============== Menu =============\n");
	printf("1. Refund book   2. Return book\n");
	printf("Choose : ");
	scanf("%d", &num);

	if(num==1)
	{
		t=b_search();
		if(t == NULL)
		{
			sleep(1);
			members_menu();
		}

		printf("\n<< Book informaion that you input>>\n");
        	printf("\nField : %s\n", t->field);
        	printf("Title : %s\n", t->title);
        	printf("Writer : %s\n", t->writer);
        	printf("Publisher : %s\n", t->publ);
        	printf("Year : %s\n", t->year);
        	printf("Price : %d\n", t->price);

		printf("\n\nIs this book you want to refund?\n");
		printf("1.Yes   2.No : ");
		scanf("%d", &num);

		if(num==1)
		{
			while(p != NULL)
			{
				if(strcmp(MEMBER_NAME, p->name)==0)
				{
					if(p->buy_price == 0)
					{
						printf("\nI'm sorry. You can't refund this Book\n\n");
					}

					printf("\nI'll refund this book. Thanks\n");
					t->buy_flag--;
					p->buy_price = p->buy_price - t->price;
					break;
				}
				p = p->m_next;
			}
		}
		else if(num==2)
		{
			printf("\nI got it. I don't refund this book.\n");
			printf("** Go to first page\n");
		}
		else
		{
			scanf("%c", &fi);
                	if(fi)
                	{
				printf("There is no comformed informaion.\n");
				printf("Go back page..\n\n");
				sleep(1);
                	}
		}
	}
	else if(num==2)
	{
		t=b_search();
		if(t == NULL)
		{
			sleep(1);
			members_menu();
		}

		printf("\n<< Book informaion that you input>>\n");
        	printf("\nField : %s\n", t->field);
        	printf("Title : %s\n", t->title);
        	printf("Writer : %s\n", t->writer);
        	printf("Publisher : %s\n", t->publ);
        	printf("Year : %s\n", t->year);
        	printf("Price : %d\n", t->price);

		printf("\n\nIs this book you want to return?\n");
		printf("1.Yes   2.No : ");
		scanf("%d", &num);

		if(num==1)
		{
			while(p != NULL)
			{
				if(strcmp(MEMBER_NAME, p->name)==0)
				{
					if(p->borrow_check == 0)
					{
						printf("\nI'm sorry. You can't return this Book\n\n");
					}

					printf("\nI'll return this book. Thanks\n");
					t->borrow_flag--;
					p->borrow_check--;
					break;
				}
				p = p->m_next;
			}
		}
		else if(num==2)
		{
			printf("\nI got it. I don't return this book.\n");
			printf("** Go to first page\n");
		}
		else
		{
			scanf("%c", &fi);
                	if(fi)
                	{
				printf("There is no comformed informaion.\n");
				printf("Go back page..\n\n");
				sleep(1);
                	}
		}
	}
	else
	{
		scanf("%c", &fi);
                if(fi)
                {
			printf("There is no comformed informaion.\n");
			printf("Go back page..\n\n");
			sleep(1);
                }
	}	
}

void save_book()
{
        FILE *fp = fopen("book's info.txt", "w");
        book *p = b_head;

        while(p != NULL)
        {
                fprintf(fp, "%s\n", p->field);
                fprintf(fp, "%s\n", p->title);
                fprintf(fp, "%s\n", p->writer);
                fprintf(fp, "%s\n", p->publ);
                fprintf(fp, "%s\n", p->year);
                fprintf(fp, "%d\n", p->price);
		fprintf(fp, "%d\n", p->buy_flag);
		fprintf(fp, "%d\n", p->borrow_flag);
		
                p = p->b_next;
        }
        fclose(fp);
}

void load_book()
{
	book *p;
	book *node = b_head;
	
	book *new_node = NULL;
        FILE *fp = fopen("book's info.txt", "r+");

        if(fp == NULL)
        {
                return;
        }

        while(!feof(fp))
        {
                new_node = (book*)malloc(sizeof(book));
                new_node->b_next = NULL;

                fscanf(fp, "%s\n", new_node->field);
                fscanf(fp, "%s\n", new_node->title);
                fscanf(fp, "%s\n", new_node->writer);
                fscanf(fp, "%s\n", new_node->publ);
                fscanf(fp, "%s\n", new_node->year);
                fscanf(fp, "%d\n", &new_node->price);
		fscanf(fp, "%d\n", &new_node->buy_flag);
		fscanf(fp, "%d\n", &new_node->borrow_flag);

                if(b_head != NULL)	
		{
			new_node->b_next = b_head;
			b_head = new_node;
		}
		else
		{
			new_node->b_next = NULL;
			b_head = new_node;
		}	
		book_num++;
        }
        fclose(fp);
}

void add_best()
{
	book *p = b_head;
    	char name[20];
	int how;

	printf("\nChoice Best Seller Title : ");
    	scanf("%s", name);
	printf("How many books have been sold? : ");
	scanf("%d", &how);

	while(p != NULL)
	{
		if(strcmp(name, p->title)==0)
		{
			p->buy_flag = p->buy_flag + how;
			printf("\n== complete!! == \n\n");
		}
		p = p->b_next;
	}
}

void print_best()
{
	book *p = b_head;
	int point_num=0;
	int temp, j, i;
	char temp1[20], temp2[20];
		
	while(p != NULL)
	{	
		point_num++;
		p = p->b_next;
	}

	best_seller s[point_num];
	p = b_head;
	for(i=0; i<point_num; i++)
	{
		strcpy(s[i].title, p->title);
		strcpy(s[i].writer, p->writer);
		s[i].buy = p->buy_flag;
		p = p->b_next;
	}

	for(i=0; i<point_num; i++)
	{
		for(j=0; j<point_num-i-1; j++)
		{
			if(s[j+1].buy > s[j].buy)
			{
				temp = s[j].buy;
				strcpy(temp1, s[j].title);
				strcpy(temp2, s[j].writer);
				s[j].buy = s[j+1].buy;
				strcpy(s[j].title, s[j+1].title);
				strcpy(s[j].writer, s[j+1].writer);
				s[j+1].buy = temp;
				strcpy(s[j+1].title, temp1);
				strcpy(s[j+1].writer, temp2);
			}
		}
	}

	for(i=0; i<point_num; i++)
	{
		if(i>10)
		{
			break;
		}
		printf("%d. < %s > of '%s' \n", i+1, s[i].title, s[i].writer);
	}	
}

void sale()
{
	book *t = b_head;
        member *p = m_head;
        int sum1=0, sum2=0;

        system("clear");
        printf("<< Print all Sale's report >>\n\n");
        while(p != NULL)
        {
                sum1 += p->buy_price;
                p = p->m_next;
        }
	
	while(t != NULL)
	{
		sum2 += t->borrow_flag;
		t = t->b_next;
	}
        printf("Total book sales are %d. \n", sum1);
        printf("Total book borrow nums are %d. \n", sum2);
}

void eve_join()
{
	int num;
	int event_point=0;
	member *p = m_head;

	system("clear");
	printf("      << Print all EVENT >>\n");
	printf("1. Quiz Game    2. Baseball Game\n");
	printf("3. Cord Input   4. Get out of here\n");
	printf("Choose : ");
	scanf("%d", &num);

	if(num==1)
	{
		int i,j,sum;
		char answer[20];
		srand(time(NULL));

		p = m_search();
		p->join_event++;

		char questions[20][100] = {
			{"<Les Miserables> is the four Musical. O, X ?"},
			{"____ launches iphone serise."},
			{"Who acts in a Movie <Mission Impossible>?"},
			{"What country is famous for Animation?"},
			{"In Korea, usually students study for ___ years."},
			{"Musical <The phantom of the opera> has a sequel. O, X ?"},
			{"Gundam serises greet the __th anniversary."},
			{"Where is the capital of China?"},  
			{"Computer Programming Class is a 2-credit class."},
			{"IS terrorizes Paris"},
			{"Goryeo celadon color is ____."},
			{"What is opposite mean of cosmos?"},
			{"What is the name of hero movie's production company?"},
			{"Earth has ___ Month."},
			{"___ is the most famous education company in Korea."},
			{"In Korea, Most people search for information on a ____ portal."},
			{"In Korea, Second language is ______."},
			{"What is the acceleration law? (Newton's second law)."},
			{"Einstein is famous for the theory of ______."},
			{"What is this program?"}
		};

		char Answer[20][20] = { 
			{"O"},
			{"Apple"},
			{"Tom_Cruise"},
			{"Japan"},
			{"16"},
			{"O"},
			{"35"},
			{"Beijing"},
			{"X"},
			{"O"},
			{"Blue"},
			{"Chaos"},
			{"Marvel"},
			{"12"},
			{"EBS"},
			{"NEVER"},
			{"English"},
			{"F=ma"},
			{"Relativity"},
			{"Book_Management"}
		};

		printf("<< Quiz Game >>\n\n");

		for(i=0 ; i<5; i++)
		{
			j = rand()%20 -i;
			printf("%d << %s >>\n",  i+1, questions[j]);
			printf("ANSWER : ");
			scanf("%s",answer);
   
			if(strcmp(answer, Answer[j]) == 0)
			{
				printf("** RIGHT **\n");
				printf(" +1 point\n\n");
				event_point++;
			}
			else
			{
				printf("** WRONG **\n\n");
			}
		}
		
		printf("Complete to Game.\n");
		printf("Your SCORE is %d.\n", event_point);
		if(event_point >= 4)
		{
			printf("\nCongratulation~~\n");
			printf("You can obtain ** Serial Number **\n");
			printf("Serial Number : %d\n", *eve_cord);

		}
		else
		{
			printf("\n** See you later. Try oter time~\n");
		}
 	}
	else if(num==2)
	{
		int ball=0 ,strike=0;
		int i=0,j=0;
		int com[3],player[3];
		int result=0, val=0, event_point=0;

		p = m_search();
		p->join_event++;

		srand((int)time(NULL));

		printf("<< Baseball Game Start >>\n\n");

		com[0]=rand()%10;
		com[1]=rand()%10;
		com[2]=rand()%10;

		while(result != 1)
		{
			printf("** Choose 3 number : ");
			while(1)
			{
				scanf("%d %d %d", &player[0], &player[1], &player[2]);

				if(player[0]==player[1] || player[0]==player[2] || player[1]==player[2])
				{
					val=0;
				}
				else
				{
					break;
				}
			}
			
			for(i=0; i<3; i++)
			{
				for(j=0; j<3; j++)
				{
					if(com[i]==player[j])
					{
						if (i = j)
						{
							strike++;
						}
						else
						{
							ball++;
						}
					}
				}
			}
			event_point++;
			printf("< %d > result : %dstrike   %dball\n\n", event_point, strike, ball);

			if(strike==3)
			{
				result=1;
			}
			else
			{
				result=0;
			}
		}
		printf("** Complete!!!! **\n");

		if(event_point <= 5)
		{
			printf("\nCongratulation~~\n");
			printf("You can obtain ** Serial Number **\n");
			printf("Serial Number : %d\n", *eve_cord);
		}		
		else
		{
		printf("\n** See you later. Try oter time~\n");
		}
	}
	else if(num==3)
	{
		int cord,i,j=0;
		char A[10][50] = {
			{"Math skill"},
			{"Basic English skill"},
			{"Phantom of the opera"},
			{"Pride and Prejudice"},
			{"Jane Eyre"},
			{"Wuthering Heights"},
			{"Chaos "},
			{"Sherlock Holmes"},
			{"All the Light We Cannot See"},
			{"Still Alice"}
		};

		printf("Input Serial Number : ");
		scanf("%d", &cord);

		for(i=0; i<MAX_event; i++)
		{
			if(cord == *eve_cord)
			{
				printf("\nYou can obtain BOOK\n");
				j=rand()%10;
				printf("\n<< Book Title : ' %s ' >>\n\n", A[j]);
				printf("** Congratulation!!!\n");
			}
		}
	}
	else if(num==4)
	{
		members_menu();
	}
	else
	{
		printf("There is no comformed informaion.\n\n");
	}
}

void eve_manage()
{
	int num,i;

	if(MAX_event==0)
	{
		system("clear");
		printf("How many EVENT do you want? : ");
		scanf("%d", &MAX_event);

		eve_cord = (int*)malloc(sizeof(int)*MAX_event);

		for(i=0; i<MAX_event; i++)
		{
			printf("\n** Creat cord **\n");
			*eve_cord = rand();
		}
	}
	else
	{
		printf("Do you want to add EVENT? : ");
		printf("1. Yes   2. No\n");
		printf("Choose : ");
		scanf("%d", &num);

		if(num==1)
		{
			printf("How many EVENT do you want? : ");
			scanf("%d", &MAX_event);

			eve_cord = (int*)realloc(eve_cord, sizeof(int)*MAX_event);

			for(i; i<MAX_event; i++)
			{
				printf("\n** Creat cord **\n");
				*eve_cord = rand();
			}
			printf("\n** Complete **\n");
		}
		else if(num==2)
		{
			printf("I'll get out of here\n");
			manager_menu();
		}
		else
		{
			printf("There is no comformed informaion.\n\n");
		}
	}
}
