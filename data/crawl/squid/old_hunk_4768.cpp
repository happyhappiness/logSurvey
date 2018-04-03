    }
    origbuf = buf;
    if (ntlmCheckHeader(&auth->hdr, NTLM_AUTHENTICATE)) {

	fprintf(stderr, "ntlmDecodeAuth: header check fails\n");
	return -1;
    }
/* only on when you need to debug
 * fprintf(stderr,"ntlmDecodeAuth: size of %d\n", size);
 * fprintf(stderr,"ntlmDecodeAuth: flg %08x\n", auth->flags);
 * fprintf(stderr,"ntlmDecodeAuth: usr o(%d) l(%d)\n", auth->user.offset, auth->user.len);
 */
    if ((p = ntlmGetString(&auth->hdr, &auth->domain, 2)) == NULL)
	p = authenticate_ntlm_domain;
//      fprintf(stderr,"ntlmDecodeAuth: Domain '%s'.\n",p);
    if ((s = strlen(p) + 1) >= size)
	return 1;
    strcpy(buf, p);
//      fprintf(stdout,"ntlmDecodeAuth: Domain '%s'.\n",buf);

    size -= s;
    buf += (s - 1);
    *buf++ = '\\';		/* Using \ is more consistent with MS-proxy */

    p = ntlmGetString(&auth->hdr, &auth->user, 2);
    if ((s = strlen(p) + 1) >= size)
	return 1;
    while (*p)
	*buf++ = (*p++);	//tolower

    *buf++ = '\0';
    size -= s;
//      fprintf(stderr, "ntlmDecodeAuth: user: %s%s\n",origbuf, p);


    return 0;
}


int
main()
{
    char buf[256];
    char user[256], *p, *cleartext;
    struct ntlm_challenge chal;
    int len;
    char *data = NULL;

    setbuf(stdout, NULL);
    while (fgets(buf, 256, stdin) != NULL) {
	user[0] = '\0';		/*no usercode */

	if ((p = strchr(buf, '\n')) != NULL)
	    *p = '\0';		/* strip \n */
#if defined(NTLMHELPPROTOCOLV3) || !defined(NTLMHELPPROTOCOLV2)
	if (strncasecmp(buf, "YR", 2) == 0) {
	    ntlmMakeChallenge(&chal);
	    len =
		sizeof(chal) - sizeof(chal.pad) +
		le16toh(chal.target.maxlen);
	    data = (char *) base64_encode_bin((char *) &chal, len);
	    printf("TT %s\n", data);
	} else if (strncasecmp(buf, "KK ", 3) == 0) {
	    cleartext = (char *) uudecode(buf + 3);
	    if (!ntlmCheckHeader((ntlmhdr *) cleartext, NTLM_AUTHENTICATE)) {
		if (!ntlmDecodeAuth((struct ntlm_authenticate *) cleartext, user, 256)) {
		    lc(user);
		    printf("AF %s\n", user);
		} else {
		    lc(user);
		    printf("NA invalid credentials%s\n", user);
		}
	    } else {
		lc(user);
		printf("BH wrong packet type!%s\n", user);
	    }
	}
#endif
#ifdef NTLMHELPPROTOCOLV2
/* V2 of the protocol */
	if (strncasecmp(buf, "RESET", 5) == 0) {
	    printf("RESET OK\n");
	} else {
	    cleartext = (char *) uudecode(buf);
	    if (!ntlmCheckHeader((struct ntlmhdr *) cleartext, NTLM_NEGOTIATE)) {
		ntlmMakeChallenge(&chal);
		len =
		    sizeof(chal) - sizeof(chal.pad) +
		    le16toh(chal.target.maxlen);
		data = (char *) base64_encode_bin((char *) &chal, len);
		printf("CH %s\n", data);
	    } else if (!ntlmCheckHeader
		((struct ntlmhdr *) cleartext, NTLM_AUTHENTICATE)) {
		if (!ntlmDecodeAuth
		    ((struct ntlm_authenticate *) cleartext, user, 256)) {
		    lc(user);
		    printf("OK %s\n", user);
		} else {
		    lc(user);
		    printf("ERR %s\n", user);
		}
	    } else {
		lc(user);
		printf("ERR %s\n", user);
	    }
	}
#endif /*v2 */
    }
    exit(0);
}
