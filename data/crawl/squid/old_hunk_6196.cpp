#include <arpa/inet.h>
main ()
{
	struct in_addr in;
	in.s_addr = inet_addr("1.2.3.4");
        fprintf (fopen("conftestval", "w"), "%s\n", inet_ntoa(in));
	exit(0);
}
],