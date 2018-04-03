    printf("<OPTION VALUE=\"stats/objects\">Objects\n");
    printf("<OPTION VALUE=\"stats/vm_objects\">VM_Objects\n");
    printf("<OPTION VALUE=\"server_list\">Cache Server List\n");
    printf("<OPTION VALUE=\"stats/general\">IP Cache Contents\n");
    printf("</SELECT>");
    printf("<INPUT TYPE=\"hidden\" NAME=\"host\" VALUE=\"%s\">\n", hostname);
    printf("<INPUT TYPE=\"hidden\" NAME=\"port\" VALUE=\"%d\">\n", portnum);
