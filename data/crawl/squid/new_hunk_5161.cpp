	    (buf[0] == '\n'))
	    continue;
	user = strtok(buf, ":\n");
	realm = strtok(NULL, ":\n");
	passwd = strtok(NULL, ":\n");
	if (!passwd) {
	    passwd = realm;
	    realm = NULL;
	}
	if ((strlen(user) > 0) && passwd) {
	    if (strncmp(passwd, "{HHA1}", 6) == 0) {
		ha1 = passwd + 6;
		passwd = NULL;
	    } else if (ha1mode) {
		ha1 = passwd;
		passwd = NULL;
	    }
	    if (ha1 && strlen(ha1) != 32) {
		/* We cannot accept plaintext passwords when using HA1 encoding,
		 * as the passwords may be output to cache.log if debugging is on.
		 */
		fprintf(stderr, "digest_pw_auth: ignoring invalid password for %s\n", user);
		continue;
	    }
	    u = xmalloc(sizeof(*u));
	    if (realm) {
		int len = strlen(user)+strlen(realm)+2;
		u->hash.key = malloc(len);
		snprintf(u->hash.key, len, "%s:%s", user, realm);
	    } else {
		u->hash.key = xstrdup(user);
	    }
	    if (ha1)
		u->ha1 = xstrdup(ha1);
	    else
		u->passwd = xstrdup(passwd);
	    hash_join(hash, &u->hash);
  	}
    }
    fclose(f);
