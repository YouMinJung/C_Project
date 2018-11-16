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

# Operating System (HRRN) - 2016
<p> Operating system Scheduling 기법의 하나인 HRRN 시뮬레이션을 C로 구현 </p><br>

- HRRN은 Highest Response Ratio Next로 프로세스 처리의 우선순위를 CPU 처리 기간과 해당 프로세스의 대기 시간을 동시에 고려해 선정하는 스케줄링 알고리즘이다. 즉, R = waiting time + service time / service time을 이용해 R값이 큰 process부터 수행한다. (수행되던 process가 exit하게 되면 suspend/block되었던 process들 중에서 R값이 가장 큰 process가 선택되어 running state로 된다.) 
  따라서 이 프로그램은 FCFS의 방식을 그대로 따라가되, dequeue할 때 R값의 크기를 측정하여 가장 큰 process를 꺼낸다. 이런 방식으로 running state process를 선정하며 선정된 process는 t값의 증가량과 자신이 가진 service time이 같아지게 되면 exit한다. 위의 그림과 같은 구조대로 process state가 변하며, HRRN.c는 new와 suspend/block state를 모두 Not Running state로 간주한다. <br> 

![noname03](https://user-images.githubusercontent.com/21214309/48598353-c93e9e80-e9a5-11e8-866f-202f173b7d0b.png)

- processes가 모두 exit state가 되면 program의 큰 틀은 끝난 것이며 마지막으로 process log informations(waiting time, turnaround time, entry time, response time 등)와 이들의 통계 정보를 출력한다. 


##### Program Structure
![noname01](https://user-images.githubusercontent.com/21214309/48598208-14a47d00-e9a5-11e8-8622-ca0dc6a7bb8c.png)

##### 자료구조
-

