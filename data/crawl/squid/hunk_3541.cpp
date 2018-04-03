     setbuf(stdin, NULL);
 
     while (-1 != (opt = getopt(argc, argv, "dirs:h"))) {
-	switch (opt) {
-	case 'd':
-	    debug = 1;
-	    break;
-	case 'i':
-	    log = 1;
-	    break;
-	case 'r':
-	    norealm = 1;
-	    break;
-	case 's':
-	    service_principal = xstrdup(optarg);
-	    break;
-	case 'h':
-	    fprintf(stderr, "Usage: \n");
-	    fprintf(stderr, "squid_kerb_auth [-d] [-i] [-s SPN] [-h]\n");
-	    fprintf(stderr, "-d full debug\n");
-	    fprintf(stderr, "-i informational messages\n");
-	    fprintf(stderr, "-r remove realm from username\n");
-	    fprintf(stderr, "-s service principal name\n");
-	    fprintf(stderr, "-h help\n");
-	    fprintf(stderr,
-		"The SPN can be set to GSS_C_NO_NAME to allow any entry from keytab\n");
-	    fprintf(stderr, "default SPN is HTTP/fqdn@DEFAULT_REALM\n");
-	    exit(0);
-	default:
-	    fprintf(stderr, "%s| %s: unknown option: -%c.\n", LogTime(),
-		PROGRAM, opt);
-	}
+        switch (opt) {
+        case 'd':
+            debug = 1;
+            break;
+        case 'i':
+            log = 1;
+            break;
+        case 'r':
+            norealm = 1;
+            break;
+        case 's':
+            service_principal = xstrdup(optarg);
+            break;
+        case 'h':
+            fprintf(stderr, "Usage: \n");
+            fprintf(stderr, "squid_kerb_auth [-d] [-i] [-s SPN] [-h]\n");
+            fprintf(stderr, "-d full debug\n");
+            fprintf(stderr, "-i informational messages\n");
+            fprintf(stderr, "-r remove realm from username\n");
+            fprintf(stderr, "-s service principal name\n");
+            fprintf(stderr, "-h help\n");
+            fprintf(stderr,
+                    "The SPN can be set to GSS_C_NO_NAME to allow any entry from keytab\n");
+            fprintf(stderr, "default SPN is HTTP/fqdn@DEFAULT_REALM\n");
+            exit(0);
+        default:
+            fprintf(stderr, "%s| %s: unknown option: -%c.\n", LogTime(),
+                    PROGRAM, opt);
+        }
     }
 
     if (debug)
-	fprintf(stderr, "%s| %s: Starting version %s\n", LogTime(), PROGRAM,
-	    SQUID_KERB_AUTH_VERSION);
+        fprintf(stderr, "%s| %s: Starting version %s\n", LogTime(), PROGRAM,
+                SQUID_KERB_AUTH_VERSION);
     if (service_principal && strcasecmp(service_principal, "GSS_C_NO_NAME")) {
-	service.value = service_principal;
-	service.length = strlen((char *) service.value);
+        service.value = service_principal;
+        service.length = strlen((char *) service.value);
     } else {
-	host_name = gethost_name();
-	if (!host_name) {
-	    fprintf(stderr,
-		"%s| %s: Local hostname could not be determined. Please specify the service principal\n",
-		LogTime(), PROGRAM);
-	    fprintf(stdout, "BH hostname error\n");
-	    exit(-1);
-	}
-	service.value = xmalloc(strlen(service_name) + strlen(host_name) + 2);
-	snprintf((char*)service.value, strlen(service_name) + strlen(host_name) + 2,
-	    "%s@%s", service_name, host_name);
-	service.length = strlen((char *) service.value);
+        host_name = gethost_name();
+        if (!host_name) {
+            fprintf(stderr,
+                    "%s| %s: Local hostname could not be determined. Please specify the service principal\n",
+                    LogTime(), PROGRAM);
+            fprintf(stdout, "BH hostname error\n");
+            exit(-1);
+        }
+        service.value = xmalloc(strlen(service_name) + strlen(host_name) + 2);
+        snprintf((char*)service.value, strlen(service_name) + strlen(host_name) + 2,
+                 "%s@%s", service_name, host_name);
+        service.length = strlen((char *) service.value);
     }
 
     while (1) {
-	if (fgets(buf, sizeof(buf) - 1, stdin) == NULL) {
-	    if (ferror(stdin)) {
-		if (debug)
-		    fprintf(stderr,
-			"%s| %s: fgets() failed! dying..... errno=%d (%s)\n",
-			LogTime(), PROGRAM, ferror(stdin),
-			strerror(ferror(stdin)));
-
-		fprintf(stdout, "BH input error\n");
-		exit(1);	/* BIIG buffer */
-	    }
-	    fprintf(stdout, "BH input error\n");
-	    exit(0);
-	}
-
-	c = (char*)memchr(buf, '\n', sizeof(buf) - 1);
-	if (c) {
-	    *c = '\0';
-	    length = c - buf;
-	} else {
-	    err = 1;
-	}
-	if (err) {
-	    if (debug)
-		fprintf(stderr, "%s| %s: Oversized message\n", LogTime(),
-		    PROGRAM);
-	    fprintf(stdout, "BH Oversized message\n");
-	    err = 0;
-	    continue;
-	}
-
-	if (debug)
-	    fprintf(stderr, "%s| %s: Got '%s' from squid (length: %d).\n",
-		LogTime(), PROGRAM, buf, length);
-
-	if (buf[0] == '\0') {
-	    if (debug)
-		fprintf(stderr, "%s| %s: Invalid request\n", LogTime(),
-		    PROGRAM);
-	    fprintf(stdout, "BH Invalid request\n");
-	    continue;
-	}
-
-	if (strlen(buf) < 2) {
-	    if (debug)
-		fprintf(stderr, "%s| %s: Invalid request [%s]\n", LogTime(),
-		    PROGRAM, buf);
-	    fprintf(stdout, "BH Invalid request\n");
-	    continue;
-	}
-
-	if (!strncmp(buf, "QQ", 2)) {
-	    gss_release_buffer(&minor_status, &input_token);
-	    gss_release_buffer(&minor_status, &output_token);
-	    gss_release_buffer(&minor_status, &service);
-	    gss_release_cred(&minor_status, &server_creds);
-	    if (server_name)
-		gss_release_name(&minor_status, &server_name);
-	    if (client_name)
-		gss_release_name(&minor_status, &client_name);
-	    if (gss_context != GSS_C_NO_CONTEXT)
-		gss_delete_sec_context(&minor_status, &gss_context, NULL);
-	    if (kerberosToken) {
-		/* Allocated by parseNegTokenInit, but no matching free function exists.. */
-		if (!spnego_flag)
-		    xfree((char *) kerberosToken);
-		kerberosToken = NULL;
-	    }
-	    if (spnego_flag) {
-		/* Allocated by makeNegTokenTarg, but no matching free function exists.. */
-		if (spnegoToken)
-		    xfree((char *) spnegoToken);
-		spnegoToken = NULL;
-	    }
-	    if (token) {
-		xfree(token);
-		token = NULL;
-	    }
-	    if (host_name) {
-		xfree(host_name);
-		host_name = NULL;
-	    }
-	    fprintf(stdout, "BH quit command\n");
-	    exit(0);
-	}
-
-	if (strncmp(buf, "YR", 2) && strncmp(buf, "KK", 2)) {
-	    if (debug)
-		fprintf(stderr, "%s| %s: Invalid request [%s]\n", LogTime(),
-		    PROGRAM, buf);
-	    fprintf(stdout, "BH Invalid request\n");
-	    continue;
-	}
-	if (!strncmp(buf, "YR", 2)) {
-	    if (gss_context != GSS_C_NO_CONTEXT)
-		gss_delete_sec_context(&minor_status, &gss_context, NULL);
-	    gss_context = GSS_C_NO_CONTEXT;
-	}
-
-	if (strlen(buf) <= 3) {
-	    if (debug)
-		fprintf(stderr, "%s| %s: Invalid negotiate request [%s]\n",
-		    LogTime(), PROGRAM, buf);
-	    fprintf(stdout, "BH Invalid negotiate request\n");
-	    continue;
-	}
-
-	input_token.length = ska_base64_decode_len(buf + 3);
-	if (debug)
-	    fprintf(stderr, "%s| %s: Decode '%s' (decoded length: %d).\n",
-		LogTime(), PROGRAM, buf + 3, (int) input_token.length);
-	input_token.value = xmalloc(input_token.length);
-
-	ska_base64_decode((char*)input_token.value, buf + 3, input_token.length);
+        if (fgets(buf, sizeof(buf) - 1, stdin) == NULL) {
+            if (ferror(stdin)) {
+                if (debug)
+                    fprintf(stderr,
+                            "%s| %s: fgets() failed! dying..... errno=%d (%s)\n",
+                            LogTime(), PROGRAM, ferror(stdin),
+                            strerror(ferror(stdin)));
+
+                fprintf(stdout, "BH input error\n");
+                exit(1);	/* BIIG buffer */
+            }
+            fprintf(stdout, "BH input error\n");
+            exit(0);
+        }
+
+        c = (char*)memchr(buf, '\n', sizeof(buf) - 1);
+        if (c) {
+            *c = '\0';
+            length = c - buf;
+        } else {
+            err = 1;
+        }
+        if (err) {
+            if (debug)
+                fprintf(stderr, "%s| %s: Oversized message\n", LogTime(),
+                        PROGRAM);
+            fprintf(stdout, "BH Oversized message\n");
+            err = 0;
+            continue;
+        }
+
+        if (debug)
+            fprintf(stderr, "%s| %s: Got '%s' from squid (length: %d).\n",
+                    LogTime(), PROGRAM, buf, length);
+
+        if (buf[0] == '\0') {
+            if (debug)
+                fprintf(stderr, "%s| %s: Invalid request\n", LogTime(),
+                        PROGRAM);
+            fprintf(stdout, "BH Invalid request\n");
+            continue;
+        }
+
+        if (strlen(buf) < 2) {
+            if (debug)
+                fprintf(stderr, "%s| %s: Invalid request [%s]\n", LogTime(),
+                        PROGRAM, buf);
+            fprintf(stdout, "BH Invalid request\n");
+            continue;
+        }
+
+        if (!strncmp(buf, "QQ", 2)) {
+            gss_release_buffer(&minor_status, &input_token);
+            gss_release_buffer(&minor_status, &output_token);
+            gss_release_buffer(&minor_status, &service);
+            gss_release_cred(&minor_status, &server_creds);
+            if (server_name)
+                gss_release_name(&minor_status, &server_name);
+            if (client_name)
+                gss_release_name(&minor_status, &client_name);
+            if (gss_context != GSS_C_NO_CONTEXT)
+                gss_delete_sec_context(&minor_status, &gss_context, NULL);
+            if (kerberosToken) {
+                /* Allocated by parseNegTokenInit, but no matching free function exists.. */
+                if (!spnego_flag)
+                    xfree((char *) kerberosToken);
+                kerberosToken = NULL;
+            }
+            if (spnego_flag) {
+                /* Allocated by makeNegTokenTarg, but no matching free function exists.. */
+                if (spnegoToken)
+                    xfree((char *) spnegoToken);
+                spnegoToken = NULL;
+            }
+            if (token) {
+                xfree(token);
+                token = NULL;
+            }
+            if (host_name) {
+                xfree(host_name);
+                host_name = NULL;
+            }
+            fprintf(stdout, "BH quit command\n");
+            exit(0);
+        }
+
+        if (strncmp(buf, "YR", 2) && strncmp(buf, "KK", 2)) {
+            if (debug)
+                fprintf(stderr, "%s| %s: Invalid request [%s]\n", LogTime(),
+                        PROGRAM, buf);
+            fprintf(stdout, "BH Invalid request\n");
+            continue;
+        }
+        if (!strncmp(buf, "YR", 2)) {
+            if (gss_context != GSS_C_NO_CONTEXT)
+                gss_delete_sec_context(&minor_status, &gss_context, NULL);
+            gss_context = GSS_C_NO_CONTEXT;
+        }
+
+        if (strlen(buf) <= 3) {
+            if (debug)
+                fprintf(stderr, "%s| %s: Invalid negotiate request [%s]\n",
+                        LogTime(), PROGRAM, buf);
+            fprintf(stdout, "BH Invalid negotiate request\n");
+            continue;
+        }
+
+        input_token.length = ska_base64_decode_len(buf + 3);
+        if (debug)
+            fprintf(stderr, "%s| %s: Decode '%s' (decoded length: %d).\n",
+                    LogTime(), PROGRAM, buf + 3, (int) input_token.length);
+        input_token.value = xmalloc(input_token.length);
+
+        ska_base64_decode((char*)input_token.value, buf + 3, input_token.length);
 
 
 #if !HAVE_SPNEGO
-	if ((rc = parseNegTokenInit(input_token.value,
-		    input_token.length,
-		    &kerberosToken, &kerberosTokenLength)) != 0) {
-	    if (debug)
-		fprintf(stderr, "%s| %s: parseNegTokenInit failed with rc=%d\n",
-		    LogTime(), PROGRAM, rc);
-
-	    /* if between 100 and 200 it might be a GSSAPI token and not a SPNEGO token */
-	    if (rc < 100 || rc > 199) {
-		if (debug)
-		    fprintf(stderr, "%s| %s: Invalid GSS-SPNEGO query [%s]\n",
-			LogTime(), PROGRAM, buf);
-		fprintf(stdout, "BH Invalid GSS-SPNEGO query\n");
-		goto cleanup;
-	    }
-	    if ((input_token.length >= sizeof ntlmProtocol + 1) &&
-		(!memcmp(input_token.value, ntlmProtocol,
-			sizeof ntlmProtocol))) {
-		if (debug)
-		    fprintf(stderr, "%s| %s: received type %d NTLM token\n",
-			LogTime(), PROGRAM,
-			(int) *((unsigned char *) input_token.value +
-			    sizeof ntlmProtocol));
-		fprintf(stdout, "BH received type %d NTLM token\n",
-		    (int) *((unsigned char *) input_token.value +
-			sizeof ntlmProtocol));
-		goto cleanup;
-	    }
-	    if (debug)
-		fprintf(stderr, "%s| %s: Token is possibly a GSSAPI token\n",
-		    LogTime(), PROGRAM);
-	    spnego_flag = 0;
-	} else {
-	    gss_release_buffer(&minor_status, &input_token);
-	    input_token.length = kerberosTokenLength;
-	    input_token.value = (void *) kerberosToken;
-	    spnego_flag = 1;
-	}
+        if ((rc = parseNegTokenInit(input_token.value,
+                                    input_token.length,
+                                    &kerberosToken, &kerberosTokenLength)) != 0) {
+            if (debug)
+                fprintf(stderr, "%s| %s: parseNegTokenInit failed with rc=%d\n",
+                        LogTime(), PROGRAM, rc);
+
+            /* if between 100 and 200 it might be a GSSAPI token and not a SPNEGO token */
+            if (rc < 100 || rc > 199) {
+                if (debug)
+                    fprintf(stderr, "%s| %s: Invalid GSS-SPNEGO query [%s]\n",
+                            LogTime(), PROGRAM, buf);
+                fprintf(stdout, "BH Invalid GSS-SPNEGO query\n");
+                goto cleanup;
+            }
+            if ((input_token.length >= sizeof ntlmProtocol + 1) &&
+                    (!memcmp(input_token.value, ntlmProtocol,
+                             sizeof ntlmProtocol))) {
+                if (debug)
+                    fprintf(stderr, "%s| %s: received type %d NTLM token\n",
+                            LogTime(), PROGRAM,
+                            (int) *((unsigned char *) input_token.value +
+                                    sizeof ntlmProtocol));
+                fprintf(stdout, "BH received type %d NTLM token\n",
+                        (int) *((unsigned char *) input_token.value +
+                                sizeof ntlmProtocol));
+                goto cleanup;
+            }
+            if (debug)
+                fprintf(stderr, "%s| %s: Token is possibly a GSSAPI token\n",
+                        LogTime(), PROGRAM);
+            spnego_flag = 0;
+        } else {
+            gss_release_buffer(&minor_status, &input_token);
+            input_token.length = kerberosTokenLength;
+            input_token.value = (void *) kerberosToken;
+            spnego_flag = 1;
+        }
 #else
-	if ((input_token.length >= sizeof ntlmProtocol + 1) &&
-	    (!memcmp(input_token.value, ntlmProtocol, sizeof ntlmProtocol))) {
-	    if (debug)
-		fprintf(stderr, "%s| %s: received type %d NTLM token\n",
-		    LogTime(), PROGRAM,
-		    (int) *((unsigned char *) input_token.value +
-			sizeof ntlmProtocol));
-	    fprintf(stdout, "BH received type %d NTLM token\n",
-		(int) *((unsigned char *) input_token.value +
-		    sizeof ntlmProtocol));
-	    goto cleanup;
-	}
+        if ((input_token.length >= sizeof ntlmProtocol + 1) &&
+                (!memcmp(input_token.value, ntlmProtocol, sizeof ntlmProtocol))) {
+            if (debug)
+                fprintf(stderr, "%s| %s: received type %d NTLM token\n",
+                        LogTime(), PROGRAM,
+                        (int) *((unsigned char *) input_token.value +
+                                sizeof ntlmProtocol));
+            fprintf(stdout, "BH received type %d NTLM token\n",
+                    (int) *((unsigned char *) input_token.value +
+                            sizeof ntlmProtocol));
+            goto cleanup;
+        }
 #endif
 
-	if (service_principal) {
-	    if (strcasecmp(service_principal, "GSS_C_NO_NAME")) {
-		major_status = gss_import_name(&minor_status, &service,
-		    (gss_OID) GSS_C_NULL_OID, &server_name);
-
-	    } else {
-		server_name = GSS_C_NO_NAME;
-		major_status = GSS_S_COMPLETE;
-	    }
-	} else {
-	    major_status = gss_import_name(&minor_status, &service,
-		gss_nt_service_name, &server_name);
-	}
-
-	if (check_gss_err(major_status, minor_status, "gss_import_name()",
-		debug, log))
-	    goto cleanup;
-
-	major_status =
-	    gss_acquire_cred(&minor_status, server_name, GSS_C_INDEFINITE,
-	    GSS_C_NO_OID_SET, GSS_C_ACCEPT, &server_creds, NULL, NULL);
-	if (check_gss_err(major_status, minor_status, "gss_acquire_cred()",
-		debug, log))
-	    goto cleanup;
-
-	major_status = gss_accept_sec_context(&minor_status,
-	    &gss_context,
-	    server_creds,
-	    &input_token,
-	    GSS_C_NO_CHANNEL_BINDINGS,
-	    &client_name, NULL, &output_token, &ret_flags, NULL, NULL);
-
-
-	if (output_token.length) {
+        if (service_principal) {
+            if (strcasecmp(service_principal, "GSS_C_NO_NAME")) {
+                major_status = gss_import_name(&minor_status, &service,
+                                               (gss_OID) GSS_C_NULL_OID, &server_name);
+
+            } else {
+                server_name = GSS_C_NO_NAME;
+                major_status = GSS_S_COMPLETE;
+            }
+        } else {
+            major_status = gss_import_name(&minor_status, &service,
+                                           gss_nt_service_name, &server_name);
+        }
+
+        if (check_gss_err(major_status, minor_status, "gss_import_name()",
+                          debug, log))
+            goto cleanup;
+
+        major_status =
+            gss_acquire_cred(&minor_status, server_name, GSS_C_INDEFINITE,
+                             GSS_C_NO_OID_SET, GSS_C_ACCEPT, &server_creds, NULL, NULL);
+        if (check_gss_err(major_status, minor_status, "gss_acquire_cred()",
+                          debug, log))
+            goto cleanup;
+
+        major_status = gss_accept_sec_context(&minor_status,
+                                              &gss_context,
+                                              server_creds,
+                                              &input_token,
+                                              GSS_C_NO_CHANNEL_BINDINGS,
+                                              &client_name, NULL, &output_token, &ret_flags, NULL, NULL);
+
+
+        if (output_token.length) {
 #if !HAVE_SPNEGO
-	    if (spnego_flag) {
-		if ((rc = makeNegTokenTarg(output_token.value,
-			    output_token.length,
-			    &spnegoToken, &spnegoTokenLength)) != 0) {
-		    if (debug)
-			fprintf(stderr,
-			    "%s| %s: makeNegTokenTarg failed with rc=%d\n",
-			    LogTime(), PROGRAM, rc);
-		    fprintf(stdout, "BH makeNegTokenTarg failed with rc=%d\n",
-			rc);
-		    goto cleanup;
-		}
-	    } else {
-		spnegoToken = output_token.value;
-		spnegoTokenLength = output_token.length;
-	    }
+            if (spnego_flag) {
+                if ((rc = makeNegTokenTarg(output_token.value,
+                                           output_token.length,
+                                           &spnegoToken, &spnegoTokenLength)) != 0) {
+                    if (debug)
+                        fprintf(stderr,
+                                "%s| %s: makeNegTokenTarg failed with rc=%d\n",
+                                LogTime(), PROGRAM, rc);
+                    fprintf(stdout, "BH makeNegTokenTarg failed with rc=%d\n",
+                            rc);
+                    goto cleanup;
+                }
+            } else {
+                spnegoToken = output_token.value;
+                spnegoTokenLength = output_token.length;
+            }
 #else
-	    spnegoToken = (unsigned char *)output_token.value;
-	    spnegoTokenLength = output_token.length;
+            spnegoToken = (unsigned char *)output_token.value;
+            spnegoTokenLength = output_token.length;
 #endif
-	    token = (char*)xmalloc(ska_base64_encode_len(spnegoTokenLength));
-	    if (token == NULL) {
-		if (debug)
-		    fprintf(stderr, "%s| %s: Not enough memory\n", LogTime(),
-			PROGRAM);
-		fprintf(stdout, "BH Not enough memory\n");
-		goto cleanup;
-	    }
-
-	    ska_base64_encode(token, (const char *) spnegoToken,
-		ska_base64_encode_len(spnegoTokenLength), spnegoTokenLength);
-
-	    if (check_gss_err(major_status, minor_status,
-		    "gss_accept_sec_context()", debug, log))
-		goto cleanup;
-	    if (major_status & GSS_S_CONTINUE_NEEDED) {
-		if (debug)
-		    fprintf(stderr, "%s| %s: continuation needed\n", LogTime(),
-			PROGRAM);
-		fprintf(stdout, "TT %s\n", token);
-		goto cleanup;
-	    }
-	    gss_release_buffer(&minor_status, &output_token);
-	    major_status =
-		gss_display_name(&minor_status, client_name, &output_token,
-		NULL);
-
-	    if (check_gss_err(major_status, minor_status, "gss_display_name()",
-		    debug, log))
-		goto cleanup;
-	    user = (char*)xmalloc(output_token.length + 1);
-	    if (user == NULL) {
-		if (debug)
-		    fprintf(stderr, "%s| %s: Not enough memory\n", LogTime(),
-			PROGRAM);
-		fprintf(stdout, "BH Not enough memory\n");
-		goto cleanup;
-	    }
-	    memcpy(user, output_token.value, output_token.length);
-	    user[output_token.length] = '\0';
-	    if (norealm && (p = strchr(user, '@')) != NULL) {
-		*p = '\0';
-	    }
-	    fprintf(stdout, "AF %s %s\n", token, user);
-	    if (debug)
-		fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM, token,
-		    user);
-	    if (log)
-		fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(),
-		    PROGRAM, user);
-	    goto cleanup;
-	} else {
-	    if (check_gss_err(major_status, minor_status,
-		    "gss_accept_sec_context()", debug, log))
-		goto cleanup;
-	    if (major_status & GSS_S_CONTINUE_NEEDED) {
-		if (debug)
-		    fprintf(stderr, "%s| %s: continuation needed\n", LogTime(),
-			PROGRAM);
-		fprintf(stdout, "NA %s\n", token);
-		goto cleanup;
-	    }
-	    gss_release_buffer(&minor_status, &output_token);
-	    major_status =
-		gss_display_name(&minor_status, client_name, &output_token,
-		NULL);
-
-	    if (check_gss_err(major_status, minor_status, "gss_display_name()",
-		    debug, log))
-		goto cleanup;
-	    /*
-	     *  Return dummy token AA. May need an extra return tag then AF
-	     */
-	    user = (char*)xmalloc(output_token.length + 1);
-	    if (user == NULL) {
-		if (debug)
-		    fprintf(stderr, "%s| %s: Not enough memory\n", LogTime(),
-			PROGRAM);
-		fprintf(stdout, "BH Not enough memory\n");
-		goto cleanup;
-	    }
-	    memcpy(user, output_token.value, output_token.length);
-	    user[output_token.length] = '\0';
-	    if (norealm && (p = strchr(user, '@')) != NULL) {
-		*p = '\0';
-	    }
-	    fprintf(stdout, "AF %s %s\n", "AA==", user);
-	    if (debug)
-		fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM,
-		    "AA==", user);
-	    if (log)
-		fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(),
-		    PROGRAM, user);
-
-	}
-      cleanup:
-	gss_release_buffer(&minor_status, &input_token);
-	gss_release_buffer(&minor_status, &output_token);
-	gss_release_cred(&minor_status, &server_creds);
-	if (server_name)
-	    gss_release_name(&minor_status, &server_name);
-	if (client_name)
-	    gss_release_name(&minor_status, &client_name);
-	if (kerberosToken) {
-	    /* Allocated by parseNegTokenInit, but no matching free function exists.. */
-	    if (!spnego_flag)
-		xfree((char *) kerberosToken);
-	    kerberosToken = NULL;
-	}
-	if (spnego_flag) {
-	    /* Allocated by makeNegTokenTarg, but no matching free function exists.. */
-	    if (spnegoToken)
-		xfree((char *) spnegoToken);
-	    spnegoToken = NULL;
-	}
-	if (token) {
-	    xfree(token);
-	    token = NULL;
-	}
-	if (user) {
-	    xfree(user);
-	    user = NULL;
-	}
-	continue;
+            token = (char*)xmalloc(ska_base64_encode_len(spnegoTokenLength));
+            if (token == NULL) {
+                if (debug)
+                    fprintf(stderr, "%s| %s: Not enough memory\n", LogTime(),
+                            PROGRAM);
+                fprintf(stdout, "BH Not enough memory\n");
+                goto cleanup;
+            }
+
+            ska_base64_encode(token, (const char *) spnegoToken,
+                              ska_base64_encode_len(spnegoTokenLength), spnegoTokenLength);
+
+            if (check_gss_err(major_status, minor_status,
+                              "gss_accept_sec_context()", debug, log))
+                goto cleanup;
+            if (major_status & GSS_S_CONTINUE_NEEDED) {
+                if (debug)
+                    fprintf(stderr, "%s| %s: continuation needed\n", LogTime(),
+                            PROGRAM);
+                fprintf(stdout, "TT %s\n", token);
+                goto cleanup;
+            }
+            gss_release_buffer(&minor_status, &output_token);
+            major_status =
+                gss_display_name(&minor_status, client_name, &output_token,
+                                 NULL);
+
+            if (check_gss_err(major_status, minor_status, "gss_display_name()",
+                              debug, log))
+                goto cleanup;
+            user = (char*)xmalloc(output_token.length + 1);
+            if (user == NULL) {
+                if (debug)
+                    fprintf(stderr, "%s| %s: Not enough memory\n", LogTime(),
+                            PROGRAM);
+                fprintf(stdout, "BH Not enough memory\n");
+                goto cleanup;
+            }
+            memcpy(user, output_token.value, output_token.length);
+            user[output_token.length] = '\0';
+            if (norealm && (p = strchr(user, '@')) != NULL) {
+                *p = '\0';
+            }
+            fprintf(stdout, "AF %s %s\n", token, user);
+            if (debug)
+                fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM, token,
+                        user);
+            if (log)
+                fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(),
+                        PROGRAM, user);
+            goto cleanup;
+        } else {
+            if (check_gss_err(major_status, minor_status,
+                              "gss_accept_sec_context()", debug, log))
+                goto cleanup;
+            if (major_status & GSS_S_CONTINUE_NEEDED) {
+                if (debug)
+                    fprintf(stderr, "%s| %s: continuation needed\n", LogTime(),
+                            PROGRAM);
+                fprintf(stdout, "NA %s\n", token);
+                goto cleanup;
+            }
+            gss_release_buffer(&minor_status, &output_token);
+            major_status =
+                gss_display_name(&minor_status, client_name, &output_token,
+                                 NULL);
+
+            if (check_gss_err(major_status, minor_status, "gss_display_name()",
+                              debug, log))
+                goto cleanup;
+            /*
+             *  Return dummy token AA. May need an extra return tag then AF
+             */
+            user = (char*)xmalloc(output_token.length + 1);
+            if (user == NULL) {
+                if (debug)
+                    fprintf(stderr, "%s| %s: Not enough memory\n", LogTime(),
+                            PROGRAM);
+                fprintf(stdout, "BH Not enough memory\n");
+                goto cleanup;
+            }
+            memcpy(user, output_token.value, output_token.length);
+            user[output_token.length] = '\0';
+            if (norealm && (p = strchr(user, '@')) != NULL) {
+                *p = '\0';
+            }
+            fprintf(stdout, "AF %s %s\n", "AA==", user);
+            if (debug)
+                fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM,
+                        "AA==", user);
+            if (log)
+                fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(),
+                        PROGRAM, user);
+
+        }
+cleanup:
+        gss_release_buffer(&minor_status, &input_token);
+        gss_release_buffer(&minor_status, &output_token);
+        gss_release_cred(&minor_status, &server_creds);
+        if (server_name)
+            gss_release_name(&minor_status, &server_name);
+        if (client_name)
+            gss_release_name(&minor_status, &client_name);
+        if (kerberosToken) {
+            /* Allocated by parseNegTokenInit, but no matching free function exists.. */
+            if (!spnego_flag)
+                xfree((char *) kerberosToken);
+            kerberosToken = NULL;
+        }
+        if (spnego_flag) {
+            /* Allocated by makeNegTokenTarg, but no matching free function exists.. */
+            if (spnegoToken)
+                xfree((char *) spnegoToken);
+            spnegoToken = NULL;
+        }
+        if (token) {
+            xfree(token);
+            token = NULL;
+        }
+        if (user) {
+            xfree(user);
+            user = NULL;
+        }
+        continue;
     }
 }
 #else
