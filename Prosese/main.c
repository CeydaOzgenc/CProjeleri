#include<pthread.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
void *runner(void *thread){
    char *yaz= (char *)thread;
    char *sifreliyaz=malloc(300);
    char krk;
    int kac=2;
    for(int i=0;i<strlen(yaz);i++){
        if(yaz[i]==' '){
            sifreliyaz[i] = ' ';
            continue;
        }else{
            krk = (char) (((int) yaz[i]+kac));
            sifreliyaz[i] = krk;
        }
    }
    return sifreliyaz;
}

int main()
{
    int fd1[2];
    pid_t pid;

    if (pipe(fd1) == -1) {

            fprintf(stderr, "Pipe Failed");
            return 1;
        }
    pid = fork();

    if (pid == -1){
        printf("Fork gerçekleþtirilemedi...\n");
        exit(1);
    }else if (pid == 0){
        char concat_str[200],sifreli_str[200],*sifreliyaz;
        int shm_fd1,i=0;
        void * ptr;
        pthread_t threads[4];
        read(fd1[0], concat_str, 200);
        int uzunluk= strlen(concat_str),ceyrek=uzunluk/4,count=0;
        //printf("%d\n",uzunluk);
        char deneuzun[4][ceyrek];
        for(long i=0; i<4 ;i++){
            for (int j=0;j<ceyrek;j++){
                deneuzun[i][j]=concat_str[count];
                count+=1;
            }
            pthread_create(&threads[i],NULL,runner,(void *)deneuzun[i]);
            pthread_join(threads[i],(void **)&sifreliyaz);
            if (i==0){
               strcpy(sifreli_str,sifreliyaz);
            }else{
               strcat(sifreli_str,sifreliyaz);
            }    
        }
        shm_fd1=shm_open("OS",O_CREAT | O_RDWR,0666);
        ftruncate(shm_fd1,4096);
        ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd1,0);
        sprintf(ptr,"%s",sifreli_str);
        ptr+=strlen(sifreli_str);
        pthread_exit(NULL);
        close(fd1[0]);
        close(fd1[1]);
    }else{
        char *input_str="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt fiskuletp ut labore et dolore magna aliqua. Nam aliquam sem et tortor.";
        void * ptr;
        int shm_fd;
        write(fd1[1], input_str, strlen(input_str) + 1);
        wait(NULL);
        shm_fd=shm_open("OS",O_RDONLY,0666);
        ptr=mmap(0,4096,PROT_READ,MAP_SHARED,shm_fd,0);
        printf(ptr,"%s",(char *)ptr);
        shm_unlink("OS");
        close(fd1[1]);
        close(fd1[0]);
    }
    return 0;
}
