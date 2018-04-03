	/* NOTREACHED */
    }

    time_string = ctime(&now);

    printf("<HTML><HEAD><TITLE>Cache Manager: %s:%s:%d</TITLE></HEAD>\n",
	operation, hostname, portnum);
