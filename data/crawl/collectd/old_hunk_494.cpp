     * non-blocking call added for Mac OS X bugfix.  Sent by Max Horn.
     * ref http://www.tcpdump.org/lists/workers/2002/09/msg00033.html
     */
    x = pcap_setnonblock(pcap, 1, errbuf);
    if (x < 0) {
	fprintf(stderr, "pcap_setnonblock failed: %s\n", errbuf);
	exit(1);
    }

    switch (pcap_datalink(pcap)) {
    case DLT_EN10MB:
	handle_datalink = handle_ether;
	break;
