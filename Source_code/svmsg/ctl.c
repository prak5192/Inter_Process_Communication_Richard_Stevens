#include	"unpipc.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int
main(int argc, char **argv)
{
	int				msqid;
	struct msqid_ds	info;
	struct msgbuf	buf;

	msqid = Msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);

	buf.mtype = 1;
	buf.mtext[0] = 1;
	Msgsnd(msqid, &buf, 1, 0);

	Msgctl(msqid, IPC_STAT, &info);
	printf("read-write: %03o, cbytes = %lu, qnum = %lu, qbytes = %lu\n",
		   info.msg_perm.mode & 0777, (unsigned long int) info.msg_cbytes,
		   (unsigned long int ) info.msg_qnum, (unsigned long int) info.msg_qbytes);

	int ret = system("ipcs -q");
    if( ret == -1){
        perror("system\n");
        printf("Error in system call\n");
    }

	Msgctl(msqid, IPC_RMID, NULL);
	exit(0);
}
