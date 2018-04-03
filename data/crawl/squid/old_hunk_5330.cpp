	if (u == NULL) {
	    printf("ERR\n");
	} else {
	    DigestCalcHA1("md5", user, realm, u->passwd, NULL, NULL, HA1, HHA1);
	    printf("%s\n", HHA1);
	}
    }
    exit(0);
