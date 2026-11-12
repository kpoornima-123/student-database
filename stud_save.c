#include "header.h"
void stud_save(void)
{
    ST *temp = headptr;
    FILE *fp = fopen("student.dat", "w");
    if(fp==0){ printf("File not opened\n"); return; }
    while(temp != 0)
    {
        fprintf(fp, "%d %s %f\n", temp->rollno, temp->name, temp->marks);
        temp = temp->next;
    }
    fclose(fp);
    printf("Saved to student.dat\n");
}

int stud_exit(void)
{
    char ch;
    printf("Enter\n");
    printf("S / s : save and exit\n");
    printf("E / e : exit without saving\n");
    printf("Enter choice: ");
    scanf(" %c", &ch);
    while(getchar() != '\n');
    if(ch=='S'||ch=='s'){ stud_save(); return 1; }
    else if(ch=='E'||ch=='e'){ return 1; }
    else { printf("Invalid, not exiting\n"); return 0; }
}

void stud_sort(void)
{
    ST *i, *j;
    int t_roll;
    char t_name[20];
    float t_marks;
    char ch;
    if(headptr==0){ printf("no records found\n"); return; }

    printf("Enter\n");
    printf("N / n : sort with name\n");
    printf("P / p : sort with percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &ch);
    while(getchar() != '\n');

    for(i=headptr; i->next!=0; i=i->next)
    {
        for(j=i->next; j!=0; j=j->next)
        {
            int swap = 0;
            if((ch=='N'||ch=='n') && strcmp(i->name, j->name) > 0) swap = 1;
            if((ch=='P'||ch=='p') && i->marks > j->marks) swap = 1;
            if(swap)
            {
                t_roll = i->rollno; i->rollno = j->rollno; j->rollno = t_roll;
                strcpy(t_name, i->name); strcpy(i->name, j->name); strcpy(j->name, t_name);
                t_marks = i->marks; i->marks = j->marks; j->marks = t_marks;
            }
        }
    }
    printf("Sorted\n");
}

void stud_del_all(void)
{
    ST *temp;
    while(headptr != 0)
    {
        temp = headptr;
        headptr = headptr->next;
        free(temp);
    }
    printf("All records deleted\n");
}

void stud_rev(void)
{
    ST *prev = 0, *curr = headptr, *next = 0;
    while(curr != 0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    headptr = prev;
    printf("List reversed\n");
}
