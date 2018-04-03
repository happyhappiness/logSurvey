	    printf("<B>\n %20s %10s %s</B><HR>\n", "Parameter", "Value", "Description");
	}
	break;
    case STATS_U:
	if (hasTables) {
	    printf("<table border=1><td><B>Protocol</B><td><B>Count</B><td><B>Max KB</B><td><B>Current KB</B><td><B>Min KB</B><td><B>Hit Ratio</B><td><B>Transfer Rate</B><td><B>References</B><td><B>Transfered KB</B><tr>\n");
