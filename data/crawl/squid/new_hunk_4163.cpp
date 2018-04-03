      spnegoToken = output_token.value;
      spnegoTokenLength = output_token.length;
#endif
      token = xmalloc(ska_base64_encode_len(spnegoTokenLength));
      if (token == NULL) {
	if (debug)
	  fprintf(stderr, "%s| %s: Not enough memory\n", LogTime(), PROGRAM);
	fprintf(stdout, "BH Not enough memory\n");
        goto cleanup;
      }

      ska_base64_encode(token,(const char *)spnegoToken,ska_base64_encode_len(spnegoTokenLength),spnegoTokenLength);

      if (check_gss_err(major_status,minor_status,"gss_accept_sec_context()",debug,log) )
	goto cleanup;
      if (major_status & GSS_S_CONTINUE_NEEDED) {
	if (debug)
