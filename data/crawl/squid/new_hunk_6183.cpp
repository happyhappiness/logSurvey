#include <sys/types.h>
#endif
main() {
	FILE *fp = fopen("conftestval", "w");
	fprintf (fp, "%d\n", FD_SETSIZE);
	exit(0);
}

EOF
if { (eval echo configure:4222: \"$ac_link\") 1>&5; (eval $ac_link) 2>&5; } && test -s conftest && (./conftest; exit) 2>/dev/null
then
  DEFAULT_FD_SETSIZE=`cat conftestval`
else
