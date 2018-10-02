#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list* next;
}node;

int total = 0;
node *head;
node *Insert_Begin(int data) {
  total++;
  node* temp = malloc (sizeof(node));
  temp -> data = data;
  temp -> next = head;
  if (head == NULL) {
    temp -> next = temp;
    return temp;
  }
  node *q = head;
  while (q -> next != head) {
    q = q -> next;
  }
  q -> next = temp;
  return temp;
}
node *Insert_End(int data) {
  total++;
  node* temp = malloc (sizeof(node));
  temp -> data = data;
  temp -> next = head;
  if (head == NULL){
    temp -> next = temp;
    return temp;
  }
  node* q = head;
  while (q -> next != head) {
    q = q -> next;
  }
  q -> next = temp;
  return head;
}
node *Insert (int data, int pos) {
  if (pos == 0)
    return Insert_Begin(data);
  if (pos == total)
    return Insert_End(data);
  if (pos > total) {
    printf("position out of bound\n");
    return head;
  }
  total++;
  node* temp = malloc (sizeof(node));
  temp -> data = data;
  int count = 0;
  node *q = head;
  while (count < pos - 1) {
    count++;
    q = q -> next;
  }
  temp -> next = q -> next;
  q -> next = temp;
  return head;
}
node *Delete_Beg () {
  if (head == NULL)  {
    printf("Nothing to Delete\n");
    return head;
  }
  total--;
  if (head -> next == head){
    free (head);
    return NULL;
  }
  node *q = head;
  head = head -> next;
  node *temp = head;
  while (temp -> next != q) {
    temp = temp -> next;
  }
  temp -> next = head;
  free (q);
  return head;
}
node *Delete_End () {
  if (head == NULL)  {
    printf("Nothing to Delete\n");
    return head;
  }
  total--;
  if (head -> next == head){
    free (head);
    return NULL;
  }
  if ((head -> next) -> next == head) {
    free (head -> next);
    head -> next = head;
    return head;
  }
  node *q = head;
  while (q -> next -> next != head) {
    q = q -> next;
  }
  free (q -> next);
  q -> next = head;
  return head;
}
node *Delete (int pos) {
  if (pos == 0)
    return Delete_Beg();
  if (pos == total - 1){
    return Delete_End();
  }
  if (pos > total) {
    printf("position out of bound\n");
    return head;
  }
  total--;
  int count = 0;
  node *q = head, *temp;
  while (count < pos - 1) {
    count++;
    q = q -> next;
  }
  temp = q -> next;
  q -> next = temp -> next;
  free (temp);
  return head;
}
void Display () {
  printf("No of nodes : %d\n", total);
  if (head == NULL) {
    printf("Nothing To Display\n");
    return;
  } 
  node *p = head;
  do {
    printf("%d ", p -> data);
    p = p -> next;
  } while (p != head);
  printf("\n");
}

int main() {
  int data, choice, pos;
  head = malloc(sizeof(head));
  head = NULL;
  while (1) {
    printf("1.Insert at beginning\n2.Insert at end\n3.Insert at Intermediate\n");
    printf("4.Delete at beginning\n5.Delete at end\n6.Delete at Intermediate\n7.Display\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the data to Insert : ");
        scanf ("%d", &data);
        head = Insert_Begin(data);
        break;
      case 2:
        printf("Enter the data to Insert : ");
        scanf ("%d", &data);
        head = Insert_End(data);
        break;
      case 3:
        printf("Enter the position (0 - based indexing) : ");
        scanf ("%d", &pos);
        printf("Enter the data to Insert : ");
        scanf ("%d", &data);
        head = Insert(data, pos);
        break;
      case 4:
        head = Delete_Beg();
        break;
      case 5:
        head = Delete_End();
        break;
      case 6:
        printf("Enter the position (0 - based indexing) : ");
        scanf ("%d", &pos);
        head = Delete(pos);
        break;
      case 7:
        Display();
        break;
      default :
        return 0;
    }
  }
}