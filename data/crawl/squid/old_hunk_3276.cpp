        if (retval == PAM_SUCCESS && !no_acct_mgmt)
            retval = pam_acct_mgmt(pamh, 0);
        if (retval == PAM_SUCCESS) {
            fprintf(stdout, "OK\n");
        } else {
error:
            fprintf(stdout, "ERR\n");
        }
        /* cleanup */
        retval = PAM_SUCCESS;
