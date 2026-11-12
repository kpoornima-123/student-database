#include"header.h"
void stud_show(void)
{
        ST *temp=headptr;
        if(temp==0)
        {
                printf("no records found\n");
                return;
        }
        while(temp!=0)
        {
                printf("rollno=%d name=%s marks=%f\n",temp->rollno,temp->name,temp->marks);
                temp=temp->next;
        }
}
