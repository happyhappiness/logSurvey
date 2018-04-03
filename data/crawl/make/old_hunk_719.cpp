$! compiler
$!
$CHECK_CC_QUAL:
$ open/write tmpc 'tc 
$ ccqual = "/warn=(disable=questcompare)"
$ write tmpc "#include <stdio.h>"
$ write tmpc "unsigned int i = 1;"
$ write tmpc "int main(){"
$ write tmpc "if (i < 0){printf(""Mission impossible\n"");}}"  
$ close tmpc
$ gosub cc_qual_check
$ return
