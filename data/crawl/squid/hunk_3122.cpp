 #include <arpa/inet.h>
 #endif
 
-#ifdef INET6
-#error "INET6 defined but has been deprecated! Try running bootstrap and configure again."
-#endif
-
-#if !USE_IPV6
-//  So there are some places where I will drop to using Macros too.
-//  At least I can restrict them to this file so they don't corrupt the app with C code.
-#  define sin6_addr	sin_addr
-#  define sin6_port	sin_port
-#  define sin6_family	sin_family
-#undef s6_addr
-#  define s6_addr	s_addr
-#endif
-
 /* Debugging only. Dump the address content when a fatal assert is encountered. */
-#if USE_IPV6
 #define IASSERT(a,b)  \
 	if(!(b)){	printf("assert \"%s\" at line %d\n", a, __LINE__); \
 		printf("Ip::Address invalid? with IsIPv4()=%c, IsIPv6()=%c\n",(IsIPv4()?'T':'F'),(IsIPv6()?'T':'F')); \
