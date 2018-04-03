	perror("fdopen");
	return 1;
    }
    printf("Content-Type: text/html\r\n\r\n");
    if (parse_menu) {
	printf("<H2>Cache Manager menu for %s:</H2>", req->hostname);
	printf("<UL>\n");
    } else {
	printf("<P><A HREF=\"%s\">%s</A>\n<HR>\n",
	    menu_url(req, "menu"), "Cache Manager menu");
	printf("<PRE>\n");
    }
    while (fgets(buf, 1024, fp) != NULL) {
	if (1 == state)
	    if (parse_menu)
		fputs(munge_menu_line(buf, req), stdout);
	    else
		fputs(buf, stdout);
	if (0 == strcmp(buf, "\r\n"))
	    state++;
    }
    if (parse_menu)
	printf("</UL>\n");
    else
	printf("</PRE>\n");
    print_trailer();
    close(s);
    return 0;
}
