#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define F1 1L

struct msgbuf
{
	long mtype; // 消息的标识
	char mtext[50]; // 消息的正文
};

int main(int argc, char const *argv[])
{
	//获取键值
	key_t key = ftok(".", 12);
	if (key == -1)
	{
		perror("ftok");
		return -1;
	}

	//获取消息队列的ID
	int msgid = msgget(key,  IPC_CREAT | 0666);
	if (msgid == -1)
	{
		perror("msgget");
		return -1;
	}

	//接收
	//定义接收数据结构体变量
	struct msgbuf buf;
	bzero(&buf, sizeof(buf));
	int ret = msgrcv(msgid, &buf, sizeof(buf.mtext), F1, 0);

	if (ret == -1)
	{
		perror("msgsnd");
		return -1;
	}
	printf("消息接收成功\n");
	printf("buf = %s\n", buf.mtext);

	// msgctl(msgid, IPC_RMID, NULL);

	return 0;
}