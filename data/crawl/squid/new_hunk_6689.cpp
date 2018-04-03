	case isStatusLine:
	    /* get HTTP status */
	    /* uncomment the following if you want to debug headers */
	    /* fputs("\r\n\r\n", stdout); */
	    status = parse_status_line(buf, &statusStr);
	    istate = status == 200 ? isHeaders : isForward;
	    /* if cache asks for authentication, we have to reset our info */
	    if (status == 401 || status == 407) {
		reset_auth(req);
		status = 403;	/* Forbiden, see comments in case isForward: */
	    }
	    /* this is a way to pass HTTP status to the Web server */
	    if (statusStr)
		printf("Status: %d %s", status, statusStr);	/* statusStr has '\n' */
	    break;
	case isHeaders:
	    /* forward header field */
	    if (!strcmp(buf, "\r\n")) {		/* end of headers */
		fputs("Content-Type: text/html\r\n", stdout);	/* add our type */
		istate = isBodyStart;
	    }
	    if (strncasecmp(buf, "Content-Type:", 13))	/* filter out their type */
		fputs(buf, stdout);
	    break;
	case isBodyStart:
	    printf("<HTML><HEAD><TITLE>CacheMgr@%s: %s</TITLE></HEAD><BODY>\n",
		req->hostname, action);
	    if (parse_menu) {
		printf("<H2><a href=\"%s\">Cache Manager</a> menu for %s:</H2>",
		    menu_url(req, "authenticate"), req->hostname);
