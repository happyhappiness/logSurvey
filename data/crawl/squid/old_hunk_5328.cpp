	user = strtok(buf, ":\n");
	passwd = strtok(NULL, ":\n");
	if ((strlen(user) > 0) && passwd) {
	    u = xmalloc(sizeof(*u));
	    u->hash.key = xstrdup(user);
	    u->passwd = xstrdup(passwd);
	    hash_join(hash, &u->hash);
	}
    }
    fclose(f);
}
