     printf("<P>This is a WWW interface to the instrumentation interface\n");
     printf("for the Squid object cache.</P>\n");
     printf("<HR noshade size=\"1px\">\n");
-    printf("<FORM METHOD=\"GET\" ACTION=\"%s\">\n", script_name);
+    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
     printf("<TABLE BORDER=\"0\" CELLPADDING=\"10\" CELLSPACING=\"1\">\n");
     printf("<TR><TH ALIGN=\"left\">Cache Host:</TH><TD><INPUT NAME=\"host\" ");
     printf("size=\"30\" VALUE=\"%s\"></TD></TR>\n", host);