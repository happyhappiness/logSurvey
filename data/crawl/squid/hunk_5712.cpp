 	    ntlm_request = auth_user_request->scheme_data;
 	    switch (ntlm_request->auth_state) {
 	    case AUTHENTICATE_STATE_NONE:
+	    case AUTHENTICATE_STATE_FAILED:
 		debug(29, 9) ("authenticateNTLMFixErrorHeader: Sending type:%d header: 'NTLM'\n", type);
 		httpHeaderPutStrf(&rep->header, type, "NTLM");
 		/* drop the connection */
