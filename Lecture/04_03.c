// 연결리스트 정렬 / 삽입 구현

/*
연결리스트에서 SetSortRule함수를 통해 정렬 기준을 정한다.
(LinkedList 멤버 comp에 저장)
A, B 사이에 노드를 삽입하기 위해서는 A, B 노드의 주소를 알아야 함.
--> 처음에 Pred라는 노드가 더미노드를 가리키게 설정.

pred->next != NULL // 마지막 노드인지 확인하는 조건
plist->comp(data,pred->next->data) != 0
여기서 data는 삽입하려는 data값,
pred->next->data는 pred 다음 노드의 값, 즉 비교하려는 노드의 데이터다.
comp의 리턴값이 0 : 인수 a(삽입 데이터), b에서 
a(삽입)가 b(기존)보다 앞선다.
comp의 리턴값이 1 : 인수 a(삽입데이터), b에서 
b(기존)가 a(삽입)보다 앞선다.
따라서 리턴값이 1이라면 pred는 계속 뒤로 이동해서 비교해야 한다.
*/