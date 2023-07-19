#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>


int main(int argc, char* argv[]) {
	FILE *f1 = fopen("thousand.bin", "r");
	FILE *f2 = fopen("five-hundred.bin", "r");
	
	if(f1 == NULL | f2 == NULL) {
		printf("File Not Found\n");
		return 0;
	}

	uint32_t v1;
	uint32_t v2;

	fread(&v1, sizeof(v1), 1, f1);
	fread(&v2, sizeof(v2), 1, f2);
	
	fclose(f1);
	fclose(f2);

	v1 = ntohl(v1);
	v2 = ntohl(v2);

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", v1, v1, v2, v2, v1+v2, v1+v2);
	
	return 0;
}
