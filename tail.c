/*
 * tail.c
 * William Whelan
 * wwhelan@ucsc.edu
 * CMPS_111
 * 10/6/2018
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int fileDes;
	char *buffer;
	int bytesRead;
	int bytesWritten;
	int offset;
	char *error = "there was an error\n";
	if(argc > 1){
		for (int i = 1; i < argc; ++i){
			fileDes = open(argv[i], O_RDONLY);
			if (fileDes < 0){
				write(1, error, 20);
				return(-1);
			}
			buffer = malloc(8192 * sizeof(char));
			
			offset = lseek(fileDes, 0, SEEK_END);
			
			bytesRead = read(fileDes, buffer, 8192);
			
			bytesWritten = write(0, buffer, 8192);
			
			close(fileDes);	

		}
	}else{
		fileDes = 0;
		if (fileDes < 0){
			write(1, error, 20);
			return(-1);
		}
		buffer = malloc(8192 * sizeof(char));
	
		offset = lseek(fileDes, -10, SEEK_END);
		
		bytesRead = read(fileDes, buffer, 8192);
		
		bytesWritten = write(0, buffer, 8192);
		
		close(fileDes);	
	}
		
	return(0);
}
