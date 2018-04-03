 #else
 #define IASSERT(a,b)  \
 	if(!(b)){	printf("assert \"%s\" at line %d\n", a, __LINE__); \
-		printf("IPAddress invalid? with IsIPv4()=%c, IsIPv6()=%c\n",(IsIPv4()?'T':'F'),(IsIPv6()?'T':'F')); \
+		printf("IpAddress invalid? with IsIPv4()=%c, IsIPv6()=%c\n",(IsIPv4()?'T':'F'),(IsIPv6()?'T':'F')); \
 		printf("ADDRESS: %x\n", (unsigned int)m_SocketAddr.sin_addr.s_addr); \
 		assert(b); \
 	}
 #endif
 
-IPAddress::IPAddress()
+IpAddress::IPAddress()
 {
     SetEmpty();
 }
 
-IPAddress::~IPAddress()
+IpAddress::~IPAddress()
 {
-    memset(this,0,sizeof(IPAddress));
+    memset(this,0,sizeof(IpAddress));
 }
 
 int
-IPAddress::GetCIDR() const
+IpAddress::GetCIDR() const
 {
     uint8_t shift,byte;
     uint8_t bit,caught;
