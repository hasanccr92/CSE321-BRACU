#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
void main(int argc, char *argv[]) {  	
	
	char data[1000];  				
	FILE *fptr;		
	fptr = fopen(argv[1], "w"); 
	
	if (fptr == NULL) { 
		printf("File parsing error. Please try again.");
		exit(1); 		
		} 	
			 		
	printf("Input strings in the file:\n"); 		 		
	while (strcmp(data, "-1\n") != 0){
	 			
		fgets(data, sizeof(data), stdin); 			 			
	if (strcmp(data, "-1\n") != 0) 
					
	fprintf(fptr, "%s", data); 
		} 		 				
	fclose(fptr);
 	
 }
