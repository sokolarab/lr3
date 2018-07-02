#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#define N 7

int compare(const void* a, const void* b){
	switch(sizeof(a)){
		case 1:
			if(*(char*)a < *(char*)b) return -1;
			if(*(char*)a > *(char*)b) return 1;
			if(*(char*)a == *(char*)b) return 0;
			break;
		case 4:
			if(*(int*)a > *(int*)b) return 1;
			else
				if(*(int*)a = *(int*)b) return 0;
				else return -1;
			break;
		case 8:
			if (fabs(*(double*)a - *(double*)b <= FLT_EPSILON)) return 0;
			if (*(double*)a < *(double*)b) return -1;
				else return 1;
			break;
	}
}
 void* mybsearch(const void *key, const void *str, int length, int size, int (*compare)(const void* a,const void* b)){

	if(length = 0)
		return NULL;
	int m=N/2;
	int found;
	if(compare(str[m],key)==0)
		found = m;
	else
		if(compare(str[m],key)<0){
			found = mybsearch(key,str+m+1,N-m-1,size,compare);
		}
	else
		found = mybsearch(key,str,m,size,compare);

return str[found];

}
int main(){
	int q;
	scanf("%d",&q);
	if(q=1){
		char *str1 = malloc(N * sizeof(char));
		fgets(str1,N,stdin);
		char* key1;
		scanf("%c",key1);
		char* res1 = mybseacrh(key1,str1,N,1,compare);
		printf("Индекс найденного элемента: %li",(key1-str1));
	}
	if(q=4){
		int *str4 = malloc(N * sizeof(int));
                for(int i=0;i<N;i++)
			scanf("%d",&str4[i]);
                int* key4;
                scanf("%d",key4);
                int* res4 = mybseacrh(key4,str4,N,4,compare);
                printf("Индекс найденного элемента: %li",(key4-str4));
	}
	if(q=8){
		double *str8 = malloc(N * sizeof(double));
                for(int i=0;i<N;i++)
                        scanf("%lf",&str8[i]);
                double* key8;
                scanf("%lf",key8);
                double* res8 = mybseacrh(key8,str8,N,8,compare);
                printf("Индекс найденного элемента: %li",(key8-str8));
	}

return 0;
}

