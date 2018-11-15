#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book  //도서와 관련된 구조체
{
	char title[30];
	char publ[30];
    char writer[30];
	char year[30];
	int checkout_flag;  
}book;

typedef struct user  //회원과 관련된 구조체
{
	char name[10];
	char ID[10];
	char password[10];
}user;

int book_num=0; //전체 도서 수
int user_num=0; //전체 회원 수
user info[10]; //회원과 관련된 문자열
book chac[30]; //도서와 관련된 문자열
int a=1; // book추가
int j=1; // user추가

void login(); //로그인
void manager(); //관리자 메뉴
void user_menu(); //일반회원 메뉴
void search_book(); //도서 검색
void borrow_book(); //도서 대출
void borrow_book_manager(); //도서 대출-관리자용
void back_book(); //도서 반납
void display_all_book(); //전체 도서 출력
void display_all_user(); //전체 회원 출력
void add_book(); // 도서 추가
void add_user(); //회원 추가(회원가입)
void remove_book(); //도서 삭제
void remove_user(); //회원 삭제(회원 탈퇴)
void fix_book(); //도서 정보 수정
void fix_user(); //회원 정보 수정
int the_end(); //프로그램 종료

int main(void)
{
    int num;
	int x;
	char name[10];
	char ID[10];
	char password[10];

	char Name[]= "관리자";
	char id[]= "manager";
	char Password[]= "0000";

	system("cls");
	printf("<<★ 도서 관리 프로그램을 시작합니다. ★>> \n\n");
	system("pause");

	system("cls");
	printf("도서관 관리자이십니까? <yes:1  no:2> : ");
	scanf("%d", &num);
	printf("\n========================================\n");

	if(num==1)
	{
		printf("\n로그인을 시작합니다. \n");
		printf("\n");
		printf("이름을 입력해주세요 : ");
		scanf("%s", name);

		if(strcmp(name, Name)==0)
		{
			printf("아이디를 입력해주세요 : ");
		    scanf("%s", ID);

			if(strcmp(ID, id)==0)
			{
				printf("비밀번호를 입력해주세요 : ");
		        scanf("%s", password);

				if(strcmp(password, Password)==0)
				{
					system("cls");
					printf("====================================\n");
					printf("\n로그인에 성공했습니다. \n");
                    printf("\n관리자 모드를 시작하겠습니다. \n\n");
					printf("====================================\n");
                    system("pause");
					manager();
				}
			}
		}
		else
		{
			printf("\n\n[잘못된 정보를 입력하셨습니다, 처음으로 돌아갑니다.]\n\n\n");
			system("pause");
			main();
	    }
	}
	else if(num==2)
	{
		system("cls");

		printf("도서관 일반회원이십니까? <yes:1 no:2> : ");
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
			printf("잘못입력하셨습니다.\n");
		    system("pause");
		    system("cls");
			main();
		}	
	}
	else
	{
		printf("잘못입력하셨습니다.\n");
		system("pause");
		system("cls");
		main();
	}
}

void add_user()
{
	printf("\n회원가입을 시작하겠습니다.\n");
	printf("\n");

	for(j; j<11;)
	{
		printf("이름을 입력해주세요: ");
		scanf("%s", info[j].name);
		printf("원하는 ID를 입력해주세요: ");
		scanf("%s", info[j].ID);
		printf("비밀번호를 입력해주세요: ");
		scanf("%s", info[j].password);
		user_num++;
		j++;

		printf("\n정상적으로 회원가입되셨습니다!!\n");
		printf("\n================================\n\n");
		login();
		break;
	}
}

void login()
{
	char name[10], ID[10], password[10];
	int i=1;

	printf("\n로그인을 시작합니다.");
	printf("\n================================\n\n");

	while(i<user_num+1)
	{
		printf("이름을 입력해주세요: ");
		scanf("%s", name);
		printf("ID를 입력해주세요: ");
		scanf("%s", ID);
		printf("비밀번호를 입력해주세요: ");
		scanf("%s", password);
		
		if(strcmp(name, info[i++].name)==0 && strcmp(ID, info[i++].ID)==0 && strcmp(password, info[i++].password)==0)
		{
			system("cls");
			printf("정상적으로 로그인되셨습니다.!!\n");
			printf("환영합니다. %s님~~", name);
			system("pause");
			user_menu();
		}
		else
		{
			printf("일치하는 정보가 없습니다.\n");
			printf("다시 입력해주세요.\n");
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

		printf("    <<일반회원 모드 메뉴>>        \n");
	    printf("============================\n");
	    printf("    1. 도서 정보 검색           \n");
	    printf("    2.   도서 대출              \n");
	    printf("    3.   도서 반납              \n");
	    printf("    4. 전체 도서 출력           \n");
	    printf("    5. 개인 정보 수정           \n");
	    printf("    6.   회원  탈퇴             \n");
	    printf("    7. 로그인 전 화면으로...    \n");
	    printf("    0.      종료                \n");
	    printf("===========================\n");
	    printf("원하시는 메뉴를 선택해주세요.: ");
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
		    printf("잘못입력하셨습니다.\n");
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

		printf("    <<관리자 모드 메뉴>>        \n");
	    printf("============================\n");
	    printf("    1. 도서 정보 입력           \n");
	    printf("    2. 도서 정보 삭제           \n");
	    printf("    3. 도서 정보 수정           \n");
	    printf("    4. 도서 정보 검색           \n");
	    printf("    5.   도서 대출              \n");
	    printf("    6.   도서 반납              \n");
	    printf("    7. 전체 도서 출력           \n");
		printf("    8. 전체 회원 출력           \n");
		printf("    9. 로그인 전 화면으로...    \n");
	    printf("    0.     종료                \n");
	    printf("===========================\n");

        printf("원하는 동작을 입력해 주세요. : ");
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
			printf("잘못입력하셨습니다.\n");
			system("pause");
			system("cls");
		}
	}
}

void add_book()
{
	if(a>=31)
	{
		printf("더 이상 책을 입력 할 수 없습니다. \n");
	}
	else 
	{
		for(a; a<31;)
	    {
			printf("\n제목을 입력해 주세요 : ");
			scanf("%s", chac[a].title);
			printf("출판사를 입력해 주세요 : ");
            scanf("%s", chac[a].publ);
			printf("작가를 입력해 주세요 : ");
            scanf("%s", chac[a].writer);
		    printf("출판년도를 입력해 주세요 : ");
            scanf("%s", chac[a].year);
				
			book_num++;
			a++;
			printf("\n저장되었습니다.\n\n");
			system("pause");
			break;
		}
	}
}

void remove_book()
{
	int del_a;
	int i;

	printf("삭제할 번호를 입력해 주세요 : ");
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
        printf("\n삭제 했습니다.\n\n");
		system("pause");
		system("cls");
    }
}

void fix_book()
{
	int del_a;

	printf("수정할 번호를 입력해 주세요 : ");
    scanf("%d", &del_a);
 
    if((del_a >= 1) && (del_a <= 31))
    {
		printf("제목을 입력해 주세요 : ");
	    scanf("%s", chac[del_a].title);
		printf("출판사를 입력해 주세요 : ");
		scanf("%s", chac[del_a].publ);
		printf("작가를 입력해 주세요 : ");
		scanf("%s", chac[del_a].writer);
		printf("출판년도를 입력해 주세요 : ");
		scanf("%s", chac[del_a].year);
              
        printf("\n수정 했습니다.\n\n");
		system("pause");
    }
    else
	{
		printf("잘못된 번호를 입력하셨습니다.\n\n");
		system("pause");
		system("cls");
	}
}

void display_all_book()
{
	int i;

	printf("\n전체도서를 출력합니다.!!\n");
	printf("\n");
	
	for(i=1; i<book_num+1; i++)
	{
		printf("%d번\n", i);
		printf("제목 : %s\n", chac[i].title);
		printf("출판사 : %s\n", chac[i].publ);
		printf("작가 : %s\n", chac[i].writer);
		printf("출판년도 : %s\n", chac[i].year);
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

	printf("\n1. 제목 검색\n\n");
	printf("2. 작가 검색 \n");

	printf("\n검색 방법을 선택하세요 : ");
	scanf("%d", &b);
			
	if (b == 1)
	{
		printf("\n검색할 단어를 입력해주세요 : ");
		scanf("%s",c);
				
		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].title,c)==0)
			{
				printf("\n도서 번호 : %d\n", i);
				printf("\n도서 제목 : %s\n", chac[i].title);
				printf("도서 출판사 : %s\n", chac[i].publ);
				printf("도서 저자 : %s\n", chac[i].writer);
				printf("도서 출판년도 : %s\n", chac[i].year);
				printf(" \n");
				system("pause");
			}
		}
	}
	else if (b == 2)
	{
		printf("\n검색할 단어를 입력해주세요 : ");
		scanf("%s",c);
				
		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].writer,c)==0)
			{
				printf("\n도서 번호 : %d\n", i);
				printf("\n도서 제목 : %s\n", chac[i].title);
				printf("도서 출판사 : %s\n", chac[i].publ);
				printf("도서 저자 : %s\n", chac[i].writer);
				printf("도서 출판년도 : %s\n", chac[i].year);
				printf(" \n");
				system("pause");
			}
		}
	}
	else 
	{
		printf("\n잘못된 번호를 입력했습니다.\n\n");
		system("pause");
	}
}

void borrow_book()
{
    char book_name[30], book_author[30];
	int num, i;

    printf("\n+++++++대출 메뉴+++++++ \n\n");
	printf("1. 도서명 검색   2. 작가 검색 \n");
	printf("\n대출방법을 선택해주세요: ");
	scanf("%d", &num);

	if(num==1)
	{
		printf("대출할 도서명을 입력하세요: ");
        scanf("%s", book_name);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].title, book_name)==0)
		    {
				printf("\n도서 번호 : %d\n", i);
		        printf("도서 제목 : %s\n", chac[i].title);
		        printf("도서 출판사 : %s\n", chac[i].publ);
		        printf("도서 저자 : %s\n", chac[i].writer);
		        printf("도서 출판년도 : %s\n", chac[i].year);

                chac[i].checkout_flag = 1;

			    printf("대출자 이름:%s \n", info[i].name);
			    printf("대출자 ID:%s \n", info[i].ID);
			    printf("대출이 완료되었습니다.!! \n");
			    printf(" \n");
		        system("pause");
		    }
		    else
            {
				printf("책을 찾을 수 없습니다\n"); 
				system("pause");
            }
		}
	}
	else if(num==2)
	{
		printf("대출할 도서의 작가명을 입력하세요.: ");
		scanf("%s", book_author);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].writer, book_author)==0)
		    {
				printf("\n도서 번호 : %d\n", i);
		        printf("도서 제목 : %s\n", chac[i].title);
		        printf("도서 출판사 : %s\n", chac[i].publ);
		        printf("도서 저자 : %s\n", chac[i].writer);
		        printf("도서 출판년도 : %s\n", chac[i].year);

                chac[i].checkout_flag = 1;

			    printf("대출자 이름:%s \n", info[i].name);
			    printf("대출자 ID:%s \n", info[i].ID);
			    printf("대출이 완료되었습니다.!! \n");
			    printf(" \n");
		        system("pause");
		    }
		    else
            {
				printf("책을 찾을 수 없습니다\n");
				system("pause");
            }
		}
	}
	else
    {
		printf("잘못입력하셨습니다.\n");
		system("pause");
    }
}

void back_book()
{
	int num, i;
    char book_name[30], book_author[30];

	printf("\n+++++++반납 메뉴+++++++  \n\n");
	printf("1. 도서명 검색   2. 작가 검색 \n");
	printf("\n반납방법을 선택해주세요.: ");
	scanf("%d", &num);

	if(num==1)
	{
		printf("\n도서명을 입력하세요.: \n");
        scanf("%s", book_name);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].title, book_name)==0)
            {
				printf("%s 책을 반납합니다.\n", chac[i].title);
                chac[i].checkout_flag = 0;
				system("pause");
            }
	    }
	}
	else if(num==2)
	{
		printf("작가명을 입력하세요.: \n");
		scanf("%s", book_author);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].writer, book_author)==0)
            {
				printf("%s 책을 반납합니다.\n", chac[i].title);
                chac[i].checkout_flag = 0;
				system("pause");
            }
	    }
	}
	else
	{
		printf("\n잘못 입력하셨습니다.\n");
		system("pause");
	}
}

void fix_user()
{
	int del_a;

	printf("수정할 번호를 입력해 주세요 : ");
    scanf("%d", &del_a);
 
    if((del_a >= 1) && (del_a <= 10))
    {
		printf("이름을 입력해 주세요 : ");
	    scanf("%s", info[del_a].name);
		printf("ID를 입력해 주세요 : ");
		scanf("%s", info[del_a].ID);
		printf("패스워드를 입력해 주세요 : ");
		scanf("%s", info[del_a].password);
              
        printf("\n수정 했습니다.\n\n");
		system("pause");
    }
    else
	{
		printf("잘못된 번호를 입력하셨습니다.\n\n");
		system("pause");
	}
}

void display_all_user()
{
	int j;

	printf("전체 회원을 출력합니다.!!\n");
	printf("\n");

	for(j=1; j<user_num+1; j++)
	{
		printf("%d번\n", j);
		printf("이름 : %s\n", info[j].name);
		printf("아이디 : %s\n", info[j].ID);
		printf("비밀번호 : %s\n", info[j].password);
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

	printf("삭제할 번호를 입력해 주세요 : ");
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
		printf("\n삭제 했습니다.\n\n");
		system("pause");
		system("cls");
    }
}

void borrow_book_manager()
{
	char Name[]= "관리자";
	char id[]= "manager";
	char book_name[30], book_author[30];
	int num, i;

    printf("\n+++++++대출 메뉴+++++++ \n\n");
	printf("1. 도서명 검색   2. 작가 검색 \n");
	printf("\n대출방법을 선택해주세요: ");
	scanf("%d", &num);

	if(num==1)
	{
		printf("\n대출할 도서명을 입력하세요.: ");
        scanf("%s", book_name);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].title, book_name)==0)
		    {
				printf("\n도서 번호 : %d\n", i);
		        printf("도서 제목 : %s\n", chac[i].title);
		        printf("도서 출판사 : %s\n", chac[i].publ);
		        printf("도서 저자 : %s\n", chac[i].writer);
		        printf("도서 출판년도 : %s\n", chac[i].year);

                chac[i].checkout_flag = 1;

			    printf("\n대출자 이름:%s \n", Name);
			    printf("대출자 ID:%s \n", id);
			    printf("\n대출이 완료되었습니다.!! \n");
			    printf(" \n");
		        system("pause");
		    }
		}
	}
	else if(num==2)
	{
		printf("\n대출할 도서의 작가명을 입력하세요.: ");
		scanf("%s", book_author);

		for(i=1; i<book_num+1; i++)
		{
			if(strcmp(chac[i].writer, book_author)==0)
		    {
				printf("\n도서 번호 : %d\n", i);
		        printf("도서 제목 : %s\n", chac[i].title);
		        printf("도서 출판사 : %s\n", chac[i].publ);
		        printf("도서 저자 : %s\n", chac[i].writer);
		        printf("도서 출판년도 : %s\n", chac[i].year);

                chac[i].checkout_flag = 1;

			    printf("\n대출자 이름: %s \n", Name);
			    printf("대출자 ID: %s \n", id);
			    printf("\n대출이 완료되었습니다.!! \n");
			    printf(" \n");
		        system("pause");
		    }
		}
	}
	else
	{
		printf("\n잘못 입력하셨습니다.\n");
		system("pause");
	}
}

int the_end()
{
	system("cls");
    printf("======프로그램을 종료합니다.====== \n");
	exit(0);
}