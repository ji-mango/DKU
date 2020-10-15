/*mycp program, by kimjm, susie000301@naver.com*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>			//for stat
#define MAX_BUF 64

int main(int argc, char *argv[])
{
	int fd, cpfd, mode, read_size;
	char buf[MAX_BUF];
	struct stat st;	
	
	if (argc!=3) {			//인자가 3개인지 확인
		printf("USAGE:%s file_name cp_file_name\n", argv[0]); exit(-1);
	}
	fd=open(argv[1],O_RDONLY);
	if(fd<0){
		printf("can't open %s\n",argv[1]); exit(-1);
	}
	mode-stat(argv[1],&st);
	cpfd=open(argv[2],O_WRONLY | O_CREAT | O_EXCL,st.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
	if(cpfd<0){
		printf("can't open %s\n",argv[2]); exit(-1); 
	}
	while(1){
		read_size=read(fd,buf,MAX_BUF);
		if(read_size==0)
			break;
		write(cpfd,buf,read_size);
	}
	close(fd);
	close(cpfd);
}

