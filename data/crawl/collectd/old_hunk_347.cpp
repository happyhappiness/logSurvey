	    break;

	default:
	    fprintf (stderr, "unsupported data link type %d\n",
		    pcap_datalink(pcap_obj));
	    status = 0;
	    break;