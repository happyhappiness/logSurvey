                debug((char *) "%s| %s: DEBUG: Groups %s\n", LogTime(), PROGRAM, ag);
            }
#endif
            rfc_user = rfc1738_escape(user);
#if HAVE_PAC_SUPPORT
            fprintf(stdout, "AF %s %s %s\n", token, rfc_user, ag?ag:"group=");
#else
            fprintf(stdout, "AF %s %s\n", token, rfc_user);
#endif
            debug((char *) "%s| %s: DEBUG: AF %s %s\n", LogTime(), PROGRAM, token, rfc_user);
            if (log)
                fprintf(stderr, "%s| %s: INFO: User %s authenticated\n", LogTime(),
                        PROGRAM, rfc_user);
            goto cleanup;
        } else {
            if (check_gss_err(major_status, minor_status, "gss_accept_sec_context()", log, 1))
