    setbuf(stdin, NULL);

    if (!proxy) {
        fprintf(stderr, "%s| %s: Error: No proxy server name\n", LogTime(),
                PROGRAM);
        return NULL;
    }
    service.value = xmalloc(strlen("HTTP") + strlen(proxy) + 2);
    snprintf((char *) service.value, strlen("HTTP") + strlen(proxy) + 2, "%s@%s", "HTTP", proxy);
    service.length = strlen((char *) service.value);

    major_status = gss_import_name(&minor_status, &service,
                                   gss_nt_service_name, &server_name);

    if (check_gss_err(major_status, minor_status, "gss_import_name()"))
        goto cleanup;

    major_status = gss_init_sec_context(&minor_status,
                                        GSS_C_NO_CREDENTIAL, &gss_context, server_name,
                                        gss_mech_spnego,
                                        0,
                                        0,
                                        GSS_C_NO_CHANNEL_BINDINGS,
                                        &input_token, NULL, &output_token, NULL, NULL);

    if (check_gss_err(major_status, minor_status, "gss_init_sec_context()"))
        goto cleanup;

    if (output_token.length) {
        token = (char *) xmalloc(ska_base64_encode_len(output_token.length));
        ska_base64_encode(token, (const char *) output_token.value,
                          ska_base64_encode_len(output_token.length), output_token.length);
    }
cleanup:
    gss_delete_sec_context(&minor_status, &gss_context, NULL);
    gss_release_buffer(&minor_status, &service);
    gss_release_buffer(&minor_status, &input_token);
