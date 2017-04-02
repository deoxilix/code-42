#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>

int m, n;
int b[10000], g[10000];

struct index{
	int data;
    struct index* next;
};
struct index *p, *head=NULL, *temp;

void entail(){
	p=(struct index*)malloc(sizeof(struct index));
	p->next=NULL;
	struct index *tmp= head;
	if(head==NULL) head=p;
	else{
    	while(tmp->next!=NULL){
        	tmp=tmp->next;
        }
    tmp->next=p;
}
	p->data=n-1;
printf("\nentailed.p->data=%d\n", p->data);
}

void delete(){
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    else if(p==head){
        head=p->next;
        free(p);
    }
    else{
            temp->next=p->next;
            free(p);
	}
}

int main(){
    int t, i ,j, pair=0;

do{
	scanf("%d", &t);
}while(t>10);

	while(t--){

        while(head!=NULL) delete();

		scanf("%d%d", &m,&n);

		for(i=m; i && scanf("%d", &b[i-1])<200; i--); //i++; //m=i;

		for(j=0; n && scanf("%d", &g[n-1])<200; n--){
             entail();
             j++;
		} n=j;

		//sort(g[]);

		int swapped=1;
	while(swapped){

		swapped=0;

		for(i=0;i<n-2;i++){
			if(g[i]>g[i+1]){
			int tmp= g[i];
			g[i]=g[i+1];
			g[i+1]=tmp;
			swapped=1;
			}
		}

	}

            //solve();
        for (i=m; m; m--){
		 for(p=head, temp=head; n; n--){

printf("\nsolve.p->data=%d\n", p->data);
		 	if(b[m-1]>g[p->data]){
		 		pair++;
                delete();
                break;
		 	}
		 	if(p->next==NULL)break;
		 	temp=p;
		 	p=p->next;

		 }
		}

	m=i;
	if(pair==m) {printf("YES");}
    else {printf("NO");}
	}
}
