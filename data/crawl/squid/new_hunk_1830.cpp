        fprintf(stdout, "Token: %s\n", Token ? Token : "NULL");
    }

    return 0;
}

#else
#include <stdlib.h>
int
main(int argc, char *argv[])
{
    return -1;
}

#endif /* HAVE_GSSAPI */
