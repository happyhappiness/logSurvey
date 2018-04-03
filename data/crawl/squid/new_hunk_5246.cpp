	u = (user_data *)hash_lookup(hash, user);
	if (u == NULL) {
	    printf("ERR\n");
	} else if (strcmp(u->passwd, (char *) crypt(passwd, u->passwd)) == 0) {
	    printf("OK\n");
	} else if (strcmp(u->passwd, (char *) crypt_md5(passwd, u->passwd)) == 0) {
	    printf("OK\n");
	} else {
	    printf("ERR\n");
	}
    }
    exit(0);