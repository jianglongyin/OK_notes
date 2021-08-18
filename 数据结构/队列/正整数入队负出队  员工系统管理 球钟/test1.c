#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Datatype;

typedef struct Queue
{
	Datatype *queue;		//队的连续内存的名字（数组名）队列指针
	int size;				//队的长度
	int front;				//队头
	int rear;				//队尾
}Sq, *node_q;

//初始化一个空的队列
node_q init_queue(int size)
{
	node_q s = malloc(sizeof(Sq));
	if (s != NULL)
	{
		s->queue = calloc(size, sizeof(Datatype));		//为队列申请空间
		s->size = size;									//队的大小
		s->front = s->rear = 0;
	}
	return s;
}

//队空
bool queue_empty(node_q s)
{
	return (s->front == s->rear);
}

//队满
bool queue_full(node_q s)
{
	return ((s->rear+1)%s->size == s->front);
}

//入队
bool in_queue(node_q s, Datatype data)
{
	//判断队满
	if (queue_full(s))
	{
		return false;
	}
	//将rear往后偏移
	s->rear = (s->rear+1) % s->size;
	//填数据
	s->queue[s->rear] = data;
	//*(s->queue + s->rear) = data;
	return true;
}

//出队
bool out_queue(node_q s, Datatype *data)
{
	//判断队空
	if (queue_empty(s))
	{
		return false;
	}
	//将front往后偏移
	s->front = (s->front+1) % s->size;
	//获取
	*data = s->queue[s->front];
	return true;
}

//遍历
void display(node_q s)
{
	if (queue_empty(s))
	{
		return ;
	}
	int i = s->front;
	for (; i != s->rear; )
	{
		i = (i+1)%(s->size);
		printf("%d ", s->queue[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	//初始化一个空队，有8个位置
	node_q s = init_queue(8);

	int num;
	int data;
	while(1)
	{
		int ret = scanf("%d", &num);
		while(getchar()!='\n');
		if (ret == 1)
		{
			in_queue(s, num);
			display(s);
		}
		else
		{
			out_queue(s, &data);
			display(s);
		}
	}
	

	return 0;
}