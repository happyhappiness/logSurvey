	    printf("ERR\n");
	    continue;
	}
	res = get_nis_password(user, nispasswd, nisdomain, nismap);

	if (res) {
	    /* User does not exist */
	    printf("ERR\n");
	} else if (strcmp(nispasswd, (char *) crypt(passwd, nispasswd))) {
	    /* Password incorrect */
	    printf("ERR\n");
	} else {
	    /* All ok !, thanks... */
	    printf("OK\n");
	}
    }
    exit(0);