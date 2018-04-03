/* Debugging only. Dump the address content when a fatal assert is encountered. */
#define IASSERT(a,b)  \
	if(!(b)){	printf("assert \"%s\" at line %d\n", a, __LINE__); \
		printf("Ip::Address invalid? with isIPv4()=%c, isIPv6()=%c\n",(isIPv4()?'T':'F'),(isIPv6()?'T':'F')); \
		printf("ADDRESS:"); \
		for(unsigned int i = 0; i < sizeof(mSocketAddr_.sin6_addr); ++i) { \
			printf(" %x", mSocketAddr_.sin6_addr.s6_addr[i]); \
		} printf("\n"); assert(b); \
	}

int
Ip::Address::cidr() const
{
    uint8_t shift,byte;
    uint8_t bit,caught;
    int len = 0;
    const uint8_t *ptr= mSocketAddr_.sin6_addr.s6_addr;

    /* Let's scan all the bits from Most Significant to Least */
    /* Until we find an "0" bit. Then, we return */
