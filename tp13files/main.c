#include <stdio.h>

#define STUDENT_NB 3

int writeToFile1(){
   char name[50];
   int marks,i;
   FILE *fptr;
   fptr=(fopen("./file.txt","a"));
   if(fptr==NULL){
       printf("Error!");
       exit(1);
   }
   for(i=0;i<STUDENT_NB;++i)
   {
      printf("For student%d\nEnter name: ",i+1);
      scanf("%s",name);
      printf("Enter marks: ");
      scanf("%d",&marks);
      fprintf(fptr,"\nName: %s \nMarks=%d \n",name,marks);
   }
   fclose(fptr);
   return 0;
}

struct student
{
char name[80];
int mark;
};

int writeToFile2(){
    struct student students[STUDENT_NB];
    FILE *fptr;
    int i;
    fptr=fopen("./file.txt","wb");
    for(i=0;i<STUDENT_NB;++i)
    {
        fflush(stdin);
        printf("Enter name: ");
        gets(students[i].name);
        printf("Enter mark: ");
        scanf("%d",&students[i].mark);
    }
    fwrite(students,sizeof(students),1,fptr);
    fclose(fptr);
}

int readFromFile1(){
    struct student students[STUDENT_NB];
    FILE *fptr;
    int i;
    fptr=fopen("./file.txt","rb");
    fread(students,sizeof(students),1,fptr);
    for(i=0;i<STUDENT_NB;++i)
    {
        printf("Name: %s\nMark: %d\n",students[i].name,students[i].mark);
    }
    fclose(fptr);
}

int readFromFile2 ()
{
   FILE *fp;
   int c;

   fp = fopen("./file.txt","r");
   while(1)
   {
      c = fgetc(fp);
      if( feof(fp) )
      {
         break;
      }
      printf("%c", c);
   }
   fclose(fp);
}

int main(){
    char name;
    //writeToFile2();
    readFromFile2();
    scanf("%s",name);
}
