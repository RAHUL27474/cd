#include<stdio.h>
int main(){
        FILE *out = fopen("output.txt","w");
        int n;
        printf("ENter nO>");
        scanf("%d",&n);
        for(int i =0;i<n;i++){
                char name[25];
                int marks;
                scanf("%s %d",name, &marks);
                fprintf(out,"%s %d \n", name, marks);
        }
        fclose(out);
        return 0;
}


