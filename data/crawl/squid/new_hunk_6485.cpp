        close(i); close(i-1);
	i++;
#endif
#endif /* __CYGWIN32__ */
	fprintf (fopen("conftestval", "w"), "%d\n", i);
	exit(0);
}

EOF
if { (eval echo configure:3856: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest && (./conftest; exit) 2>/dev/null
then
  SQUID_MAXFD=`cat conftestval`
else
