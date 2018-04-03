 extern char *sys_siglist[]; puts(*sys_siglist);
 ; return 0; }
 EOF
-if eval $ac_link; then
+if { (eval echo configure:1523: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; }; then
   rm -rf conftest*
   	    ac_cv_check_symbol_sys_siglist=yes
 else
