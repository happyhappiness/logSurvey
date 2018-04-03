    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
    printf("<TABLE BORDER=0>\n");
    printf("<TR><TH ALIGN=\"left\">Cache Host:</TH><TD><INPUT NAME=\"host\" ");
    printf("SIZE=30 VALUE=\"%s\"></TD></TR>\n", host ? host : "localhost");
    printf("<TR><TH ALIGN=\"left\">Cache Port:</TH><TD><INPUT NAME=\"port\" ");
    printf("SIZE=30 VALUE=\"%d\"></TD></TR>\n", port);
    printf("<TR><TH ALIGN=\"left\">Manager name:</TH><TD><INPUT NAME=\"user_name\" ");
