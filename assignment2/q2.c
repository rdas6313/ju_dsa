#include<stdio.h>
#include<stdlib.h>

struct node{
	int coeff;
	int power;
	struct node *next;
};

struct node* create_node(){
	struct node * dummy = (struct node*)malloc(sizeof(struct node));
	if(!dummy){
		printf("Unable to allocate memory!\n");
		return NULL;
	}
	dummy->next = NULL;
	return dummy;
}

struct node* add(struct node* head1,struct node* head2){

	struct node * dummy = create_node();
	struct node *current = dummy;
	while(head1 && head2){
		struct node* tmp = create_node();
		current->next = tmp;
		current = tmp;
		if(head1->power < head2->power){
			tmp->power = head2->power;
			tmp->coeff = head2->coeff;
			head2 = head2->next;
		}else if(head1->power > head2->power){
			tmp->power = head1->power;
			tmp->coeff = head1->coeff;
			head1 = head1->next;
		}else{
			tmp->power = head1->power;
			tmp->coeff = head1->coeff + head2->coeff;
			head2 = head2->next;
			head1 = head1->next;
		}
		
		
	}

	while(head1){
		struct node* tmp = create_node();
		current->next = tmp;
		current = tmp;
		tmp->power = head1->power;
		tmp->coeff = head1->coeff;
		head1 = head1->next;
	}

	while(head2){
		struct node* tmp = create_node();
		current->next = tmp;
		current = tmp;
		tmp->power = head2->power;
		tmp->coeff = head2->coeff;
		head2 = head2->next;
	}
	current = dummy->next;
	free(dummy);
	return current;
}

struct node* create_list(){
	int count;
	printf("No of element: ");
	scanf("%d",&count);
	struct node * dummy = create_node();
	struct node * current = dummy, *tmp;
	int i,coeff,power;
	printf("Enter coefficent and power: \n");
	for(i=0;i<count;i++){
		scanf("%d %d",&coeff,&power);
		tmp = create_node();
		tmp->coeff = coeff;
		tmp->power = power;
		current->next = tmp;
		current = tmp;
	}
	tmp = dummy->next;
	free(dummy);
	return tmp; 
}


void printResult(struct node* result){
	printf("Result: \n");
	while(result){
		if(result->coeff)
			printf("%d %d\n",result->coeff,result->power);
		result = result->next;
	}
}

void free_space(struct node *current){
	struct node* tmp = NULL;
	while(current){
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void substruction(){
	struct node *head1 = create_list();
	struct node *head2 = create_list();
	
	struct node *current = head2;
	while(current){
		current->coeff = -current->coeff;
		current = current->next;
	}
	current = NULL;
	struct node *result = add(head1,head2);
	printResult(result);
	free_space(head1);
	free_space(head2);
	free_space(result);
}


void addition(){
	struct node *head1 = create_list();
	struct node *head2 = create_list();
	struct node *result = add(head1,head2);
	struct node *current = NULL;
	printResult(result);
	free_space(head1);
	free_space(head2);
	free_space(result);

}

void multiplication(){
	struct node *head1 = create_list();
	struct node *head2 = create_list();
	struct node *dummy = create_node();
	struct node *result = NULL;
	struct node * current = dummy, *hcurrent = NULL, *tmp = NULL;
	while(head1){
		hcurrent = head2;
		current = dummy;
		while(hcurrent){
			tmp = create_node();
			tmp->coeff = head1->coeff * hcurrent->coeff;
			tmp->power = head1->power + hcurrent->power;
			current->next = tmp;
			current = tmp;
			hcurrent = hcurrent->next;
		}
		result = add(dummy->next,result);
		free_space(dummy->next);
		head1 = head1->next;
	}

	printResult(result);
	free_space(head1);
	free_space(head2);
	free_space(result);
}

int main(){
	printf("1. Add\n");
	printf("2. Sub\n");
	printf("3. Multiply\n");
	printf("> ");
	int option;
	scanf("%d",&option);
	switch(option){
		case 1:
			addition();
			break;
		case 2:
			substruction();
			break;
		case 3:
			multiplication();
			break;
		
	}
	return 0;
}