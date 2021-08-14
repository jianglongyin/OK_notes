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
	Link head = malloc(sizeof(Node));
	//创建纯粹链表
	if (head != NULL)
	{
		INIT_LIST_HEAD(&(head->list));
	}
	return head;
}

//创建节点
Link create_node(Datatype data)
{
	Link new = malloc(sizeof(Node));
	if (new != NULL)
	{
		new->data = data;
		new->list.prev = NULL;
		new->list.next = NULL;
	}
	return new;
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
	Link N = NULL;
	list_for_each_entry_safe(Node_p, N, &(head->list), list)
	{
		if (Node_p->data == data)
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
Link find_node(Link head, Datatype data)
{
	Link Node_p = NULL;
	Link N = NULL;
	list_for_each_entry_safe(Node_p, N, &(head->list), list)
	{
		if (Node_p->data == data)
		{
			return Node_p;
		}
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	//初始化一个空链表
	Link head = init_list();

	//创建节点在插入
	int i;
	for (i = 0; i < 5; ++i)
	{	
		Link new = create_node(i+1);	
		list_add_tail(&(new->list), &(head->list));
	}

	//遍历
	display(head);

	return 0;
}