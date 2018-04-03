	perror("fdopen");
	return 1;
    }
    if (parse_menu)
	action = "menu";
    /* read reply interpreting one line at a time depending on state */
    while (istate < isEof) {
	if (!fgets(buf, sizeof(buf), fp))
	    istate = istate == isForward ? isForwardEof : isEof;
	switch (istate) {
	case isStatusLine:
	    /* get HTTP status */
	    /* uncomment the following if you want to debug headers */
            /* fputs("\r\n\r\n", stdout); */
	    status = parse_status_line(buf, &statusStr);
	    istate = status == 200 ? isHeaders : isForward;
	    /* if cache asks for authentication, we have to reset our info */
	    if (status == 401 || status == 407) {
		reset_auth(req);
		status = 403; /* Forbiden, see comments in case isForward: */
	    }
	    /* this is a way to pass HTTP status to the Web server */
	    if (statusStr)
		printf("Status: %d %s", status, statusStr);
	    break;
	case isHeaders:
	    /* forward header field */
	    if (!strcmp(buf, "\r\n")) { /* end of headers */
		fputs("Content-Type: text/html\r\n", stdout); /* add our type */
		istate = isBodyStart;
	    }
	    if (strncasecmp(buf, "Content-Type:", 13)) /* filter out their type */
	        fputs(buf, stdout);
	    break;
	case isBodyStart:
	    printf("<HTML><HEAD><TITLE>CacheMgr@%s: %s</TITLE></HEAD><BODY>\n",
		   req->hostname, action);
	    if (parse_menu) {
		printf("<H2><a href=\"%s\">Cache Manager</a> menu for %s:</H2>",
		    menu_url(req, "authenticate"), req->hostname);
		printf("<UL>\n");
	    } else {
		printf("<P><A HREF=\"%s\">%s</A>\n<HR>\n",
		    menu_url(req, "menu"), "Cache Manager menu");
		printf("<PRE>\n");
	    }
	    istate = isBody;
	    break;
	case isBody:
	    /* interpret [and reformat] cache response */
	    if (parse_menu)
		fputs(munge_menu_line(buf, req), stdout);
	    else
		fputs(buf, stdout);
	    break;
	case isForward:
	    /* forward: no modifications allowed */
	    /*
	     * Note: we currently do not know any way to get browser.reply to
	     * 401 to .cgi because web server filters out all auth info. Thus we
	     * disable authentication headers for now.
	     */
	    if (!strncasecmp(buf, "WWW-Authenticate:", 17) || !strncasecmp(buf, "Proxy-Authenticate:", 19))
		; /* skip */
	    else
	 	fputs(buf, stdout);
	    break;
	case isEof:
	    /* print trailers */
	    if (parse_menu)
		printf("</UL>\n");
	    else
		printf("</PRE>\n");
	    print_trailer();
	    istate = isSuccess;
	    break;
	case isForwardEof:
	    /* indicate that we finished processing an "error" sequence */
	    istate = isError;
	    break;
	default:
	    printf("%s: internal bug: invalid state reached: %d", script_name, istate);
	    istate = isError;
	}
    }
    /* printf("\n\n\n<pre>%s</pre>\n", req->headers ? req->headers : "no headers"); */
    close(s);
    return 0;
}