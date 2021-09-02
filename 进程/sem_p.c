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
#include <sys/shm.h>
#include <sys/sem.h>
#include <errno.h>

union semun
{
	int val; /* 当 cmd 为 SETVAL 时使用 */
	struct semid_ds *buf; /* 当 cmd 为 IPC_STAT 或 IPC_SET 时使用 */
	unsigned short *array; /* 当 cmd 为 GETALL 或 SETALL 时使用 */
	struct seminfo *__buf; /* 当 cmd 为 IPC_INFO 时使用 */
};

//信号量元素初始化
void sem_init(int semid, int semnum, int value)
{
	//semid:为信号量的ID
	//semnum:表示信号量元素的下标
	//semnum == 0 ：读资源
	//semnum == 1 ：写资源
	//value：用来表示资源的个数
	//value == 0：没有资源
	//value == 1：有一个资源

	union semun x;
	x.val = value;
	semctl(semid, semnum, SETVAL, x);
}

//P操作 		资源数-1
void sem_p(int semid, int semnum)
{
	struct sembuf sops[1];
	sops[0].sem_num = semnum;
	sops[0].sem_op = -1;		//P操作，资源数-1
	sops[0].sem_flg = 0;
	semop(semid, sops, 1);
}

//V操作 		资源数+1
void sem_v(int semid, int semnum)
{
	struct sembuf sops[1];
	sops[0].sem_num = semnum;		//semnum  信号量元素下标
	sops[0].sem_op = 1;		//V操作，资源数+1
	sops[0].sem_flg = 0;
	semop(semid, sops, 1);
}

int main(int argc, char const *argv[])
{
	//获取键值(共享内存的键值)
	key_t shmkey = ftok(".", 14);
	if (shmkey == -1)
	{
		perror("ftok shm");
		return -1;
	}

	//获取共享内存的ID
	int shmid = shmget(shmkey, 1024, IPC_CREAT | 0644);

	//对共享内存空间进行映射
	char *p = shmat(shmid, NULL, 0);
	if (p == (char *)-1)
	{
		perror("shmat");
		return -1;
	}

	//获取键值（系统信号量的键值）
	key_t semkey = ftok(".", 15);
	if (semkey == -1)
	{
		perror("ftok sem");
		return -1;
	}

	//获取信号量的ID
	int semid = semget(semkey, 2, IPC_CREAT | IPC_EXCL | 0644);
	//如果信号量存在，只需要获取ID
	if (semid == -1 && errno == EEXIST)
	{
		semid = semget(semkey, 2, 0644);
	}
	//否则就创建成功，初始化信号量（设置信号量的资源）
	else
	{
		//写资源【1】设置个数为1
		sem_init(semid, 1, 1);//101010
		//读资源【0】设置个数为0
		sem_init(semid, 0, 0);//010101
	}
	
	//对共享内存进行访问（通过PV操作限制，进行管理）
	while(1)
	{
		//申请写资源P操作		1：写资源
		sem_p(semid, 1);
		scanf("%s", p);
		//对读资源进行V操作	0：读资源
		sem_v(semid, 0);
	}

	
	//解除映射
	shmdt(p);

	//删除共享内存
	// shmctl(shmid, IPC_RMID, NULL);

	//删除信号量
	// semctl(semid, 0, IPC_RMID);
	
	return 0;
}