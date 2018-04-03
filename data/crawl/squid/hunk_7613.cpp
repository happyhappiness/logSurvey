 	break;
     case PARAM:
 	if (hasTables) {
-	    printf("<table border=1><td><B>Parameter</B><td><B>Value</B><td><B>Description</B><tr>\n");
+	    printf("<table border=1><tr><td><STRONG>Parameter</STRONG><td><STRONG>Value</STRONG><td><STRONG>Description</STRONG>\n");
 	    in_table = 1;
 	} else {
-	    printf("<B>\n %20s %10s %s</B><HR>\n", "Parameter", "Value", "Description");
+	    printf("\n    Parameter   Value   Description\n");
+	    printf("-------------- ------- -------------------------------------\n");
 	}
 	break;
     case STATS_U:
 	if (hasTables) {
-	    printf("<table border=1><td><B>Protocol</B><td><B>Count</B><td><B>Max KB</B><td><B>Current KB</B><td><B>Min KB</B><td><B>Hit Ratio</B><td><B>Transfer Rate</B><td><B>References</B><td><B>Transfered KB</B><tr>\n");
+	    printf("<table border=1><tr><td><STRONG>Protocol</STRONG><td><STRONG>Count</STRONG><td><STRONG>Max KB</STRONG><td><STRONG>Current KB</STRONG><td><STRONG>Min KB</STRONG><td><STRONG>Hit Ratio</STRONG><td><STRONG>Transfer Rate</STRONG><td><STRONG>References</STRONG><td><STRONG>Transfered KB</STRONG>\n");
 	    in_table = 1;
 	} else {
-	    printf("<B>Protocol | Count | Maximum  | Current  | Minimum | Hit   | Transfer | Reference | Transfered |</B>\n");
-	    printf("<B>         |       | KB       | KB       | KB      | Ratio | Rate     | Count     | KB         |</B>\n");
-	    printf("<B>---------|-------|----------|----------|---------|-------|----------|-----------|------------|</B>\n");
+	    printf("Protocol  Count   Maximum   Current   Minimum  Hit  Trans   Transfer Transfered\n");
+	    printf("                  KB        KB        KB       Rate KB/sec  Count     KB\n");
+	    printf("-------- ------- --------- --------- --------- ---- ------ --------- ----------\n");
 	}
 	break;
     default:
