extern char *sys_siglist[]; puts(*sys_siglist);
; return 0; }
EOF
if eval $ac_link; then
  rm -rf conftest*
  	    ac_cv_check_symbol_sys_siglist=yes
else
