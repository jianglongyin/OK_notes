#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//数据节点结构体声明
struct node		//大结构体：存放数据
{
	int data;
	struct list_head list;		//小结构体：存放前驱指针和后继指针
};

int main(int argc, char const *argv[])
{
	//创建节点
	struct node *head = malloc(sizeof(struct node));
	struct node *head1 = malloc(sizeof(struct node));
	//创建纯粹链表
	if (head != NULL)
	{
		INIT_LIST_HEAD(&(head->list));
	}
	if (head1 != NULL)
	{
		INIT_LIST_HEAD(&(head1->list));
	}
	int i;
	for (i = 0; i < 5; ++i)
	{
		struct node *new = malloc(sizeof(struct node));
		if (new != NULL)
		{
			new->data = i+1;
			new->list.prev = NULL;
			new->list.next = NULL;
		}
		else
		{
			i--;
			continue;
		}

		//向链表里面插入节点
		//头插
		// list_add(&(new->list), &(head->list));
		//尾插
		list_add_tail(&(new->list), &(head->list));
	}

	for (i = 0; i < 5; ++i)
	{
		struct node *new = malloc(sizeof(struct node));
		if (new != NULL)
		{
			new->data = i+11;
			new->list.prev = NULL;
			new->list.next = NULL;
		}
		else
		{
			i--;
			continue;
		}

		//向链表里面插入节点
		//头插
		// list_add(&(new->list), &(head->list));
		//尾插
		list_add_tail(&(new->list), &(head1->list));
	}
	//create_node(head,11);

	//遍历

	struct list_head *pos = NULL;
	struct list_head *n = NULL;

	struct node *Node_p = NULL;
	struct node *N = NULL;

	//第一种
	// list_for_each(pos, &(head->list))
	// {
	// 	struct node *p = list_entry(pos, struct node, list);	
	// 	printf("%d ", p->data);
	// }
	// printf("\n");

	//第二种
	// list_for_each_prev(pos, &(head->list))
	// {
	// 	struct node *p = list_entry(pos, struct node, list);	
	// 	printf("%d ", p->data);
		
	// }
	// printf("\n");

	//第三种
	// list_for_each_safe(pos, n, &(head->list))
	// {
	// 	struct node *p = list_entry(pos, struct node, list);
	// 	if (p->data == 3)
	// 	{
	// 		list_del(&(p->list));
	// 	}
	// 	else	
	// 		printf("%d ", p->data);
	// }
	// printf("\n");

	//第四种
	// list_for_each_entry(Node_p, &(head->list), list)
	// {		
	// 	printf("%d ", Node_p->data);
	// }
	// printf("\n");

	//第五种
	// list_for_each_entry_safe(Node_p, N, &(head->list), list)
	// {
	// 	if (Node_p->data == 3)
	// 	{
	// 		// list_del(&(Node_p->list));//删除节点
	// 		// free(Node_p);

	// 		list_del_init(&(Node_p->list));
	// 	}
	// 	else
	// 		printf("%d ", Node_p->data);
	// }
	// printf("\n");

	list_for_each_entry_safe(Node_p, N, &(head->list), list)
	{
		printf("%d ", Node_p->data);	
	}
	printf("\n");
	
	//移动节点
	struct node *N1 = NULL;
	struct node *N2 = NULL;
	list_for_each_entry_safe(Node_p, N, &(head->list), list)
	{
		if (Node_p->data == 2)
		{
			N1 = Node_p;
		}
		if (Node_p->data == 4)
		{
			N2 = Node_p;
		}
	}
	

	//把 N1 移到 N2 后面
	list_move(&(N1->list), &(N2->list));
	list_for_each_entry_safe(Node_p, N, &(head->list), list)
	{
		printf("%d ", Node_p->data);	
	}
	printf("\n");
	//把 N1 移到 N2 前
	list_move_tail(&(N1->list), &(N2->list));

	list_for_each_entry_safe(Node_p, N, &(head->list), list)
	{
		printf("%d ", Node_p->data);	
	}
	printf("\n");


	//合并链表
	list_splice(&(head->list), &(head1->list));

	list_for_each_entry_safe(Node_p, N, &(head1->list), list)
	{
		printf("%d ", Node_p->data);	
	}
	printf("\n");


	return 0;
}