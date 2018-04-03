    VAX*:ULTRIX*:*:*)
	echo vax-dec-ultrix${UNAME_RELEASE}
	exit 0 ;;
    mips:*:*:UMIPS | mips:*:*:RISCos)
	sed 's/^	//' << EOF >dummy.c
	int main (argc, argv) int argc; char **argv; {
	#if defined (host_mips) && defined (MIPSEB)
	#if defined (SYSTYPE_SYSV)
	  printf ("mips-mips-riscos%ssysv\n", argv[1]); exit (0);
