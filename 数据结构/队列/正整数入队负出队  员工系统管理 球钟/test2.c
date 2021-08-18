#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

typedef struct massige
{
	int num;
	char name[20];
	float salary;
}Datatype;

//链式队列的节点管理结构体
typedef struct node
{
	Datatype data;				//数据域
	struct node *next;			//指针域	
}Node, *p_node;

//链式队列管理结构体
typedef struct link_queue
{
	p_node front;				//队首指针
	p_node rear;				//队尾指针
	int size;					//当前元素个数
}Link_queue, *p_queue;

//初始化空链式队列
p_queue init_link_queue(void)
{
	//给管理结构体分配空间、
	p_queue q = malloc(sizeof(Link_queue));
	if (q != NULL)
	{
		q->front = q->rear = NULL;
		q->size = 0;
	}
	return q;
}

//判断链式队列队空
bool link_queue_empty(p_queue q)
{
	return (q->size == 0);
}

//创建节点
p_node create_node(Datatype data)
{
	p_node new = malloc(sizeof(Node));
	if (new != NULL)
	{
		new->data = data;
		new->next = NULL;
	}
	return new;
}

//入队
bool in_queue(p_queue q, Datatype data)
{
	p_node new = create_node(data);
	if (new == NULL)
	{
		return false;
	}
	//如果队列是空队
	if (link_queue_empty(q))
	{
		q->front = new;
		q->rear = new;
	}
	//如果队列不为空
	else
	{
		//将新节点加入队列链表
		q->rear->next = new;
		//重新指明队尾在new节点位置
		q->rear = new;
	}
	q->size++;
	return true;
}

//出队
bool out_queue(p_queue q, p_node *data)
{
	//判断队是否为空
	if (link_queue_empty(q))
	{
		return false;
	}
	//如果队列只有一个元素
	else
	if (q->size == 1)
	{
		q->rear = NULL;
	}
	
	//如果队列有多个元素
	*data = q->front;
	q->front = q->front->next;
	q->size--;
	return true;
}

int main(int argc, char const *argv[])
{
	p_queue q = init_link_queue();
	
	int num;
	Datatype ma;
	p_node p;
	while(1)
	{
		scanf("%d", &num);
		if (num > 0)
		{
			//入队
			ma.num = num;
			printf("输入员工的姓名\n");
			scanf("%s", ma.name);
			printf("输入员工的工资\n");
			scanf("%f", &ma.salary);
			in_queue(q, ma);
		}
		else
		if (num < 0)
		{
			//出队
			out_queue(q, &p);
			printf("员工号\t姓名\t工资\n");
			printf("%d\t%s\t%.2f\n", p->data.num, p->data.name, p->data.salary);
			bzero(&(p->data), sizeof(p->data));
		}
		else
		{
			break;
		}
	}
	
	return 0;
}
