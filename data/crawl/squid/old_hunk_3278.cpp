        retval = pam_end(pamh, retval);
        if (retval != PAM_SUCCESS) {
            pamh = NULL;
            fprintf(stderr, "ERROR: failed to release PAM authenticator\n");
        }
    }
    return 0;
