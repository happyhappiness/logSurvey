static void
usage(char *program)
{
    fprintf(stderr,"Usage: %s [-c] [-d] [-h]\n"
	    	" -c      use case insensitive compare\n"
	    	" -d      enable debugging\n"
		" -h      this message\n",
		program);
