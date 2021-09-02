//写端
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <error.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


#define FIFO_PATHNAME "/tmp/myfifo"

int main(int argc, char const *argv[])
{
	//创建有名管道（判断是否有这个文件）
	if(access(FIFO_PATHNAME, F_OK))	//判断这个文件是否存在
	{
		int ret = mkfifo(FIFO_PATHNAME, 0644);
		if (ret == -1)
		{
			perror("mkfifo");
			return -1;
		}
	}

	//打开有名管道
 	int fd = open(FIFO_PATHNAME, O_RDWR);
 	if (fd == -1)
 	{
 		perror("open");
		return -1;
 	}
 	printf("有名管道打开成功\n");
 	char w_buf[1024] = {0};
 	while(1)
 	{
 		//写数据
	 	
	 	scanf("%s", w_buf);
	 	write(fd, w_buf, strlen(w_buf));
 	}
 	



	return 0;
}