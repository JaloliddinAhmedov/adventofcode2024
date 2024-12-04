
#include <stdio.h>
#include <math.h>

#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

char data [141][142];  // Allocate memory for 100 rows
int cnt = 0;
int SIZE = 140;
bool res = false, holat1=false,holat2=false,holat3=false,holat4 = false;

bool tekshir(int i, int j){
	holat1 = data[i][j] == 'M' && data[i + 2][j] == 'M' && data[i][j+2] == 'S' && data[i + 2][j+2] == 'S' && data[i + 1][j+1] == 'A';
	holat2 = data[i][j] == 'M' && data[i + 2][j] == 'S' && data[i][j+2] == 'M' && data[i + 2][j+2] == 'S' && data[i + 1][j+1] == 'A';
	holat3 = data[i][j] == 'S' && data[i + 2][j] == 'M' && data[i][j+2] == 'S' && data[i + 2][j+2] == 'M' && data[i + 1][j+1] == 'A';
	holat4 = data[i][j] == 'S' && data[i + 2][j] == 'S' && data[i][j+2] == 'M' && data[i + 2][j+2] == 'M' && data[i + 1][j+1] == 'A';
	
	return holat1 || holat2 || holat3 || holat4;
}


int main(){
  
    FILE *file = fopen("C:/Users/ahmj/Downloads/input_4_1.txt", "r");  // Open the file in read mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;  // Return error code
    }

    
    int ind = 0;
    while (fgets(data[ind ++], sizeof(data[ind]), file)) {
    }

    fclose(file);  // Close the file

    for(int i = 0; i < SIZE-2; i ++){
    	for(int j = 0; j < SIZE - 2; j ++){
			cnt += (tekshir(j, i)?1:0);
		}
	}
    printf("tekshir Natija=%d\n",cnt);
    
  
  return 0;
}
