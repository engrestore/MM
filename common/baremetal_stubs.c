/**
* @file baremetal_stubs.c
* @brief Minimal newlib stubs for bare-metal STM32
* @note why we need it? Newlib expects these functions to be defined
*       for basic operations like memory allocation, file I/O, etc.
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>

void _exit(int status) { while (1) {} }
int _kill(int pid, int sig) { return -1; }
int _getpid(void) { return 1; }
caddr_t _sbrk(int incr) { return (caddr_t)-1; }
int _write(int file, char *ptr, int len) { return -1; }
int _close(int file) { return -1; }
int _fstat(int file, struct stat *st) { st->st_mode = S_IFCHR; return 0; }
int _isatty(int file) { return 1; }
int _lseek(int file, int ptr, int dir) { return 0; }
int _read(int file, char *ptr, int len) { return 0; }
