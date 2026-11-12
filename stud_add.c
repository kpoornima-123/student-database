#include"header.h"
void stud_add(void)
{
        ST *new,*temp;
        int roll=1;
        new=malloc(sizeof(ST));
        if(new==0)
        {
                printf("memory not available\n");
                return;
        }
        while(1)
        {
                temp=headptr;
                int found=0;
                while(temp!=0)
                {
                        if(temp->rollno==roll)
                        {
                                found=1;
                                break;
                        }
                        temp=temp->next;
                }
                if(found==0)
                        break;
                roll++;
        }
        printf("enter name,marks\n");
        scanf("%s%f",new->name,&new->marks);
        new->rollno=roll;
        new->next=0;
        if(headptr==0)
        {
                headptr=new;
        }
        else
        {
                temp=headptr;
                while(temp->next!=0)
                        temp=temp->next;
                temp->next=new;
        }
        printf("rollno=%d\n",roll);
}
