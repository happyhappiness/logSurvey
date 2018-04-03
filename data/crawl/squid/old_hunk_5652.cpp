	echo clipper-intergraph-clix${UNAME_RELEASE}
	exit 0 ;;
    mips:*:*:UMIPS | mips:*:*:RISCos)
	sed 's/^	//' << EOF >$dummy.c
#ifdef __cplusplus
#include <stdio.h>  /* for printf() prototype */
