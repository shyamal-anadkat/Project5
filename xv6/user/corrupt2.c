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
   int i, j;

   fd = open("out", O_RDONLY);
   //assert(fd >= 0);

   for (i = 0; i < NDIRECT; i++) {
      r = read(fd, buf, BSIZE);
      assert(r == BSIZE);
      for (j = 0; j < BSIZE; j++) {
         assert(buf[j] == 0);
      }
   }
   r = read(fd, buf, BSIZE);
   assert(r == -1);

   printf(1, "TEST PASSED\n");

   exit();
}
