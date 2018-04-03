    if (0 == stat(device, &sb))
	readfile_state = 1;
    if (readfile_state) {
	pcap_obj = pcap_open_offline(device, errbuf);
    } else {
	pcap_obj = pcap_open_live(device, PCAP_SNAPLEN, promisc_flag, 1000, errbuf);
    }
    if (NULL == pcap_obj) {
	fprintf(stderr, "pcap_open_*: %s\n", errbuf);
	exit(1);
    }
