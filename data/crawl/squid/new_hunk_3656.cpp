{
    char *p = string, c;
    while ((c = *p)) {
	*p = xtolower(c);
	p++;
    }
}

void
helperfail(const char *reason)
{
#if FAIL_DEBUG
    fail_debug_enabled = 1;
#endif
    SEND2("BH %s", reason);
}

/*
 * options:
 * -d enable debugging.
 * -v enable verbose Negotiate packet debugging.
 */
char *my_program_name = NULL;

void
usage()
{
    fprintf(stderr,
	"Usage: %s [-d] [-v] [-h]\n"
	" -d  enable debugging.\n"
	" -v  enable verbose Negotiate packet debugging.\n"
	" -h  this message\n\n",
	my_program_name);
}


