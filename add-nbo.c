#include <stdio.h>                                                                  
#include <stdint.h>                                                                 
#include <netinet/in.h>

int main(int argc, char* argv[]){                                                             
    FILE* fileA;                                                                         
    FILE* fileB;                                                                    
	
	//open file in binary format	
	fileA = fopen(argv[1], "rb");                                                        
    fileB = fopen(argv[2], "rb");                                                           
	// read fileA, fileB to uint32_t	
    uint32_t a, b;  
    fread(&a, sizeof(a), 1, fileA);                                                     
    fread(&b, sizeof(b), 1, fileB);                                                         
	//network to host
    a = ntohl(a);                                                                       
	b = ntohl(b);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a,a,b,b,a+b,a+b);                                                                                                          
    fclose(fileA);                                                                      
	fclose(fileB);                                                                                
    return 0;                                                                           
}    
