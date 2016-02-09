#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

struct student2
{
    int id;
    char* name;
    int mark;
};

typedef struct dlist2
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
} Dlist2;

Dlist2 *dlist2_new(void);

#endif // TEST_H_INCLUDED
