		    fprintf(stderr, PROGRAM_NAME ": WARNING, SSL error %d (%s)\n", sslerr, ldapssl_err2string(sslerr));
		}
#endif
		ldap_msgfree(res);
		return 1;
	    }
	}
	entry = ldap_first_entry(ld, res);
	if (!entry) {
	    ldap_msgfree(res);
	    return 1;
	}
	userdn = ldap_get_dn(ld, entry);
	if (!userdn) {
	    fprintf(stderr, PROGRAM_NAME ": ERROR, could not get user DN for '%s'\n", userid);
	    ldap_msgfree(res);
	    return 1;
	}
	snprintf(dn, sizeof(dn), "%s", userdn);
	squid_ldap_memfree(userdn);
	ldap_msgfree(res);
    } else {
	snprintf(dn, sizeof(dn), "%s=%s,%s", userattr, userid, basedn);
    }

    if (debug)
	fprintf(stderr, "attempting to bind to user '%s'\n", dn);
    if (ldap_simple_bind_s(ld, dn, password) != LDAP_SUCCESS)
	return 1;

    return 0;
}

int readSecret(const char *filename)
{
  char  buf[BUFSIZ];
  char  *e = NULL;
  FILE  *f;
  char  *passwd = NULL;

  if(!(f=fopen(filename, "r"))) {
    fprintf(stderr, PROGRAM_NAME " ERROR: Can not read secret file %s\n", filename);
    return 1;
  }

  if( !fgets(buf, sizeof(buf)-1, f)) {
    fprintf(stderr, PROGRAM_NAME " ERROR: Secret file %s is empty\n", filename);
    fclose(f);
    return 1;
  }

  /* strip whitespaces on end */
  if((e = strrchr(buf, '\n'))) *e = 0;
  if((e = strrchr(buf, '\r'))) *e = 0;

  passwd = (char *) calloc(sizeof(char), strlen(buf)+1);
  if (!passwd) {
    fprintf(stderr, PROGRAM_NAME " ERROR: can not allocate memory\n"); 
    exit(1);
  }
  strcpy(passwd, buf);
  bindpasswd = passwd;

  fclose(f);

  return 0;
}
