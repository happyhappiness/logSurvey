	break;
    default:
	fprintf(stderr, "unsupported data link type %d\n",
	    pcap_datalink(pcap));
	return 1;
	break;
    }
