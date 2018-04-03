	    }
	    goto error;
	}
	
	if ((p = strchr(buf, '\n')) != NULL)
	    *p = '\0';		/* strip \n */
	if ((p = strchr(buf, '\r')) != NULL)
	    *p = '\0';		/* strip \r */

	debug("Got '%s' from Squid (length: %d).\n",buf,strlen(buf));

	if (buf[0] == '\0') {
	    fprintf(stderr, "Invalid Request\n");
	    goto error;
	}

	username = strtok(buf, " ");
	for (n = 0; (group = strtok(NULL, " ")) != NULL; n++) {
	    rfc1738_unescape(group);
	    groups[n] = group;
	}
	groups[n] = NULL;

        if (NULL == username) {
            fprintf(stderr, "Invalid Request\n");
            goto error;
        }
	rfc1738_unescape(username);

	if ((use_global ? Valid_Global_Groups(username, groups) : Valid_Local_Groups(username, groups))) {
	    printf ("OK\n");
	} else {
error:
	    printf ("ERR\n");
	}
	err = 0;
    }