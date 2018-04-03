	  cat >$dummy.c <<EOF
#include <features.h>
#ifdef __cplusplus
	int main (int argc, char *argv[]) {
#else
	int main (argc, argv) int argc; char *argv[]; {
