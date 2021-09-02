#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <error.h>
#include <unistd.h>
#include <sys/wait.h>

//信号响应函数
void func(int sig)
{
	printf("信号响应函数\n");
	printf("sig = %d\n", sig);
}

int main(int argc, char const *argv[])
{
	pid_t x = fork();
	int i = 0;
	int s;
	if (x > 0) //父进程
	{
		sleep(5);
		kill(x, 2);
		wait(&s);
	}
	else
	if (x == 0)	//子进程
	{
		// signal(2, SIG_IGN);		//忽略
		// signal(2, SIG_DFL);		//执行缺省动作
		signal(2, func);		//响应响应信号函数
		while(1)
		{
			printf("i = %d\n", i++);
			sleep(1);
			if (i == 10)
			{
				break;
			}
		}
	}
	else
	{
		perror("fork");
	}

	return 0;
}