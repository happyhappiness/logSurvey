	break;
    case PARAM:
	if (hasTables) {
	    printf("<table border=1><td><B>Parameter</B><td><B>Value</B><td><B>Description</B><tr>\n");
	    in_table = 1;
	} else {
	    printf("<B>\n %20s %10s %s</B><HR>\n", "Parameter", "Value", "Description");
	}
	break;
    case STATS_U:
	if (hasTables) {
	    printf("<table border=1><td><B>Protocol</B><td><B>Count</B><td><B>Max KB</B><td><B>Current KB</B><td><B>Min KB</B><td><B>Hit Ratio</B><td><B>Transfer Rate</B><td><B>References</B><td><B>Transfered KB</B><tr>\n");
	    in_table = 1;
	} else {
	    printf("<B>Protocol | Count | Maximum  | Current  | Minimum | Hit   | Transfer | Reference | Transfered |</B>\n");
	    printf("<B>         |       | KB       | KB       | KB      | Ratio | Rate     | Count     | KB         |</B>\n");
	    printf("<B>---------|-------|----------|----------|---------|-------|----------|-----------|------------|</B>\n");
	}
	break;
    default:
