	    goto error;
	}

	username = strtok(buf, " ");
	for (n = 0; (group = strtok(NULL, " ")) != NULL; n++) {
	    rfc1738_unescape(group);
	    groups[n] = group;
	}
	groups[n] = NULL;

        if (NULL == username) {
            warn("Invalid Request\n");
            goto error;
        }
	rfc1738_unescape(username);

	if (Valid_Groups(username, groups)) {
	    printf ("OK\n");
	} else {
error:
	    printf ("ERR\n");
	}
    }
    return 0;
}