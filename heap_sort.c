/*DATE:-02/02/2018
*NAME:- VINIT BOLLA
*ROLL:- 54
*DIV:- H 
*Implement Heap sort on set of Intergers stored in a File.
*FILE NAME:- heap.txt 
*C-FILE NAME:- heap_sort.c
*/ 
#include<stdio.h>
#include<stdlib.h>
int main(void){
//void main(){	
	FILE *fs;
	char ch;
	int num[100],i,n,c,temp,root,j;
	/*
	fs = fopen("heap.txt",'r');
	ch=fgetc(fs);
	*/

	for(i=0;i<=100;i++){
		num[i] = 0;
	}
	
	i=0;
	
		if((fs=fopen("heap.txt","r"))==NULL){
			printf("heap.txt failed to open\n");
			//return 1;
					
		}
		else{
			while((fscanf(fs,"%d",&num[i]))!=EOF){
				printf("num[%d]is %d\n",i,num[i]);
				i++;
				n++;			
			}
			
		}
		
	printf("\ncount=%d",n);
	//printf("\nUnsorted array:\n");
	// for (i = 0; i < n; i++)	
	//scanf("%d",&num[i]);
	  for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (num[root] < num[c])  //create heap
            {
                temp = num[root];
                num[root] = num[c];
                num[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
 
    printf("\nHeap array : \n\t");
    for (i = 0; i < n; i++)
        printf("%d\n\t ", num[i]);
    for (j = n - 1; j >= 0; j--)
    {
        temp = num[0];
        num[0] = num[j];    //swapping the maximum vala element
        num[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    // left of the root element
            if ((num[c] < num[c + 1]) && c < j-1)
                c++;
            if (num[root]<num[c] && c<j)    //arranging the max heap
            {
                temp = num[root];
                num[root] = num[c];
                num[c] = temp;
            }
            root = c;
        } while (c < j);
    } 
  
  printf("\n The sorted array is :\n ");
    for (i = 0; i < n; i++)
       printf("\t %d\n", num[i]);
 return 0;
}
