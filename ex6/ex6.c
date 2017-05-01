#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* very messy.  lots of practice with mmap, fopen, fread, and the like.
 * warning, no error checking on syscalls
 */
static void method4(FILE *fp, size_t size);
static void method3(int fd, size_t size);
static void usage(char *prog);
static void method1(FILE *fp, size_t len);
static void method2(FILE *fp, size_t len);

int main(int argc, char *argv[])
{
	if(argc != 2)
		usage(argv[0]);

	char *file_name = argv[1];

	FILE *fp;
	long int len;
	
	fp = fopen(file_name, "r");
	if(fp == NULL)
		usage(argv[0]);

	/* move pointer to end of file to get file size */
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);

	method1(fp, (size_t)len);

	method2(fp, (size_t)len);


	/* another way, lower level */

	struct stat stat;
	int fd;

	fd = open(argv[1], O_RDONLY, 0);
	fstat(fd, &stat);
	method3(fd, stat.st_size);

	FILE *fp2 = fdopen(fd, "r");
	method4(fp2, stat.st_size);

	
	fclose(fp);
	fclose(fp2);
	close(fd);
	return EXIT_SUCCESS;
}

static void method4(FILE *fp, size_t size)
{
	char *buf = malloc(size + 1);
	memset(buf, 0, size + 1);
	
	fseek(fp, 0, SEEK_SET);

	size_t ind;
	for(ind = size; ind < ~0; ind--)
		{
			fseek(fp, ind, SEEK_SET);
			fread(buf, sizeof(char), 1, fp);
			printf("%s", buf);			
		}
	printf("\n");

	free(buf);
}

static void method3(int fd, size_t size)
{
	char *bufp;

	bufp = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
	write(1, bufp, size);
	return;
}

/* copies file to output using mmap */
static void method2(FILE *fp, size_t len)
{
	char *buf;
	buf = mmap(NULL, len, PROT_READ, MAP_PRIVATE, fileno(fp), 0);
	printf("%s \n\n", buf);
	munmap(buf, len);
}

/* copies file to a buffer string using fread before printing */
static void method1(FILE *fp, size_t len)
{
	fseek(fp, 0, SEEK_SET);
	/* the buffer string that will hold the file stuff */
	char *buf = (char *)malloc(sizeof(char) * len + 1);
	if(buf == NULL)
		exit(EXIT_FAILURE);

	memset(buf, 0, (size_t)len + 1);
	/* getting an error in valgrind because of not setting the last element to \0.
	 *   will think about that in the future; here i took the easy route and malloced
	 *   an extra byte in malloc before memset-ing all of buf to \0 and copying over.
	 */
	fread(buf, (size_t)len, 1, fp);


	printf("%s \n\n", buf);
	free(buf);

}

static void usage(char *prog)
{
	fprintf(stderr,
			"Usage: %s requires a file name\n",
			prog);
	exit(EXIT_FAILURE);
}
