
#include <stdio.h>
#include <math.h>

#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

int main(){
  
    FILE *file = fopen("C:/Users/ahmj/Downloads/input_2_1.txt", "r");  // Open the file in read mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;  // Return error code
    }

    int data [1000][100];  // Allocate memory for 100 rows
    int lineCounts[1000];  // Array to store the count of numbers in each line
    int lineNumber = 0;  // To track the current line
    bool inc, safe;
    int sum = 0;

    char line[MAX_LINE_LENGTH];  // Buffer to store each line

    while (fgets(line, sizeof(line), file)) {
        // Strip the newline character at the end of the line if exists
        line[strcspn(line, "\n")] = 0;

        // Allocate memory for storing numbers in the current line
        int currentLineData[100];
        int count = 0;

        // Tokenize the line into individual numbers
        char *token = strtok(line, " ");
        while (token != NULL) {
            currentLineData[count++] = atoi(token);  // Convert token to integer and store it
            token = strtok(NULL, " ");
        }

        // Store the count of numbers in the current line
        lineCounts[lineNumber] = count;

        // Store the array of numbers in the 2D array
        for(int i = 0; i < count; i ++){
        	data[lineNumber][i] = currentLineData[i];	
		}
		

        lineNumber++;  // Move to the next line
    }

    fclose(file);  // Close the file

    for (int i = 0; i < lineNumber; i++) {
        printf("Line %d (Count %d): ", i + 1, lineCounts[i]);
        for (int j = 0; j < lineCounts[i]; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
	
    for (int i = 0; i < lineNumber; i++) {
        inc = (data[i][1] < data[i][0])?false:true;
        safe = true;
        for (int j = 1; j < lineCounts[i]; j++) {
            if((((data[i][j] - data[i][j-1]) > 0) == inc) && (0<abs(data[i][j] - data[i][j-1]) && abs(data[i][j] - data[i][j-1])<4)){
            	
			}else{
				safe = false;
			}
        }
        if(safe){
        	sum ++;
        	printf("Qator=[%d]\n",i+1);
		}
    }		
    
    printf("Natija=%d",sum);
    
  
  return 0;
}
