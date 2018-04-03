	u = (user_data *) hash_lookup(hash, user);
	if (u == NULL) {
	    printf("ERR No such user\n");
#if HAVE_CRYPT
	} else if (strcmp(u->passwd, (char *) crypt(passwd, u->passwd)) == 0) {
	    printf("OK\n");
#endif
	} else if (strcmp(u->passwd, (char *) crypt_md5(passwd, u->passwd)) == 0) {
	    printf("OK\n");
	} else if (strcmp(u->passwd, (char *) md5sum(passwd)) == 0) {	/* md5 without salt and magic strings - Added by Ramon de Carvalho and Rodrigo Rubira Branco */
	    printf("OK\n");
	} else {
	    printf("ERR Wrong password\n");
	}