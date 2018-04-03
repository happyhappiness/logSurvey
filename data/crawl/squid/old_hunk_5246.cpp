	u = (user_data *)hash_lookup(hash, user);
	if (u == NULL) {
	    printf("ERR\n");
	} else if (strcmp(u->passwd, (char *) crypt(passwd, u->passwd))) {
	    printf("ERR\n");
	} else {
	    printf("OK\n");
	}
    }
    exit(0);