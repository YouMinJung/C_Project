# < C project > Make some program using C

#### Environment : Visual Studio 2010 in Windows, Vi Editor in Ubuntu
#### Language : C

<br><br>

# Book Mangement System ver.1 - 2015.06
<p> 총 도서권수 30권, 회원수 10명인 도서관리시스템</p>
<p> Array를 정적할당, 동적 할당 등을 이용하여 간단한 시스템 제작 <p> 

##### Program Structure
![default](https://user-images.githubusercontent.com/21214309/48597802-05243480-e9a3-11e8-8c3e-fd9b433161d3.JPG)

- 관리자와 회원의 역할로 구분되며, 기본적 도서관 시스템을 제공

<br><br>

# Book Mangement System ver.2 - 2015.12
<p> 회원과 도서 정보는 연결리스트 구조체로 구현하여 지속적 추가 가능</p>
<p> Linked List 및 파일 입출력 등을 이용하여 기존 시스템의 업그레이드 된 시스템 제작 <p> 

##### Program Structure
![default](https://user-images.githubusercontent.com/21214309/48597955-d78bbb00-e9a3-11e8-9da8-6157a8dcb9c9.JPG)


- 회원과 관리자에 더하여 게스트기능 추가
- 연결리스트 + 파일입출력(프로그램 실행 시 load, 종료 시 save)
- 포인터를 이용하여 추가, 수정, 삭제, 출력, 검색 구현
- 판매 결과 출력 + 도서 구매, 대여, 환불, 반납
- 이벤트 (quiz, baseball 게임) -> 특정 점수 이상 획득 시 시리얼 코드 부여 -> 입력 시 상품 지급 + 시리얼 코드 동적 할당
- 베스트 셀러 출력 (정렬 사용)
- 회원 등급(구매금액에 따라 차등 지정)

<br><br>

# Operating System (HRRN) - 2017.06
<p> Operating system Scheduling 기법의 하나인 HRRN 시뮬레이션을 C로 구현 </p><br>

- HRRN은 Highest Response Ratio Next로 프로세스 처리의 우선순위를 CPU 처리 기간과 해당 프로세스의 대기 시간을 동시에 고려해 선정하는 스케줄링 알고리즘이다. 즉, R = waiting time + service time / service time을 이용해 R값이 큰 process부터 수행한다. (수행되던 process가 exit하게 되면 suspend/block되었던 process들 중에서 R값이 가장 큰 process가 선택되어 running state로 된다.) 
  따라서 이 프로그램은 FCFS의 방식을 그대로 따라가되, dequeue할 때 R값의 크기를 측정하여 가장 큰 process를 꺼낸다. 이런 방식으로 running state process를 선정하며 선정된 process는 t값의 증가량과 자신이 가진 service time이 같아지게 되면 exit한다. 위의 그림과 같은 구조대로 process state가 변하며, HRRN.c는 new와 suspend/block state를 모두 Not Running state로 간주한다. <br> 

![noname03](https://user-images.githubusercontent.com/21214309/48598353-c93e9e80-e9a5-11e8-866f-202f173b7d0b.png)

- processes가 모두 exit state가 되면 program의 큰 틀은 끝난 것이며 마지막으로 process log informations(waiting time, turnaround time, entry time, response time 등)와 이들의 통계 정보를 출력한다. 


##### Program Structure
![noname01](https://user-images.githubusercontent.com/21214309/48598208-14a47d00-e9a5-11e8-8622-ca0dc6a7bb8c.png)

##### 자료구조
![noname05](https://user-images.githubusercontent.com/21214309/48598371-dfe4f580-e9a5-11e8-80f1-8df12b210c66.png)
![noname06](https://user-images.githubusercontent.com/21214309/48598372-e07d8c00-e9a5-11e8-9bcb-cbb81ce8fef0.png)

- 이 프로그램에서 사용하는 자료는 process 정보와 이들의 상태를 저장하기 위한 queue이다. 먼저 process는 Process라는 구조체 구조를 가진 process_list가 위와 같이 존재하며 이는 각각의 process들의 정보를 담고 있다. (배열과 같은 방식으로 사용가능)

- queue는 단순 일차원 배열을 사용하였으며 생성된 process가 not running state로 (suspend state) 전환될 시 전환 순서대로 배열의 index=1부터 enqueue된다. (queue_size 값을 index값으로 사용하였기 때문에, 0은 비어있는 상태로 정의하였다.) 이때 process_queue에는 process_list의 index 값이 저장된다. CPU가 idle이 되면 suspend되었던 process중 하나(R 값이 큰 process)가 dequeue된다.

##### Execute Result
<img width="414" alt="fcfs" src="https://user-images.githubusercontent.com/21214309/48598515-93e68080-e9a6-11e8-8958-b97c2e7891d1.PNG">

<br><br>

# Linux Shell - 2017.12
<p> 리눅스의 Shell을 모방하여 Myshell이라는 나만의 Shell을 구현 </p>
![default](https://user-images.githubusercontent.com/21214309/48598774-e4121280-e9a7-11e8-9c59-152799c3c28e.JPG)

<p> Main Command는 Parent가 진행하고 각각의 명령어는 Child가 진행한다. <br>

- 기존의 Shell에는 존재하지 않는, Client1과 client2가 server의 중재 하에 토론을 진행하는 프로그램 pchatt을 추가
![default](https://user-images.githubusercontent.com/21214309/48598693-77971380-e9a7-11e8-8269-b314780902b9.JPG)

- Fork() 및 Pipe의 개념을 이용하여 구현함 
1) Server가 누가 먼저 발언할 것인지 묻는다.
2) 발언을 먼저 하고자 하는 process의 이름을 적는다.
3) 적힌 process부터 발언을 시작한다.
4) 대화는 순차적으로 넘어간다. ( ex) client1부터 시작했으면 다음은 client2, 그 다음은 client1 … )
5) 일정 대화 이후 server가 다시 대화 순서를 묻는다. (Turn Change입력 시…)
6) 위 과정과 같이 토론을 계속 진행한다.
7) 토론 중 참여자가 bye를 외치며 토론을 빠져나가면 토론을 중단한다. 

##### PDF File : [Linux_Project.pdf](https://github.com/YouMinJung/C_Project/files/2588020/Linux_Project.pdf)
