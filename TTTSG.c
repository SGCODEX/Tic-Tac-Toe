#include<stdio.h>
int win(int array[],int a);
int check(int ch,int array[]);
int isSubset(int arr1[], int arr2[]);
int main(){
    char choi='y';
    while(choi == 'y' || choi == 'Y')
    {
    int i,j,count=0,choice,count1=0,count2=0,final_flag=0;
    int db[9]={100,100,100,100,100,100,100,100,100};
    int db1[5]={100,100,100,100,100};
    int db2[5]={100,100,100,100,100};
    int b[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    printf("-----------------------------------------------------------------");
    printf("\n");
    printf("\n");
    printf("Welcome to Shivam's Multiplayer TIC TAC TOE\n");
    printf("\n");
    printf("Type the number(1-9) where you want to put your symbol\n");
    printf("\n");
    printf("Symbols -> Player1:11, Player2:22\n");
    printf("\n");
    printf("-----------------------------------------------------------------");
    printf("\n");
    printf("\n");
    printf("Lets's Start!!! Default Arena:\n");
    printf("\n");

    while(count<10){
    printf("------------------------------------------------\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(j<2){
                printf("\t%d\t|",b[i][j]);
            }
            else{
                printf("\t%d",b[i][j]);
            }
        }
        //printf("\n\t--\t\t--\t\t--",arr[i][j]);
        printf("\n------------------------------------------------");
        printf("\n");}

    if(count>=5 && count<=8){
        if(win(db1,1)){
            final_flag=1;
            break;
        }
        if(win(db2,2)){
            final_flag=1;
            break;
        }
        }
    count+=1;
    if(count==10){
        break;
    }
        choice=10;
        if(count%2==0)
        {
            printf("\nPlayer 2(TWO) choose number:");
            scanf("%d",&choice);
            printf("\n");
            choice=check(choice,db);          
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if (choice==b[i][j]){
                        b[i][j]=22;
                    }
                }
            }
            count2+=1;
            db2[count2-1]=choice;
            db[count-1]=choice;  
        }
        else{
            printf("\nPlayer 1(ONE) choose number:");
            scanf("%d",&choice);
            printf("\n");
            choice=check(choice,db);
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if (choice==b[i][j]){
                        b[i][j]=11;
                    }
                }
            }
            count1+=1;
            db1[count1-1]=choice;
            db[count-1]=choice;
        }
    }
    if(final_flag==0){
        printf("\nIt was a Tie. Better luck next time players");
    }

        printf("\nDo you wish to continue playing?(y/n)\n");
        scanf("%s",&choi);
        printf("Thank you for checking out my game.");
        sleep(5);
    }
    return 0;
}


int check(int ch,int array[])
{
    int k,final,num;
    for(k=0;k<9;k++)
    {
        if(array[k]==ch){
            printf("Sorry that number has already been chosen. ");
            printf("Please Re-enter another number:");
            scanf("%d",&num);
            printf("\n");
            ch=check(num,array);
        }
    }
    return ch;
}


int win(int array[],int a){
    int k,m,n;
    int wi[8][3]= {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
    int wii[3];
    for(k=0;k<8;k++){
        for(m=0;m<3;m++){
            wii[m]=wi[k][m];
        }
        if (isSubset(array,wii)){
            printf("Player %d have WON!!!, Congratulations",a);
            return 1;          
        }
    }
}


int isSubset(int arr1[], int arr2[])
{
    int flag = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
        if (j == 5)
            return 0;
    }
    return 1;
}
