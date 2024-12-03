#include <stdio.h>
#include <math.h>

int main(){
  
  FILE *myFile;
    myFile = fopen("C:/Users/JaloliddinAhmad/Pictures/input.txt", "r");

    //read file into array
    int arr1[1001], arr2[1001], temp = 0, sum = 0;
    

    for (int i = 0; i < 1000; i++)
    {
        fscanf(myFile, "%d", &arr1[i]);
        fscanf(myFile, "%d", &arr2[i]);
    }

    for (int i = 0; i < 999; i++)
    {
        for(int j=i+1; j < 1000; j ++){
          if(arr1[i]>arr1[j]){
            temp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp;
          }
          
          if(arr2[i]>arr2[j]){
            temp = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp;
          }
        }                               
    }
    
    for(int i = 0; i < 1000; i ++){
    sum += abs(arr1[i] - arr2[i]);
    }
    
    
    
  
  printf("test[%d]",sum);
  return 0;
}
