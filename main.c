#include "1.h"

int main(){
    int number = 0;
    while(number != 5){
        printf("=====================================================================\n");
        printf("Which sport you would like to calculate win probability?\n");
        printf("{1: Tennis}\n");
        printf("{5: Terminate the program}\n");
        printf("Enter the integer corresponding to the sport:");
        scanf("%d", &number);
        switch(number){
            case 1:{
                float pro;
                printf("Enter your win probability for each rally in Tennis in percentage (0.0 - 100.00):");
                scanf("%f", &pro);
                if(!((0 <= pro)&&(pro <= 100))){
                    printf("Invalid percentage!\n");
                    break;
                }
                printf(">>>Your probability of winning a Tennis game is %.5Lf%%\n", tennis_game(pro));
                printf(">>>Your probability of winning a Tennis set is %.5Lf%%\n", tennis_set(pro));
                printf(">>>Your probability of winning a Tennis match is %.5Lf%%\n", tennis_match(pro));
                break;
            }
            case 5:{
                break;
            }
            default:{
                printf("Invalid integer!\n");
            }

        }
    }
   
    return 0;
}