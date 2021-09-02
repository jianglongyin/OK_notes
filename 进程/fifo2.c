#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
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
 	char r_buf[1024];
	while(1)
	{
		//读数据
	 	
	 	bzero(r_buf, sizeof(r_buf));
	 	read(fd, r_buf, sizeof(r_buf));

	 	printf("r_buf = %s\n", r_buf);
	}
 	
	return 0;
}