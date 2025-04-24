#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *in = fopen("input.txt", "r");
    FILE *ev = fopen("even.txt","w");
    FILE *od = fopen("odd.txt","w");
    int ch;
    while(fscanf(in,"%d",&ch)==1){
            if(ch%2==0){
                fprintf(ev, "%d",ch);
            }else{
                fprintf(od, "%d",ch);
            }
    }
}