#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int mon = 5000;
int pay = 150;
int k = 60;
int start = 0;
int mid = 0;
int end = 0;

void Out(){
    
    
    printf ("Your val  = %d %d %d\n" , start, mid, end);    
    printf ("Money  = %d\n", mon);  
}

void randV(){
    start = rand() % 8;
    mid = rand () % 8;
    end = rand () % 8;
}

int giveprize(){
    int prize = 0;
    
    if (start <= 4){
        if ((start == mid) && (mid == end)) 
        prize = (start + 1) * k;
    }
    if ((start==6) && (mid==6) && (end=6)) {
    return -1;
    }
   
    if (start ==5 || start == 7){
        if((start == 7) && (mid == 7) && (end == 7)) 
        return 100;
        else
        prize = (start + 1) * k;
}

    return prize;
}



void runmoney(){
    while ((mon - pay) >= 0) {
        randV();
        //printf("\n\n RUNWH    f = %d, s = %d, t = %d, pr = %d\n\n", first, second, third, winCheck());
        mon = mon - pay + giveprize();
        printf("Your prize = %d\n",giveprize());
        Out();
        if (giveprize() == 1) {
            printf("You win!\n");            
            exit(1);
        }
        if(giveprize() == 2){
            printf("You failed!\n");          
            exit(0);
        }  
    }
    printf("You don`t have money. \n");          
    exit(0);

}


int main(){

    int i;
    srand(time(NULL));
    printf("Your money = %d\n", mon);
    runmoney();
    
    return 0;
}
