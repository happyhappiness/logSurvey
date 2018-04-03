 /*
  * $Id: IPInterception.h,v 1.7 2007/12/14 23:11:45 amosjeffries Exp $
  *
- *
- * SQUID Web Proxy Cache          http://www.squid-cache.org/
- * ----------------------------------------------------------
- *
- *  Squid is the result of efforts by numerous individuals from
- *  the Internet community; see the CONTRIBUTORS file for full
- *  details.   Many organizations have provided support for Squid's
- *  development; see the SPONSORS file for full details.  Squid is
- *  Copyrighted (C) 2001 by the Regents of the University of
- *  California; see the COPYRIGHT file for full details.  Squid
- *  incorporates software developed and/or copyrighted by other
- *  sources; see the CREDITS file for full details.
- *
- *  This program is free software; you can redistribute it and/or modify
- *  it under the terms of the GNU General Public License as published by
- *  the Free Software Foundation; either version 2 of the License, or
- *  (at your option) any later version.
- *  
- *  This program is distributed in the hope that it will be useful,
- *  but WITHOUT ANY WARRANTY; without even the implied warranty of
- *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
- *  GNU General Public License for more details.
- *  
- *  You should have received a copy of the GNU General Public License
- *  along with this program; if not, write to the Free Software
- *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
+ * DEBUG: section 89    NAT / IP Interception
+ * AUTHOR: Robert Collins
+ * AUTHOR: Amos Jeffries
  *
  */
 #ifndef SQUID_IPINTERCEPTION_H
 #define SQUID_IPINTERCEPTION_H
 
-#include "IPAddress.h"
+class IPAddress;
+
+/* for time_t */
+#include "SquidTime.h"
+
+/**
+ \defgroup IPInterceptAPI IP Interception and Transparent Proxy API
+ \ingroup SquidComponent
+ \par
+ * There is no formal state-machine for transparency and interception
+ * instead there is this neutral API which other connection state machines
+ * and the comm layer use to co-ordinate their own state for transparency.
+ */
+class IPIntercept
+{
+public:
+    IPIntercept() : transparent_active(0), intercept_active(0), last_reported(0) {};
+    ~IPIntercept() {};
+
+    /** Perform NAT lookups */
+    int NatLookup(int fd, const IPAddress &me, const IPAddress &peer, IPAddress &dst);
+
+#if LINUX_TPROXY2
+    // only relevant to TPROXY v2 connections.
+    // which require the address be set specifically post-connect.
+    int SetTproxy2OutgoingAddr(int fd, const IPAddress &src);
+#endif
+
+    /**
+     \retval 0	Full transparency is disabled.
+     \retval 1  Full transparency is enabled and active.
+     */
+    inline int TransparentActive() { return transparent_active; };
+
+    /** \par
+     * Turn on fully Transparent-Proxy activities.
+     * This function should be called during parsing of the squid.conf
+     * When any option requiring full-transparency is encountered.
+     */
+    inline void StartTransparency() { transparent_active=1; };
+
+    /** \par
+     * Turn off fully Transparent-Proxy activities on all new connections.
+     * Existing transactions and connections are unaffected and will run
+     * to their natural completion.
+     \param str    Reason for stopping. Will be logged to cache.log
+     */
+    void StopTransparency(const char *str);
 
-#if LINUX_TPROXY4 && !defined(IP_TRANSPARENT)
+    /**
+     \retval 0	IP Interception is disabled.
+     \retval 1  IP Interception is enabled and active.
+     */
+    inline int InterceptActive() { return intercept_active; };
+
+    /** \par
+     * Turn on IP-Interception-Proxy activities.
+     * This function should be called during parsing of the squid.conf
+     * When any option requiring interception / NAT handling is encountered.
+     */
+    inline void StartInterception() { intercept_active=1; };
+
+    /** \par
+     * Turn off IP-Interception-Proxy activities on all new connections.
+     * Existing transactions and connections are unaffected and will run
+     * to their natural completion.
+     \param str    Reason for stopping. Will be logged to cache.log
+     */
+    inline void StopInterception(const char *str);
+
+
+private:
+
+    /**
+     * perform Lookups on Netfilter interception targets (REDIRECT, DNAT).
+     *
+     \param silent[in]   0 if errors are to be displayed. 1 if errors are to be hidden.
+     \retval 0     Successfuly located the new address.
+     \retval -1    An error occured during NAT lookups.
+     */
+    int NetfilterInterception(int fd, const IPAddress &me, IPAddress &dst, int silent);
+
+    /**
+     * perform Lookups on Netfilter fully-transparent interception targets (TPROXY).
+     *
+     \param silent[in]   0 if errors are to be displayed. 1 if errors are to be hidden.
+     \retval 0     Successfuly located the new address.
+     \retval -1    An error occured during NAT lookups.
+     */
+    int NetfilterTransparent(int fd, const IPAddress &me, IPAddress &dst, int silent);
+
+    /**
+     * perform Lookups on IPFW interception.
+     *
+     \param silent[in]   0 if errors are to be displayed. 1 if errors are to be hidden.
+     \retval 0     Successfuly located the new address.
+     \retval -1    An error occured during NAT lookups.
+     */
+    int IPFWInterception(int fd, const IPAddress &me, IPAddress &dst, int silent);
+
+
+    int transparent_active;
+    int intercept_active;
+    time_t last_reported; /**< Time of last error report. Throttles NAT error display to 1 per minute */
+};
+
+#if LINUX_NETFILTER && !defined(IP_TRANSPARENT)
+/// \ingroup IPInterceptAPI
 #define IP_TRANSPARENT 19
 #endif
 
-SQUIDCEXTERN int clientNatLookup(int fd, const IPAddress &me, const IPAddress &peer, IPAddress &dst);
+/**
+ \ingroup IPInterceptAPI
+ * Globally available instance of the IP Interception manager.
+ */
+extern IPIntercept IPInterceptor;
 
 #endif /* SQUID_IPINTERCEPTION_H */
