#include <stdio.h>
#include <string.h>

int isStopWord(char *word, FILE *stopfile){
        char stop[50];
        rewind(stopfile);
        while(fscanf(stopfile, "%s",stop)!=EOF){
                if(strcmp(stop,word)==0)return 1;
        }
        return 0;
}
int main(){
        FILE *stop = fopen("stopwords.txt","r");
        FILE *story = fopen("story.txt","r");
        FILE *out = fopen("output.txt","w");
        char word[50];
        while(fscanf(story,"%s",word)!=EOF){
                if(!isStopWord(word,stop))fprintf(out,"%s",word);
        }
        fclose(stop);
        fclose(story);
        fclose(out);
        return 0;
}







