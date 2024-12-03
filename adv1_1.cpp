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

    for (int i = 0; i < 1000; i++)
    {
      for(int j = 0; j < 1000; j ++){
          if(arr1[i] == arr2[j]){
            sum += arr1[i];
          }               
    }
    } 
    
    
  
  printf("test[%d]",sum);
  return 0;
}
