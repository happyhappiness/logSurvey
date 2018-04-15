	    break;

	default:
	    ERROR ("handle_pcap: unsupported data link type %d\n",
		    pcap_datalink(pcap_obj));
	    status = 0;
	    break;