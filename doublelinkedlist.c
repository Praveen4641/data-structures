//c program to implement dll an dperforming various additional operations in it like even and odd count search  split and etc...
#include <stdio.h>
#include <stdlib.h>
struct node
	{
	   int data;
	   struct node*prev,*next;
	   
	};
struct odd
	{
		int n1;
		struct odd *fol1;
	};
struct even
	{
		int n2;
		struct even *fol2;
	};			
	typedef struct node NODE;
	typedef struct odd ODD;
	typedef struct even EVEN;
	NODE*head=NULL;
	EVEN*head1=NULL;
	ODD*head2=NULL;
	void create();
	void insert_front(int);
	void insert_last(int);
	void insert_pos(int,int);
	void delete_front();
	void delete_last();
	void delete_pos(int);
	void traverseR_L();
	void traverseL_R();
	void display();
	void count();
	void search(int);
	void split();
	void EVEN_and_ODD();
	int main()
 	 {
    	int item,ch,pos,key;
    	create();
    	while(1)
     	{
       	printf("\nMENU\n");
	    printf("1.Insert front\n");
	    printf("2.Insert last\n");
	    printf("3.Insert pos\n");
	    printf("4.delete front\n");
	    printf("5.delete last\n");  
	    printf("6.delete pos\n");
	    printf("7.traverse right to left\n");
	    printf("8.traverse left to right\n");
	    printf("9.count the elements in the list\n");
	    printf("10.the key to be searched\n");
	    printf("11.the list to split into 2 halves\n");
	    printf("12.EVEN LIST AND ODD LIST\n 14.exit\n");
	    printf("Enter your choice :");
	    scanf("%d",&ch);
	    switch(ch)
	    {
			  case 1 :printf("enter element to be inserted:");
			  		  scanf("%d",&item);
			  		  insert_front(item);	
			          break;
              case 2 :printf("enter the elements to be inserted:");
              		  scanf("%d",&item);
              		  insert_last(item);
                      break;
              case 3 :printf("enter the element:");
              		  scanf("%d",&item);
              		  printf("enter the position:\n");
              		  scanf("%d",&pos);
              		  insert_pos(item,pos);
              		  break;
              case 4 :delete_front();
              		  break;
              case 5 :delete_last();
              		  break;
              case 6 :printf("enter the position:");
             		  scanf("%d",&pos);
              		  delete_pos(pos);
              case 7 :traverseR_L();
             		  break;
              case 8 :traverseL_R();
             		  break;
              case 9 :count();
                      break;	
              case 10:printf("enter the key:");
             		  scanf("%d",&key);
              		  search(key);
              		  break;
              case 11:split();
                      break;
              case 12:EVEN_and_ODD();
                      break;            		         	 
              case 13:exit(0);	     
              default:printf("invalid choice:\n");
		}
	 }
  }
	void create()
	{
		NODE*temp,*cur;
		int item,ch;
		do
		{
			printf("enter the element:\n");
			scanf("%d",&item);
			temp=(NODE*)malloc(sizeof(NODE));
			temp->data=item;
			if(head==NULL)
			{
				head=cur=temp;
			}
			else
			{
				cur->next=temp;
				temp->prev=cur;
				cur=temp;
			}
			printf("Do you want to continue (1/0):\n");
			scanf("%d",&ch);
		}while(ch== 1 );
		head->prev=NULL;
	    cur->next=NULL;
	}
	void insert_front(int item)
	{
		NODE*temp;
		temp=(NODE*)malloc(sizeof(NODE));
		temp->data=item;
		temp->next=head;
		temp->prev=NULL;
		head->prev=temp;
		head=temp;
	}
	void insert_last(int item)
	{
		NODE *temp,*cur;
		temp= (NODE*)malloc(sizeof(NODE));
		temp->data=item;
		if(head==NULL)
		{
			head=temp;
			temp->prev=NULL;
		}
		else
		{
			cur=head;
			while(cur->next!=NULL)
			{
				cur=cur->next;
			}
			cur->next=temp;
			temp->prev=cur;
		}
		temp->next=NULL;
	}
	void delete_front()
	{
		NODE*temp;
		if(head==NULL)
		{
			printf("list is empty\n");
		}
		else
		{
			temp=head;
			head=head->next;
			head->prev=NULL;
			printf("element deleted:%d\n",temp->data);
			free(temp);
		}	
	}
	void delete_last()
	{
		NODE *temp,*cur;
		if(head==NULL)
		{
			printf("list is empty\n");
		}
		else if(head->next=NULL)
		{
			temp=head;
			head=NULL;
			printf("deleted element:%d\n",temp->data);
			free(temp);
		}
		else
		{
			cur=head;
			while(cur->next!=NULL)
			{
				cur=cur->next;
			}
			temp=cur->next;
			cur->next=NULL;
			printf("deleted element:%d\n",temp->data);
			free(temp);
		}
	}
	void insert_pos(int item,int pos)
	{
		NODE*temp,*cur1=head,*cur2;
		int i;
		if(pos==1)
			insert_front(item);
		else
		{
			for(i=1;i<=(pos-2);i++)
				cur1=cur1->next;
			if(cur1->next==NULL)
				printf("invalid position\n");
			else
			{
				cur2=cur1->next;
				temp=(NODE*)malloc(sizeof(NODE));
				temp->data=item;
				temp->next=cur2;
                cur2->prev=temp;
                cur1->next=temp;
                temp->prev=cur1;	
            }   			
		}	
	}						
  	void delete_pos(int pos)
  	{
  		NODE*temp,*cur2,*cur1=head;
  		int i;
  		if(pos==1)
  			delete_front();
  		else
  		{
  			for(i=1;i<=(pos-2);i++)
  				cur1=cur1->next;
  			if(cur1->next==NULL)
  				printf("invalid position\n");
  			else
  			{
  				temp=cur1->next;
  				cur2=temp->next;
  				cur1->next=cur2;
  				cur2->prev=cur1;
  				printf("deleted element:%d\n",temp->data);
				free(temp);
			}
		}
	}
	void traverseR_L()
	{
		NODE*cur=head;
		if(head==NULL)
			printf("list is empty\n");
		else
		{
			while(cur->next!=NULL)
			{
				cur=cur->next;
			}
			while(cur!=NULL)
			{
				printf("%4d",cur->data);
				cur=cur->prev;
			}					
  		}				
	}
	void traverseL_R()
	{
		NODE*cur=head;
		if(head==NULL)
			printf("list is empty\n");
		else
		{
			printf("list content:\n");
			while(cur!=NULL)
			{
				printf("%4d",cur->data);
				cur=cur->next;
			}
		}			
	}
	void count()
	{
		int i=0;
		NODE*cur=head;
		if(head==NULL)
		{
			printf("The list haS NO nodes");
		}
		else 
		{	while(cur!=NULL)
			{
				i++;
				cur=cur->next;
			}
			printf("The list has %d nodes",i);
		}
	}
	void search(int key)
	{
		int i=0,flag=0;
		NODE*cur=head;
		if(head==NULL)
			printf("The list is empty");
		else
		{
			while(cur!=NULL)
			{
				i++;
				if(key==cur->data)
				{
					flag=1;
					break;
				}
				cur=cur->next;
			}
			if(flag==0)
				printf("key is not found in the list\n");
			else 
				printf("key is found  at node %d in the list :",i);
			
		}
	}
	void split()
	{
		int i=0,j;
		NODE*cur=head;
		if(head==NULL)
			printf("list is empty\n");
		else
		{
			while(cur!=NULL)
			{
				i++;
				cur=cur->next;
			}
			cur=head;
			printf("the first half of the list is :");
			j=i;
			i=i/2;
			while(i!=0)
			{
				printf("%d",cur->data);
				cur=cur->next;
				i--;
			}							
			if(j%2!=0)
			{
		  		printf("\nthe middle element of the list:");
		  		cur=cur->next;
		  		printf("\nthe second half of the list:");
		  		while(cur!=NULL)
		  		{
					printf("%d ",cur->data);
					cur=cur->next;
				}
			}
			else
			{
				printf("\nThe second half of the list:");
		  		while(cur!=NULL)
		  		{
					printf("%d ",cur->data);
					cur=cur->next;
				}
			}
		}
	}
	void EVEN_and_ODD()
	{
		int item;
		NODE*cur=head;
		ODD *head1=NULL,*cur1,*temp1;
	    EVEN *head2=NULL,*cur2,*temp2;
		if(head==NULL)
			printf("the list is empty\n");
		else
		{
			while(cur!=NULL)
			{
				if(cur->data%2!=0)
				{
					temp1=(ODD*)malloc(sizeof(ODD));
					temp1->n1=item;
					if(head1==NULL)
						head1=cur1=temp1;
					else
					{
						cur1->fol1=temp1;
						cur1=temp1;
					}
					cur1->fol1=NULL;
				}
				else
				{
					temp2=(EVEN*)malloc(sizeof(EVEN));
					temp2->n2=item;
					if(head2==NULL)
						head2=cur2=temp2;
					else
					{
						cur2->fol2=temp2;
						cur2=temp2;
					}
					cur2->fol2=NULL;
				}
			}
			printf("The ODD LIST IS :\n");
			cur1=head1;
			if(head1==NULL)
				printf("list is empty");
			else
			{
				while(cur1!=NULL)
				{
					printf("%4d",cur1->n1);
					cur1=cur1->fol1;
				}
			}
			printf("The EVEN LIST IS :\n");
			cur2=head2;
			if(head2==NULL)
				printf("list is empty");
			else
			{
				while(cur2!=NULL)
				{
					printf("%4d",cur2->n2);
					cur2=cur2->fol2;
				}
			}
		}
	}																		  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
