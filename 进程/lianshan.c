#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

//链式进程
int main(int argc, char const *argv[])
{
	pid_t x = fork();
	if(x > 0)			//父进程
	{
		printf("爷爷 ID : %d\n", getpid());
		sleep(2);
	}
	else
	if (x == 0)			//子进程
	{
		printf("父亲 ID : %d\n", getpid());
		printf("爷爷的进程 ID : %d\n", getppid());
		pid_t y = fork();
		if (y == 0)
		{
			printf("儿子 ID : %d\n", getpid());
			printf("父亲的进程 ID : %d\n", getppid());
		}
		else
		if (y > 0)
		{
			sleep(1);
		}
	}
	else
	{
		return 0;
	}

	return 0;
}

//扇形进程
// int main(int argc, char const *argv[])
// {
// 	printf("父进程ID：%d\n", getpid());
// 	for (int i = 0; i < 3; ++i)
// 	{
// 		pid_t x = fork();
// 		if (x == 0)
// 		{
// 			printf("fu进程ID：%d\n", getppid());
// 			printf("子进程ID：%d\n", getpid());
// 			return 0;
// 		}
// 		if (x > 0)
// 		{
// 			usleep(10);
// 		}
// 	}
// 	sleep(2);
// 	return 0;
// }