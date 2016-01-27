#include <stdio.h>
#include <stdlib.h>

void usingBasic(){
    int n,i,ptr,sum=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of array: ");
    for(i=0;i<n;++i)
    {
        scanf("%d", &ptr);
        sum+=ptr;
    }
    printf("Sum=%d",sum);
    return 0;
}

//From http://www.programiz.com/c-programming/c-dynamic-memory-allocation
void usingMalloc(){
    int n,i,*ptr,sum=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));  //memory allocated using malloc
    if(ptr==NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
    printf("Enter elements of array: ");
    for(i=0;i<n;++i)
    {
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
    printf("Sum=%d",sum);
    free(ptr);
    return 0;
}

//From http://www.programiz.com/c-programming/c-dynamic-memory-allocation
void usingCalloc(){
    int n,i,*ptr,sum=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    if(ptr==NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
    printf("Enter elements of array: ");
    for(i=0;i<n;++i)
    {
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
    printf("Sum=%d",sum);
    free(ptr);
    return 0;
}

//From http://www.programiz.com/c-programming/c-dynamic-memory-allocation
void usingRealloc(){
    int *ptr,i,n1,n2;
    printf("Enter size of array: ");
    scanf("%d",&n1);
    ptr=(int*)malloc(n1*sizeof(int));
    printf("Address of previously allocated memory: ");
    for(i=0;i<n1;++i)
         printf("%u\t",ptr+i);
    printf("\nEnter new size of array: ");
    scanf("%d",&n2);
    ptr=realloc(ptr,n2);
    for(i=0;i<n2;++i)
         printf("%u\t",ptr+i);
    return 0;
}

int main(){
    usingBasic();
    usingMalloc();
    usingCalloc();
    usingRealloc();
}
