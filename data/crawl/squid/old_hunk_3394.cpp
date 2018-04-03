#if USE_IPV6
#define IASSERT(a,b)  \
	if(!(b)){	printf("assert \"%s\" at line %d\n", a, __LINE__); \
		printf("IpAddress invalid? with IsIPv4()=%c, IsIPv6()=%c\n",(IsIPv4()?'T':'F'),(IsIPv6()?'T':'F')); \
		printf("ADDRESS:"); \
		for(unsigned int i = 0; i < sizeof(m_SocketAddr.sin6_addr); i++) { \
			printf(" %x", m_SocketAddr.sin6_addr.s6_addr[i]); \