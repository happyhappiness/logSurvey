 /* Debugging only. Dump the address content when a fatal assert is encountered. */
 #if USE_IPV6
 #define IASSERT(a,b)  \
-	if(!b){	printf("assert \"%s\" at line %d\n", a, __LINE__); \
+	if(!(b)){	printf("assert \"%s\" at line %d\n", a, __LINE__); \
 		printf("IPAddress invalid? with IsIPv4()=%c, IsIPv6()=%c\n",(IsIPv4()?'T':'F'),(IsIPv6()?'T':'F')); \
 		printf("ADDRESS:"); \
 		for(unsigned int i = 0; i < sizeof(m_SocketAddr.sin6_addr); i++) { \
