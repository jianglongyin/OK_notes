#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Shoping
{
	int id;
	char name[20];
	char type[20];
	float price;
}DataType;

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
	printf("编号\t名称\t类别\t价格\n");
	while(p->next != head)
	{
		p = p->next;
		printf("%d\t%s\t%s\t%.2f\n", p->data.id, p->data.name, p->data.type, p->data.price);
	}
	printf("\n");
}

//查找节点
double_link find_node(double_link head, int id)
{
	double_link p = head;
	while(p->prev != head)//往前遍历查找节点
	{
		p = p->prev;
		if (p->data.id == id)
		{
			return p;
		}
	}
	return NULL;
}

//查找节点
double_link find_node1(double_link head, char *name)
{
	double_link p = head;
	while(p->prev != head)//往前遍历查找节点
	{
		p = p->prev;
		if (strcmp(p->data.name, name) == 0)
		{
			return p;
		}
	}
	return NULL;
}

void delete_node(double_link head, int id)
{
	double_link p = head;
	while(p->next != head)//往后遍历查找节点
	{		
		if (p->next->data.id == id)
		{			
			double_link delete = p->next;	//找到删除节点			
			p->next = delete->next;	//先把前驱节点的next指向删除节点的next			
			delete->next->prev = p;	//删除节点的next的prev指向删除节点的前驱节点

			free(delete);
			delete->next = NULL;
			delete->prev = NULL;
			printf("删除成功\n");
			return ;
		}
		p = p->next;
	}
	printf("没有这个编号的商品\n");
}

void delete_node1(double_link head, char *name)
{
	double_link p = head;
	while(p->next != head)//往后遍历查找节点
	{		
		if (strcmp(p->next->data.name, name) == 0)
		{			
			double_link delete = p->next;	//找到删除节点			
			p->next = delete->next;	//先把前驱节点的next指向删除节点的next			
			delete->next->prev = p;	//删除节点的next的prev指向删除节点的前驱节点

			free(delete);
			delete->next = NULL;
			delete->prev = NULL;
			printf("删除成功\n");
			return ;
		}
		p = p->next;
	}
	printf("没有这个名称的商品\n");
}

void insert_node_price(double_link head, double_link new)
{
	double_link p = head;
	while(p->next != head)//往后遍历查找节点
	{		
		if (p->next->data.price > new->data.price)
		{	
			head_node(p, new);
			return ;
		}
		p = p->next;
	}
	insert_node(head, new);
}

int main(int argc, char const *argv[])
{
	DataType da[5] = {
					{3, "西瓜", "水果", 1.8},
					{5, "辣条", "零食", 3},
					{7, "可乐", "饮料", 3},
					{9, "葡萄", "水果", 8},
					{11, "芬达", "饮料", 3}
	};

	//初始化空链表
	double_link head = init_link();

	int i;
	for (i = 0; i < 5; ++i)
	{
		insert_node_price(head, create_node(da[i]));
	}

	display_tail(head);

	int k;
	while(1)
	{
		printf("选择你要执行的操作\n");
		printf("1、增加\t2、删除\t3、修改\t4、查找\t5、查看\n");
		scanf("%d", &k);
		DataType d;
		int id;
		char name[20] = {0};
		char type[20] = {0};
		float price;
		int l;
		switch(k)
		{
			case 1:		
				printf("输入商品的编号\n");
				scanf("%d", &d.id);
				getchar();
				printf("输入商品的名称\n");
				scanf("%s", d.name);
				getchar();
				printf("输入商品的类别\n");
				scanf("%s", d.type);
				getchar();
				printf("输入商品的价格\n");
				scanf("%f", &d.price);
				getchar();
				insert_node(head, create_node(d));
				break;
			case 2:
				printf("1、编号\t2、名称\n");
				scanf("%d", &l);
				switch(l)
				{
					case 1:
						scanf("%d", &id);
						delete_node(head, id);
						break;
					case 2:
						scanf("%s", name);
						delete_node1(head, name);
				}
				break;
			case 3:
				printf("1、编号\t2、名称\n");
				scanf("%d", &l);
				switch(l)
				{
					case 1:
						scanf("%d", &id);
						double_link p = find_node(head, id);
						if (p != NULL)
						{
							printf("选择修改的内容\n");
							printf("1、编号\t2、名称\t3、类别\t4、价格\n");
							scanf("%d", &l);
							switch(l)
							{
								case 1:
									scanf("%d", &id);
									p->data.id = id;
									break;
								case 2:
									scanf("%s", name);
									strcpy(p->data.name, name);
									break;
								case 3:
									scanf("%s", type);
									strcpy(p->data.type, type);
									break;
								case 4:
									scanf("%f", &price);
									p->data.price = price;
									break;
							}
							
						}
						break;
					case 2:
						scanf("%s", name);
						double_link p1 = find_node1(head, name);
						if (p1 != NULL)
						{
							printf("选择修改的内容\n");
							printf("1、编号\t2、名称\t3、类别\t4、价格\n");
							scanf("%d", &l);
							switch(l)
							{
								case 1:
									scanf("%d", &id);
									p1->data.id = id;
									break;
								case 2:
									scanf("%s", name);
									strcpy(p1->data.name, name);
									break;
								case 3:
									scanf("%s", type);
									strcpy(p1->data.type, type);
									break;
								case 4:
									scanf("%f", &price);
									p1->data.price = price;
									break;
							}
							
						}
						break;
				}
				break;
			case 4:
				printf("1、编号\t2、名称\n");
				scanf("%d", &l);
				switch(l)
				{
					case 1:
						scanf("%d", &id);
						double_link p = find_node(head, id);
						if (p != NULL)
						{
							printf("编号\t名称\t类别\t价格\n");							
							printf("%d\t%s\t%s\t%.2f\n", p->data.id, p->data.name, p->data.type, p->data.price);	
						}
						else
						{
							printf("没有找到这个节点\n");
						}
						break;
					case 2:
						scanf("%s", name);
						double_link p1 = find_node1(head, name);
						if (p1 != NULL)
						{
							printf("编号\t名称\t类别\t价格\n");							
							printf("%d\t%s\t%s\t%.2f\n", p1->data.id, p1->data.name, p1->data.type, p1->data.price);	
						}
						else
						{
							printf("没有找到这个节点\n");
						}
						break;
				}
			case 5:display_tail(head);break;
		}
	}

	return 0;
}