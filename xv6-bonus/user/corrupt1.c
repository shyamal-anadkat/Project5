//corrupt1
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"


int ppid;
#define assert(x) if (x) {} else { \
   printf(1, "%s: %d ", __FILE__, __LINE__); \
   printf(1, "assert failed (%s)\n", # x); \
   printf(1, "TEST FAILED\n"); \
   kill(ppid); \
   exit(); \
}

int
main(int argc, char *argv[])
{
   ppid = getpid();
   int fd, r;
   char buf[BSIZE];

   fd = open("out", O_RDONLY | O_CREATE);
   assert(fd >= 0);

   r = read(fd, buf, BSIZE);
   assert(r == 0);

   printf(1, "TEST PASSED\n");

   exit();
}