#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct student
{
        int rollno;
        char name[20];
        float marks;
        struct student * next;
}SLL;
void addbegin(SLL**);
void printnode(SLL*);
int countnode(SLL*);
void savefile(SLL*);
void reverseprint(SLL*);
void addend(SLL **);
void readfile(SLL **);
void printrecursion(SLL*);
void reverserecursion(SLL*);
void deleteallnode(SLL **ptr);
void searchnode(SLL *ptr);
void sortdata(SLL *ptr);
void deletenode(SLL **ptr);
void reverselink(SLL **ptr);
int main()
{
        SLL* headptr=0;
        int op,c;
        while(1)
        {
                printf("ENTER YOUR CHOICE\n");
                printf("1) add_begin 2) add_end 3) print_node 4) count_node 5) save_file 6) read_file 7) reverse_print 8) print_recurson 9) rev_recursion 10) delete_all 11) delete_node 12) search_node 13) sort_data 14) reverse_link 15) exit\n");
                scanf("%d",&op);
                switch(op)
                {
                        case 1:addbegin(&headptr); break;
                        case 2:addend(&headptr); break;
                        case 3:printnode(headptr); break;
                        case 4:c=countnode(headptr);
                              printf("count:%d\n",c); break;
                        case 5:savefile(headptr); break;
                        case 6:readfile(&headptr); break;
                        case 7:reverseprint(headptr); break;
                        case 8:printrecursion(headptr); break;
                        case 9:reverserecursion(headptr); break;
                        case 10:deleteallnode(&headptr); break;
                        case 11:deletenode(&headptr); break;
                        case 12:searchnode(headptr); break;
                        case 13:sortdata(headptr); break;
                        case 14:reverselink(&headptr); break;
                        case 15:exit(0);
                        default:printf("UNKNOWN CHOICE\n");
                }
        }
}

void addbegin(SLL **ptr)
{
        SLL* new;
        new=malloc(sizeof(SLL));
        printf("ENTER THE ROLLNO,NAME,MARKS\n");
        scanf("%d %s %f",&new->rollno,new->name,&new->marks);
        new->next=*ptr;
        *ptr=new;
}
void printnode(SLL *ptr)
{
        if(ptr==0)
        {
                printf("no records found\n");
                return;
        }
        while(ptr)
        {
                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
                ptr=ptr->next;
        }
}
int countnode(SLL *ptr)
{
        int c=0;
        while(ptr)
        {
                c++;
                ptr=ptr->next;
        }
        return c;
}
void savefile(SLL *ptr)
{
        if(ptr==0)
        {
                printf("NO RECORDS FOUND\n");
                return;
        }

        FILE*fp=fopen("std.txt","w");

        while(ptr)
        {
                fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
                ptr=ptr->next;
        }
        fclose(fp);
}
void reverseprint(SLL *ptr)
{
        if(ptr==0)
        {
                printf("NO RECORDS FOUND\n");
                return;
        }
        SLL *t;
        int i,j,c=countnode(ptr);
        for(i=0;i<c;i++)
        {
                t=ptr;
                for(j=0;j<c-1-i;j++)
                        t=t->next;

                printf("%d %s %f\n",t->rollno,t->name,t->marks);
        }
}
void addend(SLL **ptr)
{
        SLL *new;
        new=malloc(sizeof(SLL));
        printf("ENTER ROLLNO,NAME,MARKS\n");
        scanf("%d %s %f",&new->rollno,new->name,&new->marks);
        new->next=0;
        if(*ptr==0)
                *ptr=new;
        else
        {
                SLL* last=*ptr;
                while(last->next)
                        last=last->next;

                last->next=new;
        }
}
void readfile(SLL **ptr)
{
        SLL *new;
        FILE *fp=fopen("std.txt","r");
        if(fp==0)
        {
                printf("NO FILE PRESENT\n");
                return;
        }
        while(1)
        {
                new=malloc(sizeof(SLL));
                if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks)==-1)
                        break;
                new->next=0;
                if(*ptr==0)
                        *ptr=new;
                else
                {
                        SLL*last=*ptr;
                        while(last->next)
                                last=last->next;
                        last->next=new;
                }
        }
}
void printrecursion(SLL *ptr)
{

        if(ptr==0)
        {
                printf("NO RECORS FOUND\n");
                return;
        }

        if(ptr)
        {
                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
                printrecursion(ptr->next);
        }
}
void reverserecursion(SLL *ptr)
{

        if(ptr==0)
        {
                printf("NO RECORS FOUND\n");
                return;
        }

        if(ptr)
        {
                reverserecursion(ptr->next);
                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
        }
}
void deleteallnode(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("NO RECORDS FOUND\n");
                return;
        }
        SLL*del=*ptr;
        while(del)
        {
                *ptr=del->next;
                sleep(1);
                printf("deleted\n");
                free(del);
                del=*ptr;
        }
        printf("ALL NODES DELETED\n");
}
void searchnode(SLL *ptr)
{
        if(ptr==0)
        {
                printf("NO RECORS FOUND\n");
                return;
        }
        char name[10];
        printf("ENTER THE NAME TO SEARCH\n");
        scanf("%s",name);
        int flag=0;
        while(ptr)
        {
                if(strcmp(name,ptr->name)==0)
                {
                        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
                        flag=1;
                }
                ptr=ptr->next;
                if(flag==0)
                {
                        printf("NO NAME FOUND\n");
                }
        }
}
void sortdata(SLL *ptr)
{
        if(ptr==0)
        {
                printf("NO RECORS FOUND\n");
                return;
        }
        int i,j,c=countnode(ptr);
        SLL *p1=ptr,*p2,t;
        for(i=0;i<c-1;i++)
        {
                p2=p1->next;
                for(j=0;j<c-1-i;j++)
                {
                        if(strcmp(p1->name,p2->name)>0)
                        {
                                t.rollno=p1->rollno;
                                strcpy(t.name,p1->name);
                                t.marks=p1->marks;

                                p1->rollno=p2->rollno;
                                strcpy(p1->name,p2->name);
                                p1->marks=p2->marks;

                                p2->rollno=t.rollno;
                                strcpy(p2->name,t.name);
                                p2->marks=t.marks;
                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }
}
void deletenode(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("NO RECORDS FOUND\n");
                return;
        }
        char name[10];
        printf("ENTER THE NAME TO DELETE RECORDS\n");
        scanf("%s",name);
        SLL *del=*ptr;
        SLL *prev;

        while(del)
        {
                if(strcmp(del->name,name)==0)
                {
                        if(del==*ptr)
                                *ptr=del->next;
                        else
                                prev->next=del->next;

                        free(del);
                        return;
                }
                prev=del;
                del=del->next;
        }
        printf("NAME NOT FOUND\n");
}
void reverselink(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("NO RECORDS FOUND\n");
                return;
        }
        int i,c=countnode(*ptr);
        if(c>1)
        {
                SLL **a=malloc(sizeof(SLL*)*c);

                SLL *t= *ptr;
                for(i=0;i<c;i++)
                {
                        a[i]=t;
                        t=t->next;
                }

                for(i=c-1;i>0;i--)
                        a[i]->next=a[i-1];

                a[0]->next=0;
                *ptr=a[c-1];
        }
}
