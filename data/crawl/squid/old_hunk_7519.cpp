	break;
    case STATS_U:
	if (hasTables) {
	    printf("<table border=1><tr><td><STRONG>Protocol</STRONG><td><STRONG>Count</STRONG><td><STRONG>Max KB</STRONG><td><STRONG>Current KB</STRONG><td><STRONG>Min KB</STRONG><td><STRONG>Hit Ratio</STRONG><td><STRONG>Transfer Rate</STRONG><td><STRONG>References</STRONG><td><STRONG>Transfered KB</STRONG>\n");
	    in_table = 1;
	} else {
	    printf("Protocol  Count   Maximum   Current   Minimum  Hit  Trans   Transfer Transfered\n");
	    printf("                  KB        KB        KB       Rate KB/sec  Count     KB\n");
	    printf("-------- ------- --------- --------- --------- ---- ------ --------- ----------\n");
	}
	break;
