#include <aio.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <asm/unistd.h>
#define MAX 10

int total_car;

typedef struct car_produce {
           int car_num;
           int arr_time;
           int ser_time;
} car_produce;

typedef struct Node {
           car_produce *data;
           struct Node *next;
}Node;

typedef struct car_queue {
           int balance;               //노드 개수(큐에 존재하는 차량 개수)
           Node *front, *rear;
      pthread_mutex_t headLock;
      pthread_mutex_t tailLock;
      pthread_mutex_t mutex;
} CQ;

typedef struct th_struct2 {      //구매자
           CQ *q;
           int con_type;
}th2;

void InitQueue(CQ *q)
{
           q->front=q->rear=NULL;
           q->balance = 0;
      pthread_mutex_init(&q->headLock,NULL);
      pthread_mutex_init(&q->tailLock,NULL);
      pthread_mutex_init(&q->mutex,NULL);
}

int IsEmpty(CQ *q)
{
        return q->balance == 0;
}

car_produce car[5];

/*void car_workload(int n)
{
           car[0].arr_time = 0;
           car[0].car_num = 1;
           car[0].ser_time = n * (0.2);

           car[1].arr_time = 0;
           car[1].car_num = 2;
           car[1].ser_time = n * (0.2);

           car[2].arr_time = 0;
           car[2].car_num = 3;
           car[2].ser_time = n * (0.2);

           car[3].arr_time = 0;
           car[3].car_num = 4;
           car[3].ser_time = n * (0.2);

           car[4].arr_time = 0;
           car[4].car_num = 5;
           car[4].ser_time = n * (0.2);
}*/


void Enqueue(CQ *q, int car_type) {
        Node *now = (Node *)malloc(sizeof(Node));
        now->data = (car_produce *)malloc(sizeof(car_produce));
        now->data->car_num = car_type;
   now->next=NULL;

        if(IsEmpty(q))
        {
                q->front=q->rear= now;
        }
        else {
                q->rear->next = now;
        }
        q->rear = now;
        q->balance++;
}

int Dequeue(CQ *q) {
        int re=0;
        Node *now;
        if(IsEmpty(q)) {
                return 0;
        }
        now = q->front;
        q->front = now->next;
        re=now->data->car_num;
        q->balance--;
   free(now);
        return re;
}

pthread_cond_t empty, fill;


//---------------------no lock-----------------------//
void *producer(void *q)
{
   CQ *q_ = (CQ *)q;
        int i = 0;
        while(i<total_car)
          {
                for(int j=0; j<5; j++)
             {
                        Enqueue(q_, j+1);
                        i++;
                }
        }
}

void *consumer(void *th) {
        th2 *myth2 = (th2 *)th;
        //myth2->q = (CQ *)malloc(sizeof(CQ));
        myth2->q->front = (Node *)malloc(sizeof(Node));
        myth2->q->front->data = (car_produce *)malloc(sizeof(car_produce));
        int i = 0;
        for(i=0; i<total_car*0.2;i++) {
                if(myth2->con_type == myth2->q->front->data->car_num) {
         Dequeue(myth2->q);

                }
                else {
                        i--;
                }
        }
}


//------------------fine-grained lock---------------------//
void *producer_fine(void *q) {
        CQ *q_ = (CQ *)q;
        int i = 0;
        while(i<total_car) {
                for(int j=0; j<5; j++) {
                        pthread_mutex_lock(&q_->tailLock);
                        while(q_->balance==MAX)       
                              pthread_cond_wait(&empty,&q_->tailLock);        
                        Enqueue(q_, j+1);
                        i++;
                        pthread_cond_signal(&fill);
                        pthread_mutex_unlock(&q_->tailLock);
                }
        }
}

void *consumer_fine(void *th) {
        th2 *myth2 = (th2 *)th;
        myth2->q->front = (Node *)malloc(sizeof(Node));
        myth2->q->front->data = (car_produce *)malloc(sizeof(car_produce));
        int i = 0;
        for(i=0; i<total_car*0.2;i++) {
                if(myth2->con_type == myth2->q->front->data->car_num) {
                        pthread_mutex_lock(&myth2->q->headLock);
                        while(myth2->q->balance==0)
                              pthread_cond_wait(&fill,&myth2->q->headLock);
                        Dequeue(myth2->q);
                        pthread_cond_signal(&empty);
                        pthread_mutex_unlock(&myth2->q->headLock);

                }
                else {
                        i--;
                }
        }
}

//-----------------coarse-grained lock--------------------//


void *producer_c(void *q) {
        CQ *q_ = (CQ *)q;
        int i = 0;
        while(i<total_car) {
                for(int j=0; j<5; j++) {
                        pthread_mutex_lock(&q_->mutex);
                        while(q_->balance==MAX)       
                              pthread_cond_wait(&empty,&q_->mutex);        
                        Enqueue(q_, j+1);
                        i++;
                        pthread_cond_signal(&fill);
                        pthread_mutex_unlock(&q_->mutex);
                }
        }
}

void *consumer_c(void *th) {
        th2 *myth2 = (th2 *)th;
        myth2->q->front = (Node *)malloc(sizeof(Node));
        myth2->q->front->data = (car_produce *)malloc(sizeof(car_produce));
        int i = 0;
        for(i=0; i<total_car*0.2;i++) {
                if(myth2->con_type == myth2->q->front->data->car_num) {
                        pthread_mutex_lock(&myth2->q->mutex);
                        while(myth2->q->balance==0)
                              pthread_cond_wait(&fill,&myth2->q->mutex);
                        Dequeue(myth2->q);
                        pthread_cond_signal(&empty);
                        pthread_mutex_unlock(&myth2->q->mutex);

                }
                else {
                        i--;
                }
        }
}




void lab2_sync_usage(char *cmd) {
           printf("\n Usage for %s : \n", cmd);
           printf("    -c: Total number of vehicles produced, must be bigger than 0 ( e.g. 100 )\n");
           printf("    -q: RoundRobin Time Quantum, must be bigger than 0 ( e.g. 1, 4 ) \n");
}

void lab2_sync_example(char *cmd) {
           printf("\n Example : \n");
           printf("    #sudo %s -c=100 -q=1 \n", cmd);
           printf("    #sudo %s -c=10000 -q=4 \n", cmd);
}

int main(int argc, char* argv[]) {
           int n; char junk;
           int time_quantum = 0;
           total_car = 0;
           struct timeval stime, etime;
           double gap;

           CQ c_buffer;
           InitQueue(&c_buffer);
           pthread_t p_thread[6];

           if (argc <= 1) {
                   lab2_sync_usage(argv[0]);
                   lab2_sync_example(argv[0]);
                   exit(0);
           }


           for (int i = 1; i < argc; i++) {
                   if (sscanf(argv[i], "-c=%d%c", &n, &junk) == 1) {
                           total_car = n;
                   }
                   else if (sscanf(argv[i], "-q=%d%c", &n, &junk) == 1) {
                           time_quantum = n;
                   }
                   else {
                           lab2_sync_usage(argv[0]);
                           lab2_sync_example(argv[0]);
                           exit(0);
                   }
           }



           th2 *th_2[5];

           for (int i = 0; i < 5; i++)
                   th_2[i] = (th2 *)malloc(sizeof(th2));
           for (int i = 0; i < 5; i++) {
                   th_2[i]->con_type = i + 1;
           }
           for (int i = 0; i < 5; i++) {
                   th_2[i]->q = &c_buffer;
           }

       printf("===Vehicle Production Problem ===\n");
       printf("===================(1) No Lock Experiment==================\n");
            gettimeofday(&stime, NULL);
            pthread_create(&p_thread[0], NULL, producer, &c_buffer);       
            pthread_create(&p_thread[1], NULL, consumer, (void *)th_2[0]);
            pthread_create(&p_thread[2], NULL, consumer, (void *)th_2[1]);
            pthread_create(&p_thread[3], NULL, consumer, (void *)th_2[2]);
            pthread_create(&p_thread[4], NULL, consumer, (void *)th_2[3]);
            pthread_create(&p_thread[5], NULL, consumer, (void *)th_2[4]);

            pthread_join(p_thread[0], (void *)NULL);
            pthread_join(p_thread[1], (void *)NULL);
            pthread_join(p_thread[2], (void *)NULL);
            pthread_join(p_thread[3], (void *)NULL);
            pthread_join(p_thread[4], (void *)NULL);
            pthread_join(p_thread[5], (void *)NULL);


            gettimeofday(&etime, NULL);
            gap = etime.tv_sec - stime.tv_sec;
            gap = gap + (etime.tv_usec - stime.tv_usec)*0.000001;
       printf("Experiment Info\n");
            printf("\tTotal Produce Number = %d\n", total_car);
       printf("\tFinal Balance Value = %d\n", c_buffer.balance);
       printf("\tExecution time = %lfsec\n\n", gap);

       printf("==================(2) Fine-grained Experiment==================\n");
            gettimeofday(&stime, NULL);
            pthread_create(&p_thread[0], NULL, producer_fine, &c_buffer);
            pthread_create(&p_thread[1], NULL, consumer_fine, (void *)th_2[0]);
            pthread_create(&p_thread[2], NULL, consumer_fine, (void *)th_2[1]);
            pthread_create(&p_thread[3], NULL, consumer_fine, (void *)th_2[2]);
            pthread_create(&p_thread[4], NULL, consumer_fine, (void *)th_2[3]);
            pthread_create(&p_thread[5], NULL, consumer_fine, (void *)th_2[4]);

            pthread_join(p_thread[0], (void *)NULL);
            pthread_join(p_thread[1], (void *)NULL);
            pthread_join(p_thread[2], (void *)NULL);
            pthread_join(p_thread[3], (void *)NULL);
            pthread_join(p_thread[4], (void *)NULL);
            pthread_join(p_thread[5], (void *)NULL);


            gettimeofday(&etime, NULL);
            gap = etime.tv_sec - stime.tv_sec;
            gap = gap + (etime.tv_usec - stime.tv_usec)*0.000001;
            printf("Experiment Info\n");
            printf("\tTotal Produce Number = %d\n", total_car);
            printf("\tFinal Balance Value = %d\n", c_buffer.balance);
            printf("\tExecution time = %lfsec\n\n", gap);


       printf("==================(3) Coarse-grained Lock Experiment==================\n");
            gettimeofday(&stime, NULL);
            pthread_create(&p_thread[0], NULL, producer_c, &c_buffer);
            pthread_create(&p_thread[1], NULL, consumer_c, (void *)th_2[0]);
            pthread_create(&p_thread[2], NULL, consumer_c, (void *)th_2[1]);
            pthread_create(&p_thread[3], NULL, consumer_c, (void *)th_2[2]);
            pthread_create(&p_thread[4], NULL, consumer_c, (void *)th_2[3]);
            pthread_create(&p_thread[5], NULL, consumer_c, (void *)th_2[4]);

            pthread_join(p_thread[0], (void *)NULL);
            pthread_join(p_thread[1], (void *)NULL);
            pthread_join(p_thread[2], (void *)NULL);
            pthread_join(p_thread[3], (void *)NULL);
            pthread_join(p_thread[4], (void *)NULL);
            pthread_join(p_thread[5], (void *)NULL);


            gettimeofday(&etime, NULL);
            gap = etime.tv_sec - stime.tv_sec;
            gap = gap + (etime.tv_usec - stime.tv_usec)*0.000001;
            printf("Experiment Info\n");
            printf("\tTotal Produce Number = %d\n", total_car);
            printf("\tFinal Balance Value = %d\n", c_buffer.balance);
            printf("\tExecution time = %lfsec\n\n", gap);

            return 0;

       
}
