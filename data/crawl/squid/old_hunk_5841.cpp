	}
	ldap_unbind(ld);
    }
}



int
checkLDAP(LDAP * ld, char *userid, char *password)
{
    char str[256];

    /*sprintf(str,"uid=[%s][%s], %s",userid, password, SEARCHBASE); */
    sprintf(str, "uid=%s, %s", userid, SEARCHBASE);

    if (ldap_simple_bind_s(ld, str, password) != LDAP_SUCCESS) {
	/*fprintf(stderr, "\nUnable to bind\n"); */
	return 33;
    }
    return 0;
}