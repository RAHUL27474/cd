#include<stdio.h>
#include<ctype.h>

int main(){
FILE *inp = fopen("input.txt","r");
char ch;
int n = 0, l = 0, w = 0, c = 0;
int in = 0;
if(inp == NULL){
printf("OPEN FILE ERROR");
}
while((ch = fgetc(inp))!=EOF){
c++;
if(isdigit(ch)){
n++;
}
if(ch=='\n'){
l++;
}
if(isalpha(ch)){
if(!in){
w++;
in = 1;
}
}
else{
in = 0;
}
}
fclose(inp);
printf("NUMBERS: %d, CHARS: %d, WORDS:%d, LINES: %d\n",n,c,w,l);
return 0;
}