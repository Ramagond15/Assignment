#include<stdio.h>
#include<stdlib.h>
typedef struct movies
{
    char n[20];
    int year,gross;
    struct movies *link;
}*node;
node get_details();
node insert_sort(node);
node merge(node,node);
node display_all(node);
void main()
{
    node movie,web,head;
    movie=NULL;
    web=NULL;
    head=NULL;
    int i;
    while(1)
    {
        printf("Enter the choice \n");
        printf("1.Insert_web 2.Insert_movie 3.Display_highest 4.Display_Web 5.Display_movie 6.Exit\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:web=insert_sort(web);
                   break;
            case 2:movie=insert_sort(movie);
                   break;
            case 3:head=merge(web,movie);
                   head=display_all(head);
                   break;
            case 4:printf("The details of web series are:\n");
                   printf("Name\tYear_of_release\tGross_collection\n");
                   web=display_all(web);
                   break;
            case 5:printf("The details of movies are:\n");
                   printf("Name\tYear_of_release\tGross_collection\n");
                   movie=display_all(movie);
                   break;
            case 6:exit(0);
            default:printf("Invalid choice\n");
                    break;
        }
    }
}
node get_details()
{
    node temp;
    temp=malloc(sizeof(node));
    if(temp==NULL)
    {
        return NULL;
    }
    else
    {
        printf("Enter the Name\tYear_f_release\tGross_collection\n");
        scanf("%s\t%d\t%d",temp->n,&temp->year,&temp->gross);
        temp->link=NULL;
        return temp;
    }
}
node insert_sort(node head)
{
    node newn,curr,prev;
    newn=get_details();
    if(newn==NULL)
    {
        printf("Node not created\n");
        return NULL;
    }
    else if(head==NULL)
    {
        return newn;
    }
    if(head->gross<newn->gross)
    {
        newn->link=head;
        return newn;
    }
    curr=head->link;
    prev=head;
    while(curr!=NULL)
    {
      if(head->gross<newn->gross)
      {
          newn->link=curr;
          prev->link=newn;
          return head;
      }
      prev=curr;
      curr=curr->link;
    }
    prev->link=newn;
    return head;
}
node display_all(node head)
{
    node curr;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    curr=head;
    while(curr!=NULL)
    {
        printf("%s\t%d\t%d\n",curr->n,curr->year,curr->gross);
        curr=curr->link;
    }
    return head;
}
node merge(node web,node movie)
{
    node head,end;
    if(web==NULL&&movie==NULL)
    {
        printf("No data available\n");
        return NULL;
    }
    head=web;
    head->link=movie;
    end=head;
    head=head->link;
    head->link=NULL;
    return end;
}
