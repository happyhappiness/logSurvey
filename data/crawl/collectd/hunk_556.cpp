 handle_udp(const struct udphdr *udp, int len, struct in_addr sip, struct in_addr dip)
 {
     char buf[PCAP_SNAPLEN];
-    if (port53 != udp->uh_dport)
+    fprintf (stderr, "handle_udp (udp = %p, len = %i)\n",
+		    (void *) udp, len);
+    if (ntohs (udp->uh_dport) != 53)
 	return 0;
     memcpy(buf, udp + 1, len - sizeof(*udp));
     if (0 == handle_dns(buf, len - sizeof(*udp), sip, dip))
