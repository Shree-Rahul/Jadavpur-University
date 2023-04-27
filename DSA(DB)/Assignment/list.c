#include<stdio.h>
#include<stdlib.h>

void create(int **arr,int *size){
    printf("\nEnter number of elements : ");
    scanf("%d",size);
    *arr = (int*)malloc(sizeof(int)*(*size));
    printf("\nEnter Elements one by one: ");
    for(int i=0;i< *size;i++) {
        scanf("%d",(*arr+i));
    }
}

void display(int *arr,int *size) {
    for(int i =0;i<(*size);i++) printf("%3d",*(arr+i));
    printf("\n\n");
}
void merge(int *first,int **second ,int **result,int *size_f,int *size_s,int *size_r) {
    if(!(*second)){
        printf("\nEnter number of elements in the second array : ");
        scanf("%d",size_s);
        *second= (int*)malloc(sizeof(int)*(*size_s));
        printf("\nEnter Elements one by one: ");
        for(int i=0;i< *size_s;i++) {
            scanf("%d",(*second+i));
        }
        *size_r =((*size_f)+ (*size_s));
        *result = (int*)malloc(sizeof(int)*(*size_r));
        int j =0;
        for(int i=0;i<*size_r;i++){
            if(i<*size_f) {
                *(*result+i)=*(first+i);
            }else {
                *(*result+i)=*(*second+j);
                j++;
            }
        }
    }else{
        *size_r =((*size_f)+ (*size_s));
        *result = (int*)malloc(sizeof(int)*(*size_r));
        int j =0;
        for(int i=0;i<*size_r;i++){
            if(i<*size_f) {
                *(*result+i)=*(first+i);
            }else {
                *(*result+i)=*(*second+j);
                j++;
            }
        }
    }
    display(*result,size_r);
}
void insert(int *arr, int *size) {
    int pos,num,i;
    printf("\nEnter position :");
    scanf("%d",&pos);
    printf("\nEnter Integer value : ");
    scanf("%d",&num);
    *size +=1;
    arr = realloc(arr,sizeof(int)*(*size));
    for(i=(*size)-1;i>pos-1;i--){
        *(arr+i)=*(arr+i-1);
    }
    *(arr+i)=num;
    printf("\nInserted.");
}
//Error in this function
void sort(int *arr,int *size){
    if(!(*size)) {
        printf("\nList is Empty.");
        return;
    }
    // printf("\nI am here");
    int n =(*size);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){

            if(arr[j] > arr[j+1]){
                int temp =arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
   printf("\nList sorted.");
}

void split(int *part1,int *part2,int *input,int *size_p1,int *size_p2,int *size_i){
    printf("\nInput list is :");
    display(input,size_i);
    printf("\nEnter the position you want to split:");
    scanf("%d",size_p1);
    if((*size_i)==0 || (*size_p1<0 || *size_p1>*size_i)) {
        if((*size_p1<0 || *size_p1>*size_i))
            printf("\nInvalid position ,try again..");
        else
            printf("\nList is Empty.");
        return;
    }
    *size_p2=(*size_i-(*size_p1));
    part1=realloc(part1,sizeof(int)*(*size_p1));
    part2=realloc(part2,sizeof(int)*(*size_p2));

    for(int i=0,j=0;i<(*size_i);i++){
        if(i<(*size_p1)) {
            *(part1+i)=*(input+i);
        }else{
            *(part2+j)=*(input+i);
            j++;
        }
    }

    display(part1,size_p1);
    display(part2,size_p2);
}
void reverse(int *arr,int *size) {
    if(!(*size)) {
        printf("\nList is Empty.");
        return;
    }
    int i=0, j=(*size)-1;
    while(i<j){
        int temp=*(arr+i);
        *(arr+i)=*(arr+j);
        *(arr+j)=temp;
        i++;
        j--;
    }
    printf("\nList Reversed.");
}

void fIndex(int *arr,int *size){ 

    if(!(*size)) {
        printf("\nList is Empty.");
        return;
    }

	printf("\nEnter the Element : ");
	int ele,i,flag=1;
	scanf("%d",&ele);
	for(i=0;i<(*size);i++) {
		if(*(arr+i)==ele) {
			printf("\n\n[Element %d found at index %d]\n",ele,i+1);
			flag=0;
		}
	}
	if(flag)
	printf("\n\n[Element not found]\n");
}

void delete(int *arr,int *size) {

    if(!(*size)) {
        printf("\nList is Empty.");
        return;
    }

	printf("\nEnter the index of the element you want to delete: ");
	int id;
	scanf("%d",&id);
	if(id>=(*size) || id<0) printf("\n\n[Inavlid index]\n");
	else {
		int i=id-1;
		while(i != (*size)-1) {
			*(arr+i)=*(arr+i+1);
			i++;
		}
		(*size)--;
	}

    printf("\nItem Deleted");
}


void fElement(int *arr,int *size) { 

    if(!(*size)) {
        printf("\nList is Empty.");
        return;
    }
	printf("\nEnter the index : ");
	int id;
	scanf("%d",&id);
	if(id>=(*size)) printf("\n\n[Inavlid index]\n");
	else printf("\n\n[Element at %d index is %d]\n",id,*(arr+id));
}

void search(int *arr,int *size) {
    if(!(*size)) {
        printf("\nList is Empty.");
        return;
    }

	printf("\nEnter the Element : ");
	int ele,i;
	scanf("%d",&ele);
	for(i=0;i<(*size);i++) {
		if(*(arr+i)==ele) {
			printf("\n\nGiven element present in the list.");
			return;
		}
	}
	printf("\n\n[Element not found]\n");
}
int main()
{
    int *first=NULL, size_f=0, *second=NULL, *result=NULL, size_s=0, size_r=0;

    int repeat=1;

	while(repeat){
		printf("\n\n\t [Choose one from bellow]\na)Create \nb)Display the entire list\nc)Count\nd)Reverse the list\ne)Index of given element\nf)Indexed element\ng)Insert\nh)delete\ni)Merge\nj)Split\nk)Sort\nl)Search\n\nPress 0 to exit the program..\n\n");
		char ch;
		scanf("%c",&ch);
		switch(ch){
			case 'a':create(&first,&size_f);
					break;
			case 'b':printf("\nGiven list is:");
					display(first,&size_f);
					break;
			case 'g':insert(first,&size_f);
					break;
			case 'c':printf("\n[Elements in the given list is : %d]",size_f);
					break;
			case 'd':reverse(first,&size_f);
					break;
			case 'e':fIndex(first,&size_f);
					break;
			case 'f':fElement(first,&size_f);
					break;
			case 'h':delete(first,&size_f);
                    break;
			case 'i':merge(first,&second,&result,&size_f,&size_s,&size_r);
					break;
			case 'j':split(first,second,result,&size_f,&size_s,&size_r);
					break;
			case 'k':sort(first,&size_f);
                    break;
			case 'l':search(first,&size_f);
                    break;
            case '0':printf("\n--Thank You--\n");
			    	repeat = 0;
			    	break;
			default :
			    	break;
		}
	}
}
