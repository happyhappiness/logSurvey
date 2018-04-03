 	break;
     default:
 	fprintf(stderr, "unsupported data link type %d\n",
-	    pcap_datalink(pcap));
+	    pcap_datalink(pcap_obj));
 	return 1;
 	break;
     }
