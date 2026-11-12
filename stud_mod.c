#include"header.h"
void stud_mod(void)
{
        ST *temp;
        int roll,found=0,c=0;
        char ch,name[20],newname[20];
        float per, newmarks;
        if(headptr==0)
        {
                printf("no records\n");
                        return;
        }
printf("enter which record to search for modification\n");
printf("R/r:rollno\n");
printf("N/n:name\n");
printf("P/p:per\n");
printf("enter your choice\n");
scanf("%c",&ch);
while(getchar()!='\n');
        if(ch=='R'||ch=='r')
        {
                printf("enter rollno: ");
                scanf("%d",&roll);
                while(getchar()!='\n');
        }
        else if(ch=='N'||ch=='n')
        {
                printf("enter name: ");
                scanf("%s",name);
                temp=headptr;
                while(temp!=0)
                {
                        if(strcmp(temp->name,name)==0)
                        {
                                printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
                                c++;
                        }
                                temp=temp->next;
                        }
                        if(c==0)
                        {
                                printf("no records\n");
                                return ;
                        }
                        printf("enter rollno to modify:");
                        scanf("%d",&roll);
                        while(getchar()!='\n');

        }

else if(ch=='P'||ch=='p')
        {
                printf("enter per: ");
                scanf("%f",&per);
                while(getchar()!='\n');
                temp=headptr;
                while(temp!=0)
                {
                        if(temp->marks==per)
                        {
                                printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
                                c++;
                        }
                                temp=temp->next;
                        }
                        if(c==0)
                        {
                                printf("no records\n");
                                return ;
                        }
                        printf("enter rollno to modify:");
                        scanf("%d",&roll);
                        while(getchar()!='\n');

        }

        else
        {
                printf("invalid\n");
                return ;
        }
temp=headptr;
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
{
        printf("no records");
        return;
}
printf("enter new name and percentage: ");
scanf("%s%f",newname,&newmarks);
strcpy(temp->name,newname);
temp->marks=newmarks;
printf("record modify");
}
