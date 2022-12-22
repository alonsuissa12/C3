//
// Created by alon on 12/18/22.
//
# include <stdio.h>
#include "isort.h"

void shift_element(int* arr, int i){

  // נשמור משתנה עבור האיבר "הבא " במערך
int a = *arr , b = *(arr+1);
   for (int j = 1 ; j <= i ; j++){
        // את התוכן שבמקום שקיבלנו+1 נשנה לתוכן של הקודם לו
        *(arr+j) = a;
        a = b;
       if(j+1 < sizeof(arr))  
            b=*(arr+j+1) ;
   }
}

void insertion_sort(int* arr , int len){
     int i;
     for (i = 0; i < len  ; i++ ){
        int current = *(arr+i);
        int j = 0;
          while (*(arr+j) < current && j < i){
            j++;
          }
            shift_element(arr+j, i-j);
            *(arr+j) = current; 
     }

}
void print_array(int *arr, int len) {
	int i;
	for(i = 0; i<len-1; i++) {
		printf("%d,", *arr);
		arr++;
	}
    printf("%d" , *arr);
	printf("\n");
}
int main() {
	
	int arr[6] = {99, 78, -1, 42, 12};
	int n = sizeof(arr)/sizeof(arr[0]);

	
	insertion_sort(&arr[0], n);
	
	print_array(&arr[0], n);
   
    return 1;

}



