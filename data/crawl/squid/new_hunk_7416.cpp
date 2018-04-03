	break;
    case STATS_U:
	if (hasTables) {
	    printf("<table border=1><tr><td><STRONG>Protocol</STRONG><td><STRONG>Object Count</STRONG><td><STRONG>Max KB</STRONG><td><STRONG>Current KB</STRONG><td><STRONG>Min KB</STRONG><td><STRONG>Hit Ratio</STRONG><td><STRONG>Transfer KB/sec</STRONG><td><STRONG>Transfer Count</STRONG><td><STRONG>Transfered KB</STRONG></td>\n");
	    in_table = 1;
	} else {
	    printf("Protocol  Object  Maximum   Current   Minimum  Hit  Trans   Transfer Transfered\n");