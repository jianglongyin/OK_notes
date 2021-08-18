#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node *next;
}listnode, *singly_list;

singly_list head = NULL;

//初始化链表
singly_list init_list(void)
{
	//为链表申请一个节点作为头结点
	head = malloc(sizeof(listnode));
	if (head != NULL)
	{
		head->data = 1;
		head->next = head;
	}
	return head;
}

singly_list create_node(int data)
{
	singly_list new = malloc(sizeof(listnode));
	if (new != NULL)
	{
		new->data = data;
		new->next = NULL;
	}
	return new;
}

//插入节点(尾插)
void insert_node(singly_list head, singly_list new)
{
	//如果不为空，就要找到链表的最后一个节点
	singly_list p = head;
	//如果下一个节点不为空，就一直往后找，直到这个节点的next为空
	while(p->next != head)
	{
		p = p->next;
	}
	new->next = head;
	p->next = new;
}

//遍历
void display(singly_list head)
{
	singly_list p = head;
	while(p->next != head)
	{		
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d ", p->data);
	printf("\n");
}

void zisha()
{
	singly_list p = head;
	singly_list tmp = NULL;
	while(p->next->next != p)
	{
		if (p->next != p && p->next->next != p)
		{
			tmp = p->next->next;
			p->next->next = tmp->next;
			p = tmp->next;
			printf("要自杀的是%d号\n", tmp->data);
			free(tmp);
		}
	}
	printf("最后没有自杀的是%d号和%d号\n", p->data, p->next->data);
}

int main(int argc, char const *argv[])
{
	head = init_list();
	int i;
	int n;
	printf("要玩的人数：");
	scanf("%d", &n);
	for (i = 2; i <= n; ++i)
	{
		insert_node(head, create_node(i));
	}
	display(head);

	zisha();

	return 0;
}