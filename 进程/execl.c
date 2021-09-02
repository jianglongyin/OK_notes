#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <error.h>

int main(int argc, char const *argv[])
{
	printf("进程开始运行\n");

	int n;
	pid_t x = 0;
	while(1)
	{
		scanf("%d", &n);
		switch(n)
		{
			case 1:x = fork();
				if (x == 0)
				{
					execl("../hello", "hello", NULL);
				}
				break;

			case 2: x = fork();
				if (x == 0)
				{
					execl("../hello1", "hello1", NULL);
				}
				break;
			case 3:	x = fork();
				if (x == 0)
				{
					execl("../hello2", "hello2", NULL);
				}
				break;
		}
	}
	return 0;
}