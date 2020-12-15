#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

void combine()
{
	int i;
	int v[1000000];
	int x=0;
	int sum;
	for(i=0;i<1000000;i++)
	{
		v[i]=i;
	}
	for(i=0;i<1000000;i++)
	{
		x=x+v[i];
	}
	sum=x;
	printf("sum:%d\n",sum);
}

int main()
{
	struct timeval stime,etime,gap;
	gettimeofday(&stime,NULL);
	combine();
	gettimeofday(&etime,NULL);
	gap.tv_sec = etime.tv_sec - stime.tv_sec;
        gap.tv_usec = etime.tv_usec - stime.tv_usec;
        if (gap.tv_usec < 0) {
                gap.tv_sec = gap.tv_sec-1;
                gap.tv_usec = gap.tv_usec + 1000000;
        }
        printf("%ldsec : %ldusec\n\n", gap.tv_sec, gap.tv_usec);
}
