	    goto error;
	}

	username = strwordtok(buf, &t);
	for (n = 0; (group = strwordtok(NULL, &t)) != NULL; n++)
	    groups[n] = group;
	groups[n] = NULL;

        if (NULL == username) {
            warn("Invalid Request\n");
            goto error;
        }

	if (Valid_Groups(username, groups)) {
	    printf ("OK\n");
	} else {
error:
	    printf ("ERR\n");
	}
	err = 0;
    }
    return 0;
}