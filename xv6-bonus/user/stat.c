#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"


void print_filestat(char *file) {

int fd; 
struct stat st;
//int fstat(int fd, struct stat*);

if ((fd = open (file, 0)) < 0) {
	printf(2, "Error opening file : %s\n", file);
	return;
}

// printf(1, "Before calling fstat\n");
// printf(1,"type: %d\n", st.type);
// printf(1,"dev: %d\n", st.dev);
// printf(1,"ino: %d\n", st.ino);
// printf(1,"checksum: %d\n", st.nlink);
// printf(1,"size: %d\n", st.size);
// printf(1,"checksum: %x\n\n", st.checksum);

if( (fstat(fd, &st)) < 0) {
	printf(2, "Error stat %s\n", file);
	close(fd);
	return;
}

printf(1, "After calling fstat\n");
printf(1,"type: %d\n", st.type);
printf(1,"dev: %d\n", st.dev);
printf(1,"ino: %d\n", st.ino);
printf(1,"checksum: %d\n", st.nlink);
printf(1,"size: %d\n", st.size);
printf(1,"checksum: %x\n", st.checksum);

}

int main (int argc, char *argv[]) {

if(argc < 2) {
	printf(1, "file name needed. Exiting gracefully ...");
	exit();
}
	
	print_filestat(argv[1]);
	exit();

}