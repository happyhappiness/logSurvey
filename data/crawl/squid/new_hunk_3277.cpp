        if (ttl == 0 || retval != PAM_SUCCESS) {
            retval = pam_end(pamh, retval);
            if (retval != PAM_SUCCESS) {
                debug("WARNING: failed to release PAM authenticator\n");
            }
            pamh = NULL;
        }
