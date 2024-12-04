
#include <stdio.h>
#include <math.h>

#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

char data [141][142];  // Allocate memory for 100 rows
int cnt = 0;
int SIZE = 140;
bool res = false;

bool tekshir(int i, int j){
	res = (data[i][j] == 'X' && data[i + 1][j] == 'M' && data[i + 2][j] == 'A' && data[i + 3][j] == 'S') || (data[i][j] == 'S' && data[i + 1][j] == 'A' && data[i + 2][j] == 'M' && data[i + 3][j] == 'X');
	return res;
}

bool tekshirqator(int i, int j){
	res = (data[i][j] == 'X' && data[i][j+1] == 'M' && data[i][j+2] == 'A' && data[i][j+3] == 'S') || (data[i][j] == 'S' && data[i][j+1] == 'A' && data[i][j+2] == 'M' && data[i][j+3] == 'X');
	//printf("i=%d, j=%d, date = [%c%c%c%c], res=%d\n", i, j, data[i][j], data[i][j+1], data[i][j+2], data[i][j+3], res);
	return res;
}

bool tekshirdiag1(int i, int j){
	return (data[i][j] == 'X' && data[i+1][j+1] == 'M' && data[i+2][j+2] == 'A' && data[i+3][j+3] == 'S') || (data[i][j] == 'S' && data[i+1][j+1] == 'A' && data[i+2][j+2] == 'M' && data[i+3][j+3] == 'X');
}

bool tekshirdiag2(int i, int j){
	return (data[i][j] == 'X' && data[i-1][j+1] == 'M' && data[i-2][j+2] == 'A' && data[i-3][j+3] == 'S') || (data[i][j] == 'S' && data[i-1][j+1] == 'A' && data[i-2][j+2] == 'M' && data[i-3][j+3] == 'X');
}

bool tekshirdiag3(int i, int j){
	return (data[i][j] == 'X' && data[i+1][j-1] == 'M' && data[i+2][j-2] == 'A' && data[i+3][j-3] == 'S') || (data[i][j] == 'S' && data[i+1][j-1] == 'A' && data[i+2][j-2] == 'M' && data[i+3][j-3] == 'X');
}

bool tekshirdiag4(int i, int j){
	return (data[i][j] == 'X' && data[i-1][j-1] == 'M' && data[i-2][j-2] == 'A' && data[i-3][j-3] == 'S') || (data[i][j] == 'S' && data[i-1][j-1] == 'A' && data[i-2][j-2] == 'M' && data[i-3][j-3] == 'X');
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

    for(int i = 0; i < SIZE; i ++){
    	for(int j = 0; j < SIZE - 3; j ++){
//    		if(){
//    			cnt ++;
//			}
			cnt += (tekshir(j, i)?1:0);
		}
	}
    printf("tekshir Natija=%d\n",cnt);
    cnt = 0;
    for(int i = 0; i < SIZE; i ++){
    	for(int j = 0; j < SIZE-3; j ++){
    		if(tekshirqator(i, j)) {
    			cnt ++;
			}
		}
	}
	
	printf("tekshirqator Natija=%d\n",cnt);
	
	cnt = 0;
    for(int i = 0; i < SIZE - 3; i ++){
    	for(int j = 0; j < SIZE-3; j ++){
    		cnt += (tekshirdiag1(i, j)?1:0);
		}
	}
	
	printf("tekshirdiag1 Natija=%d\n",cnt);
	
	cnt = 0;
    for(int i = 3; i < SIZE; i ++){
    	for(int j = 0; j < SIZE-3; j ++){
    		cnt += (tekshirdiag2(i, j)?1:0);
		}
	}
	
	printf("tekshirdiag2 Natija=%d\n",cnt);
	/*
	
	cnt = 0;
    for(int i = 3; i < SIZE-4; i ++){
    	for(int j = 3; j < SIZE; j ++){
    		cnt += (tekshirdiag3(i, j)?1:0);
		}
	}
	
	printf("Natija=%d\n",cnt);
	
	cnt = 0;
    for(int i = 3; i < SIZE; i ++){
    	for(int j = 3; j < SIZE; j ++){
    		cnt += (tekshirdiag4(i, j)?1:0);
		}
	}
	
	printf("Natija=%d\n",cnt);
	
	*/
    
  
  return 0;
}
