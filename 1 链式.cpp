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

void InitList(SListInfo &L);					//构造空链表 
int DestroyList(SListInfo &L);					//销毁现性表  
int SetElem(SListInfo &L, int i, int e);		//输出元素
int DeleteElem(SListInfo &L, int i, int &e);	//插入元素
void tailInsert( SListInfo &L , int data );		//创建链表(尾插法)
void Bubble_sort(SListInfo &L);					//冒泡排序 
void PrintList( SListInfo &L );				//遍历链表打印

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

void Bubble_sort(SListInfo &L)					//冒泡排序 时间复杂度O(n*n) 
{
	int t=0; 
	do{
		t=0;					
		LNode* cur=L.head->next   ;
		while(cur->next )
		{
			if( cur->data > cur->next->data ) 			//前面比后面大 交换位置 
			{
				int temp=cur->data ;
				cur->data = cur->next->data; 
				cur->next->data = temp; 
				t=1;									//发生交换 
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
		cout<<"创建链表头失败"<<endl;
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
		cout<<"输入位置有误"<<endl;
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
		cout<<"输入位置有误"<<endl;
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
void tailInsert( SListInfo &L , int data )	//创建链表(尾插法)
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
	  	LNode* p=L.head ;							//当前指针 
  		while( p->next != NULL )
		{
			p = p->next ;						//循环走到尾节点
		}
		p->next = temp ;						//尾节点接上新节点 
	}	
	L.length ++;
}
void PrintList( SListInfo &L )				//遍历链表打印 
{
	LNode* p = L.head  ;
	p = p->next ;
	cout<<"链表存储数据为："; 
	while(p!=NULL)
	{
		cout<<p->data <<" " ;
		p = p->next ;
	}
	cout<<endl;
}
