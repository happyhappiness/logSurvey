#include <sys/types.h>
#endif
main() {
	fprintf (fopen("conftestval", "w"), "%d\n", FD_SETSIZE);
	exit(0);
}
],
