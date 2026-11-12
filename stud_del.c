#include "header.h"
void stud_del(void)
{
	ST *temp, *prev;
	int roll, found = 0, count = 0;
	char ch, name[20];

	if(headptr == 0){ printf("no records found\n"); return; }

	printf("R / r : enter roll to del\n");
	printf("N / n : enter name to del\n");
	printf("Enter choice: ");
	scanf(" %c", &ch);
	while(getchar() != '\n');

	if(ch=='R' || ch=='r')
	{
		printf("Enter rollno to delete: ");
		scanf("%d", &roll);
		while(getchar() != '\n');
	}
	else if(ch=='N' || ch=='n')
	{
		printf("Enter name to delete: ");
		scanf("%s", name);
		temp = headptr;
		while(temp != 0)
		{
			if(strcmp(temp->name, name)==0)
			{
				printf("%d %s %f\n", temp->rollno, temp->name, temp->marks);
				count++;
			}
			temp = temp->next;
		}
		if(count==0)
		{ 
			printf("Record not found\n"); 
			return; 
		}
		printf("Enter rollno to delete from above: ");
		scanf("%d", &roll);
		while(getchar() != '\n');
	}
	else 
	{ 
		printf("Invalid choice\n"); 
		return; 
	}

	temp = headptr; prev = 0;
	while(temp != 0)
	{
		if(temp->rollno == roll)
		{
			found = 1; 
			break;
		}
		prev = temp; temp = temp->next;
	}
	if(found==0)
	{ 
		printf("Record not found\n"); 
		return; 
	}
	if(prev==0) headptr = temp->next;
	else prev->next = temp->next;
	free(temp);
	printf("Record deleted\n");
}
