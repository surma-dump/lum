#include <stdio.h>

int main(int argc, char **argv) {
	short magic = strtol(argv[2], NULL, 16) ;
	short sread ;
	long count = 0;
	FILE *f ;

	printf("[**] Magic Number: %x\n", magic&0xFFFF) ;
	f = fopen(argv[1],"r") ;
	if(!f) {
		printf("[!!] Could not open file\n") ;
		return 1 ;
	}

	while(fread(&sread, 2, 1, f) >= 1) {
		if(sread == magic)
			printf("[!!] HIT: %ld\n", count) ;
		count++ ;
		fseek(f, -1, SEEK_CUR) ;
	}
}
