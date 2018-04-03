+/*
+ * $Id: IPAddress.cc,v 1.1 2007/12/14 04:29:22 amosjeffries Exp $
+ *
+ * DEBUG: section 14   IP Storage and Handling
+ * AUTHOR: Amos Jeffries
+ *
+ * SQUID Internet Object Cache  http://squid.nlanr.net/Squid/
+ * ----------------------------------------------------------
+ *
+ *  Squid is the result of efforts by numerous individuals from the
+ *  Internet community.  Development is led by Duane Wessels of the
+ *  National Laboratory for Applied Network Research and funded by the
+ *  National Science Foundation.  Squid is Copyrighted (C) 1998 by
+ *  the Regents of the University of California.  Please see the
+ *  COPYRIGHT file for full details.  Squid incorporates software
+ *  developed and/or copyrighted by other sources.  Please see the
+ *  CREDITS file for full details.
+ *
+ *  This IPAddress code is copyright (C) 2007 by Treehouse Networks Ltd
+ *  of New Zealand. It is published and Lisenced as an extension of
+ *  squid under the same conditions as the main squid application.
+ *
+ *  This program is free software; you can redistribute it and/or modify
+ *  it under the terms of the GNU General Public License as published by
+ *  the Free Software Foundation; either version 2 of the License, or
+ *  (at your option) any later version.
+ *  
+ *  This program is distributed in the hope that it will be useful,
+ *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ *  GNU General Public License for more details.
+ *  
+ *  You should have received a copy of the GNU General Public License
+ *  along with this program; if not, write to the Free Software
+ *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
+ *
+ */
+
+#include "config.h"
+
+#include "IPAddress.h"
+
+#if HAVE_ASSERT_H
+#include <assert.h>
+#endif
+#if HAVE_STDLIB_H
+#include <stdlib.h>
+#endif
+#if HAVE_STRING_H
+#include <string.h>
+#endif
+#if HAVE_ARPA_INET_H
+#include <arpa/inet.h>  /* inet_ntoa() */
+#endif
+
+#include "util.h"
+
+#ifdef INET6
+#error "INET6 defined but has been deprecated! Try running bootstrap and configure again."
+#endif
+
+/* We want to use the debug routines when running as module of squid. */
+/* otherwise fallback to printf if those are not available. */
+#ifndef SQUID_DEBUG
+#    define debugs(a,b,c)        //  drop.
+#else
+#warning "IPAddress built with Debugs!!"
+#    include "../src/Debug.h"
+#endif
+
+#if !USE_IPV6
+//  So there are some places where I will drop to using Macros too.
+//  At least I can restrict them to this file so they don't corrupt the app with C code.
+#  define sin6_addr	sin_addr
+#  define sin6_port	sin_port
+#  define sin6_family	sin_family
+#undef s6_addr
+#  define s6_addr	s_addr
+#endif
+
+static const unsigned int STRLEN_IP4A = 16;              // aaa.bbb.ccc.ddd\0
+static const unsigned int STRLEN_IP4R = 28;              // ddd.ccc.bbb.aaa.in-addr.arpa.\0
+static const unsigned int STRLEN_IP4S = 21;              // ddd.ccc.bbb.aaa:ppppp\0
+static const unsigned int MAX_IP4_STRLEN = STRLEN_IP4R;
+static const unsigned int STRLEN_IP6A = 42;           // [ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff]/0
+static const unsigned int STRLEN_IP6R = 75;           // f.f.f.f f.f.f.f f.f.f.f f.f.f.f f.f.f.f f.f.f.f f.f.f.f f.f.f.f ipv6.arpa./0
+static const unsigned int STRLEN_IP6S = 48;           // [ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff]:00000/0
+static const unsigned int MAX_IP6_STRLEN = STRLEN_IP6R;
+
+
+/* Debugging only. Dump the address content when a fatal assert is encountered. */
+#if USE_IPV6
+#define IASSERT(a,b)  \
+	if(!b){	printf("assert \"%s\" at line %d\n", a, __LINE__); \
+		printf("IPAddress invalid? with IsIPv4()=%c, IsIPv6()=%c\n",(IsIPv4()?'T':'F'),(IsIPv6()?'T':'F')); \
+		printf("ADDRESS:"); \
+		for(unsigned int i = 0; i < sizeof(m_SocketAddr.sin6_addr); i++) { \
+			printf(" %x", m_SocketAddr.sin6_addr.s6_addr[i]); \
+		} printf("\n"); assert(b); \
+	}
+#else
+#define IASSERT(a,b)  \
+	if(!b){	printf("assert \"%s\" at line %d\n", a, __LINE__); \
+		printf("IPAddress invalid? with IsIPv4()=%c, IsIPv6()=%c\n",(IsIPv4()?'T':'F'),(IsIPv6()?'T':'F')); \
+		printf("ADDRESS: %x\n", (unsigned int)m_SocketAddr.sin_addr.s_addr); \
+		assert(b); \
+	}
+#endif
+
+IPAddress::IPAddress()
+{
+    SetEmpty();
+}
+
+IPAddress::~IPAddress()
+{
+    memset(this,0,sizeof(IPAddress));
+}
+
+int
+IPAddress::GetCIDR()
+{
+    uint8_t shift,byte;
+    uint8_t bit,caught;
+    int len = 0;
+#if USE_IPV6
+    uint8_t *ptr= m_SocketAddr.sin6_addr.s6_addr;
+#else
+    uint8_t *ptr= (uint8_t *)&m_SocketAddr.sin_addr.s_addr;
+#endif
+
+    /* Let's scan all the bits from Most Significant to Least */
+    /* Until we find an "0" bit. Then, we return */
+    shift=0;
+
+#if USE_IPV6
+    /* return IPv4 CIDR for any Mapped address */
+    /* Thus only check the mapped bit */
+
+    if( !IsIPv6() ) {
+        shift = 12;
+    }
+
+#endif
+
+    for (;shift<sizeof(m_SocketAddr.sin6_addr) ;shift++) {
+        byte= *(ptr+shift);
+
+        if (byte == 0xFF) {
+            len += 8;
+            continue ;  /* A short-cut */
+        }
+
+        for (caught = 0 , bit= 7 ; !caught && (bit <= 7); bit--) {
+            caught = ((byte & 0x80) == 0x00);  /* Found a '0' at 'bit' ? */
+
+            if (!caught)
+                len++;
+
+            byte <<= 1;
+        }
+
+        if (caught)
+            break; /* We have found the most significant "0" bit.  */
+    }
+
+    return len;
+}
+
+const int IPAddress::ApplyMask(IPAddress const &mask_addr)
+{
+    uint32_t *p1 = (uint32_t*)(&m_SocketAddr.sin6_addr);
+    uint32_t const *p2 = (uint32_t const *)(&mask_addr.m_SocketAddr.sin6_addr);
+    unsigned int blen = sizeof(m_SocketAddr.sin6_addr)/sizeof(uint32_t);
+    unsigned int changes = 0;
+
+    for (unsigned int i = 0; i < blen; i++) {
+        if((p1[i] & p2[i]) != p1[i])
+            changes++;
+
+        p1[i] &= p2[i];
+    }
+
+    /* we have found a situation where mask forms or destroys a IPv4 map. */
+    check4Mapped();
+
+    return changes;
+}
+
+bool IPAddress::ApplyMask(const unsigned int cidr, int mtype)
+{
+    uint8_t clearbits = 0;
+    uint8_t* p = NULL;
+
+#if !USE_IPV6
+    IASSERT("mtype != AF_INET6", mtype != AF_INET6); /* using IPv6 in IPv4 is invalid. */
+
+    if(mtype == AF_UNSPEC)
+        mtype = AF_INET;
+
+#else
+    if(mtype == AF_UNSPEC)
+        mtype = AF_INET6;
+
+#endif
+
+    // validation and short-cuts.
+    if (cidr > 128)
+        return false;
+
+    if (cidr > 32 && mtype == AF_INET)
+        return false;
+
+    clearbits = (uint8_t)( (mtype==AF_INET6?128:32) -cidr);
+
+    // short-cut
+    if(clearbits == 0)
+        return true;
+
+#if USE_IPV6
+
+    p = (uint8_t*)(&m_SocketAddr.sin6_addr) + 15;
+
+#else
+
+    p = (uint8_t*)(&m_SocketAddr.sin_addr) + 3;
+
+#endif
+
+    for (; clearbits>0 && p >= (uint8_t*)&m_SocketAddr.sin6_addr ; p-- ) {
+        if(clearbits < 8) {
+            *p &= ((0xFF << clearbits) & 0xFF);
+            clearbits = 0;
+        } else {
+            *p &= 0x00;
+            clearbits -= 8;
+        }
+    }
+
+    return true;
+}
+
+bool IPAddress::IsSockAddr() const
+{
+    return (m_SocketAddr.sin6_port != 0);
+}
+
+bool IPAddress::IsIPv4() const
+{
+#if USE_IPV6
+
+    return IsAnyAddr() || IsNoAddr() ||
+#if IPV6_SPECIAL_LOCALHOST
+           IsLocalhost() ||
+#endif
+           ( m_SocketAddr.sin6_addr.s6_addr32[0] == htonl(0x00000000) &&
+             m_SocketAddr.sin6_addr.s6_addr32[1] == htonl(0x00000000) &&
+             m_SocketAddr.sin6_addr.s6_addr32[2] == htonl(0x0000FFFF)
+           );
+
+#else
+    return true; // enforce IPv4 in IPv4-only mode.
+#endif
+}
+
+bool IPAddress::IsIPv6() const
+{
+#if USE_IPV6
+
+    return IsAnyAddr() || IsNoAddr() ||
+#if IPV6_SPECIAL_LOCALHOST
+           IsLocalhost() ||
+#endif
+           !( m_SocketAddr.sin6_addr.s6_addr32[0] == htonl(0x00000000) &&
+              m_SocketAddr.sin6_addr.s6_addr32[1] == htonl(0x00000000) &&
+              m_SocketAddr.sin6_addr.s6_addr32[2] == htonl(0x0000FFFF)
+           );
+#else
+    return false; // enforce IPv4 in IPv4-only mode.
+#endif
+}
+
+bool IPAddress::IsAnyAddr() const
+{
+#if USE_IPV6
+    return     m_SocketAddr.sin6_addr.s6_addr32[0] == 0
+               && m_SocketAddr.sin6_addr.s6_addr32[1] == 0
+               && m_SocketAddr.sin6_addr.s6_addr32[2] == 0
+               && m_SocketAddr.sin6_addr.s6_addr32[3] == 0
+               ;
+#else
+
+    return (INADDR_ANY == m_SocketAddr.sin_addr.s_addr);
+#endif
+}
+
+/// NOTE: Does NOT clear the Port stored. Ony the Address and Type.
+void IPAddress::SetAnyAddr()
+{
+#if USE_IPV6
+    memset(&m_SocketAddr.sin6_addr, 0, sizeof(struct in6_addr) );
+#else
+    memset(&m_SocketAddr.sin_addr, 0, sizeof(struct in_addr) );
+#endif
+}
+
+/// NOTE: completely empties the IPAddress structure. Address, Port, Type, everything.
+void IPAddress::SetEmpty()
+{
+    memset(&m_SocketAddr, 0, sizeof(m_SocketAddr) );
+}
+
+bool IPAddress::SetIPv4()
+{
+#if USE_IPV6
+
+#if !IPV6_SPECIAL_LOCALHOST
+    if( IsLocalhost() ) {
+        m_SocketAddr.sin6_addr.s6_addr32[2] = htonl(0xffff);
+        m_SocketAddr.sin6_addr.s6_addr32[3] = htonl(0x7F000001);
+        return true;
+    }
+#endif
+
+    if( IsAnyAddr() ) {
+        m_SocketAddr.sin6_addr.s6_addr32[2] = htonl(0xffff);
+        return true;
+    }
+
+    if( IsIPv4())
+        return true;
+
+    // anything non-IPv4 and non-convertable is BAD.
+    return false;
+#else
+    return true; // Always IPv4 in IPv4-only builds.
+#endif
+}
+
+bool IPAddress::IsLocalhost() const
+{
+#if USE_IPV6
+    return        m_SocketAddr.sin6_addr.s6_addr32[0] == 0
+               && m_SocketAddr.sin6_addr.s6_addr32[1] == 0
+               && m_SocketAddr.sin6_addr.s6_addr32[2] == 0
+               && m_SocketAddr.sin6_addr.s6_addr32[3] == htonl(0x1)
+
+#if !IPV6_SPECIAL_LOCALHOST
+               || m_SocketAddr.sin6_addr.s6_addr32[0] == 0
+               && m_SocketAddr.sin6_addr.s6_addr32[1] == 0
+               && m_SocketAddr.sin6_addr.s6_addr32[2] == htonl(0xffff)
+               && m_SocketAddr.sin6_addr.s6_addr32[3] == htonl(0x7F000001)
+#endif
+               ;
+#else
+
+    return (htonl(0x7F000001) == m_SocketAddr.sin_addr.s_addr);
+#endif
+}
+
+void IPAddress::SetLocalhost()
+{
+#if USE_IPV6
+    SetAnyAddr();
+    m_SocketAddr.sin6_addr.s6_addr[15] = 0x1;
+    m_SocketAddr.sin6_family = AF_INET6;
+
+#else
+    m_SocketAddr.sin_addr.s_addr = htonl(0x7F000001);
+    m_SocketAddr.sin_family = AF_INET;
+#endif
+}
+
+bool IPAddress::IsNoAddr() const
+{
+    // IFF the address == 0xff..ff (all ones)
+#if USE_IPV6
+    return     m_SocketAddr.sin6_addr.s6_addr32[0] == 0xFFFFFFFF
+               && m_SocketAddr.sin6_addr.s6_addr32[1] == 0xFFFFFFFF
+               && m_SocketAddr.sin6_addr.s6_addr32[2] == 0xFFFFFFFF
+               && m_SocketAddr.sin6_addr.s6_addr32[3] == 0xFFFFFFFF
+               ;
+#else
+
+    return 0xFFFFFFFF == m_SocketAddr.sin_addr.s_addr;
+#endif
+}
+
+void IPAddress::SetNoAddr()
+{
+#if USE_IPV6
+    memset(&m_SocketAddr.sin6_addr, 0xFFFFFFFF, sizeof(struct in6_addr) );
+    m_SocketAddr.sin6_family = AF_INET6;
+#else
+    memset(&m_SocketAddr.sin_addr, 0xFFFFFFFF, sizeof(struct in_addr) );
+    m_SocketAddr.sin_family = AF_INET;
+#endif
+}
+
+#if USE_IPV6
+
+bool IPAddress::GetReverseString6(char buf[MAX_IPSTRLEN], const struct in6_addr &dat) const
+{
+    char *p = buf;
+    unsigned char const *r = dat.s6_addr;
+
+    /* RFC1886 says: */
+    /*     4321:0:1:2:3:4:567:89ab */
+    /*     must be sent */
+    /*     b.a.9.8.7.6.5.0.4.0.0.0.3.0.0.0.2.0.0.0.1.0.0.0.0.0.0.0.1.2.3.4.ip6.int. */
+
+    /* Work from the binary field. Anything else may have representation changes. */
+    /* The sin6_port and sin6_addr members shall be in network byte order. */
+
+    /* Compile Err: 'Too many arguments for format. */
+
+    for(int i = 15; i >= 0; i--, p+=4)
+    {
+        snprintf(p, 5, "%x.%x.", ((r[i])&0xf), (((r[i])>>4)&0xf) );
+    }
+
+    /* RFC3152 says: */
+    /*     ip6.int is now deprecated TLD, use ip6.arpa instead. */
+    snprintf(p,10,"ip6.arpa.");
+
+    return true;
+}
+
+#endif
+
+bool IPAddress::GetReverseString4(char buf[MAX_IPSTRLEN], const struct in_addr &dat) const
+{
+    unsigned int i = (unsigned int) ntohl(dat.s_addr);
+    snprintf(buf, 32, "%u.%u.%u.%u.in-addr.arpa.",
+             i & 255,
+             (i >> 8) & 255,
+             (i >> 16) & 255,
+             (i >> 24) & 255);
+    return true;
+}
+
+bool IPAddress::GetReverseString(char buf[MAX_IPSTRLEN], int show_type) const
+{
+
+    if(show_type == AF_UNSPEC) {
+#if USE_IPV6
+        show_type = IsIPv6() ? AF_INET6 : AF_INET ;
+#else
+        show_type = AF_INET;
+#endif
+    }
+
+    if (show_type == AF_INET && IsIPv4()) {
+#if USE_IPV6
+
+        return GetReverseString4(buf, *(struct in_addr*)&m_SocketAddr.sin6_addr.s6_addr32[3] );
+    } else if ( show_type == AF_INET6 && IsIPv6() ) {
+        return GetReverseString6(buf, m_SocketAddr.sin6_addr);
+#else
+        return GetReverseString4(buf, m_SocketAddr.sin_addr);
+#endif
+    }
+
+    debugs(14,0, "Unable to convert '" << NtoA(buf,MAX_IPSTRLEN) << "' to the rDNS type requested.");
+
+    buf[0] = '\0';
+
+    return false;
+}
+
+IPAddress& IPAddress::operator =(const IPAddress &s)
+{
+    memcpy(this, &s, sizeof(IPAddress));
+    return *this;
+};
+
+IPAddress::IPAddress(const char*s)
+{
+    SetEmpty();
+    operator=(s);
+}
+
+bool IPAddress::operator =(const char* s)
+{
+    return LookupHostIP(s, true);
+}
+
+bool IPAddress::GetHostByName(const char* s)
+{
+    return LookupHostIP(s, false);
+}
+
+bool IPAddress::LookupHostIP(const char *s, bool nodns)
+{
+    int err = 0;
+
+    short port = 0;
+
+    struct addrinfo *res = NULL;
+
+    struct addrinfo want;
+
+    memset(&want, 0, sizeof(struct addrinfo));
+    if(nodns) {
+        want.ai_flags = AI_NUMERICHOST; // prevent actual DNS lookups!
+    }
+#if !USE_IPV6
+    want.ai_family = AF_INET;
+#endif
+
+    if ( (err = xgetaddrinfo(s, NULL, &want, &res)) != 0) {
+        debugs(14,1, HERE << "Given Bad IP '" << s << "': " << xgai_strerror(err) );
+        /* free the memory xgetaddrinfo() dynamically allocated. */
+        if(res) {
+            xfreeaddrinfo(res);
+            res = NULL;
+        }
+        return false;
+    }
+
+    /*
+     *  NP: =(sockaddr_*) may alter the port. we don't want that.
+     *      all we have been given as input was an IPA.
+     */
+    port = GetPort();
+    operator=(*res);
+    SetPort(port);
+
+    /* free the memory xgetaddrinfo() dynamically allocated. */
+    xfreeaddrinfo(res);
+
+    res = NULL;
+
+    return true;
+}
+
+IPAddress::IPAddress(struct sockaddr_in const &s)
+{
+    SetEmpty();
+    operator=(s);
+};
+
+IPAddress& IPAddress::operator =(struct sockaddr_in const &s)
+{
+#if USE_IPV6
+    Map4to6((const in_addr)s.sin_addr, m_SocketAddr.sin6_addr);
+    m_SocketAddr.sin6_port = s.sin_port;
+    m_SocketAddr.sin6_family = AF_INET6;
+#else
+
+    memcpy(&m_SocketAddr, &s, sizeof(struct sockaddr_in));
+#endif
+
+    /* maintain stored family values properly */
+    check4Mapped();
+
+    return *this;
+};
+
+void IPAddress::check4Mapped()
+{
+  // obsolete.
+    // TODO use this NOW to set the sin6_family properly on exporting. not on import.
+}
+
+#if USE_IPV6
+IPAddress::IPAddress(sockaddr_in6 const &s)
+{
+    SetEmpty();
+    operator=(s);
+};
+
+IPAddress& IPAddress::operator =(sockaddr_in6 const &s)
+{
+    memcpy(&m_SocketAddr, &s, sizeof(struct sockaddr_in6));
+
+    /* maintain address family properly */
+    check4Mapped();
+    return *this;
+};
+
+#endif
+
+IPAddress::IPAddress(in_addr const &s)
+{
+    SetEmpty();
+    operator=(s);
+};
+
+IPAddress& IPAddress::operator =(struct in_addr const &s)
+{
+#if USE_IPV6
+    Map4to6((const in_addr)s, m_SocketAddr.sin6_addr);
+    m_SocketAddr.sin6_family = AF_INET6;
+
+#else
+
+    memcpy(&m_SocketAddr.sin_addr, &s, sizeof(struct in_addr));
+
+#endif
+
+    /* maintain stored family type properly */
+    check4Mapped();
+
+    return *this;
+};
+
+#if USE_IPV6
+
+IPAddress::IPAddress(struct in6_addr const &s)
+{
+    SetEmpty();
+    operator=(s);
+};
+
+IPAddress& IPAddress::operator =(struct in6_addr const &s)
+{
+
+    memcpy(&m_SocketAddr.sin6_addr, &s, sizeof(struct in6_addr));
+    m_SocketAddr.sin6_family = AF_INET6;
+
+    /* maintain address family type properly */
+    check4Mapped();
+
+    return *this;
+};
+
+#endif
+
+IPAddress::IPAddress(const IPAddress &s)
+{
+    SetEmpty();
+    operator=(s);
+}
+
+IPAddress::IPAddress(IPAddress *s)
+{
+    SetEmpty();
+    operator=(s);
+}
+
+IPAddress& IPAddress::operator =(IPAddress *s)
+{
+    IPAddress *tmp = NULL;
+    if(!s) return *this;
+    tmp = dynamic_cast<IPAddress*>(s);
+    if(!tmp) return *this;
+    return operator=(*tmp);
+}
+
+IPAddress::IPAddress(const struct hostent &s)
+{
+    SetEmpty();
+    operator=(s);
+}
+
+bool IPAddress::operator =(const struct hostent &s)
+{
+
+    struct in_addr* ipv4 = NULL;
+
+    struct in6_addr* ipv6 = NULL;
+
+    //struct hostent {
+    //        char    *h_name;        /* official name of host */
+    //        char    **h_aliases;    /* alias list */
+    //        int     h_addrtype;     /* host address type */
+    //        int     h_length;       /* length of address */
+    //        char    **h_addr_list;  /* list of addresses */
+    //}
+
+    switch(s.h_addrtype)
+    {
+
+    case AF_INET:
+        ipv4 = (in_addr*)(s.h_addr_list[0]);
+        /* this */
+        operator=(*ipv4);
+        break;
+
+    case AF_INET6:
+        ipv6 = (in6_addr*)(s.h_addr_list[0]);
+#if USE_IPV6
+        /* this */
+        operator=(*ipv6);
+#else
+
+        debugs(14,1, HERE << "Discarded IPv6 Address. Protocol disabled.");
+
+        // FIXME see if there is another address in the list that might be usable ??
+        return false;
+#endif
+
+        break;
+
+    default:
+         IASSERT("false",false);
+         return false;
+    }
+
+    return true;
+}
+
+IPAddress::IPAddress(const struct addrinfo &s)
+{
+    SetEmpty();
+    operator=(s);
+}
+
+bool IPAddress::operator =(const struct addrinfo &s)
+{
+
+    struct sockaddr_in* ipv4 = NULL;
+
+    struct sockaddr_in6* ipv6 = NULL;
+
+    //struct addrinfo {
+    //             int ai_flags;           /* input flags */
+    //             int ai_family;          /* protocol family for socket */
+    //             int ai_socktype;        /* socket type */
+    //             int ai_protocol;        /* protocol for socket */
+    //             socklen_t ai_addrlen;   /* length of socket-address */
+    //             struct sockaddr *ai_addr; /* socket-address for socket */
+    //             char *ai_canonname;     /* canonical name for service location */
+    //             struct addrinfo *ai_next; /* pointer to next in list */
+    //}
+
+    switch(s.ai_family)
+    {
+
+    case AF_INET:
+        ipv4 = (sockaddr_in*)(s.ai_addr);
+        /* this */
+        assert(ipv4);
+        operator=(*ipv4);
+        break;
+
+    case AF_INET6:
+        ipv6 = (sockaddr_in6*)(s.ai_addr);
+#if USE_IPV6
+        /* this */
+        assert(ipv6);
+        operator=(*ipv6);
+#else
+
+        debugs(14,1, HERE << "Discarded IPv6 Address. Protocol disabled.");
+
+        // see if there is another address in the list that might be usable ??
+
+        if (s.ai_next)
+            return operator=(*s.ai_next);
+        else
+            return false;
+
+#endif
+        break;
+
+    case AF_UNSPEC:
+    default:
+        // attempt to handle partially initialised addrinfo.
+        // such as those where data only comes from getsockopt()
+        if(s.ai_addr != NULL) {
+#if USE_IPV6
+            if(s.ai_addrlen == sizeof(struct sockaddr_in6)) {
+                operator=(*((struct sockaddr_in6*)s.ai_addr));
+                return true;
+            }
+            else
+#endif
+            if(s.ai_addrlen == sizeof(struct sockaddr_in)) {
+                operator=(*((struct sockaddr_in*)s.ai_addr));
+                return true;
+            }
+        }
+        return false;
+    }
+
+    return true;
+}
+
+void IPAddress::GetAddrInfo(struct addrinfo *&dst, int force) const
+{
+    if(dst == NULL)
+    {
+        dst = new addrinfo;
+    }
+
+    memset(dst, 0, sizeof(struct addrinfo));
+
+    // set defaults
+    dst->ai_flags = AI_NUMERICHOST;
+
+    if(dst->ai_socktype == 0)
+        dst->ai_socktype = SOCK_STREAM;
+
+    if(dst->ai_socktype == SOCK_STREAM  // implies TCP
+            && dst->ai_protocol == 0)
+        dst->ai_protocol = IPPROTO_TCP;
+
+    if(dst->ai_socktype == SOCK_DGRAM  // implies UDP
+            && dst->ai_protocol == 0)
+        dst->ai_protocol = IPPROTO_UDP;
+
+#if USE_IPV6
+    if( force == AF_INET6 || force == AF_UNSPEC && IsIPv6() )
+    {
+        dst->ai_addr = (struct sockaddr*)new sockaddr_in6;
+
+        memset(dst->ai_addr,0,sizeof(struct sockaddr_in6));
+
+        GetSockAddr(*((struct sockaddr_in6*)dst->ai_addr));
+
+        dst->ai_addrlen = sizeof(struct sockaddr_in6);
+
+        dst->ai_family = ((struct sockaddr_in6*)dst->ai_addr)->sin6_family;
+        dst->ai_protocol = IPPROTO_IPV6;
+    } else
+#endif
+        if( force == AF_INET || force == AF_UNSPEC && IsIPv4() )
+        {
+
+            dst->ai_addr = (struct sockaddr*)new sockaddr_in;
+
+            memset(dst->ai_addr,0,sizeof(struct sockaddr_in));
+
+            GetSockAddr(*((struct sockaddr_in*)dst->ai_addr));
+
+            dst->ai_addrlen = sizeof(struct sockaddr_in);
+
+            dst->ai_family = ((struct sockaddr_in*)dst->ai_addr)->sin_family;
+        } else
+        {
+            IASSERT("false",false);
+        }
+}
+
+void IPAddress::InitAddrInfo(struct addrinfo *&ai) const
+{
+    if(ai == NULL) {
+        ai = new addrinfo;
+        memset(ai,0,sizeof(struct addrinfo));
+    }
+
+    // remove any existing data.
+    if(ai->ai_addr) delete ai->ai_addr;
+
+    ai->ai_addr = (struct sockaddr*)new sockaddr_in6;
+    memset(ai->ai_addr, 0, sizeof(struct sockaddr_in6));
+
+    ai->ai_addrlen = sizeof(struct sockaddr_in6);
+
+}
+
+void IPAddress::FreeAddrInfo(struct addrinfo *&ai) const
+{
+    if(ai == NULL) return;
+
+    if(ai->ai_addr) delete ai->ai_addr;
+
+    ai->ai_addr = NULL;
+
+    ai->ai_addrlen = 0;
+
+    // NP: name fields are NOT allocated at present.
+    delete ai;
+
+    ai = NULL;
+}
+
+int IPAddress::matchIPAddr(const IPAddress &rhs) const
+{
+#if USE_IPV6
+    uint8_t *l = (uint8_t*)m_SocketAddr.sin6_addr.s6_addr;
+    uint8_t *r = (uint8_t*)rhs.m_SocketAddr.sin6_addr.s6_addr;
+#else
+    uint8_t *l = (uint8_t*)&m_SocketAddr.sin_addr.s_addr;
+    uint8_t *r = (uint8_t*)&rhs.m_SocketAddr.sin_addr.s_addr;
+#endif
+
+    // loop a byte-wise compare
+    // NP: match MUST be R-to-L : L-to-R produces inconsistent gt/lt results at varying CIDR
+    //     expected difference on CIDR is gt/eq or lt/eq ONLY.
+    for(unsigned int i = 0 ; i < sizeof(m_SocketAddr.sin6_addr) ; i++) {
+
+        if(l[i] < r[i])
+            return -1;
+
+        if(l[i] > r[i])
+            return 1;
+    }
+
+    return 0;
+}
+
+bool IPAddress::operator ==(const IPAddress &s) const
+{
+    return (0 == matchIPAddr(s));
+}
+
+bool IPAddress::operator !=(const IPAddress &s) const
+{
+    return ! ( operator==(s) );
+}
+
+bool IPAddress::operator <=(const IPAddress &rhs) const
+{
+    if(IsAnyAddr() && !rhs.IsAnyAddr())
+        return true;
+
+    return (matchIPAddr(rhs) <= 0);
+}
+
+bool IPAddress::operator >=(const IPAddress &rhs) const
+{
+    if(IsNoAddr() && !rhs.IsNoAddr())
+        return true;
+
+    return ( matchIPAddr(rhs) >= 0);
+}
+
+bool IPAddress::operator >(const IPAddress &rhs) const
+{
+    if(IsNoAddr() && !rhs.IsNoAddr())
+        return true;
+
+    return ( matchIPAddr(rhs) > 0);
+}
+
+bool IPAddress::operator <(const IPAddress &rhs) const
+{
+    if(IsNoAddr() && !rhs.IsNoAddr())
+        return true;
+
+    return ( matchIPAddr(rhs) < 0);
+}
+
+u_short IPAddress::GetPort() const
+{
+    return ntohs( m_SocketAddr.sin6_port );
+}
+
+u_short IPAddress::SetPort(u_short prt)
+{
+    m_SocketAddr.sin6_port = htons(prt);
+
+    return prt;
+}
+
+/**
+ * NtoA Given a buffer writes a readable ascii version of the IPA and/or port stored
+ *
+ * Buffer must be of a size large enough to hold the converted address.
+ * This size is provided in the form of a global defined variable MAX_IPSTRLEN
+ * Should a buffer shorter be provided the string result will be truncated
+ * at the length of the available buffer.
+ *
+ * A copy of the buffer is also returned for simple immediate display.
+ */
+char* IPAddress::NtoA(char* buf, const unsigned int blen, int force) const
+{
+    // Ensure we have a buffer.
+    if(buf == NULL) {
+        return NULL;
+    }
+
+    /* some external code may have blindly memset a parent. */
+    /* thats okay, our default is known */
+    if( IsAnyAddr() ) {
+#if USE_IPV6
+        memcpy(buf,"::\0", xmin(3,blen));
+#else
+        memcpy(buf,"0.0.0.0\0", xmin(8,blen));
+#endif
+        return buf;
+    }
+
+    memset(buf,0,blen); // clear buffer before write
+
+    /* Pure-IPv6 CANNOT be displayed in IPv4 format. */
+    /* However IPv4 CAN. */
+    if( force == AF_INET && !IsIPv4() ) {
+        if( IsIPv6() ) {
+            memcpy(buf, "{!IPv4}\0", xmin(8,blen));
+        }
+        return buf;
+    }
+
+#if USE_IPV6
+    if( force == AF_INET6 || (force == AF_UNSPEC && IsIPv6()) ) {
+
+        xinet_ntop(AF_INET6, &m_SocketAddr.sin6_addr, buf, blen);
+
+    } else  if ( force == AF_INET || (force == AF_UNSPEC && IsIPv4()) ) {
+
+        struct in_addr tmp;
+        GetInAddr(tmp);
+        xinet_ntop(AF_INET, &tmp, buf, blen);
+#else
+   if ( force == AF_UNSPEC || (force == AF_INET && IsIPv4()) ) {
+        xinet_ntop(AF_INET, &m_SocketAddr.sin_addr, buf, blen);
+#endif
+    } else {
+        debugs(14,0,"WARNING: Corrupt IP Address details OR required to display in unknown format (" <<
+                    force << "). accepted={" << AF_UNSPEC << "," << AF_INET << "," << AF_INET6 << "}");
+        fprintf(stderr,"WARNING: Corrupt IP Address details OR required to display in unknown format (%d). accepted={%d,%d,%d} ",
+                force, AF_UNSPEC, AF_INET, AF_INET6);
+        memcpy(buf,"dead:beef::\0", xmin(13,blen));
+        assert(false);
+    }
+
+    return buf;
+}
+
+unsigned int IPAddress::ToHostname(char *buf, const unsigned int blen) const
+{
+    char *p = buf;
+
+    if(IsIPv6() && blen > 0) {
+        *p = '[';
+        p++;
+    }
+
+    /* 7 being space for [,], and port */
+    if( IsIPv6() )
+        NtoA(p, blen-7, AF_INET6);
+    else
+        NtoA(p, blen-7, AF_INET);
+
+    // find the end of the new string
+    while(*p != '\0' && p < buf+blen)
+        p++;
+
+    if(IsIPv6() && p < buf+blen-1) {
+        *p = ']';
+        p++;
+    }
+
+    /* terminate just in case. */
+    *p = '\0';
+
+    /* return size of buffer now used */
+    return (p - buf);
+}
+
+char* IPAddress::ToURL(char* buf, unsigned int blen) const
+{
+    char *p = buf;
+
+    // Ensure we have a buffer.
+
+    if(buf == NULL) {
+        return NULL;
+    }
+
+    p += ToHostname(p, blen);
+
+    if(m_SocketAddr.sin6_port > 0 && p < buf+blen-6) {
+        /* 6 is max length of expected ':port' (short int) */
+        snprintf(p, 6,":%d", GetPort() );
+    }
+
+    // force a null-terminated string
+    buf[blen] = '\0';
+
+    return buf;
+}
+
+void IPAddress::GetSockAddr(struct sockaddr_in &buf) const
+{
+#if USE_IPV6
+
+    if( IsIPv4() )
+    {
+        buf.sin_family = AF_INET;
+        buf.sin_port = m_SocketAddr.sin6_port;
+        Map6to4( m_SocketAddr.sin6_addr, buf.sin_addr);
+    } else
+    {
+        debugs(14,1, HERE << "IPAddress::GetSockAddr : Cannot convert non-IPv4 to IPv4.");
+
+        memset(&buf,0xFFFFFFFF,sizeof(struct sockaddr_in));
+        assert(false);
+    }
+
+#else
+
+    memcpy(&buf, &m_SocketAddr, sizeof(struct sockaddr_in));
+
+    if(buf.sin_family == 0)
+    {
+        buf.sin_family = AF_INET;
+    }
+
+#endif
+}
+
+#if USE_IPV6
+
+void IPAddress::GetSockAddr(struct sockaddr_in6 &buf) const
+{
+    memcpy(&buf, &m_SocketAddr, sizeof(struct sockaddr_in6));
+    /* maintain address family. It may have changed inside us. */
+    buf.sin6_family = AF_INET6;
+}
+
+#endif
+
+#if USE_IPV6
+
+void IPAddress::Map4to6(const struct in_addr &in, struct in6_addr &out) const
+{
+    /* check for special cases */
+
+    if( in.s_addr == 0x00000000)
+    {
+        /* ANYADDR */
+
+        memset(&out, 0, sizeof(struct in6_addr));
+    } else if( in.s_addr == 0xFFFFFFFF)
+    {
+        /* NOADDR */
+
+        out.s6_addr32[0] = 0xFFFFFFFF;
+        out.s6_addr32[1] = 0xFFFFFFFF;
+        out.s6_addr32[2] = 0xFFFFFFFF;
+        out.s6_addr32[3] = 0xFFFFFFFF;
+
+#if IPV6_SPECIAL_LOCALHOST
+    } else if( in.s_addr == htonl(0x7F000001))
+    {
+        /* LOCALHOST */
+
+        memset(&out, 0, sizeof(struct in6_addr));
+        out.s6_addr32[3] = htonl(0x1);
+#endif
+
+    } else
+    {
+        /* general */
+
+        memset(&out, 0, sizeof(struct in6_addr));
+        out.s6_addr32[2] = htonl(0xFFFF);
+        out.s6_addr32[3] = in.s_addr;
+    }
+}
+
+void IPAddress::Map6to4(const struct in6_addr &in, struct in_addr &out) const
+{
+    /* ANYADDR */
+    /* NOADDR */
+    /* general */
+
+    memset(&out, 0, sizeof(struct in_addr));
+    out.s_addr = in.s6_addr32[3];
+
+#if IPV6_SPECIAL_LOCALHOST
+    /* LOCALHOST */
+
+    if( IsLocalhost() )
+    {
+        out.s_addr = htonl(0x7F000001);
+    }
+#endif
+
+}
+
+#endif
+
+#if USE_IPV6
+void IPAddress::GetInAddr(in6_addr &buf) const
+{
+    memcpy(&buf, &m_SocketAddr.sin6_addr, sizeof(struct in6_addr));
+}
+
+#endif
+
+bool IPAddress::GetInAddr(struct in_addr &buf) const
+{
+
+#if USE_IPV6
+    if( IsIPv4() ) {
+        Map6to4((const in6_addr)m_SocketAddr.sin6_addr, buf);
+        return true;
+    }
+#else
+
+    if( IsIPv4() ) {
+        memcpy(&buf, &m_SocketAddr.sin_addr, sizeof(struct in_addr));
+        return true;
+    }
+#endif
+
+    // default:
+    // non-compatible IPv6 Pure Address
+
+    debugs(14,1, HERE << "IPAddress::GetInAddr : Cannot convert non-IPv4 to IPv4. IPA=" << *this);
+    memset(&buf,0xFFFFFFFF,sizeof(struct in_addr));
+    assert(false);
+    return false;
+}
