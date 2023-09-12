#include <stdio.h>
#include <stdlib.h>

void usage(char *progname)
{
	printf("Usage:\n%s <value> <bitpos>\n", progname);
}

void print_bits(unsigned long long val)
{
	int i, printed = 0;

	printf("Value = 0x%llx\n\n", val);
	for (i=0; i < 64; i++) {
		if ((1ULL<<i) & val) {
			if (!i || i%10)
				printf("%2.2d, ", i);
			else 
				printf("%2.2d, ", i);
			printed++;
			if (!(printed%10))
				printf ("\n");
		}
	}
	printf ("\n\n");
}

int main(int argc, char **argv)
{
	unsigned long long val;
	char *endptr;
	int count;

	printf ("sizeof unsigned long %ld uLL = %ld\n", sizeof(unsigned long), sizeof(unsigned long long));
	if (argc < 2) {
		usage(argv[0]);
		exit (0);
	}
	
	count = 1;
	while (count < argc) {
		val = strtoull(argv[count], &endptr, 16);
		if (val)
			print_bits(val);
		count++;
	}
}
