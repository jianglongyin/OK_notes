//顺序栈
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Datatype;

typedef struct stack
{
	Datatype *stack;	//表示栈结构的空间起始地址（比如数组的元素）
	int size;			//表示栈的大小，最多能放的元素的个数
	int top;			//栈的偏移
}S_stack, *stack_p;

//初始化一个空的顺序栈
stack_p init_stack(int size)
{
	stack_p s = malloc(sizeof(S_stack));
	if (s != NULL)
	{
		s->stack = calloc(size, sizeof(Datatype));		//为要压栈的数据申请空间
		s->size = size;				//栈的大小
		s->top = -1;				//一般初始化栈顶偏移初始化为-1，top为0表示有一个元素
	}
	return s;
}

//栈空
bool stack_empty(stack_p s)
{
	return (s->top == -1);
}

//栈满
bool stack_full(stack_p s)
{
	return (s->top == s->size-1);
}

//入栈
bool push(stack_p s, Datatype data)
{
	if (stack_full(s) || s == NULL)
	{
		return false;
	}
	//栈顶偏移，表示有一个数据入栈
	s->top++;
	//将新的数据放到栈顶
	s->stack[s->top] = data;		//*(s->stack + s->top) = data;
	return true;
}

//出栈
bool pop(stack_p s, Datatype *data)
{
	if (stack_empty(s) || s == NULL)
	{
		return false;
	}
	//拿到栈顶数据，存放到地址data
	*data = s->stack[s->top];
	// *data = *(s->stack + s->top);

	//栈顶偏移
	s->top--;
	return true;
}

//栈的遍历
void display(stack_p s)
{
	int i;
	for (i = 0; i < s->top+1; ++i)
	{
		printf("%d ", s->stack[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	//初始化空的顺序栈
	stack_p s = init_stack(5);

	int i;
	for (i = 0; i < 8; ++i)
	{
		if(push(s, i+1))
		{

		}
		else
		{
			printf("入栈失败\n");
		}
	}

	display(s);

	int data;
	for (i = 0; i < 8; ++i)
	{
		if(pop(s, &data))
		{
			printf("data = %d\n", data);
		}
		else
		{
			printf("出栈失败\n");
		}

	}
	return 0;
}


