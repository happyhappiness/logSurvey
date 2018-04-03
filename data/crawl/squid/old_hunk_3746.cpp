
            if (check_gss_err(major_status,minor_status,"gss_display_name()",debug,log) )
                goto cleanup;
            fprintf(stdout, "AF %s %s\n",token,(char *)output_token.value);
            if (debug)
                fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM, token,(char *)output_token.value);
            if (log)
                fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(), PROGRAM, (char *)output_token.value);
            goto cleanup;
        } else {
            if (check_gss_err(major_status,minor_status,"gss_accept_sec_context()",debug,log) )
