      gss_release_buffer(&minor_status, &output_token);
      gss_release_buffer(&minor_status, &service);
      gss_release_cred(&minor_status, &server_creds);
      gss_release_cred(&minor_status, &delegated_cred);
      gss_release_name(&minor_status, &server_name);
      gss_release_name(&minor_status, &client_name);
      gss_delete_sec_context(&minor_status, &gss_context, NULL);
      if (kerberosToken) {
	/* Allocated by parseNegTokenInit, but no matching free function exists.. */
        if (!spnego_flag)
          free((char *)kerberosToken);
        kerberosToken=NULL;
      }
      if (spnego_flag) {
	/* Allocated by makeNegTokenTarg, but no matching free function exists.. */
        if (spnegoToken) 
	  free((char *)spnegoToken);
      	spnegoToken=NULL;
      }
      if (token) {
        free(token);
        token=NULL;
      }
      if (host_name) {
        free(host_name);
        host_name=NULL;
      }
      exit(0);
    }

    if ( !strncmp(buf, "YR", 2) && !strncmp(buf, "KK", 2) ) {
      if (debug)
	fprintf(stderr, "%s| %s: Invalid request [%s]\n", LogTime(), PROGRAM, buf);
      fprintf(stdout, "NA Invalid request\n");
      continue;
    }
    if ( !strncmp(buf, "YR", 2) ){
