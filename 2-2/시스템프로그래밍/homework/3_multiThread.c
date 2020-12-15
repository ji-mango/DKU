#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

int x0=0;
int x1=0;
int x2=0;
int sum;

void *combine(void *data)
{
	int i;
	int v[1000000];
	char* thread_name=(char*)data;
	for(i=0;i<1000000;i++)
	{
		v[i]=i;
	}
	if(strcmp(thread_name,"thread_m")==0)
	{
		for(i=0;i<300000;i++)
		{
			x0=x0+v[i];
		}
	}
	if(strcmp(thread_name,"thread_1")==0)
	{
                for(i=300000;i<600000;i++)
                {
                        x1=x1+v[i];
                }
        }
	if(strcmp(thread_name,"thread_2")==0)
	{
		for(i=600000;i<1000000;i++)
		{
			x2=x2+v[i];
		}
	}
	sum=x0+x1+x2;
}

int main()
{
	struct timeval stime,etime,gap;
	pthread_t p_thread[2];
	char p1[]="thread_1";
	char p2[]="thread_2";
	char pM[]="thread_m";

	pthread_create(&p_thread[0],NULL,combine,(void *)p1);
        pthread_create(&p_thread[1],NULL,combine,(void *)p2);
	gettimeofday(&stime,NULL);
	combine((void *)pM);
	gettimeofday(&etime,NULL);
	gap.tv_sec = etime.tv_sec - stime.tv_sec;
        gap.tv_usec = etime.tv_usec - stime.tv_usec;
        if (gap.tv_usec < 0) {
                gap.tv_sec = gap.tv_sec-1;
                gap.tv_usec = gap.tv_usec + 1000000;
        }
        pthread_join(p_thread[0],(void *)NULL);
        pthread_join(p_thread[1],(void *)NULL);

	printf("sum:%d\n",sum);
        printf("%ldsec : %ldusec\n\n", gap.tv_sec, gap.tv_usec);
}
