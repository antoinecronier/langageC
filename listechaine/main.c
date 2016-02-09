#include <stdio.h>
#include <stdlib.h>
#include "test.h"

#define RW_STRUCT struct student
#define STRUCT_ATTRIBUTS data->id,data->name,data->mark
#define LIST_STRUCT Dlist
#define LIST_STRUCT_LOWER dlist
#define STRUCT_FILE "./list.txt"

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

typedef struct LIST_STRUCT_LOWER
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
} LIST_STRUCT;

//Allow to display correct info of list items
void LIST_STRUCT_LOWER_printf_struct(RW_STRUCT* data)
{
    printf("%d %s %d\n",STRUCT_ATTRIBUTS);
}

//Create a new list
LIST_STRUCT *LIST_STRUCT_LOWER_new(void)
{
    LIST_STRUCT *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

//Add element at the end of the list
LIST_STRUCT *LIST_STRUCT_LOWER_append(LIST_STRUCT *p_list, RW_STRUCT data)
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
LIST_STRUCT *LIST_STRUCT_LOWER_prepend(LIST_STRUCT *p_list, RW_STRUCT data)
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
LIST_STRUCT *LIST_STRUCT_LOWER_insert(LIST_STRUCT *p_list, RW_STRUCT data, int position)
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
                    p_list = LIST_STRUCT_LOWER_append(p_list, data);
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list = LIST_STRUCT_LOWER_prepend(p_list, data);
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
void LIST_STRUCT_LOWER_delete(LIST_STRUCT **p_list)
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
void LIST_STRUCT_LOWER_display(LIST_STRUCT *p_list)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            LIST_STRUCT_LOWER_printf_struct(&p_temp->data);
            fflush(stdout);
            p_temp = p_temp->p_next;
        }
    }
    printf("\n");
}

//Remove the first item regarding the data parameter
LIST_STRUCT *LIST_STRUCT_LOWER_remove(LIST_STRUCT *p_list, RW_STRUCT* data)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            //TODO use struct here
            RW_STRUCT* current_data = malloc(sizeof(RW_STRUCT));
            current_data = &p_temp->data;

            if (current_data->id == data->id && current_data->name == data->name && current_data->mark == data->mark)
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

//Remove the first item regarding the id parameter
LIST_STRUCT *LIST_STRUCT_LOWER_remove_by_id(LIST_STRUCT *p_list, int id)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            //TODO use struct here
            RW_STRUCT* current_data = malloc(sizeof(RW_STRUCT));
            current_data = &p_temp->data;

            if (current_data->id == id)
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
LIST_STRUCT *LIST_STRUCT_LOWER_remove_all(LIST_STRUCT *p_list, int data)
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
LIST_STRUCT *LIST_STRUCT_LOWER_remove_position(LIST_STRUCT *p_list, int position)
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
size_t LIST_STRUCT_LOWER_length(LIST_STRUCT *p_list)
{
    size_t ret = 0;
    if (p_list != NULL)
    {
        ret = p_list->length;
    }
    return ret;
}

//Return choosen item to a new list
LIST_STRUCT *LIST_STRUCT_LOWER_find(LIST_STRUCT *p_list, RW_STRUCT data)
{
    LIST_STRUCT *ret = NULL;
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (&p_temp->data == &data)
            {
                ret = LIST_STRUCT_LOWER_new();
                ret = LIST_STRUCT_LOWER_append(ret, data);
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
LIST_STRUCT *LIST_STRUCT_LOWER_find_all(LIST_STRUCT *p_list, RW_STRUCT data)
{
    LIST_STRUCT *ret = NULL;
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            if (&p_temp->data == &data)
            {
                if (ret == NULL)
                {
                    ret = LIST_STRUCT_LOWER_new();
                }
                ret = LIST_STRUCT_LOWER_append(ret, data);
            }
            p_temp = p_temp->p_next;
        }
    }
    return ret;
}

//Print all ids
void LIST_STRUCT_LOWER_display_list_ids(int *values)
{
    while(*values != NULL){
        printf("%d ", *values);
        values++;
    }
    printf("\n");
}

//Return all ids of items
int* LIST_STRUCT_LOWER_get_list_ids(LIST_STRUCT *p_list)
{
    if (p_list != NULL)
    {
        size_t length = LIST_STRUCT_LOWER_length(p_list);
        int* values = malloc(sizeof(int)*length);
        int i = 0;
        RW_STRUCT* data = malloc(sizeof(RW_STRUCT));

        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            data = &p_temp->data;
            printf("%d ",data->id);
            values[i] = data->id;
            fflush(stdout);
            i++;
            p_temp = p_temp->p_next;
        }
        printf("\n");
        values[i] = NULL;
        return values;
    }
    return NULL;
}

//region saving/loading
//Write the whole list in a file
void LIST_STRUCT_LOWER_writeToFile(LIST_STRUCT *p_list){
    FILE *fptr;
    fptr=fopen(STRUCT_FILE,"w+");

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
LIST_STRUCT* LIST_STRUCT_LOWER_readFromFile(){
    LIST_STRUCT *p_list = LIST_STRUCT_LOWER_new();
    RW_STRUCT* data = malloc(sizeof(RW_STRUCT));
    FILE *fptr;

    fptr=fopen(STRUCT_FILE,"r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(data,sizeof(RW_STRUCT),1,fptr) == 1) {
            LIST_STRUCT_LOWER_append(p_list, *Student_ctor(STRUCT_ATTRIBUTS));
        }
        printf("\n");
    }

    fclose(fptr);

    return p_list;
}
//endregion



int main()
{
    LIST_STRUCT* myList = LIST_STRUCT_LOWER_new();

    //Create list items
    RW_STRUCT myItem = *Student_ctor(1,"roger",10);
    LIST_STRUCT_LOWER_append(myList,myItem);

    LIST_STRUCT_LOWER_append(myList,*Student_ctor(2,"ivan",12));
    LIST_STRUCT_LOWER_append(myList,*Student_ctor(3,"igor",6));
    LIST_STRUCT_LOWER_insert(myList,*Student_ctor(4,"ivon",16),1);
    LIST_STRUCT_LOWER_display(myList);

    printf("List size :%d\n",LIST_STRUCT_LOWER_length(myList));

    //Write Read
    LIST_STRUCT_LOWER_writeToFile(myList);
    LIST_STRUCT *newList = LIST_STRUCT_LOWER_readFromFile();
    LIST_STRUCT_LOWER_display(newList);

    //Display head item
    RW_STRUCT* retrieveItem = &newList->p_head->data;

    printf("Item pointer value : %d\n",retrieveItem);
    printf("%d %s %d\n",retrieveItem->id, retrieveItem->name, retrieveItem->mark);

    LIST_STRUCT_LOWER_display_list_ids(LIST_STRUCT_LOWER_get_list_ids(newList));
    //Dlist2* test = dlist2_new();

    printf("Remove check\n");
    LIST_STRUCT_LOWER_remove_by_id(newList,4);
    LIST_STRUCT_LOWER_display(newList);

    /*LIST_STRUCT_LOWER_remove_position(newList,1);
    LIST_STRUCT_LOWER_display(newList);*/
}
