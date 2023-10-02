#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{
	Node * head; // 더미 노드를 가리키는 멤버
	Node * cur; // 참조 및 삭제를 돕는 멤버
	Node * before; // 삭제를 돕는 멤버
	int numOfData; // 저장된 데이터의 수를 기록하기 위한 멤버
	int (*comp)(LData d1, LData d2); // 정렬의 기준을 등록하기 위한 멤버
} LinkedList;


typedef LinkedList List;

void ListInit(List * plist);
// 초기화할 리스트의 주소 값을 인자로 전달
// 리스트 생성 후 제일 먼저 호출되어야 할 함수

void LInsert(List * plist, LData data);
// 리스트에 데이터 저장, 매개변수 data에 전달된 값 저장

int LFirst(List * plist, LData * pdata);
// 첫 번째 데이터가 pdata가 가리키는 메모리에 저장됨
// 데이터의 참조를 위한 초기화가 진행 됨
// 참조 성공시 True, 실패시 False 반환

int LNext(List * plist, LData * pdata);
// 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장됨.
// 순차적인 참조를 위해서 반복 호출이 가능
// 참조를 새로 시작하려면 먼저 LFirst 함수 호출
// 참조 성공시 True, 실패시 False 반환

LData LRemove(List * plist);
// LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제
// 삭제된 데이터는 반환된다.
// 마지막 반환 데이터를 삭제하므로 연이은 반복 호출  허용 X

int LCount(List * plist);
// 리스트에 저장되어 있는 데이터의 수 반환

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));
// 리스트에 정렬의 기준이 되는 함수를 등록한다.
#endif