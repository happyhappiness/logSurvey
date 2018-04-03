 			printf(" %x", m_SocketAddr.sin6_addr.s6_addr[i]); \
 		} printf("\n"); assert(b); \
 	}
-#else
-#define IASSERT(a,b)  \
-	if(!(b)){	printf("assert \"%s\" at line %d\n", a, __LINE__); \
-		printf("Ip::Address invalid? with IsIPv4()=%c, IsIPv6()=%c\n",(IsIPv4()?'T':'F'),(IsIPv6()?'T':'F')); \
-		printf("ADDRESS: %x\n", (unsigned int)m_SocketAddr.sin_addr.s_addr); \
-		assert(b); \
-	}
-#endif
 
 Ip::Address::Address()
 {
