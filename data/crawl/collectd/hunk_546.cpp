     return 0;
 }
 
-static const char *
-QnameToNld(const char *qname, int nld)
-{
-    const char *t = strrchr(qname, '.');
-    int dotcount = 1;
-    if (NULL == t)
-	t = qname;
-    if (0 == strcmp(t, ".arpa"))
-	dotcount--;
-    while (t > qname && dotcount < nld) {
-	t--;
-	if ('.' == *t)
-	    dotcount++;
-    }
-    if (t > qname)
-	t++;
-    return t;
-}
-
 static int
-handle_dns(const char *buf, int len, const struct in_addr sip, const struct in_addr dip)
+handle_dns(const char *buf, int len,
+	const struct in6_addr *s_addr,
+	const struct in6_addr *d_addr)
 {
-    rfc1035_header qh;
-    unsigned short us;
-    char qname[MAX_QNAME_SZ];
-    unsigned short qtype;
-    unsigned short qclass;
+    rfc1035_header_t qh;
+    uint16_t us;
     off_t offset;
     char *t;
-    const char *s;
     int x;
-    StringCounter *sc;
-    StringAddrCounter *ssc;
 
-    fprintf (stderr, "handle_dns (buf = %p, len = %i)\n",
-		    (void *) buf, len);
-
-    if (len < sizeof(qh))
+    /* The DNS header is 12 bytes long */
+    if (len < 12)
 	return 0;
 
-    memcpy(&us, buf + 00, 2);
+    memcpy(&us, buf + 0, 2);
     qh.id = ntohs(us);
 
     memcpy(&us, buf + 2, 2);
     us = ntohs(us);
+    fprintf (stderr, "Bytes 0, 1: 0x%04hx\n", us);
     qh.qr = (us >> 15) & 0x01;
     qh.opcode = (us >> 11) & 0x0F;
     qh.aa = (us >> 10) & 0x01;
     qh.tc = (us >> 9) & 0x01;
     qh.rd = (us >> 8) & 0x01;
     qh.ra = (us >> 7) & 0x01;
+    qh.z  = (us >> 6) & 0x01;
+    qh.ad = (us >> 5) & 0x01;
+    qh.cd = (us >> 4) & 0x01;
     qh.rcode = us & 0x0F;
 
     memcpy(&us, buf + 4, 2);
