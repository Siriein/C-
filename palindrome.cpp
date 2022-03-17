#include <bits/stdc++.h>
using namespace std;
struct LL{
  int data;
  LL *next;  
};
void insertAtBeginning(struct LL**head,int dataToBeInserted)
{
  struct LL* curr=new LL;
    
    curr->data=dataToBeInserted;
    curr->next=NULL;
  
  if(*head==NULL)
      *head=curr; //if this is first node make this as head of list
    
  else
    {
      curr->next=*head; //else make the current (new) node's next point to head and make this new node a the head
      *head=curr;
    }
    
    //O(1) constant time
}
LL* reverseListIteratively(struct LL *head)
{
  struct LL *adj= NULL,*prev=NULL,*curr=head;
  while(curr!=NULL)
  {
    adj = curr->next;
    curr->next = prev;
    prev = curr;
    curr = adj;
  }
  return prev;
  //O(number of nodes)
}
void display(struct LL**head)
{
  struct LL*temp=*head;
  while(temp!=NULL)
    {
      if(temp->next!=NULL)
      cout<<temp->data<<" ->";
      else
      cout<<temp->data;
      
      temp=temp->next; //move to next node
    }
    //O(number of nodes)
  cout<<endl;
}
bool isPalin(struct LL *head)
{
  
  struct LL *fast = head, *slow = head;

    while(fast != NULL)
    {
        fast = fast->next->next; //fast skips 1
        slow = slow->next; // slow goes 1 by 1
    }
    //once while ends that means fast has reach end and slow has reached the middle
    //reverse the half the list using slow
    slow = reverseListIteratively(slow);
    fast = head; //move fast back to head
    while(slow != NULL)
    {
        if(fast->data != slow->data)// if slow or fast val/char don't equal at any moment it
            //not a pali
            return false;
        fast = fast->next; //else continue on the list to check each val/char of the list
        slow = slow->next;
    }
    return true;
}
int main()
{
  
  struct LL *head = NULL; //initial list has no elements
  insertAtBeginning(&head,23);
  insertAtBeginning(&head,49);
  insertAtBeginning(&head,12);
  //insertAtBeginning(&head,15);
  insertAtBeginning(&head,16); // uncomment to check and see that it is a palindrome
  insertAtBeginning(&head,12);
  insertAtBeginning(&head,49);
  insertAtBeginning(&head,23);
  
  cout<<"Given List is :-\n";
  display(&head);
  int a = isPalin(head);
  if(a == 1)
    cout<<"\nGiven list is a palindrome\n";
  
  else
    cout<<"\nGiven list is not a palindrome \n";
  
  return 0;
}





