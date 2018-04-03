      if ( rc < 100 || rc > 199 ) {
	if (debug)
	  fprintf(stderr, "%s| %s: Invalid GSS-SPNEGO query [%s]\n", LogTime(), PROGRAM, buf);
	fprintf(stdout, "BH Invalid GSS-SPNEGO query\n");
	goto cleanup;
      } 
      if ((input_token.length >= sizeof ntlmProtocol + 1) &&
	  (!memcmp (input_token.value, ntlmProtocol, sizeof ntlmProtocol))) {
	if (debug)
	  fprintf(stderr, "%s| %s: received type %d NTLM token\n", LogTime(), PROGRAM, (int) *((unsigned char *)input_token.value + sizeof ntlmProtocol));
	fprintf(stdout, "BH received type %d NTLM token\n",(int) *((unsigned char *)input_token.value + sizeof ntlmProtocol));
	goto cleanup;
      } 
      if (debug)
	fprintf(stderr, "%s| %s: Token is possibly a GSSAPI token\n", LogTime(), PROGRAM);
      spnego_flag=0;
    } else {
      gss_release_buffer(&minor_status, &input_token);
