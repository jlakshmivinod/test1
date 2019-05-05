#include<stdio.h>
#include<stdlib.h>
void insert1();
void insert2();
void display1();
void display2();
void add();
struct node
{
int coeff;
int exp;
struct node *link;
}*head1,*head2,*head3,*ptr,*qtr,*Rtr;
main()
{
 int ch;
 head1=(struct node *)malloc(sizeof(struct node));
 head2=(struct node *)malloc(sizeof(struct node));
 head3=(struct node *)malloc(sizeof(struct node));
 do
 {
 printf("............menu..............\n");
 printf("1.insert1\n");
 printf("2.insert2\n");
 printf("3.display1\n");
 printf("4.display2\n");
 printf("5.add\n");
 printf("6.exit\n");
 printf("enter the choice");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:insert1();break;
 case 2:insert2();break;
 case 3:display1();break;
 case 4:display2();break;
 case 5:add();break;
 case 6:exit(1);break;
 }
 }while(ch<=6);
}



void insert1()
{
 int exp,coeff;
 struct node *temp=(struct node *)malloc(sizeof(struct node));
 int x;
 printf("enter the coefficient");
 scanf("%d",&coeff);
 printf("enter the exponent");
 scanf("%d",&exp);
 ptr=head1;
 while(ptr->link!=NULL)
 {
 ptr=ptr->link;
 }
 ptr->link=temp;
 temp->link=NULL;
 temp->coeff=coeff;
 temp->exp=exp;
}

void insert2()
{
 int exp,coeff;
 struct node *temp=(struct node *)malloc(sizeof(struct node));
 int x;
 printf("enter the coefficient");
 scanf("%d",&coeff);
 printf("enter the exponent");
 scanf("%d",&exp);
 ptr=head2;
 while(ptr->link!=NULL)
 {
 ptr=ptr->link;
 }
 ptr->link=temp;
 temp->link=NULL;
 temp->coeff=coeff;
 temp->exp=exp;
}

void display1()
{
 ptr=head1->link;
 while(ptr!=NULL)
 { 
 printf("%d %d\n",ptr->coeff,ptr->exp);
 ptr=ptr->link;
 }
}

void display2()
{
 ptr=head2->link;
 while(ptr!=NULL)
 { 
 printf("%d %d\n",ptr->coeff,ptr->exp);
 ptr=ptr->link;
 }
}


void add()
{
 int result,exp,coeff;
 ptr=head1->link;
 qtr=head2->link;
 while(ptr!=NULL && qtr!=NULL)
 {
    if(ptr->exp>qtr->exp)
    {
      struct node *temp=(struct node *)malloc(sizeof(struct node));
      Rtr=head3;
      while(Rtr->link!=NULL)
      {
      Rtr=Rtr->link;
      }
      Rtr->link=temp;
      temp->exp=ptr->exp;
      temp->coeff=ptr->coeff;
      temp->link=NULL;

      ptr=ptr->link;
    }

    else if(qtr->exp>ptr->exp)
    {
      struct node *temp=(struct node *)malloc(sizeof(struct node));
      Rtr=head3;
      while(Rtr->link!=NULL)
      {
      Rtr=Rtr->link;
      }
      Rtr->link=temp;
      temp->exp=qtr->exp;
      temp->coeff=qtr->coeff;
      temp->link=NULL;
      qtr=qtr->link;
    }


    else if(qtr->exp==ptr->exp)
    {
     struct node *temp=(struct node *)malloc(sizeof(struct node));
     result=qtr->coeff+ptr->coeff; 
     Rtr=head3;
     while(Rtr->link!=NULL)
     {
     Rtr=Rtr->link;
     }
     Rtr->link=temp;
     temp->link=NULL;
     temp->exp=qtr->exp;
     temp->coeff=result;
     qtr=qtr->link;
     ptr=ptr->link;
    }

 }

 if(ptr!=NULL && qtr==NULL)
 {
  while(ptr!=NULL)
  {   
     struct node *temp=(struct node *)malloc(sizeof(struct node)); 
     Rtr=head3;
     while(Rtr->link!=NULL)
     {
     Rtr=Rtr->link;
     }
     Rtr->link=temp;
     temp->exp=ptr->exp;
     temp->coeff=ptr->coeff;
     temp->link=NULL;
     ptr=ptr->link;
  }
 }

 if(ptr==NULL && qtr!=NULL)
 {
  while(qtr!=NULL)
  { 
     struct node *temp=(struct node *)malloc(sizeof(struct node)); 
     Rtr=head3;
     while(Rtr->link!=NULL)
     {
     Rtr=Rtr->link;
     }
     Rtr->link=temp;
     temp->link=NULL;
     temp->exp=qtr->exp;
     temp->coeff=qtr->coeff;
     qtr=qtr->link;
  }
 }

 ptr=head3->link;
 printf("added polynomial:\n");
 while(ptr!=NULL)
 { 
 printf("%d %d\n",ptr->coeff,ptr->exp);
 ptr=ptr->link;
 }
main(); 

}

