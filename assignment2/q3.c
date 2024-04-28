#include<stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
} *dummy;

struct node* create_node(int value){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL){
        printf("Unable to allocate space\n");
        return NULL;
    }
    tmp->data = value;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

void create(){
    if(dummy->next != NULL){
        printf("Already created!\n");
        return;
    }
    int count,value;
    printf("No of element: ");
    scanf("%d",&count);
    printf("Enter element: ");
    struct node* current = dummy;
    for(int i=0;i<count;i++){
        scanf("%d",&value);
        struct node* tmp = create_node(value);
        current->next = tmp;
        if(current != dummy)
        	tmp->prev = current;
        current = tmp;
    }
    dummy->prev = current;
    printf("Created\n");
}

void display(){
	if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    struct node* current = dummy->next;
    printf("List: ");
    while(current){
    	printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void insert_front(){
    if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node * tmp = create_node(value);
    tmp->next = dummy->next;
    dummy->next->prev = tmp;
    dummy->next = tmp;
    printf("Inserted\n");
}

void insert_rear(){
    if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node * tmp = create_node(value);
    dummy->prev->next = tmp;
    tmp->prev = dummy->prev;
    dummy->prev = tmp;
    
    printf("Inserted at the end\n");

}

void insert_after_kth(){
    if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node * tmp = create_node(value);
 	
 	int index;
    printf("Enter index: ");
    scanf("%d",&index);
    struct node* current = dummy->next;
    
    int i=0;
    while(i<index && current){
    	i++;
    	current = current->next;
    }

    if(!current){
    	printf("Invalid index\n");
    	return;
    }

    tmp->next = current->next;
    tmp->prev = current;
    if(current->next)
    	current->next->prev = tmp;
    current->next = tmp;
    if(current == dummy->prev)
    	dummy->prev = tmp;

    printf("Inserted Successfully\n");

}

void insert_by_value(){
    if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    int value;
    printf("Enter value: ");
    scanf("%d",&value);

    struct node * tmp = create_node(value);
    int node_value;
    printf("Enter node value: ");
    scanf("%d",&node_value);

    struct node* current = dummy->next;
    int is_inserted = 0;
    while(current){
        if(current->data == node_value){
            tmp->next = current->next;
		    tmp->prev = current;
		    if(current->next)
		    	current->next->prev = tmp;
		    current->next = tmp;
		    if(current == dummy->prev)
    			dummy->prev = tmp;
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
    if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);
    struct node * tmp = create_node(value);
 	
 	int index;
    printf("Enter index: ");
    scanf("%d",&index);
    struct node* current = dummy->next;
    
    int i=0;
    while(i<index && current){
    	i++;
    	current = current->next;
    }

    if(!current){
    	printf("Invalid index\n");
    	return;
    }

    tmp->next = current;
    tmp->prev = current->prev;
    if(current->prev)
    	current->prev->next = tmp;
    current->prev = tmp;
    if(dummy->next == current)
    	dummy->next = tmp;


    printf("Inserted Successfully\n");

}

void insert_by_value_before(){
	if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    int value;
    printf("Enter value: ");
    scanf("%d",&value);

    struct node * tmp = create_node(value);
    int node_value;
    printf("Enter node value: ");
    scanf("%d",&node_value);

    struct node* current = dummy->next;
    int is_inserted = 0;
    while(current){
        if(current->data == node_value){
            tmp->next = current;
		    tmp->prev = current->prev;
		    if(current->prev)
		    	current->prev->next = tmp;
		    current->prev = tmp;
		    if(dummy->next == current)
		    	dummy->next = tmp;
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

void delete_first(){
	if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }

    struct node* current = dummy->next;
    dummy->next = current->next;
    if(current->next)
    	current->next->prev = NULL;
    free(current);
    printf("Deleted\n");
}

void delete_last_node(){
	if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }

    struct node* current = dummy->prev;
    dummy->prev = current->prev;
    if(current->prev)
    	current->prev->next = NULL;
    free(current);
    printf("Deleted\n");
}


void delete_after_kth(){
	if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
 	
 	int index;
    printf("Enter index: ");
    scanf("%d",&index);
    struct node* current = dummy->next;
    
    int i=0;
    while(i<index && current){
    	i++;
    	current = current->next;
    }

    if(!current){
    	printf("Invalid index\n");
    	return;
    }else if(!current->next){
    	printf("Nothing after index %d!\n",index);
    	return;
    }

    current = current->next;
    current->prev->next = current->next;
    if(current->next)
    	current->next->prev = current->prev;

    if(current == dummy->prev)
    	dummy->prev = current->prev;

    free(current);
    

    printf("Deleted Successfully\n");

}

void delete_before_kth(){
	if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
 	
 	int index;
    printf("Enter index: ");
    scanf("%d",&index);
    struct node* current = dummy->next;
    
    int i=0;
    while(i<index && current){
    	i++;
    	current = current->next;
    }

    if(!current){
    	printf("Invalid index\n");
    	return;
    }else if(!current->prev){
    	printf("Nothing before index %d!\n",index);
    	return;
    }

    current = current->prev;
    current->next->prev = current->prev;
    if(current->prev)
    	current->prev->next = current->next;

    if(current == dummy->next)
    	dummy->next = current->next;

    free(current);
    
    

    printf("Deleted Successfully\n");
}

void delete_kth(){
	if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
 	
 	int index;
    printf("Enter index: ");
    scanf("%d",&index);
    struct node* current = dummy->next;
    
    int i=0;
    while(i<index && current){
    	i++;
    	current = current->next;
    }

    if(!current){
    	printf("Invalid index\n");
    	return;
    }

    if(current->prev)
    	current->prev->next = current->next;
    if(current->next)
    	current->next->prev = current->prev;

    dummy->next = (current == dummy->next) ? current->next : dummy->next;
    dummy->prev = (current == dummy->prev) ? current->prev : dummy->prev;

    free(current);

    printf("Deleted Successfully\n");
}

void delete_with_value(){
	if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }
    printf("Enter value: ");
    int value;
    scanf("%d",&value);

    struct node* current = dummy->next;

    int f = 0;
    while(current){
        if(current->data == value){
            if(current->prev)
    			current->prev->next = current->next;
		    if(current->next)
		    	current->next->prev = current->prev;

		    dummy->next = (current == dummy->next) ? current->next : dummy->next;
		    dummy->prev = (current == dummy->prev) ? current->prev : dummy->prev;
            f = 1;
        }
        current = current->next;
    }

    if(f)
        printf("Deleted\n");
    else
        printf("No data found with %d\n",value);
}

void reverse(){
	if(dummy->next == NULL){
        printf("Linked list not created yet\n");
        return;
    }

    struct node * current = dummy->next, *next;

    while(current){
    	next = current->next;
    	current->next = current->prev;
    	current->prev = next;
    	current = next;
    }

    current = dummy->next;
    dummy->next = dummy->prev;
    dummy->prev = current;
    printf("Reversed\n");

}

int main(){
	dummy = create_node(0);
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
        }
        
    }
	return 0;
}