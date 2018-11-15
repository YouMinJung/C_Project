#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book  //������ ���õ� ����ü
{
	char title[30];
	char publ[30];
    char writer[30];
	char year[30];
	int checkout_flag;  
}book;

typedef struct user  //ȸ���� ���õ� ����ü
{
	char name[10];
	char ID[10];
	char password[10];
}user;

int book_num=0; //��ü ���� ��
int user_num=0; //��ü ȸ�� ��
user info[10]; //ȸ���� ���õ� ���ڿ�
book chac[30]; //������ ���õ� ���ڿ�
int a=1; // book�߰�
int j=1; // user�߰�

void login(); //�α���
void manager(); //������ �޴�
void user_menu(); //�Ϲ�ȸ�� �޴�
void search_book(); //���� �˻�
void borrow_book(); //���� ����
void borrow_book_manager(); //���� ����-�����ڿ�
void back_book(); //���� �ݳ�
void display_all_book(); //��ü ���� ���
void display_all_user(); //��ü ȸ�� ���
void add_book(); // ���� �߰�
void add_user(); //ȸ�� �߰�(ȸ������)
void remove_book(); //���� ����
void remove_user(); //ȸ�� ����(ȸ�� Ż��)
void fix_book(); //���� ���� ����
void fix_user(); //ȸ�� ���� ����
int the_end(); //���α׷� ����

int main(void)
{
    int num;
	int x;
	char name[10];
	char ID[10];
	char password[10];

	char Name[]= "������";
	char id[]= "manager";
	char Password[]= "0000";

	system("cls");
	printf("<<�� ���� ���� ���α׷��� �����մϴ�. ��>> \n\n");
	system("pause");

	system("cls");
	printf("������ �������̽ʴϱ�? <yes:1  no:2> : ");
	scanf("%d", &num);
	printf("\n========================================\n");

	if(num==1)
	{
		printf("\n�α����� �����մϴ�. \n");
		printf("\n");
		printf("�̸��� �Է����ּ��� : ");
		scanf("%s", name);

		if(strcmp(name, Name)==0)
		{
			printf("���̵� �Է����ּ��� : ");
		    scanf("%s", ID);

			if(strcmp(ID, id)==0)
			{
				printf("��й�ȣ�� �Է����ּ��� : ");
		        scanf("%s", password);

				if(strcmp(password, Password)==0)
				{
					system("cls");
					printf("====================================\n");
					printf("\n�α��ο� �����߽��ϴ�. \n");
                    printf("\n������ ��带 �����ϰڽ��ϴ�. \n\n");
					printf("====================================\n");
                    system("pause");
					manager();
				}
			}
		}
		else
		{
			printf("\n\n[�߸��� ������ �Է��ϼ̽��ϴ�, ó������ ���ư��ϴ�.]\n\n\n");
			system("pause");
			main();
	    }
	}
	else if(num==2)
	{
		system("cls");

		printf("������ �Ϲ�ȸ���̽ʴϱ�? <yes:1 no:2> : ");
		scanf("%d", &x);

		if(x==1)
		{
			login();
		}
		if(x==2)
		{
			add_user();
		}
		else 
		{
			printf("�߸��Է��ϼ̽��ϴ�.\n");
		    system("pause");
		    system("cls");
			main();
		}	
	}
	else
	{
		printf("�߸��Է��ϼ̽��ϴ�.\n");
		system("pause");
		system("cls");
		main();
	}
}

void add_user()
{
	printf("\nȸ�������� �����ϰڽ��ϴ�.\n");
	printf("\n");

	for(j; j<11;)
	{
		printf("�̸��� �Է����ּ���: ");
		scanf("%s", info[j].name);
		printf("���ϴ� ID�� �Է����ּ���: ");
		scanf("%s", info[j].ID);
		printf("��й�ȣ�� �Է����ּ���: ");
		scanf("%s", info[j].password);
		user_num++;
		j++;

		printf("\n���������� ȸ�����ԵǼ̽��ϴ�!!\n");
		printf("\n================================\n\n");
		login();
		break;
	}
}

void login()
{
	char name[10], ID[10], password[10];
	int i=1;

	printf("\n�α����� �����մϴ�.");
	printf("\n================================\n\n");

	while(i<user_num+1)
	{
		printf("�̸��� �Է����ּ���: ");
		scanf("%s", name);
		printf("ID�� �Է����ּ���: ");
		scanf("%s", ID);
		printf("��й�ȣ�� �Է����ּ���: ");
		scanf("%s", password);
		
		if(strcmp(name, info[i++].name)==0 && strcmp(ID, info[i++].ID)==0 && strcmp(password, info[i++].password)==0)
		{
			system("cls");
			printf("���������� �α��εǼ̽��ϴ�.!!\n");
			printf("ȯ���մϴ�. %s��~~", name);
			system("pause");
			user_menu();
		}
		else
		{
			printf("��ġ�ϴ� ������ �����ϴ�.\n");
			printf("�ٽ� �Է����ּ���.\n");
			printf("\n================================\n\n");
			login();
			system("pause");
			system("cls");
		}
	}
}

void user_menu()
{
	int num;

	while(1)
	{
		system("cls");

		printf("    <<�Ϲ�ȸ�� ��� �޴�>>        \n");
	    printf("============================\n");
	    printf("    1. ���� ���� �˻�           \n");
	    printf("    2.   ���� ����              \n");
	    printf("    3.   ���� �ݳ�              \n");
	    printf("    4. ��ü ���� ���           \n");
	    printf("    5. ���� ���� ����           \n");
	    printf("    6.   ȸ��  Ż��             \n");
	    printf("    7. �α��� �� ȭ������...    \n");
	    printf("    0.      ����                \n");
	    printf("===========================\n");
	    printf("���Ͻô� �޴��� �������ּ���.: ");
	    scanf("%d", &num);

	    if(num==1)
	    {
		    search_book();
	    }
	    else if(num==2)
	    {
		    borrow_book();
	    }
	    else if(num==3)
	    {
		    back_book();
	    }
	    else if(num==4)
	    {
		    display_all_book();
	    }
	    else if(num==5)
	    {
		    fix_user();
	    }
	    else if(num==6)
	    {
		    remove_user();
	    }
	    else if(num==7)
	    {
		    main();
	    }
	    else if(num==0)
 	    {
		    the_end();
	    }
	    else
	    {
		    printf("�߸��Է��ϼ̽��ϴ�.\n");
	        system("pause");
		    system("cls");
	    }
    }
}

void manager()
{
	int y;

	while(1)
	{
		system("cls");

		printf("    <<������ ��� �޴�>>        \n");
	    printf("============================\n");
	    printf("    1. ���� ���� �Է�           \n");
	    printf("    2. ���� ���� ����           \n");
	    printf("    3. ���� ���� ����           \n");
	    printf("    4. ���� ���� �˻�           \n");
	    printf("    5.   ���� ����              \n");
	    printf("    6.   ���� �ݳ�              \n");
	    printf("    7. ��ü ���� ���           \n");
		printf("    8. ��ü ȸ�� ���           \n");
		printf("    9. �α��� �� ȭ������...    \n");
	    printf("    0.     ����                \n");
	    printf("===========================\n");

        printf("���ϴ� ������ �Է��� �ּ���. : ");
        scanf("%d", &y);


		if(y==1)
		{
			add_book();
		}
		else if(y==2)
		{
			remove_book();
		}
		else if(y==3)
		{
			fix_book();
		}
		else if(y==4)
		{
			search_book();
		}
		else if(y==5)
		{
			borrow_book_manager();
		}
		else if(y==6)
		{
			back_book();
		}
		else if(y==7)
		{
			display_all_book();
		}
		else if(y==8)
		{
			display_all_user();
		}
		else if(y==9)
		{
			main();
		}
		else if(y==0)
		{
			the_end();
		}
		else
		{
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			system("pause");
			system("cls");
		}
	}
}

void add_book()
{
	if(a>=31)
	{
		printf("�� �̻� å�� �Է� �� �� �����ϴ�. \n");
	}
	else 
	{
		for(a; a<31;)
	    {
			printf("\n������ �Է��� �ּ��� : ");
			scanf("%s", chac[a].title);
			printf("���ǻ縦 �Է��� �ּ��� : ");
            scanf("%s", chac[a].publ);
			printf("�۰��� �Է��� �ּ��� : ");
            scanf("%s", chac[a].writer);
		    printf("���ǳ⵵�� �Է��� �ּ��� : ");
            scanf("%s", chac[a].year);
				
			book_num++;
			a++;
			printf("\n����Ǿ����ϴ�.\n\n");
			system("pause");
			break;
		}
	}
}

void remove_book()
{
	int del_a;
	int i;

	printf("������ ��ȣ�� �Է��� �ּ��� : ");
    scanf("%d", &del_a);
 
	if((del_a >= 1) && (del_a <= 30))
	{
		for(i=del_a; i<book_num+1; i++)
		{
			strcpy(chac[del_a].title, chac[i].title);
			strcpy(chac[del_a].publ, chac[i].publ);
			strcpy(chac[del_a].writer, chac[i].writer);
			strcpy(chac[del_a].year, chac[i].year);
		}
		book_num--;
		del_a--;
        printf("\n���� �߽��ϴ�.\n\n");
		system("pause");
		system("cls");
    }
}

void fix_book()
{
	int del_a;

	printf("������ ��ȣ�� �Է��� �ּ��� : ");
    scanf("%d", &del_a);
 
    if((del_a >= 1) && (del_a <= 31))
    {
		printf("������ �Է��� �ּ��� : ");
	    scanf("%s", chac[del_a].title);
		printf("���ǻ縦 �Է��� �ּ��� : ");
		scanf("%s", chac[del_a].publ);
		printf("�۰��� �Է��� �ּ��� : ");
		scanf("%s", chac[del_a].writer);
		printf("���ǳ⵵�� �Է��� �ּ��� : ");
		scanf("%s", chac[del_a].year);
              
        printf("\n���� �߽��ϴ�.\n\n");
		system("pause");
    }
    else
	{
		printf("�߸��� ��ȣ�� �Է��ϼ̽��ϴ�.\n\n");
		system("pause");
		system("cls");
	}
}

void display_all_book()
{
	int i;

	printf("\n��ü������ ����մϴ�.!!\n");
	printf("\n");
	
	for(i=1; i<book_num+1; i++)
	{
		printf("%d��\n", i);
		printf("���� : %s\n", chac[i].title);
		printf("���ǻ� : %s\n", chac[i].publ);
		printf("�۰� : %s\n", chac[i].writer);
		printf("���ǳ⵵ : %s\n", chac[i].year);
		printf("\n");

		continue;
		break;
    }
	system("pause");
}
			
void search_book()
{
	char c[30];
	int i, b;

	printf("\n1. ���� �˻�\n\n");
	printf("2. �۰� �˻� \n");

	printf("\n�˻� ����� �����ϼ��� : ");
	scanf("%d", &b);
			
	if (b == 1)
	{
		printf("\n�˻��� �ܾ �Է����ּ��� : ");
		scanf("%s",c);
				
		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].title,c)==0)
			{
				printf("\n���� ��ȣ : %d\n", i);
				printf("\n���� ���� : %s\n", chac[i].title);
				printf("���� ���ǻ� : %s\n", chac[i].publ);
				printf("���� ���� : %s\n", chac[i].writer);
				printf("���� ���ǳ⵵ : %s\n", chac[i].year);
				printf(" \n");
				system("pause");
			}
		}
	}
	else if (b == 2)
	{
		printf("\n�˻��� �ܾ �Է����ּ��� : ");
		scanf("%s",c);
				
		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].writer,c)==0)
			{
				printf("\n���� ��ȣ : %d\n", i);
				printf("\n���� ���� : %s\n", chac[i].title);
				printf("���� ���ǻ� : %s\n", chac[i].publ);
				printf("���� ���� : %s\n", chac[i].writer);
				printf("���� ���ǳ⵵ : %s\n", chac[i].year);
				printf(" \n");
				system("pause");
			}
		}
	}
	else 
	{
		printf("\n�߸��� ��ȣ�� �Է��߽��ϴ�.\n\n");
		system("pause");
	}
}

void borrow_book()
{
    char book_name[30], book_author[30];
	int num, i;

    printf("\n+++++++���� �޴�+++++++ \n\n");
	printf("1. ������ �˻�   2. �۰� �˻� \n");
	printf("\n�������� �������ּ���: ");
	scanf("%d", &num);

	if(num==1)
	{
		printf("������ �������� �Է��ϼ���: ");
        scanf("%s", book_name);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].title, book_name)==0)
		    {
				printf("\n���� ��ȣ : %d\n", i);
		        printf("���� ���� : %s\n", chac[i].title);
		        printf("���� ���ǻ� : %s\n", chac[i].publ);
		        printf("���� ���� : %s\n", chac[i].writer);
		        printf("���� ���ǳ⵵ : %s\n", chac[i].year);

                chac[i].checkout_flag = 1;

			    printf("������ �̸�:%s \n", info[i].name);
			    printf("������ ID:%s \n", info[i].ID);
			    printf("������ �Ϸ�Ǿ����ϴ�.!! \n");
			    printf(" \n");
		        system("pause");
		    }
		    else
            {
				printf("å�� ã�� �� �����ϴ�\n"); 
				system("pause");
            }
		}
	}
	else if(num==2)
	{
		printf("������ ������ �۰����� �Է��ϼ���.: ");
		scanf("%s", book_author);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].writer, book_author)==0)
		    {
				printf("\n���� ��ȣ : %d\n", i);
		        printf("���� ���� : %s\n", chac[i].title);
		        printf("���� ���ǻ� : %s\n", chac[i].publ);
		        printf("���� ���� : %s\n", chac[i].writer);
		        printf("���� ���ǳ⵵ : %s\n", chac[i].year);

                chac[i].checkout_flag = 1;

			    printf("������ �̸�:%s \n", info[i].name);
			    printf("������ ID:%s \n", info[i].ID);
			    printf("������ �Ϸ�Ǿ����ϴ�.!! \n");
			    printf(" \n");
		        system("pause");
		    }
		    else
            {
				printf("å�� ã�� �� �����ϴ�\n");
				system("pause");
            }
		}
	}
	else
    {
		printf("�߸��Է��ϼ̽��ϴ�.\n");
		system("pause");
    }
}

void back_book()
{
	int num, i;
    char book_name[30], book_author[30];

	printf("\n+++++++�ݳ� �޴�+++++++  \n\n");
	printf("1. ������ �˻�   2. �۰� �˻� \n");
	printf("\n�ݳ������ �������ּ���.: ");
	scanf("%d", &num);

	if(num==1)
	{
		printf("\n�������� �Է��ϼ���.: \n");
        scanf("%s", book_name);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].title, book_name)==0)
            {
				printf("%s å�� �ݳ��մϴ�.\n", chac[i].title);
                chac[i].checkout_flag = 0;
				system("pause");
            }
	    }
	}
	else if(num==2)
	{
		printf("�۰����� �Է��ϼ���.: \n");
		scanf("%s", book_author);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].writer, book_author)==0)
            {
				printf("%s å�� �ݳ��մϴ�.\n", chac[i].title);
                chac[i].checkout_flag = 0;
				system("pause");
            }
	    }
	}
	else
	{
		printf("\n�߸� �Է��ϼ̽��ϴ�.\n");
		system("pause");
	}
}

void fix_user()
{
	int del_a;

	printf("������ ��ȣ�� �Է��� �ּ��� : ");
    scanf("%d", &del_a);
 
    if((del_a >= 1) && (del_a <= 10))
    {
		printf("�̸��� �Է��� �ּ��� : ");
	    scanf("%s", info[del_a].name);
		printf("ID�� �Է��� �ּ��� : ");
		scanf("%s", info[del_a].ID);
		printf("�н����带 �Է��� �ּ��� : ");
		scanf("%s", info[del_a].password);
              
        printf("\n���� �߽��ϴ�.\n\n");
		system("pause");
    }
    else
	{
		printf("�߸��� ��ȣ�� �Է��ϼ̽��ϴ�.\n\n");
		system("pause");
	}
}

void display_all_user()
{
	int j;

	printf("��ü ȸ���� ����մϴ�.!!\n");
	printf("\n");

	for(j=1; j<user_num+1; j++)
	{
		printf("%d��\n", j);
		printf("�̸� : %s\n", info[j].name);
		printf("���̵� : %s\n", info[j].ID);
		printf("��й�ȣ : %s\n", info[j].password);
		printf("\n");

		continue;
		break;
    }
	system("pause");
}

void remove_user()
{
	int del_a;
	int i;

	printf("������ ��ȣ�� �Է��� �ּ��� : ");
    scanf("%d", &del_a);
 
	if((del_a >= 1) && (del_a <= 10))
	{
		for(i=del_a; i<user_num+1; i++)
		{
			strcpy(info[del_a].name, info[i].name);
			strcpy(info[del_a].ID, info[i].ID);
			strcpy(info[del_a].password, info[i].password);
		}
		user_num--;
		j--;
		printf("\n���� �߽��ϴ�.\n\n");
		system("pause");
		system("cls");
    }
}

void borrow_book_manager()
{
	char Name[]= "������";
	char id[]= "manager";
	char book_name[30], book_author[30];
	int num, i;

    printf("\n+++++++���� �޴�+++++++ \n\n");
	printf("1. ������ �˻�   2. �۰� �˻� \n");
	printf("\n�������� �������ּ���: ");
	scanf("%d", &num);

	if(num==1)
	{
		printf("\n������ �������� �Է��ϼ���.: ");
        scanf("%s", book_name);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].title, book_name)==0)
		    {
				printf("\n���� ��ȣ : %d\n", i);
		        printf("���� ���� : %s\n", chac[i].title);
		        printf("���� ���ǻ� : %s\n", chac[i].publ);
		        printf("���� ���� : %s\n", chac[i].writer);
		        printf("���� ���ǳ⵵ : %s\n", chac[i].year);

                chac[i].checkout_flag = 1;

			    printf("\n������ �̸�:%s \n", Name);
			    printf("������ ID:%s \n", id);
			    printf("\n������ �Ϸ�Ǿ����ϴ�.!! \n");
			    printf(" \n");
		        system("pause");
		    }
		}
	}
	else if(num==2)
	{
		printf("\n������ ������ �۰����� �Է��ϼ���.: ");
		scanf("%s", book_author);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].writer, book_author)==0)
		    {
				printf("\n���� ��ȣ : %d\n", i);
		        printf("���� ���� : %s\n", chac[i].title);
		        printf("���� ���ǻ� : %s\n", chac[i].publ);
		        printf("���� ���� : %s\n", chac[i].writer);
		        printf("���� ���ǳ⵵ : %s\n", chac[i].year);

                chac[i].checkout_flag = 1;

			    printf("\n������ �̸�: %s \n", Name);
			    printf("������ ID: %s \n", id);
			    printf("\n������ �Ϸ�Ǿ����ϴ�.!! \n");
			    printf(" \n");
		        system("pause");
		    }
		}
	}
	else
	{
		printf("\n�߸� �Է��ϼ̽��ϴ�.\n");
		system("pause");
	}
}

int the_end()
{
	system("cls");
    printf("======���α׷��� �����մϴ�.====== \n");
	exit(0);
}