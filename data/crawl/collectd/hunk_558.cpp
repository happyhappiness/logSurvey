     char buf[PCAP_SNAPLEN];
     struct ether_header *e = (void *) pkt;
     unsigned short etype = ntohs(e->ether_type);
+    fprintf (stderr, "handle_ether (pkt = %p, len = %i)\n",
+		    (void *) pkt, len);
     if (len < ETHER_HDR_LEN)
 	return 0;
     pkt += ETHER_HDR_LEN;
