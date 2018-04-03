	/* LDAP can't bind with a blank password. Seen as "anonymous"
	 * and always granted access
	 */
	return 1;
    }
    if (searchfilter) {
