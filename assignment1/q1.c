#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 5

int *head = NULL;
int size = 0;
int current_index = 0;

void free_mem(){
	if(head != NULL)
		free(head);
}


void create(){
	if(head == NULL){
		head = (int *)malloc(ARRAY_SIZE*sizeof(int));
		if(head == NULL){
			printf("Unable to create array.Insufficient memory.\n");
		}else
			size = ARRAY_SIZE;
	}
	else
		printf("Already ");

	printf("Created\n");

}

void count(){
	if(head == NULL){
		printf("Array has not been created yet.\n");
		return;
	}
	printf("Total element in the list: %d\n",current_index);
}

void display(){
	if(head == NULL){
		printf("Array has not been created yet.\n");
		return;
	}
	printf("Elements of list: ");
	int i = 0;
	while(i < current_index){
		printf("%d ",*(head+i));
		i++;
	}
	printf("\n");
}

int insert_element(int val){
	if(current_index == size){
		head = realloc(head,(size+ARRAY_SIZE)*sizeof(int));
		if(head == NULL){
			printf("Unable to insert value. Insufficient memory.\n");
			return 0;
		}
		size += ARRAY_SIZE;
	}

	*(head+current_index) = val;
	current_index++;
	return 1;
}

void insert(){
	if(head == NULL){
		printf("Array has not been created yet.\n");
		return;
	}
	int val;
	printf("value: ");
	scanf("%d",&val);

	if(!insert_element(val))
		return;
	printf("inserted.\n");

}

void delete(){
	if(head == NULL){
		printf("Array has not been created yet.\n");
		return;
	}

	int index;
	printf("Index: ");
	scanf("%d",&index);
	if(index >= current_index){
		printf("Out of bound index.\n");
		return;
	}
	int i;
	for(i=index+1;i<current_index;i++){
		*(head+i-1) = *(head+i);
	}

	current_index--;

	if((size - current_index) > ARRAY_SIZE){
		head = realloc(head,(size-ARRAY_SIZE)*sizeof(int));
		if(head == NULL){
			printf("Insufficient memory.\n");
			return;
		}
		size -= ARRAY_SIZE;
	}

	printf("Deleted\n");

}


void reverse(){
	if(head == NULL){
		printf("Array has not been created yet.\n");
		return;
	}
	if(current_index < 1){
		printf("Currently no element in the array.\n");
		return;
	}
	int *last = (head+current_index-1);
	int *first = head;
	int tmp;
	while(first < last){
		tmp = *first;
		*first = *last;
		*last = tmp;
		first++;
		last--;
	}
	printf("list reversed.\n");
}


void find_index(){
	if(head == NULL){
		printf("Array has not been created yet.\n");
		return;
	}
	int element;
	printf("Element: ");
	scanf("%d",&element);
	printf("Indices are: ");
	int i=0;
	int f = 0;
	while(i < current_index){
		if(*(head+i) == element){
			printf("%d ",i);
			f = 1;
		}
		i++;
	}
	if(!f)
		printf("No indices found!");
	printf("\n");

}


void element_at(){
	if(head == NULL){
		printf("Array has not been created yet.\n");
		return;
	}
	int index;
	printf("Index: ");
	scanf("%d",&index);
	if(index >= current_index){
		printf("Out of bound index.\n");
		return;
	}
	printf("Value at index %d : %d\n",index,*(head+index));
}

void merge(){
	if(head == NULL){
		printf("Array has not been created yet.\n");
		return;
	}
	int n;
	printf("No of Merge Elements: ");
	scanf("%d",&n);
	int element, flag = 0;
	printf("\nElements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&element);
		if(!insert_element(element)){
			flag = 1;
			break;
		}
	}

	if(!flag)
		printf("Merged Successfully!\n");
	

}


void split(){
	if(head == NULL){
		printf("Array has not been created yet.\n");
		return;
	}

	printf("Index from where you want to split: ");
	int index;
	scanf("%d",&index);
	if(index > current_index){
		printf("Index out of bound!\n");
		return;
	}
	printf("Element of Array 1: ");
	for(int i=0;i<index;i++)
		printf("%d ",head[i]);
	printf("\nElement of Array 2: ");
	for(int i=index;i<current_index;i++)
		printf("%d ",head[i]);
	printf("\n");
}

void sort(){
	if(head == NULL){
		printf("Array has not been created yet.\n");
		return;
	}
	if(current_index <= 1){
		printf("No need to sort! Either no of element is one or less than that.\n");
		return;
	}
	int i,j;
	for(i=0;i<current_index-1;i++){
		for(j=i+1;j<current_index;j++){
			if(head[i] > head[j]){
				int tmp = head[i];
				head[i] = head[j];
				head[j] = tmp;
			}
		}
	}
	printf("Sorted!\n");
}

int main(){
	int should_exit = 0;
	while(!should_exit){
		printf("1. Create\n");
		printf("2. Display list\n");
		printf("3. Count\n");
		printf("4. Reverse the list\n");
		printf("5. Index of a given element\n");
		printf("6. Indexed element\n");
		printf("7. Insert\n");
		printf("8. Delete\n");
		printf("9. Merge\n");
		printf("10. Split\n");
		printf("11. Sort\n");
		printf("0. Exit\n");
		printf("Choose:> ");
		int option;
		scanf("%d",&option);
		switch(option){
			case 1:
				printf(".........\n");
				create();
				printf(".........\n");
				break;
			case 2:
				printf(".........\n");
				display();
				printf(".........\n");
				break;
			case 3:
				printf(".........\n");
				count();
				printf(".........\n");
				break;
			case 4:
				printf(".........\n");
				reverse();
				printf(".........\n");
				break;
			case 5:
				printf(".........\n");
				find_index();
				printf(".........\n");
				break;
			case 6:
				printf(".........\n");
				element_at();
				printf(".........\n");
				break;
			case 7:
				printf(".........\n");
				insert();
				printf(".........\n");
				break;
			case 8:
				printf(".........\n");
				delete();
				printf(".........\n");
				break;
			case 9:
				printf(".........\n");
				merge();
				printf(".........\n");
				break;
			case 10:
				printf(".........\n");
				split();
				printf(".........\n");
				break;
			case 11:
				printf(".........\n");
				sort();
				printf(".........\n");
				break;
			default:
				free_mem();
				should_exit = 1;
		}
	

	}
	return 0;
}