#include<stdio.h>
#include <stdlib.h>


void solve_array(){
	int len;
	printf("No of element: ");
	scanf("%d",&len);
	int ele[2][len],i;
	printf("Elements: ");
	for(i=0;i<len;i++){
		scanf("%d",&ele[0][i]);
		ele[1][i] = 0;
	}

	int k;
	printf("No of Skipped element: ");
	scanf("%d",&k);

	int del = 0;
	i = -1;
	int c = 0;
	printf("Executed person: ");
	while(len-del > 1){
		i = (i+1)%len;
		if(ele[1][i]){
			continue;
		}
		if(c < k){
			c++;
			continue;
		}
		printf("%d ",ele[0][i]);
		ele[1][i] = 1;
		del++;
		c = 0;
	}

	for(i = 0;i<len;i++)
		if(!ele[1][i]){
			printf("\nFreed person: %d\n",ele[0][i]);
			break;
		}
}





void solve_linked_list(){
	struct node{
		int val;
		struct node * next;
	} *dummy,*cur,*tmp,*prev ;

	dummy = (struct node*)malloc(sizeof(struct node));
	dummy->next = NULL;
	cur = dummy;
	int len,i;
	printf("No of element: ");
	scanf("%d",&len);
	printf("Enter elements: ");
	for(i=0;i<len;i++){
		tmp = (struct node*) malloc(sizeof(struct node));
		tmp->next = NULL;
		scanf("%d",&tmp->val);
		cur->next = tmp;
		cur = tmp;	
	}

	cur->next = dummy->next;

	int k;
	printf("No of Skipped element: ");
	scanf("%d",&k);

	cur = dummy;
	int c = 0;
	int del = 0;
	printf("Executed person: ");
	while(len-del > 1){
		prev = cur;
		cur = cur->next;
		if(c == k){
			c = 0;
			prev->next = cur->next;
			tmp = cur;
			cur = cur->next;
			if(dummy->next == tmp)
				dummy->next = cur;
			printf("%d ",tmp->val);
			free(tmp);
			del++;
		}
		c++;
	}

	printf("\nFreed person: %d\n",dummy->next->val);


}

void solve_doubly(){
	struct node{
		int val;
		struct node * next;
		struct node *prev;
	} *dummy,*cur,*tmp ;

	dummy = (struct node*)malloc(sizeof(struct node));
	dummy->next = NULL;
	dummy->prev = NULL;
	cur = dummy;
	int len,i;
	printf("No of element: ");
	scanf("%d",&len);
	printf("Enter elements: ");
	for(i=0;i<len;i++){
		tmp = (struct node*) malloc(sizeof(struct node));
		tmp->next = NULL;
		tmp->prev = cur;
		cur->next = tmp;
		cur = tmp;
		scanf("%d",&tmp->val);
	}
	cur->next = dummy->next;
	dummy->next->prev = cur;

	int k;
	printf("No of Skipped element: ");
	scanf("%d",&k);

	cur = dummy;
	int c = 0;
	int del = 0;
	printf("Executed person: ");
	while(len-del > 1){
		cur = cur->next;
		if(c == k){
			c = 0;
			cur->next->prev = cur->prev;
			cur->prev->next = cur->next;
			tmp = cur;
			cur = cur->next;
			if(dummy->next == tmp)
				dummy->next = tmp->next;
			del++;
			printf("%d ",tmp->val);
			free(tmp);
		}
		c++;
	}

	printf("\nFreed person: %d\n",dummy->next->val);
}


int main(){
	printf("1. Solve using array!\n");
	printf("2. Solve using circular linked list\n");
	printf("3. Solve using circular doubly linked list\n");
	int op;
	printf("> ");
	scanf("%d",&op);
	switch(op){
		case 1:
			solve_array();
			break;
		case 2:
			solve_linked_list();
			break;
		case 3:
			solve_doubly();
			break;

	}
	return 0;
}