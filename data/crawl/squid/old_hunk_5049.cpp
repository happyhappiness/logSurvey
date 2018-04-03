
	if (!nispasswd) {
	    /* User does not exist */
	    printf("ERR\n");
	} else if (strcmp(nispasswd, (char *) crypt(passwd, nispasswd)) == 0) {
	    /* All ok !, thanks... */
	    printf("OK\n");
	} else {
	    /* Password incorrect */
	    printf("ERR\n");
	}
    }
    exit(0);
