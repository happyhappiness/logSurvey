 	echo clipper-intergraph-clix${UNAME_RELEASE}
 	exit 0 ;;
     mips:*:*:UMIPS | mips:*:*:RISCos)
+	eval $set_cc_for_build
 	sed 's/^	//' << EOF >$dummy.c
 #ifdef __cplusplus
 #include <stdio.h>  /* for printf() prototype */
