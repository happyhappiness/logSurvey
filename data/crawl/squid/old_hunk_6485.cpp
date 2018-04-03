        close(i); close(i-1);
	i++;
#endif
	fprintf (fopen("conftestval", "w"), "%d\n", i);
	exit(0);
}

EOF
if { (eval echo configure:3835: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest && (./conftest; exit) 2>/dev/null
then
  SQUID_MAXFD=`cat conftestval`
else
