            if (!comment || !*comment)
                comment = server;

            if (!servers)
                printf("<TR><TH ALIGN=\"left\">Cache Server:</TH><TD><SELECT id=\"server\" NAME=\"server\">\n");

            printf("<OPTION VALUE=\"%s\"%s>%s</OPTION>\n", server, (servers || *host) ? "" : " SELECTED", comment);
            servers++;
