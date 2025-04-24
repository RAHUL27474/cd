#include<stdio.h>
int main(){
        FILE *f1 = fopen("file.txt","r");
        FILE *f2 = fopen("temp.txt","w");
        int ltod, cnt=1;
        char str[100];
        printf("Enter the line");
        scanf("%d",&ltod);
        while(fgets(str, sizeof(str),f1)){
                if(cnt!=ltod){
                        fputs(str,f2);
                }cnt++;
        }
        fclose(f1);
        fclose(f2);
        remove("file.txt");
        rename("temp.txt","file.txt");
        return 0;
}



