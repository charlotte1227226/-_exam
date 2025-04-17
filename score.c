#include<stdio.h>
#include<stdlib.h>
int main(){
    while(1){
        int pre_score[7]={0};
        int check[7]={0};
        // for(int i=0;i<7;i++){
        //     printf("pre_score[%d] = %d\n", i, pre_score[i]);
        //     printf("check[%d] = %d\n", i, check[i]);
        // }
        int Previous_score = 0;
        int Final_score = 0;
        printf("Yellow sheet score:\n");
        for(int i=0;i<7;i++){
            printf("Enter the score for question %d (Yellow sheet), enter -1 to exit:\n", i+1);
            scanf("%d",&pre_score[i]);
        }
        printf("\n");
        if(pre_score[0]==-1){
            break;
        }
        printf("White sheet score:\n");
        for(int i=0;i<7;i++){
            printf("Enter the score for question %d (white sheet), enter -1 to exit:\n", i+1);
            scanf("%d",&check[i]);
        }
        if(check[0]==-1){
            break;
        }
        for(int i=0;i<7;i++){
            Previous_score+=pre_score[i];
        }
        for(int i=0;i<7;i++){
            if(pre_score[i]<check[i]){
                Final_score+=check[i];
            }
            else{
                Final_score+=pre_score[i];
            }
        }
        printf("Previous_score = %d\n", Previous_score);
        printf("Final_score = %d\n", Final_score);
        printf("Do you want to continue? (Enter 1 to continue):\n");
        int continue_flag;
        scanf("%d", &continue_flag);
        if(continue_flag!=1){
            printf("You chose not to continue. Program ends.\n");
            break;
        }
        
    }
    return 0;
}

