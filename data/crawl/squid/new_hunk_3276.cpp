        if (retval == PAM_SUCCESS && !no_acct_mgmt)
            retval = pam_acct_mgmt(pamh, 0);
        if (retval == PAM_SUCCESS) {
            SEND_OK("");
        } else {
error:
            SEND_ERR("");
        }
        /* cleanup */
        retval = PAM_SUCCESS;
