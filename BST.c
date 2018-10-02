#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list* left;
  struct list* right;
}node;

node *root;

node  *new_node (int data) {
  node *temp = (node *) malloc (sizeof(node));
  temp -> left = NULL;
  temp -> right = NULL;
  temp -> data = data;
}

node *find_min (node *root) {
  if (root -> left == NULL) {
    return root;
  } else find_min (root -> left);
}

int Search (node *root, int data) {
  if (root == NULL)
    return -1;
  if (root -> data == data)
    return 1;
  if (data > root -> data)
    return Search(root -> right, data);
  else
    return Search(root -> left, data);
}

node *Insert (node *Bstroot, int data) {
  if (Bstroot == NULL) {
    Bstroot = new_node(data);
  } else if (Bstroot -> data < data) {
    Bstroot -> right = Insert (Bstroot -> right, data);
  } else {
    Bstroot -> left = Insert (Bstroot -> left, data);
  }  
  return Bstroot;
}

node *Delete (node *root, int data) {
  if (root == NULL) {
    printf("%d not found.\n", data);
  } else if (root -> data < data) {
    root -> right = Delete (root -> right, data);
  } else if (root -> data > data){
    root -> left = Delete (root -> left, data);
  } else {
    if (root -> left == NULL && root -> right == NULL) {
      free (root);
      return NULL;
    } else if (root -> left == NULL) {
      node *temp = root;
      root = root -> right;
      free (temp);
    } else if (root -> right == NULL) {
      node *temp = root;
      root = root -> left;
      free (temp);
    } else {
      node *temp = find_min(root -> right);
      root -> data = temp -> data;
      root -> right = Delete (root -> right, temp -> data);
    }
  }
  return root;
}
void Inorder (node *root) {
  if (root == NULL) {
    printf("The tree is empty.\n");
    return;
  }
  if (root -> left != NULL)
    Inorder (root -> left);
  printf("%d ", root -> data);
  if (root -> right != NULL)
    Inorder (root -> right);
  return;
}
void PreOrder (node *root) {
  if (root == NULL) {
    printf("The tree is empty.\n");
    return;
  }
  printf("%d ", root -> data);
  if (root -> left != NULL)
    PreOrder (root -> left);
  if (root -> right != NULL)
    PreOrder (root -> right);
  return;
}
void PostOrder (node *root) {
  if (root == NULL) {
    printf("The tree is empty.\n");
    return;
  }
  if (root -> left != NULL)
    PostOrder (root -> left);
  if (root -> right != NULL)
    PostOrder (root -> right);
  printf("%d ", root -> data);
  return;
}

int main() {
  int data, choice, pos;
  root = NULL;
  while (1) {
    printf("1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Pre-Order\n6.Post-Order\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the data to Insert : ");
        scanf ("%d", &data);
        root = Insert(root, data);
        break;
      case 2:
        printf("Enter the data to Delete : ");
        scanf ("%d", &data);
        root = Delete(root, data);
        break;
      case 3:
        printf("Enter the data to Search : ");
        scanf ("%d", &data);
        if (Search(root, data) != -1) 
          printf("%d found.\n", data);
        else
          printf("%d not found.\n", data);
        break;
      case 4:
        Inorder(root);
        printf("\n");
        break;
      case 5:
        PreOrder(root);
        printf("\n");
        break;
      case 6:
        PostOrder(root);
        printf("\n");
        break;
      default :
        return 0;
    }
  }
}