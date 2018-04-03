	}
	entry = ldap_first_entry(search_ld, res);
	if (!entry) {
	    ret = 1;
	    goto search_done;
	}
