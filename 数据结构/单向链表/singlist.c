//单向链表（非循环）
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node *next;
}listnode, *singly_list;

//typedef struct Node listnode;
//typedef struct Node *singly_list; 

//初始化链表
singly_list init_list(void)
{
	//为链表申请一个节点作为头结点
	singly_list head = malloc(sizeof(listnode));
	if (head != NULL)
	{
		head->next = NULL;
	}
	return head;
}

//判断空链表
bool empty(singly_list head)
{
	return head->next == NULL;
}

//新建节点
singly_list create_node(DataType data)
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
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = new;
}

//插入节点(头插)
void tail_node(singly_list head, singly_list new)
{
	new->next = head->next;
	head->next = new;
}

//遍历
void display(singly_list head)
{
	singly_list p = head;
	while(p->next != NULL)
	{
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}

//查找节点
singly_list find_node(singly_list head, DataType data)
{
	singly_list p = head;
	while(p->next != NULL)
	{
		p = p->next;
		if (p->data == data)
		{
			//如果跟链表的节点数据相同，表示找到这个节点
			return p;
		}
	}
	//如果遍历了整个链表都没有找到数据data
	return NULL;
}

//删除节点(只删除匹配到的第一个节点)
void delete_node1(singly_list head, DataType data)
{
	singly_list p = head;
	if(find_node(head, data) != NULL)
	{
		printf("链表里面有这个值存在\n");
	}
	else
	{
		printf("链表里面没有这个值存在\n");
		return ;
	}
	while(p->next != NULL)
	{
		if (p->next->data == data)
		{
			singly_list delete = p->next;//表示下一个节点就是要删除的节点
			p->next = delete->next;
			free(delete);
			return ;
		}
		p = p->next;
	}
}

//删除节点(将所有相同的值删掉)
void delete_node2(singly_list head, DataType data)
{
	singly_list p = head;
	if(find_node(head, data) != NULL)
	{
		printf("链表里面有这个值存在\n");
	}
	else
	{
		printf("链表里面没有这个值存在\n");
		return ;
	}
	while(p->next != NULL)
	{
		if (p->next->data == data)
		{
			singly_list delete = p->next;//表示下一个节点就是要删除的节点
			p->next = delete->next;
			free(delete);
			//假设后面有连续的要删除的节点，那么我们不能删除一个之后就往后偏移
			continue ;
		}
		p = p->next;
	}
}

//删除节点(要删除的数据是一个节点)
void delete_node3(singly_list head, singly_list delete)
{
	singly_list p = head;
	if(find_node(head, delete->data) != NULL)
	{
		printf("链表里面有这个值存在\n");
	}
	else
	{
		printf("链表里面没有这个值存在\n");
		return ;
	}
	while(p->next != NULL)
	{
		if (p->next == delete)
		{
			p->next = delete->next;
			free(delete);		
			return ;
		}
		p = p->next;
	}
}

//修改节点
void update_node(singly_list head, DataType old_data, DataType new_data)	
{
	singly_list find = find_node(head, old_data);
	if (find == NULL)
	{
		printf("没有找到这个数据\n");
	}
	else
	{
		find->data = new_data;
		printf("数据修改成功\n");
	}
	return;
}

//清空链表
void clear_list(singly_list head)
{
	while(head->next != NULL)
	{
		singly_list dele = head->next;
		head->next = dele->next;
		free(dele);
	}
}

//取出节点
singly_list get_node(singly_list head, DataType data)
{
	if (empty(head))
	{
		return NULL;
	}
	singly_list p = head;
	while(p->next != NULL)
	{
		if (p->next->data == data)
		{
			singly_list node = p->next;//表示下一个节点就是要删除的节点
			p->next = node->next;	
			return node;
		}
		p = p->next;
	}
	return NULL;
}

//移动节点()将data2的节点移动到data1的前面
void move_node(singly_list head, DataType data1, DataType data2)
{
	//取出data2的节点
	singly_list node1 = get_node(head, data2);
	//找到data1的节点
	singly_list node2 = find_node(head, data1);
	node1->next = node2->next;
	node2->next = node1;
}

//指定位置插入节点
void insert_any_node(singly_list node1, singly_list node2)
{
	if (node1 == NULL || node2 == NULL)
	{
		return ;
	}
	// node1->next = node2->next;
	// node2->next = node1;
	tail_node(node2, node1);
}

int main(int argc, char const *argv[])
{
	//初始化一个空链表
	singly_list head = init_list();

	int i;
	for (i = 0; i < 5; ++i)
	{
		insert_node(head, create_node(1+i));
	}

	// listnode n = {.next = NULL, .data = 7};
	// insert_node(head, &n);

	display(head);

	// singly_list node = get_node(head, 2);

	// printf("node->data = %d\n", node->data);
	// singly_list node1 = find_node(head, 1);
	// singly_list node3 = find_node(head, 3);


	// singly_list node2 = create_node(7);
	// singly_list node4 = create_node(10);
	// insert_any_node(node2, node1);
	// insert_any_node(node4, node3);
	// move_node(head,1,4);

	

	return 0;
}