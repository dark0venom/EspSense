
#include <ctype.h>
#include <sys/types.h>
#include <errno.h>

#define ETHER_ADDR_LEN 6

int ether_aton_r(u_char *dest, size_t len, const char *str);

