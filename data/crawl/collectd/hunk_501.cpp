 {
     int status;
 
+    fprintf (stderr, "handle_pcap (udata = %p, hdr = %p, pkt = %p): hdr->caplen = %i\n",
+		    (void *) udata, (void *) hdr, (void *) pkt,
+		    hdr->caplen);
+
     if (hdr->caplen < ETHER_HDR_LEN)
 	return;
 
