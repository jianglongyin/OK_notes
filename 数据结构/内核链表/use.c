//头文件
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;



//数据节点结构体声明
typedef struct node		//大结构体：存放数据
{
	Datatype data;
	struct list_head list;		//小结构体：存放前驱指针和后继指针
}Node, *Link;



//初始化链表
Link init_list()
{
	//创建节点
	Link head = malloc( sizeof( Node ) ) ;
	//创建纯粹链表
	if ( head != NULL )
	{
		INIT_LIST_HEAD( &( head->list ) ) ;
	}
	return head ; 
}
//创建节点
Link head = malloc( sizeof( struct node ) ) ;

//给大结构体里的数据域放入数据
int a ;
    Link new = malloc( sizeof( struct node ) );
	if ( new != NULL )
	{
		new->data = a ;
		new->list.prev = NULL ;
		new->list.next = NULL ;
	}

//头插
list_add( &( new -> list ) , &( head -> list ) ) ;
//尾插
list_add_tail( &( new -> list ) , &( head -> list ) ) ;


//创建节点
Link create_node( Datatype data )
{
	Link new = malloc( sizeof( Node ) ) ;
	if ( new != NULL )
	{
		new->data = data ;
		new->list.prev = NULL ;
		new->list.next = NULL ;
	}
	return new ;
}

//遍历
void display(Link head)
{
	Link Node_p = NULL;
	Link N = NULL;
	list_for_each_entry_safe(Node_p, N, &(head->list), list)
	{
		printf("%d ", Node_p->data);
	}
	printf("\n");
}

//删除节点
void delete_node(Link head, Datatype data)
{
	Link Node_p = NULL;
	Link N = NULL ;
	list_for_each_entry_safe(Node_p, N, &(head->list), list)
	{
		if ( Node_p->data == data )
		{
			list_del(&(Node_p->list));//删除节点
			free(Node_p);
		}
	}
	printf("没有该节点\n");

	// Link Node_p = find_node(head, data);
	// if (Node_p == NULL)
	// {
	// 	printf("没有该节点\n");
	// }
	// else
	// {
	// 	list_del(&(Node_p->list));//删除节点
	// 	free(Node_p);
	// }
}

//查找节点
Link find_node( Link head, Datatype data )
{
	Link Node_p = NULL;
	Link N = NULL;
	list_for_each_entry_safe( Node_p , N , &( head -> list ) , list )
	{
		if ( Node_p -> data == data )
		{
			return Node_p ;
		}
	}
	return NULL ;
}


//移动节点
	Link N1 = NULL ;
	Link N2 = NULL ;
	list_for_each_entry_safe( Node_p , N , &( head -> list ), list )
	{
		if ( Node_p -> data == 2 )
		{
			N1 = Node_p ;
		}
		if ( Node_p -> data == 4 )
		{
			N2 = Node_p ;
		}
	}
//把 N1 移到 N2 后面  把 2 移到 4 后面
	list_move( &( N1 -> list ), &( N2 -> list ) ) ;
//把 N1 移到 N2 前面  把 2 移到 4 前面
	list_move_tail( &( N1 -> list ) , &( N2 -> list ) ) ;



//合并链表
	//            12345             6789
	list_splice( &( head -> list ) , &( head1 -> list ) ) ;

	list_for_each_entry_safe( Node_p , N , &( head1 -> list ) , list )
	{
		printf( "%d", Node_p -> data ) ;	
	}
	printf("\n");
	//123456789