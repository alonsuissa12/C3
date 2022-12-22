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

//  בשביל המיון נממש פונקצית עזר נוספת
// הפונקציה תקבל מצביע לתחילת המערך ומצביע למיקום במערך
// וכל עוד הערך במיקום קטן מהערך לפניו היא תדחוף אותו אחורה במערך 
void MY_shift_element(int *arr , int *i) {
     int ival;
         for  ( ival = *i ; ival < *(i-1) && i > arr; i--)
            {  
            *i = *(i-1);
           }
           *i = ival;
}

void insertion_sort(int* arr , int len){
     int i;
     for (i = 0; i < len  ; i++ ){
        int current = *(arr+i);
        printf("current: %d \n" ,current );
          print_array(&arr[0], len);
        int j = 0;
          while (*(arr) < current && j < i){
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

// shift_element (arr , 3);
	// print_array(&arr[0], n);
	
	insertion_sort(&arr[0], n);
	
	print_array(&arr[0], n);
   
    return 1;

}



