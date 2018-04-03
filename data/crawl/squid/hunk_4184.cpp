       major_status = gss_display_name(&minor_status, client_name, &output_token,
 				      NULL);
 
-      if (check_gss_err(major_status,minor_status,"gss_display_name()",debug,loging) )
+      if (check_gss_err(major_status,minor_status,"gss_display_name()",debug,log) )
 	goto cleanup;
       fprintf(stdout, "AF %s %s\n",token,(char *)output_token.value);
       if (debug)
 	fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM, token,(char *)output_token.value); 
-      if (loging)
+      if (log)
 	fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(), PROGRAM, (char *)output_token.value);
       goto cleanup;
     } else {
-      if (check_gss_err(major_status,minor_status,"gss_accept_sec_context()",debug,loging) )
+      if (check_gss_err(major_status,minor_status,"gss_accept_sec_context()",debug,log) )
 	goto cleanup;
       if (major_status & GSS_S_CONTINUE_NEEDED) {
 	if (debug)
 	  fprintf(stderr, "%s| %s: continuation needed\n", LogTime(), PROGRAM);
-	fprintf(stdout, "NA No token to return to continue\n");
+	fprintf(stdout, "NA %s\n",token);
 	goto cleanup;
       }
       gss_release_buffer(&minor_status, &output_token);
       major_status = gss_display_name(&minor_status, client_name, &output_token,
 				      NULL);
 
-      if (check_gss_err(major_status,minor_status,"gss_display_name()",debug,loging) )
+      if (check_gss_err(major_status,minor_status,"gss_display_name()",debug,log) )
 	goto cleanup;
       /* 
        *  Return dummy token AA. May need an extra return tag then AF
        */
       fprintf(stdout, "AF %s %s\n","AA==",(char *)output_token.value);
       if (debug)
 	fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM, "AA==", (char *)output_token.value);
-      if (loging)
+      if (log)
 	fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(), PROGRAM, (char *)output_token.value);
 
 cleanup:
       gss_release_buffer(&minor_status, &input_token);
       gss_release_buffer(&minor_status, &output_token);
       gss_release_cred(&minor_status, &server_creds);
-      gss_release_cred(&minor_status, &delegated_cred);
-      gss_release_name(&minor_status, &server_name);
-      gss_release_name(&minor_status, &client_name);
+      if (server_name)
+        gss_release_name(&minor_status, &server_name);
+      if (client_name)
+        gss_release_name(&minor_status, &client_name);
       if (kerberosToken) {
 	/* Allocated by parseNegTokenInit, but no matching free function exists.. */
 	if (!spnego_flag)
-           free((char *)kerberosToken);
+           xfree((char *)kerberosToken);
       	kerberosToken=NULL;
       }
       if (spnego_flag) {
 	/* Allocated by makeNegTokenTarg, but no matching free function exists.. */
         if (spnegoToken)
-	  free((char *)spnegoToken);
+	  xfree((char *)spnegoToken);
       	spnegoToken=NULL;
       }
       if (token) {
-        free(token);
+        xfree(token);
       	token=NULL;
       }
       continue;            
