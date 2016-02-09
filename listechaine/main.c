#include <stdio.h>
#include <stdlib.h>

#define RW_STRUCT struct student
#define STRUCT_ATTRIBUTS data->id,data->name,data->mark

struct student
{
    int id;
    char* name;
    int mark;
};

struct student* Student_ctor(int id, char* name, int mark) {
  struct student* p = malloc(sizeof(struct student));
  p->id = id;
  p->name = name;
  p->mark = mark;
  return p;
}

struct node
{
    RW_STRUCT data;
    struct node *p_next;
    struct node *p_prev;
} Node;

typedef struct dlist
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
} Dlist;

//Allow to display correct info of list items
void printf_struct(RW_STRUCT* data)
{
    printf("%d %s %d\n",STRUCT_ATTRIBUTS);
}

//Create a new list
Dlist *dlist_new(void)
{
    Dlist *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

//Add element at the end of the list
Dlist *dlist_append(Dlist *p_list, RW_STRUCT data)
{
    if (p_list != NULL) /* On vérifie si notre liste a été allouée */
    {
        struct node *p_new = malloc(sizeof *p_new); /* Création d'un nouveau node */
        if (p_new != NULL) /* On vérifie si le malloc n'a pas échoué */
        {
            p_new->data = data; /* On 'enregistre' notre donnée */
            p_new->p_next = NULL; /* On fait pointer p_next vers NULL */
            if (p_list->p_tail == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
            {
                p_new->p_prev = NULL; /* On fait pointer p_prev vers NULL */
                p_list->p_head = p_new; /* On fait pointer la tête de liste vers le nouvel élément */
                p_list->p_tail = p_new; /* On fait pointer la fin de liste vers le nouvel élément */
            }
            else /* Cas où des éléments sont déjà présents dans notre liste */
            {
                p_list->p_tail->p_next = p_new; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
                p_new->p_prev = p_list->p_tail; /* On fait pointer p_prev vers le dernier élément de la liste */
                p_list->p_tail = p_new; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
            }
            p_list->length++; /* Incrémentation de la taille de la liste */
        }
    }
    return p_list; /* on retourne notre nouvelle liste */
}

//Add element at start of the list
Dlist *dlist_prepend(Dlist *p_list, RW_STRUCT data)
{
    if (p_list != NULL)
    {
        struct node *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->data = data;
            p_new->p_prev = NULL;
            if (p_list->p_tail == NULL)
            {
                p_new->p_next = NULL;
                p_list->p_head = p_new;
                p_list->p_tail = p_new;
            }
            else
            {
                p_list->p_head->p_prev = p_new;
                p_new->p_next = p_list->p_head;
                p_list->p_head = p_new;
            }
            p_list->length++;
       }
    }
    return p_list;
}

//Insert an element at the position choice
//Warning: position have to start to 1 and end to the current number of items
//Warning: use only if you already have an item in the list
Dlist *dlist_insert(Dlist *p_list, RW_STRUCT data, int position)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list = dlist_append(p_list, data);
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list = dlist_prepend(p_list, data);
                }
                else
                {
                    struct node *p_new = malloc(sizeof *p_new);
                    if (p_new != NULL)
                    {
                        p_new->data = data;
                        p_temp->p_next->p_prev = p_new;
                        p_temp->p_prev->p_next = p_new;
                        p_new->p_prev = p_temp->p_prev;
                        p_new->p_next = p_temp;
                        p_list->length++;
                    }
                }
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}

//This will unallocate the entire list this cannot be access after
void dlist_delete(Dlist **p_list)
{
    if (*p_list != NULL)
    {
        struct node *p_temp = (*p_list)->p_head;
        while (p_temp != NULL)
        {
            struct node *p_del = p_temp;
            p_temp = p_temp->p_next;
            free(p_del);
        }
        free(*p_list), *p_list = NULL;
    }
}

//This display the list
void dlist_display(Dlist *p_list)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            printf_struct(&p_temp->data);
            fflush(stdout);
            p_temp = p_temp->p_next;
        }
    }
    printf("\n");
}

//Remove the first item regarding the data parameter
Dlist *dlist_remove(Dlist *p_list, RW_STRUCT data)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (&p_temp->data == &data)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list->p_tail = p_temp->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list->p_head = p_temp->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
                found = 1;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return p_list;
}

//Remove all items regarding the data parameter
Dlist *dlist_remove_all(Dlist *p_list, int data)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            if (&p_temp->data == &data)
            {
                struct node *p_del = p_temp;
                p_temp = p_temp->p_next;
                if (p_del->p_next == NULL)
                {
                    p_list->p_tail = p_del->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_del->p_prev == NULL)
                {
                    p_list->p_head = p_del->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_del->p_next->p_prev = p_del->p_prev;
                    p_del->p_prev->p_next = p_del->p_next;
                }
                free(p_del);
                p_list->length--;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return p_list;
}

//Remove item with selected position
Dlist *dlist_remove_id(Dlist *p_list, int position)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list->p_tail = p_temp->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list->p_head = p_temp->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}

//Return current list size
size_t dlist_length(Dlist *p_list)
{
    size_t ret = 0;
    if (p_list != NULL)
    {
        ret = p_list->length;
    }
    return ret;
}

//Return choosen item to a new list
Dlist *dlist_find(Dlist *p_list, RW_STRUCT data)
{
    Dlist *ret = NULL;
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (&p_temp->data == &data)
            {
                ret = dlist_new();
                ret = dlist_append(ret, data);
                found = 1;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return ret;
}

//Return all choosen items to a new list
Dlist *dlist_find_all(Dlist *p_list, RW_STRUCT data)
{
    Dlist *ret = NULL;
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            if (&p_temp->data == &data)
            {
                if (ret == NULL)
                {
                    ret = dlist_new();
                }
                ret = dlist_append(ret, data);
            }
            p_temp = p_temp->p_next;
        }
    }
    return ret;
}

//region saving/loading
//Write the whole list in a file
void writeToFile(Dlist *p_list){
    FILE *fptr;
    fptr=fopen("./list.txt","w+");

    RW_STRUCT* data = malloc(sizeof(RW_STRUCT));
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            data = &p_temp->data;
            fwrite(data,sizeof(RW_STRUCT),1,fptr);
            p_temp = p_temp->p_next;
        }
        printf("\n");
    }
    fclose(fptr);
}

//Read a list of structure to display it
Dlist* readFromFile(){
    Dlist *p_list = dlist_new();
    RW_STRUCT* data = malloc(sizeof(RW_STRUCT));
    FILE *fptr;

    fptr=fopen("./list.txt","r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(data,sizeof(RW_STRUCT),1,fptr) == 1) {
            dlist_append(p_list, *Student_ctor(STRUCT_ATTRIBUTS));
        }
        printf("\n");
    }

    fclose(fptr);

    return p_list;
}
//endregion



int main()
{
    Dlist* myList = dlist_new();

    RW_STRUCT myItem = *Student_ctor(1,"roger",10);

    dlist_append(myList,myItem);
    dlist_append(myList,*Student_ctor(2,"ivan",12));
    dlist_append(myList,*Student_ctor(3,"igor",6));
    printf("List size :%d\n",dlist_length(myList));
    dlist_display(myList);

    dlist_insert(myList,*Student_ctor(4,"ivon",16),1);
    dlist_display(myList);

    /*dlist_insert(myList,32,4);
    dlist_display(myList);

    dlist_insert(myList,22,1);
    dlist_display(myList);

    dlist_insert(myList,42,4);
    dlist_display(myList);*/

    printf("List size :%d\n",dlist_length(myList));

    /*dlist_delete(myList);
    dlist_display(myList);*/

    /*dlist_append(myList,101);
    dlist_append(myList,102);
    dlist_display(myList);

    printf("List size :%d\n",dlist_length(myList));

    dlist_remove(myList, 100);
    dlist_display(myList);

    printf("List size :%d\n",dlist_length(myList));

    dlist_append(myList,42);

    printf("List size :%d\n",dlist_length(myList));

    dlist_append(myList,42);

    printf("List size :%d\n",dlist_length(myList));

    dlist_append(myList,42);
    dlist_display(myList);

    printf("List size :%d\n",dlist_length(myList));*/

    /*dlist_remove_all(myList,42);
    dlist_display(myList);

    printf("List size :%d\n",dlist_length(myList));*/

    /*dlist_remove_id(myList, 1);
    dlist_display(myList);

    printf("List size :%d\n",dlist_length(myList));

    Dlist *finded = dlist_find(myList, 42);
    dlist_display(finded);

    Dlist *findedall = dlist_find_all(myList, 42);
    dlist_display(findedall);*/

    //Display head item
    RW_STRUCT* retrieveItem = &myList->p_head->data;

    printf("%d\n",retrieveItem);
    printf("%d %s %d\n",retrieveItem->id, retrieveItem->name, retrieveItem->mark);

    printf("Start write\n");
    writeToFile(myList);
    printf("Start read\n");
    Dlist *newList = readFromFile();
    printf("Print extracted list\n");
    dlist_display(newList);

    //Display head item
    retrieveItem = &newList->p_head->data;

    printf("%d\n",retrieveItem);
    printf("%d %s %d\n",retrieveItem->id, retrieveItem->name, retrieveItem->mark);
}
