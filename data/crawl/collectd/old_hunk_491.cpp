
	default:
	    fprintf (stderr, "unsupported data link type %d\n",
		    pcap_datalink(pcap));
	    status = 0;
	    break;
    } /* switch (pcap_datalink(pcap)) */

    if (0 == status)
	return;
