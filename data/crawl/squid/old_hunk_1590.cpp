    return 0;
}

#else
#include <stdio.h>
int
main(int argc, char *argv[])
{
    fprintf(stderr, "%s: ICMP support not compiled in.\n", argv[0]);
    return 1;
}
