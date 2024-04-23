#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
} *head;

struct node* create_node(int value){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL){
        printf("Unable to allocate space\n");
        return NULL;
    }
    tmp->data = value;
    tmp->next = NULL;
    return tmp;
}

void create(){
    if(head != NULL){
        printf("Already created!\n");
        return;
    }
    int count,value;
    printf("No of element: ");
    scanf("%d",&count);
    printf("Enter element: ");
    struct node* current;
    for(int i=0;i<count;i++){
        scanf("%d",&value);
        if(i == 0){
            head = create_node(value);
            current = head;
        }else{
            struct node* tmp = create_node(value);
            current->next = tmp;
            current = tmp;
        }
    }
    
    printf("Created\n");
}

void display(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    struct node* current = head;
    printf("List: ");
    while(current){
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void insert_front(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node * tmp = create_node(value);
    tmp->next = head;
    head = tmp;
    printf("Inserted\n");
}

void insert_rear(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node * tmp = create_node(value);
    struct node* current = head;
    while(current->next)
        current = current->next;
    
    current->next = tmp;
    printf("Inserted at the end\n");

}

void insert_after_kth(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node * tmp = create_node(value);
    if(tmp == NULL){
        return;
    }
    printf("Enter index: ");
    int index;
    scanf("%d",&index);
    struct node* current = head;
    int count = 0;
    while(current){
        count++;
        current = current->next;
    }
    if(index < 1 || index > count){
        printf("Invalid index\n");
        return;
    }
    current = head;
    int i = 1;
    while(current && i<index){ // 2
        i++;
        current = current->next;
    }
    struct node* part = current->next;
    current->next = tmp;
    tmp->next = part;
    printf("Inserted Successfully\n");

}

void insert_by_value(){
     if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node * tmp = create_node(value);
    printf("Enter node value: ");
    int node_value;
    scanf("%d",&node_value);
    struct node* current = head;
    int is_inserted = 0;
    while(current){
        if(current->data == node_value){
            tmp->next = current->next;
            current->next = tmp;
            is_inserted = 1;
            break;
        }
        current = current->next;
    } 
    if(is_inserted)
        printf("Inserted successfully\n");
    else
        printf("No such element found\n");
}

void insert_before_kth(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node * tmp = create_node(value);
    if(tmp == NULL){
        return;
    }
    printf("Enter index: ");
    int index;
    scanf("%d",&index);
    struct node* current = head;
    int count = 0;
    while(current){
        count++;
        current = current->next;
    }
    if(index < 1 || index > count){
        printf("Invalid index\n");
        return;
    }
    current = head;
    int i = 1;
    struct node *prev = NULL;
    while(current && i<index){ // 2
        i++;
        prev = current;
        current = current->next;
    }
    tmp->next = current;
    if(prev != NULL){
         prev->next = tmp;
    }else{
        head = tmp;
    }
    

    printf("Inserted Successfully\n");
}

void insert_by_value_before(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node * tmp = create_node(value);
    printf("Enter node value: ");
    int node_value;
    scanf("%d",&node_value);
    struct node* current = head;
    int is_inserted = 0;
    struct node* prev = NULL;
    while(current){
        if(current->data == node_value){
            if(prev){
                prev->next = tmp;
                
            }else{
                head = tmp;
            }
            tmp->next = current;
            is_inserted = 1;
            break;
        }
        prev = current;
        current = current->next;
    } 
    if(is_inserted)
        printf("Inserted successfully\n");
    else
        printf("No such element found\n");
}

void delete_first(){
     if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    struct node* tmp = head;
    head = head->next;
    free(tmp);
    printf("Deleted\n");
}

void delete_after_kth(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    struct node* current = head;
    printf("Enter index: ");
    int index;
    scanf("%d",&index);
    if(index == 0){
        printf("Invalid index!");
        return;
    }

    int i = 1;
    
    while(current && i < index){
        current = current->next;
        i++;
    }
    if(!current){
        printf("Invalid index\n");
        return;
    }
    struct node * tmp = current->next;
    if(tmp){
        current->next = tmp->next;
        free(tmp);
        printf("Deleted successfully\n");
    }else{
        printf("No element to delete\n");
    }

}

void delete_last_node(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    struct node* current = head;
    struct node* prev = NULL;
    while(current->next){
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
    printf("Deleted successfully\n");
}

void delete_before_kth(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    struct node* current = head;
    printf("Enter index: ");
    int index;
    scanf("%d",&index);
    int i = 1;
    struct node* prev = NULL;
    while(current && i < index){
        prev = current;
        current = current->next;
        i++;
    }
    if(prev){
        prev->data = current->data;
        prev->next = current->next;
        free(current);
        printf("Deleted\n");
    }else{
        printf("Nothing to delete\n");
    }
    
    
}

void  delete_kth(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    struct node* current = head;
    printf("Enter index: ");
    int index;
    scanf("%d",&index);
    int i = 1;
    struct node* prev = NULL;
    while(current && i < index){
        prev = current;
        current = current->next;
        i++;
    }
    if(prev){
        prev->next = current->next;
    }else{
        head = current->next;
    }
    free(current);
    printf("Deleted\n");

}

void delete_with_value(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node* current = head;
    struct node* prev = NULL;
    int f = 0;
    while(current){
        if(current->data == value){
            if(prev){
                prev->next = current->next;
            }else
                head = current->next;
            free(current);
            f = 1;
        }
        prev = current;
        current = current->next;
    }

    if(f)
        printf("Deleted\n");
    else
        printf("No data found with %d\n",value);
}

void reverse(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    struct node* current = NULL,*prev = NULL,*next = NULL;
    if(head->next)
        current = head->next;
    prev = head;
    if(current)
        next = current->next;

    while(current){
        if(prev == head)
            prev->next = NULL;
        current->next = prev;
        prev = current;
        current = next;
        if(next)
            next = next->next;
    }

    head = prev;
    printf("Reversed\n");


}

void sort(){
     if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    struct node* prevIndex = NULL, *index = head, *current = head->next, *prev = head;
    while(index->next){
        while(current){
            if(index->data > current->data){
                
                if(index == prev){
                    index->next = current->next;
                    current->next  = index;
                    if(prevIndex){
                        prevIndex->next = current;
                    }else{
                        head = current;
                    }
                }else{
                    prev->next = current->next;
                    if(prevIndex){
                        prevIndex->next = index->next;
                        current->next = prevIndex->next;
                        prevIndex->next = current;    
                    }else{
                        current->next = index->next;
                        head = current;
                    }
                    index->next = prev->next;
                    prev->next = index;
                }
                
                

                struct node * tmp = index;
                index = current;
                current = tmp;
            }
            prev = current;
            current = current->next;
        }
        prevIndex = index;
        index = index->next;
        prev = index;
        current = index->next;
    }
    printf("Sorted\n");
}

void search(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }

    int value;
    printf("Enter search value: ");
    scanf("%d",&value);

    int f = 0;
    struct node* current = head;
    while(current){
        if(current->data == value){
            f = 1;
            break;
        }
        current = current->next;
    }

    if(f)
        printf("Found!\n");
    else
        printf("Not found\n");


}

void merge(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    int n,value;
    struct node* current = head;
    printf("Number of element in list 2: ");
    scanf("%d",&n);
    printf("Enter values in assending order: ");
    struct node* head2 = NULL, *tmp;
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        if(head2 == NULL){
            head2 = create_node(value);
            tmp = head2;
        }else{
            tmp->next = create_node(value);
            tmp = tmp->next;
        }
    }


    struct node* current2 = head2,*head3 = NULL,*current3 = NULL;
    while(current && current2){
        if(current->data < current2->data){
            tmp = current;
            current = current->next;
            tmp->next = NULL;

        }else{
            tmp = current2;
            current2 = current2->next;
            tmp->next = NULL;
        }

        if(head3 == NULL){
            head3 = tmp;
            current3 = head3;
        }else{
            current3->next = tmp;
            current3 = tmp;
        }
    }

    while(current){
        tmp = current;
        current = current->next;
        tmp->next = NULL;
        if(current3)
            current3->next = tmp;
        current3 = tmp;
        if(head3 == NULL)
            head3 = current3;
    }

    while(current2){
        tmp = current2;
        current2 = current2->next;
        tmp->next = NULL;
        if(current3)
            current3->next = tmp;
        current3 = tmp;
        if(head3 == NULL)
            head3 = current3;
    }

    if(head3)
        head = head3;
    printf("Merged\n");

}

void concate(){
     if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    int n,value;
    struct node* current = head;
    printf("Number of element in list 2: ");
    scanf("%d",&n);
    printf("Enter values: ");
    struct node* head2 = NULL, *tmp;
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        if(head2 == NULL){
            head2 = create_node(value);
            tmp = head2;
        }else{
            tmp->next = create_node(value);
            tmp = tmp->next;
        }
    }

    tmp = head;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = head2;
    printf("Concatenated\n");

}

void equal(){
    if(head == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    int n,value;
    struct node* current = head;
    printf("Number of element in list 2: ");
    scanf("%d",&n);
    printf("Enter values: ");
    struct node* head2 = NULL, *tmp;
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        if(head2 == NULL){
            head2 = create_node(value);
            tmp = head2;
        }else{
            tmp->next = create_node(value);
            tmp = tmp->next;
        }
    }

    tmp = head2;
    current = head;
    int f = 1;
    while(current && tmp){
        if(current->data != tmp->data){
            f = 0;
            break;
        }
        current = current->next;
        tmp = tmp->next;
    }

    if(tmp || current)
        f = 0;
    if(!f)
        printf("Not Equal\n");
    else
        printf("Equal\n");

}


int main(){
    while(1){
        printf("1. Create linked list\n");
        printf("2. Print content of the list\n");
        printf("3. Insert element at the front of the list\n");
        printf("4. Insert element at the end of the list\n");
        printf("5. Insert a node after the kth node\n");
        printf("6. Insert a node after the node containing a given value\n");
        printf("7. Insert a node before the kth node\n");
        printf("8. Insert a node before the node containing a given value\n");
        printf("9. Delete the first node\n");
        printf("10. Delete the last node\n");
        printf("11. Delete a node after the kth node\n");
        printf("12. Delete a node before the kth node\n");
        printf("13. Delete the kth node\n");
        printf("14. Delete the node containing a specified value\n");
        printf("15. Reverse of the list\n");
        printf("16. Sort the list\n");
        printf("17. search a given element\n");
        printf("18. Merge two lists(ascending order)\n");
        printf("19. Concatenate two list\n");
        printf("20. Find if two list are equal(boolean output)\n");
        
        int option;
        printf("> ");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("..............\n");
                create();
                printf("..............\n");
                break;
            case 2:
                printf("..............\n");
                display();
                printf("..............\n");
                break;
            case 3:
                printf("..............\n");
                insert_front();
                printf("..............\n");
                break;
            case 4:
                printf("..............\n");
                insert_rear();
                printf("..............\n");
                break;
            case 5:
                printf("..............\n");
                insert_after_kth();
                printf("..............\n");
                break;
            case 6:
                printf("..............\n");
                insert_by_value();
                printf("..............\n");
                break;
            case 7:
                printf("..............\n");
                insert_before_kth();
                printf("..............\n");
                break;
            case 8:
                printf("..............\n");
                insert_by_value_before();
                printf("..............\n");
                break;
            case 9:
                printf("..............\n");
                delete_first();
                printf("..............\n");
                break;
            case 10:
                printf("..............\n");
                delete_last_node();
                printf("..............\n");
                break;
            case 11:
                printf("..............\n");
                delete_after_kth();
                printf("..............\n");
                break;
            case 12:
                printf("..............\n");
                delete_before_kth();
                printf("..............\n");
                break;
            case 13:
                printf("..............\n");
                delete_kth();
                printf("..............\n");
                break;
            case 14:
                printf("..............\n");
                delete_with_value();
                printf("..............\n");
                break;
            case 15:
                printf("..............\n");
                reverse();
                printf("..............\n");
                break;
            case 16:
                printf("..............\n");
                sort();
                printf("..............\n");
                break;
            case 17:
                printf("..............\n");
                search();
                printf("..............\n");
                break;
            case 18:
                printf("..............\n");
                merge();
                printf("..............\n");
                break;
            case 19:
                printf("..............\n");
                concate();
                printf("..............\n");
                break;
            case 20:
                printf("..............\n");
                equal();
                printf("..............\n");
                break;




        }
    }
    return 0;
}