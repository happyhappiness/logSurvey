#include <sys/types.h>
#endif
main() {
	fprintf (fopen("conftestval", "w"), "%d\n", FD_SETSIZE);
	exit(0);
}

EOF
if { (eval echo configure:4221: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest && (./conftest; exit) 2>/dev/null
then
  DEFAULT_FD_SETSIZE=`cat conftestval`
else
