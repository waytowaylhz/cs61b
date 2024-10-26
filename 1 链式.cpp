#include <iostream>
using namespace std;

struct LNode 
{
	int data;
	LNode* next;
};
struct SListInfo
{
	LNode* head;
	LNode* tail;
	LNode* pCurNode ;
	int length;
};

void InitList(SListInfo &L);					//��������� 
int DestroyList(SListInfo &L);					//�������Ա�  
int SetElem(SListInfo &L, int i, int e);		//���Ԫ��
int DeleteElem(SListInfo &L, int i, int &e);	//����Ԫ��
void tailInsert( SListInfo &L , int data );		//��������(β�巨)
void Bubble_sort(SListInfo &L);					//ð������ 
void PrintList( SListInfo &L );				//���������ӡ

int main()
{
	SListInfo List;
	InitList( List );
	
	tailInsert( List , 4 );
	tailInsert( List , 2 );
	tailInsert( List , 3 );
	tailInsert( List , 1 );
	PrintList( List );
	Bubble_sort(List);
	
	PrintList( List );
	//LNode* cur=List.head->next->next   ;
	//cout<<cur->data ;
	
	return 0;
} 

void Bubble_sort(SListInfo &L)					//ð������ ʱ�临�Ӷ�O(n*n) 
{
	int t=0; 
	do{
		t=0;					
		LNode* cur=L.head->next   ;
		while(cur->next )
		{
			if( cur->data > cur->next->data ) 			//ǰ��Ⱥ���� ����λ�� 
			{
				int temp=cur->data ;
				cur->data = cur->next->data; 
				cur->next->data = temp; 
				t=1;									//�������� 
			}
			cur=cur->next ;
		}	
	}while(t==1);
}
void InitList(SListInfo &L)
{
	L.head = new LNode;
	if(L.head == NULL )
	{
		cout<<"��������ͷʧ��"<<endl;
		return;
	}
	L.head->next = NULL;
	L.tail = L.head ;
	L.pCurNode = L.head ; 
	L.length = 0 ;
}

int DestroyList(SListInfo &L) 
{
    LNode* cur = L.head;
    while ( cur != NULL ) 
	{
        LNode* nextNode = cur->next;
        delete cur;  
        cur = nextNode;
    }
    L.head = NULL;
    L.tail = NULL;
    L.pCurNode = NULL;
    L.length = 0;
    return 1;
}

int SetElem(SListInfo &L, int i, int e) 
{
    if (i < 1 || i > L.length + 1)
	{
		cout<<"����λ������"<<endl;
		return 0;  
	} 
    LNode* cur = L.head->next;
    for (int p = 1; p < i; p++) {
        cur = cur->next;
    }
    cur->data = e;  
    L.pCurNode = cur;
    return 1; 
}

void InsertElem( SListInfo &L , int i , int e ) 
{
    if (i < 1 || i > L.length + 1)
	{
		cout<<"����λ������"<<endl;
		return ;  
	} 
    LNode* temp = new LNode();
    temp->data = e;
    LNode* cur = L.head;
    for ( int j = 1; j < i; j++ ) {
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;
    if (temp->next == NULL) {
        L.tail = temp;
    }
    L.length++;
}
void tailInsert( SListInfo &L , int data )	//��������(β�巨)
{
	
	LNode* temp=new LNode();  
	temp->data = data ;
	temp->next = NULL ;
	if( L.head->next ==NULL )
	{
		L.head->next = temp ;
  	}
  	else
  	{
	  	LNode* p=L.head ;							//��ǰָ�� 
  		while( p->next != NULL )
		{
			p = p->next ;						//ѭ���ߵ�β�ڵ�
		}
		p->next = temp ;						//β�ڵ�����½ڵ� 
	}	
	L.length ++;
}
void PrintList( SListInfo &L )				//���������ӡ 
{
	LNode* p = L.head  ;
	p = p->next ;
	cout<<"����洢����Ϊ��"; 
	while(p!=NULL)
	{
		cout<<p->data <<" " ;
		p = p->next ;
	}
	cout<<endl;
}
