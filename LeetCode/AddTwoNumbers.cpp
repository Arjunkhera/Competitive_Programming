#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}

};

void insertHead(ListNode* &head,int data){
  ListNode *temp = new ListNode(data);
  temp->next = head;
  head = temp;
}

void input(ListNode* &l){
  int data;
  cin>>data;

  while(data != -1){
    insertHead(l,data);
    cin>>data;
  }
}

void display(ListNode *head){
  while(head != NULL){
    cout<<head->val<<"->";
    head = head->next;
  }
  cout<<"NULL\n";
}

ListNode* addTwoNumbers_Editorial(ListNode* l1, ListNode* l2) {
  // the following solution has been taken from editorial
  ListNode *dummyHead = new ListNode(0);
  ListNode *p = l1;
  ListNode *q = l2;
  ListNode *curr = dummyHead;
  int carry = 0;
  while (p != NULL || q != NULL) {
    int x = (p != NULL) ? p->val : 0;
    int y = (q != NULL) ? q->val : 0;
    int sum = carry + x + y;
    carry = sum / 10;
    curr->next = new ListNode(sum % 10);
    curr = curr->next;
    if (p != NULL) p = p->next;
    if (q != NULL) q = q->next;
  }
  if (carry > 0) {
    curr->next = new ListNode(carry);
  }
  return dummyHead->next;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
  vector<int> a,b;
  ListNode* temp;
  ListNode* head;
  int len1=0,len2=0,sum,carry=0;

  temp = l1;
  while(temp!=NULL){
    a.push_back(temp->val);
    temp = temp->next;
    len1++;
  }

  temp = l2;
  while(temp!=NULL){
    b.push_back(temp->val);
    temp = temp->next;
    len2++;
  }

  temp = NULL;
  int i = 0;
  while( len1 && len2 ){
    sum = a[i]+b[i]+carry;
    carry = sum/10;
    sum = sum%10;

    ListNode *val = new ListNode(sum);
    if(i == 0){
      temp = val;
      head = val;
    }
    else temp->next = val;
    temp = val;

    i++;
    len1--;
    len2--;
  }
  while(len1){
    sum = a[i]+carry;
    carry = sum/10;
    sum = sum%10;

    ListNode *val = new ListNode(sum);
    temp->next = val;
    temp = val;
    i++;
    len1--;
  }
  while(len2){
    sum = b[i]+carry;
    carry = sum/10;
    sum = sum%10;

    ListNode *val = new ListNode(sum);
    temp->next = val;
    temp = val;
    i++;
    len2--;
  }
  if(carry){
    ListNode *val = new ListNode(carry);
    temp->next = val;
    temp = val;
  }
  return head;
}

istream& operator>>(istream &in,ListNode* &l){
  input(l);
  return in;
}

ostream& operator<<(ostream &out,ListNode *l){
  display(l);
  return out;
}

int main(){

  ListNode* list1 = NULL;
  ListNode* list2 = NULL;

  cin>>list1>>list2;
  ListNode* list3 = addTwoNumbers(list1,list2);
  cout<<list3;
  return 0;
}
