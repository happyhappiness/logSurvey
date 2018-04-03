            /* Create PAM connection */
            retval = pam_start(service, user, &conv, &pamh);
            if (retval != PAM_SUCCESS) {
                debug("ERROR: failed to create PAM authenticator\n");
                goto error;
            }
        } else if (!pamh || (time(NULL) - pamh_created) >= ttl || pamh_created > time(NULL)) {
            /* Close previous PAM connection */
            if (pamh) {
                retval = pam_end(pamh, retval);
                if (retval != PAM_SUCCESS) {
                    debug("WARNING: failed to release PAM authenticator\n");
                }
                pamh = NULL;
            }
            /* Initialize persistent PAM connection */
            retval = pam_start(service, "squid@", &conv, &pamh);
            if (retval != PAM_SUCCESS) {
                debug("ERROR: failed to create PAM authenticator\n");
                goto error;
            }
            pamh_created = time(NULL);
