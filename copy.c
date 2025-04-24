#include<stdio.h>
int main(){
        FILE*src = fopen("file.txt","r");
        FILE *dest = fopen("temp.txt","w");
        if(src==NULL || dest == NULL){printf("File error");return 1;}
        char ch;
        while((ch = fgetc(src))!=EOF){
                fputc(ch,dest);
        }
        fclose(src);
        fclose(dest);
        return 0;
}



