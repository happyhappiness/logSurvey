    }
}

static void
GetPassword (RequestData *requestData)
{
    user_data *u;
    struct stat sb;
    if (stat(passwdfile, &sb) == 0) {
	if (sb.st_mtime != change_time) {
	    read_passwd_file(passwdfile, ha1mode);
	    change_time = sb.st_mtime;
	}
    }
    requestData->password = NULL;
    if (!hash)
	return;
    u = (user_data *)hash_lookup(hash, requestData->user);
    if (u != NULL)
	requestData->password = u->passwd;
}

void
TextHHA1(RequestData *requestData)
{
    GetPassword (requestData);
    if (requestData->password == NULL) {
	requestData->error = -1;
	return;
    }
    if(!ha1mode) {
	HASH HA1;
	DigestCalcHA1("md5", requestData->user, requestData->realm, requestData->password, NULL, NULL, HA1, requestData->HHA1);
	
	/* fprintf(stderr, "digest_pw_auth: %s:{HHA1}%s\n", requestData.user, HHA1); */
    } else
	xstrncpy (requestData->HHA1, &requestData->password[6], sizeof (requestData->HHA1));
}