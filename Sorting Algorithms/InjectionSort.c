#include <stdio.h>

void main(){
    
    int a[] = {9,3,7,2,6,4,8,1,5}; //array to be sorted can also be taken from user
    int size = sizeof(a)/sizeof(a[0]);
    int temp = 0;

    //print unsorted array
    printf("Unsorted array: ");
    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    for(int i=0; i<size-1; i++){ //loop to compare each element with next element
        if(a[i]>a[i+1]){ //if current element is greater than next element

            temp = a[i+1]; //store next element in temp variable

            //loops places shifts all elements greater than temp to right by 1 position
            int j=i;
            while(a[j]>temp && j>=0){
                a[j+1] = a[j]; //shift current element to right
                j--; //decrement j to compare with previous element
            }
            a[j+1] = temp; //place next element at its correct position
        }  

        // // print array after every iteration (understanding purpose)
        // for(int i =0; i<size; i++){
        //     printf("%d ", a[i]);
        // }
        // printf("\n"); 
    }
    //print sorted array
    printf("Sorted array: ");
    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
}
