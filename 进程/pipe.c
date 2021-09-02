#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <error.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	//创建无名管道
	int fd[2];

	int ret = pipe(fd);
	if (ret == -1)
	{
		perror("pipe");
		return -1;
	}
	printf("无名管道创建成功\n");
	//fd[0]:读端
	//fd[1]:写端

	int s;
	//创建亲缘进程（父子进程）
	pid_t x = fork();
	char buf[100] = {0};
	char w_buf[100] = {0};
	if (x == 0)
	{
		printf("子进程开始运行\n");
		read(fd[0], buf, sizeof(buf));
		printf("buf = %s\n", buf);
		printf("子进程结束运行\n");
	}
	else
	if (x > 0)
	{
		printf("父进程开始运行\n");
		scanf("%s", w_buf);
		write(fd[1], w_buf, strlen(w_buf));

		wait(&s);
	}
	else
	{
		perror("fork");
		return -1;
	}


	return 0;
}


