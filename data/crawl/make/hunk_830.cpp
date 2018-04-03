 $ if f$search("make.opt").nes."" then $ del make.opt;*
 $ exit
 $!
+$!------------------------------------------------------------------------------
+$!
+$! Check if this is a define relating to the properties of the C/C++
+$! compiler
+$!
+$CHECK_CC_QUAL:
+$ open/write tmpc 'tc 
+$ ccqual = "/warn=(disable=questcompare)"
+$ write tmpc "#include <stdio.h>"
+$ write tmpc "unsigned int i = 1;"
+$ write tmpc "int main(){"
+$ write tmpc "if (i < 0){printf(""Mission impossible\n"");}}"  
+$ close tmpc
+$ gosub cc_qual_check
+$ return
+$!
+$!------------------------------------------------------------------------------
+$!
+$! Check for properties of C/C++ compiler
+$!
+$CC_QUAL_CHECK:
+$ cc_qual = false
+$ set message/nofac/noident/nosever/notext
+$ cc 'ccqual' 'tmpnam'
+$ if $status then cc_qual = true
+$ set message/fac/ident/sever/text
+$ delete/nolog 'tmpnam'.*;*
+$ if cc_qual then ccopt = ccopt + ccqual 
+$ return
+$!------------------------------------------------------------------------------
+$!
 $ compileit : subroutine
 $ ploc = f$locate("]",p1)
 $ filnam = p1
 $ if ploc .lt. f$length(p1) then filnam=f$extract(ploc+1,100,p1)
 $ write optf "''filnam'"
-$ cc'ccopt'/include=([],[.glob])/define=("allocated_variable_expand_for_file=alloc_var_expand_for_file","unlink=remove","HAVE_CONFIG_H","VMS") 'p1'
+$ cc'ccopt'/include=([],[.glob]) - 
+  /define=("allocated_variable_expand_for_file=alloc_var_expand_for_file","unlink=remove","HAVE_CONFIG_H","VMS") - 
+  'p1'
 $ exit
 $ endsubroutine : compileit
