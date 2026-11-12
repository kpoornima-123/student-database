#include"header.h"
ST *headptr=0;
int main()
{
        char ch;
        FILE *fp;
        ST *new,*temp;
        fp=fopen("student.dat","r");
        if(fp!=0)
        {
                while(1)
                {
                        new=malloc(sizeof(ST));
                        if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks)!=3)
                        {
                                free(new);
                                break;
                        }
                        new->next=0;
                        if(headptr==0)
                                headptr=new;
                        else
                        {
                                temp=headptr;
                                while(temp->next!=0)
                                        temp=temp->next;
                                temp->next=new;
                        }

                }
        }
        while(1)
        {
                printf("****STUDENT RECORD MENU******\n");
                printf("a/A:add new record\n");
                printf("d/D:delete a record\n");
                printf("s/S:show the list\n");
                printf("m/M:modify a record\n");
                printf("v/V:save\n");
                printf("e/E: exit\n");
                printf("t/T:sort\n");
                printf("l/L:delete all\n");
                printf("r/R: reverse\n");
                printf("enter your  choice:");
                scanf(" %c",&ch);
                while(getchar()!='\n');
                if(ch=='a'||ch=='A')
                        stud_add();
                else if(ch=='d'||ch=='D')
                        stud_del();
                else if(ch=='s'||ch=='S')
                        stud_show();
                else if(ch=='m'||ch=='M')
                        stud_mod();

                else if(ch=='v'||ch=='V')
                        stud_save();
                else if(ch=='t'||ch=='T')
                        stud_sort();
                else if(ch=='l'||ch=='L')
                        stud_del_all();
                else if(ch=='r'||ch=='R')
                        stud_rev();
                else if(ch=='e'||ch=='E')
                {
                        if(stud_exit()==1)
                                break;
                }
                else
                        printf("invalid choice\n");
        }
        return 0;
}
