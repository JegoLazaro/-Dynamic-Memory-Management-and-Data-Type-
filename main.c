/*
ALFONSO, ALESSANDRO K.
LAZARO, JOSE GABRIEL R.
MENDOZA, FRANCESCA A.
CSADPRG S11 - Mini MP2: Dynamic Memory Management and Data Type
*/
#include <stdio.h>
#include <stdlib.h>

struct node{//STRUCTURE FOR NODE
  int value;
  struct node* next;
};

typedef struct node node;

void sort_set(node* head) { //SORTS LIST ASCENDING ORDER
    struct node *current = head, *index = NULL; //INITIALIZE NODES
    int temp;

    if(head == NULL) {// RETURN EMPTY SET IF HEAD IS NULL
        return;
    }
    else {
      while(current != NULL) {//POINT TO NODE NEXT TO CURRENT NODE
        index = current->next;

        while(index != NULL) {//SWAP VALUE IF CURRENT IS GREATER THAN NEXT
          if(current->value > index->value) {
              temp = current->value;
              current->value = index->value;
              index->value = temp;
          }
          index = index->next;
        }
        current = current->next;
      }
    }
  }

void print(node* head){ // DISPLAYS LIST
  node * temp = head;//INITIALIZE TEMPORARY NODE AS HEAD

  sort_set(head);//SORT HEAD BEFORE PRINTING
  printf("(");
  while (temp != NULL){
    printf("%d,", temp->value);
    temp = temp->next;//POINT TO NEXT VALUE TO BE PRINTED
  }
  printf(")");
  printf("\n");
}

node * create(){  //CREATES LIST SET TO NULL
  node* new_set;
  new_set = NULL;

  return new_set; // RETURNS AN EMPTY SET
}

node *set_value(int value){ //GETS VALUE OF NODE
  node* result = (struct node*)malloc(sizeof(struct node));
  result->value = value;
  result->next = NULL;

  if(result == NULL){   // CHECK IF NULL
    printf("Memory cannot be allocated. Try Again.");
  }

  return result;  // RETURNS VALUE OF CURRENT VALUE
}

node* add(node* *head, int value){ //ADDS/INSERTS NODE AT START OF LIST
  node * result = malloc(sizeof(node));
  result->value = value;
  result->next = NULL;

  node* node_to_insert = set_value(value);
  node_to_insert->next = *head;
  *head = node_to_insert;

  return result; // RETURNS POINTER AT FIRST ELEMENT OF HEAD
}

node* find_node(node* head, int value){ //FINDS NODE IN A LIST
  node *temp = head;
  while (temp != NULL){
    if (temp->value == value){  //NODE FOUND, RETURN
      return temp;
    }else{
      temp = temp->next;
    }
  }
  return NULL;  //RETURNS NULL IF NOT FOUND ELSE RETURNS NODE
}

node* Intersection(node * set1, node * set2){ //FINDS INTERSECTION IN 2 SETS
  node * intersections = NULL;

  while (set1 != NULL){
    if(find_node(set2, set1->value)){     //IF NODE IN SET1 IS FOUND IN SET2, THEN ADD
      add(&intersections, set1->value);
    }
    set1 = set1->next;
  }
  return intersections;   //RETURNS COMMON ELEMENTS FOUND IN THE 2 SETS
}

node * Union(node * set1, node * set2){ //FINDS UNION OF SET 1 AND SET 2 
  node * unions = NULL;

  while(set1 != NULL){
    add(&unions, set1->value);
    set1 = set1->next;
  }
  while(set2 != NULL){
    if(!find_node(unions, set2->value)){  //REMOVE DUPLICATES
      add(&unions, set2->value);        //IF NODE IN SET NOT FOUND IN UNION, THEN ADD
    }
    set2 = set2->next;
  }
  return unions;  // RETURNS MERGED SET FROM SET 1 AND SET 2
}

node * Difference(node * set1, node * set2){  //FINDS UNIQUE ELEMENTS IN SET 1 AND SET 2
  node *  difference = NULL;
  while (set1 != NULL){
    if(!find_node(set2, set1->value)){    //IF NODE IN SET1 NOT FOUND IN SET2, THEN ADD
      add(&difference, set1->value);
    }
    set1 = set1->next;
  }

  return difference; // RETURNS A SET CONTAINING UNIQUE ELEMENTS OF SET 1 AND SET 2
}

int main(){
  node* s1; 
  node* s2; 
  node* s3;


  s1 = create();
  s2 = create();
  add(&s1, 8);
  add(&s1, 10);
  add(&s1, 9);
  add(&s2, 4);
  add(&s2, 10);
  add(&s2, 5);
  print(s1);
  print(s2);
  print(Union(s1,s2));
  print(Intersection(s1,s2));


  return 0;
}