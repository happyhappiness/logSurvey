 		/* copy the challenge to the state data */
 		helperstate = helperStatefulServerGetData(lastserver);
 		if (helperstate == NULL)
-		    fatal("lost NTLm helper state! quitting\n");
+		    fatal("lost NTLM helper state! quitting\n");
 		helperstate->challenge = xstrndup(reply, NTLM_CHALLENGE_SZ + 5);
 		helperstate->challengeuses = 0;
 		helperstate->renewed = squid_curtime;
