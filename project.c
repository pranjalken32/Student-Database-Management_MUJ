#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//structure
struct student
{
    int enroll_no;
    char name[100];
    char phone[100];
    char project[100];
    char faculty[100];
    int marks1;
    int marks2;
    int marks3;
    int total;
    struct student *next;



}; typedef struct student c1;
c1 *front=NULL,*rear=NULL,*student;
void insert(int enroll_no, char* name, char* phone, char *project,char *faculty,int marks1,int marks2,int marks3)
{
    
    student = (c1*) malloc(sizeof(c1));
    student->enroll_no = enroll_no;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    strcpy(student->project, project);
    strcpy(student->faculty, faculty);
    student->marks1 = marks1;
    student->marks2 = marks2;
    student->marks3 = marks3;
    student->total= marks1+marks2+marks3;
   
    rear=front;
    if(rear==NULL){
        // if head is NULL
        // set student as the new head
       student->next=student;
       front=student;
    }
    else if(rear->total>=student->total)
    {
        while(rear->next!=front)
        
            rear=rear->next;
            rear->next=student;
            student->next=front;
        student->next=front;
        front=student;
    
    }
    else
    {
        while (rear->next!= front && rear->next->total < student->total)
      rear = rear->next;
 
    student->next = rear->next;
    rear->next = student;
  }
    

}

void display()
{
    c1 *temp=front;
    if(front==NULL)
printf("\nEmpty");
else
{
do
{
 printf("\n %d \t %s\t %s \t %s \t %s \t  %d \t  %d \t  %d \n",temp->enroll_no,temp->name,temp->phone,temp->project,temp->faculty,temp->marks1,temp->marks2,temp->marks3);
temp=temp->next;
} while (temp!=front);
}
}

void updateproject(int enroll_no1)
{
    printf("\n");
	
    c1 *temp = front;
	do
    {
        if(temp->enroll_no==enroll_no1)
        {
			printf("Record with Enroll_no %d Found !!!\n", enroll_no1);
			printf("Enter New Project Info: ");
			scanf("%s", temp->project);
			return;
		}
		temp = temp->next;
    } while (temp!=front);
	
	printf("Student with roll number %d is not found !!!\n",enroll_no1);
	
}


void updatemarks()
{
    printf("\n");
	
    c1 *temp = front;


    
	do
    {
			printf("Update the Marks (mid presentation, final presentation, guide marks) for %d\n", temp->enroll_no);
			scanf("%d%d%d", &temp->marks1, &temp->marks2, &temp->marks3);
            temp->total= temp->marks1+temp->marks2+temp->marks3;
		    temp = temp->next;
    } while (temp!=front);

    //sorting
    
    c1 *temp1=front;
     while(temp1->next!=front)
    {

        c1 *temp2=(c1*) malloc(sizeof(c1));
        c1 *sort= (c1*) malloc(sizeof(c1));
        temp2=temp1->next;
        while(temp2!=front)
        {
            if(temp2->total < temp1->total)
            {
                sort->enroll_no = temp1->enroll_no;
                strcpy(sort->name, temp1->name);
                strcpy(sort->phone, temp1->phone);
                strcpy(sort->project, temp1->project);
                strcpy(sort->faculty, temp1->faculty);
                sort->marks1 = temp1->marks1;
                sort->marks2 = temp1->marks2;
                sort->marks3 = temp1->marks3;

                temp1->enroll_no = temp2->enroll_no;
                strcpy(temp1->name, temp2->name);
                strcpy(temp1->phone, temp2->phone);
                strcpy(temp1->project, temp2->project);
                strcpy(temp1->faculty, temp2->faculty);
                temp1->marks1 = temp2->marks1;
                temp1->marks2 = temp2->marks2;
                temp1->marks3 = temp2->marks3;


                temp2->enroll_no = sort->enroll_no;
                strcpy(temp2->name, sort->name);
                strcpy(temp2->phone, sort->phone);
                strcpy(temp2->project, sort->project);
                strcpy(temp2->faculty, sort->faculty);
                temp2->marks1 = sort->marks1;
                temp2->marks2 = sort->marks2;
                temp2->marks3 = sort->marks3;



                
            }

            temp2=temp2->next;

        }
         temp1=temp1->next;
    }



    
	
	printf("All marks Updated !!!\n");
	
}
int main ()
{
    int enroll_no,i,ch;
     char name[100], phone[100],  project[100], faculty[100];
     int marks1, marks2, marks3;
     int check;


     printf("\n 1 to Insert Student \n 2 Update project info of given Enrollment no. \n 3 Update marks of all student (mark individually \n 4 Display Student Information \n 5 Exit \n");
do{
       printf("Enter your choice \n");
       scanf("%d",&ch);
       switch(ch)
       {

           case 1:
                 printf("Initially enter the data for 5 students \n");
                 for(i=0;i<5;i++)
                     {
                          printf("Enter the Enrollment no.\n");
                         scanf("%d",&enroll_no);
                        printf("Enter the Name \n");
                        scanf("%s",name);
                        printf("Enter the Mobile no \n");
                        scanf("%s",phone);
                        printf("Enter Project name \n");
                        scanf("%s",project);
                        printf("Enter the Faculty assigned \n");
                        scanf("%s",faculty);
                        printf("Enter the Marks (mid presentation, final presentation, guide marks)\n");
                        scanf("%d%d%d",&marks1,&marks2,&marks3);
                        insert(enroll_no,name,phone,project,faculty,marks1,marks2,marks3); 
                        }
     

     break;

     case 2:
     
     printf("Enter the Enrollement no. to Update project info \n");
     scanf("%d",&check);
     updateproject(check);
     break;

     case 3:
     updatemarks();
     break;

     case 4:
     display();
     break;

     case 5:
     printf("Enter 0 to Exit");
     default:
     printf("Wrong Choice");



       }
}while(ch!=0);
return 0 ;
}
