#else
#define IASSERT(a,b)  \
	if(!(b)){	printf("assert \"%s\" at line %d\n", a, __LINE__); \
		printf("Ip::Address invalid? with IsIPv4()=%c, IsIPv6()=%c\n",(IsIPv4()?'T':'F'),(IsIPv6()?'T':'F')); \
		printf("ADDRESS: %x\n", (unsigned int)m_SocketAddr.sin_addr.s_addr); \
		assert(b); \
	}
#endif

Ip::Address::Address()
{
    SetEmpty();
}

Ip::Address::~Address()
{
    memset(this,0,sizeof(Ip::Address));
}

int
Ip::Address::GetCIDR() const
{
    uint8_t shift,byte;
    uint8_t bit,caught;
