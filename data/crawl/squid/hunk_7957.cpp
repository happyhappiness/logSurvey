     }
 }
 
-void parseMailTraceLine(line_in)
+static void parseMailTraceLine(line_in)
      char *line_in;
 {
     fprintf(stderr, "'mail_trace' not supported in this version; ignored.\n");
 }
 
 
-void parseSourcePingLine(line_in)
+static void parseSourcePingLine(line_in)
      char *line_in;
 {
     char *srcping;
