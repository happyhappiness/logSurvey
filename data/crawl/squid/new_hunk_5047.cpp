		ld = NULL;
		goto recover;
	    }
	    printf("ERR %s\n", ldap_err2string(squid_ldap_errno(ld)));
	} else {
	    printf("OK\n");
	}
