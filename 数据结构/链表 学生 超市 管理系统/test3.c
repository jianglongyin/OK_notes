#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char name[20];
	int id;
	int age;
	float score;
}DataType;

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
		if (p->next->data.id > new->data.id)
		{
			new->next = p->next;
			p->next = new;
			return ;
		}
		p = p->next;
	}
	p->next = new;
}

//遍历
void display(singly_list head)
{
	singly_list p = head;
	printf("%-10s%-10s%-10s%-10s\n", "姓名", "学号", "年龄", "成绩");
	while(p->next != NULL)
	{
		p = p->next;

		printf("%-10s%-10d%-10d%-10f\n", p->data.name, p->data.id, p->data.age, p->data.score);
	}
	printf("\n");
}

//删除节点(只删除匹配到的第一个节点)
void delete_node1(singly_list head, int data)
{
	singly_list p = head;	
	while(p->next != NULL)
	{
		if (p->next->data.id == data)
		{
			singly_list delete = p->next;//表示下一个节点就是要删除的节点
			p->next = delete->next;
			free(delete);
			return ;
		}
		p = p->next;
	}
	printf("没有这个学生\n");
}

//查找节点
singly_list find_node_id(singly_list head, int id)
{
	singly_list p = head;
	while(p->next != NULL)
	{
		p = p->next;
		if (p->data.id == id)
		{
			//如果跟链表的节点数据相同，表示找到这个节点
			return p;
		}
	}
	//如果遍历了整个链表都没有找到数据data
	return NULL;
}

//查找节点
singly_list find_node_name(singly_list head, char *name)
{
	singly_list p = head;
	while(p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->data.name, name) == 0)
		{
			//如果跟链表的节点数据相同，表示找到这个节点
			return p;
		}
	}
	//如果遍历了整个链表都没有找到数据data
	return NULL;
}

int main(int argc, char const *argv[])
{
	//初始化一个空链表
	singly_list head = init_list();

	DataType stu[5] = {
						{"zhangsan", 1004, 18, 85.5},
						{"lisi", 	 1002, 19, 87.5},
						{"wangwu",   1001, 20, 89.5},
						{"zhaoliu",  1005, 21, 82.5},
						{"tianqi",   1003, 22, 95.5},
					  };

	int i;
	for (i = 0; i < 5; ++i)
	{
		insert_node(head, create_node(stu[i]));
	}

	// while(1)
	// {
	// 	menu();
	// }
	display(head);

	printf("输入需要删除的学生的学号\n");
	int num;
	scanf("%d", &num);

	delete_node1(head, num);
	display(head);

	int n;
	printf("1、学号2、姓名查找学生成绩\n");
	scanf("%d", &n);
	
	switch(n)
	{
		case 1:
			printf("输入这个学生的学号\n");
			int id1;
			scanf("%d", &id1);
			singly_list id_node = find_node_id(head, id1);
			if (id_node == NULL)
			{
				printf("没有这个学生\n");
			}
			else
			{
				printf("输入需要修改的成绩\n");
				float f;
				scanf("%f", &f);
				id_node->data.score = f;
			}
			break;
		case 2:
			printf("输入这个学生的姓名\n");
			char name1[20] = {0};
			scanf("%s", name1);
			singly_list name_node = find_node_name(head, name1);
			if (name_node == NULL)
			{
				printf("没有这个学生\n");
			}
			else
			{
				printf("输入需要修改的成绩\n");
				float f;
				scanf("%f", &f);
				name_node->data.score = f;
			}
	}

	display(head);

	
	printf("1、学号2、姓名查找学生成绩\n");
	scanf("%d", &n);
	
	switch(n)
	{
		case 1:
			printf("输入这个学生的学号\n");
			int id1;
			scanf("%d", &id1);
			singly_list id_node = find_node_id(head, id1);
			if (id_node == NULL)
			{
				printf("没有这个学生\n");
			}
			else
			{
				printf("找到这个学生\n");
				printf("这个学生的成绩是：%f分\n", id_node->data.score);				
			}
			break;
		case 2:
			printf("输入这个学生的姓名\n");
			char name1[20] = {0};
			scanf("%s", name1);
			singly_list name_node = find_node_name(head, name1);
			if (name_node == NULL)
			{
				printf("没有这个学生\n");
			}
			else
			{
				printf("找到这个学生\n");
				printf("这个学生的成绩是：%f分\n", name_node->data.score);
			}
	}

	display(head);

	return 0;
}