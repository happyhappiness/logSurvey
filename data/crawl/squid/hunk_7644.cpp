     printf("<OPTION VALUE=\"stats/ipcache\">IP Cache Contents\n");
     printf("<OPTION VALUE=\"stats/fqdncache\">FQDN Cache Contents\n");
     printf("<OPTION VALUE=\"stats/dns\">DNS Server Statistics\n");
+    printf("<OPTION VALUE=\"stats/redirector\">Redirector Statistics\n");
     printf("</SELECT>");
     printf("<INPUT TYPE=\"hidden\" NAME=\"host\" VALUE=\"%s\">\n", hostname);
     printf("<INPUT TYPE=\"hidden\" NAME=\"port\" VALUE=\"%d\">\n", portnum);
