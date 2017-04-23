#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void dump_hex(void *p_data, size_t byte_len);
void Usage(char *prog);

typedef struct {
	char char_val;
	int32_t int_val;
	float float_val;
	double double_val;
} Ex2Struct;

/* print in hex the values of the bytes allocated to some variable */
int main(int argc, char *argv[])
{
	char char_val;
	int32_t int_val;
	float float_val;
	double double_val;

	if(argc != 5)
		Usage(argv[0]);
	
	sscanf(argv[1], "%c", (char *) &char_val);
	sscanf(argv[2], "%d", (int32_t *) &int_val);
	sscanf(argv[3], "%f", (float *) &float_val);
	sscanf(argv[4], "%lf", (double *) &double_val);

	Ex2Struct struct_val = {'0', 1, 1.0, 1.0};

	dump_hex(&char_val, sizeof(char));
	dump_hex(&int_val, sizeof(int32_t));
	dump_hex(&float_val , sizeof(float));
	dump_hex(&double_val , sizeof(double));
	dump_hex(&struct_val , sizeof(struct_val));

	return EXIT_SUCCESS;
}
void Usage(char *prog)
{
	fprintf(stderr,
			"Usage:  %s <char> <int> <float> <double>",
			prog);
	exit(EXIT_FAILURE);
}
void dump_hex(void *p_data, size_t byte_len)
{
	printf("\nThe %lu byte(s) starting at %p are:", byte_len, p_data);

	int i;
	char *mod = p_data;
	for(i = 0; i < byte_len; i++)
		{
			uint8_t jeez = *mod;
			printf(" %02x", jeez);
			
			mod += 1;
		}
	printf("\n");

}
