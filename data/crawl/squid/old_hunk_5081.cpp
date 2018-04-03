	}
	rfc1738_unescape(user);
	rfc1738_unescape(passwd);
	tryagain = (ld != NULL);
      recover:
	if (ld == NULL && persistent)