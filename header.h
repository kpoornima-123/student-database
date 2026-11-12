#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct student
{
        int rollno;
        char name[20];
        float marks;
        struct student *next;
}ST;
extern ST *headptr;
void stud_add(void);
void stud_del(void);
void stud_show(void);
void stud_mod(void);
void stud_save(void);
void stud_sort(void);
void stud_del_all(void);
void stud_rev(void);
int stud_exit(void);
