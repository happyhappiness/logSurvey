            if (norealm && (p = strchr(user, '@')) != NULL) {
                *p = '\0';
            }
            rfc_user = rfc1738_escape(user);
#if HAVE_PAC_SUPPORT
            fprintf(stdout, "AF %s %s %s\n", "AA==", rfc_user, ag?ag:"group=");
#else
            fprintf(stdout, "AF %s %s\n", "AA==", rfc_user);
#endif
	    debug((char *) "%s| %s: DEBUG: AF %s %s\n", LogTime(), PROGRAM, "AA==", rfc_user);
            if (log)
                fprintf(stderr, "%s| %s: INFO: User %s authenticated\n", LogTime(),
                        PROGRAM, rfc_user);
        }
cleanup:
        gss_release_buffer(&minor_status, &input_token);
