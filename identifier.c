#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
const char *keywords[] = {
    "auto","break","case","char","const","continue","default","do",
    "double","else","enum","extern","float","for","goto","if",
    "int","long","register","return","short","signed","sizeof",
    "static","struct","switch","typedef","union","unsigned","void",
    "volatile","while","_Packed"
};
int is_keyword(const char *word){
        for(int i =0;i<sizeof(keywords)/sizeof(keywords[0]);i++){
                if(strcmp(word, keywords[i])==0)return 1;
        }
        return 0;
}
int is_identi(const char *word){
        if(!isalpha(word[0]) && word[0]!='_')return 0;
        for(int i =1;word[i];i++){
                if(!isalnnum(word[i]) && word[i] !='_')return 0;
        }
        return !iskeyword(word);
}
int main(){
        FILE* in = fopen("input.txt","r");
        FILE *out = fopen("output.txt","w");
        char ch, word[100];
        int i =0;
        while((ch = fget(in))!=EOF){
                if(isapha(ch)||ch=='_'){
                        word[i++];
                }else{
                        word[i] = '\0';
                        if(i>0){
                                if(isidenti(word)){fprintf("'%s' is a identifier",word);}
                                else{fprintf("'%s' is not a identifier",word);                                i=0;
                                }
                        }
                }
                fclose(in);
                fclose(out);
                return 0;
        }
}