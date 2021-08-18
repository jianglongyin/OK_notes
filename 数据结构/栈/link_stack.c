//链式栈

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Datatype;

//链式栈的节点的设计
typedef struct node
{
	Datatype data;				//链式栈节点的数据
	struct node *next;			//链式栈节点的指针（存下一个点的地址）
}lsnode, *Links;

//管理栈的结构体
typedef struct stack
{
	Links top;				//表示栈结构的空间起始地址（比如数组的元素）
	int size;				//表示当前栈里面的元素个数
}S_stack, *stack_p;

//链式栈的初始化
stack_p init_link_stack(void)
{
	stack_p s = malloc(sizeof(S_stack));		//为栈结构体分配空间
	if (s != NULL)
	{
		//成员初始化
		s->top = NULL;
		s->size = 0;
	}
	return s;
}

//判断栈空
bool stack_empty(stack_p s)
{
	return (s->size == 0);
}

//入栈
bool push(stack_p s, Datatype data)
{
	//创建新节点
	Links new = malloc(sizeof(lsnode));	
	if (new != NULL)
	{
		//给节点做初始化
		new->data = data;
		//将新节点的next指向原来栈顶
		new->next = s->top;
		//将原栈顶从新设置为新节点
		s->top = new;
		//元素个数加一
		s->size++;
		return true;
	}
	return false;
}

//出栈
bool pop(stack_p s, Links *data)
{
	if (stack_empty(s))
	{
		return false;
	}
	//将栈顶节点的指针，指向的数据，给到data
	*data = s->top;
	//往后偏移
	s->top = s->top->next;
	//元素个数--
	s->size--;
	return true;
}

int main(int argc, char const *argv[])
{
	//初始化空的顺序栈
	stack_p s = init_link_stack();

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

	Links p = NULL;
	for (i = 0; i < 8; ++i)
	{
		if(pop(s, &p))
		{
			printf("%d ", p->data);
		}
		else
		{
			printf("出栈失败\n");
		}

	}
	printf("\n");
	return 0;

}