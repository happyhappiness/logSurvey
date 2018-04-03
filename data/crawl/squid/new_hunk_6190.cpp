#include <sys/types.h>
#endif
main() {
	FILE *fp = fopen("conftestval", "w");
	fprintf (fp, "%d\n", FD_SETSIZE);
	exit(0);
}
],
