 	    printf("TT %s\n", data);
 	} else if (strncasecmp(buf, "KK ", 3) == 0) {
 	    cleartext = (char *) uudecode(buf + 3);
-	    if (!ntlmCheckHeader((struct ntlmhdr *) cleartext, NTLM_AUTHENTICATE)) {
+	    if (!ntlmCheckHeader((ntlmhdr *) cleartext, NTLM_AUTHENTICATE)) {
 		if (!ntlmDecodeAuth((struct ntlm_authenticate *) cleartext, user, 256)) {
 		    lc(user);
 		    printf("AF %s\n", user);
