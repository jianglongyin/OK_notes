#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
	DataType data;	//数据域
	struct Node *prev;	//前驱指针
	struct Node *next;	//后继指针
}listnode, *double_link;

//typedef struct Node listnode;
//typedef struct Node *singly_list; 

//初始化一个空双向循环链表
double_link init_link()
{
	double_link head = malloc(sizeof(listnode));
	if (head != NULL)
	{
		head->prev = head;
		head->next = head;
	}
	return head;
}

//判断空链表
bool is_empty(double_link head)
{
	return (head->next == head && head->prev == head);
}

//新建节点
double_link create_node(DataType data)
{
	double_link new = malloc(sizeof(listnode));
	if (new != NULL)
	{
		new->data = data;
		new->prev = NULL;
		new->next = NULL;
	}
	return new;
}

//尾插法插入节点
void insert_node(double_link head, double_link new)
{
	double_link tail = head->prev;

	new->prev = tail;
	new->next = head;
	tail->next = new;
	head->prev = new;
}

//头插法插入节点
void head_node(double_link head, double_link new)
{
	double_link first = head->next;
	
	new->prev = head;
	new->next = first;
	first->prev = new;
	head->next = new;
}

//遍历链表(往后遍历)
void display_tail(double_link head)
{
	double_link p = head;
	while(p->next != head)
	{
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}

//遍历链表(往前遍历)
void display_head(double_link head)
{
	double_link p = head;
	while(p->prev != head)
	{
		p = p->prev;
		printf("%d ", p->data);
	}
	printf("\n");
}

//查找节点
double_link find_node(double_link head, DataType data)
{
	double_link p = head;
	while(p->prev != head)//往前遍历查找节点
	{
		p = p->prev;
		if (p->data == data)
		{
			return p;
		}
	}

	// while(p->next != head)//往后遍历查找节点
	// {
	// 	p = p->next;
	// 	if (p->data == data)
	// 	{
	// 		return p;
	// 	}
	// }
	return NULL;
}

void delete_node(double_link head, DataType data)
{
	double_link p = head;
	while(p->next != head)//往后遍历查找节点
	{		
		if (p->next->data == data)
		{			
			double_link delete = p->next;	//找到删除节点			
			p->next = delete->next;	//先把前驱节点的next指向删除节点的next			
			delete->next->prev = p;	//删除节点的next的prev指向删除节点的前驱节点

			free(delete);
			delete->next = NULL;
			delete->prev = NULL;
			return ;
		}
		p = p->next;
	}
}

//更新节点
void update_node(double_link head, DataType old_data, DataType new_data)
{
	double_link node = find_node(head, old_data);
	if (node == NULL)
	{
		printf("没有该节点\n");
	}
	else
	{
		node->data = new_data;
	}
}

//清空链表
void clear_link(double_link head)
{
	while(head->next != head)
	{
		double_link dele = head->next;

		head->next = dele->next;
		dele->next->prev = head;

		free(dele);
		dele->next = NULL;
		dele->prev = NULL;
	}
}

int main(int argc, char const *argv[])
{
	//初始化空链表
	double_link head = init_link();

	int i;
	for (i = 0; i < 5; ++i)
	{
		insert_node(head, create_node(i+1));
	}

	printf("往后遍历\n");
	display_tail(head);


	// printf("往前遍历\n");
	// display_head(head);

	// if(find_node(head, 8) == NULL)
	// {
	// 	printf("链表里面没有这个节点\n");
	// }
	// else
	// {
	// 	printf("链表里面有这个节点\n");
	// }


	// delete_node(head, 3);
	// display_tail(head);

	// update_node(head, 6, 8);
	// display_tail(head);

	printf("清空链表\n");
	clear_link(head);
	display_tail(head);

	return 0;
}