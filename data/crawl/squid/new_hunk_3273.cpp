    }
#endif
    if (!appdata_ptr) {
        debug("ERROR: No password available to password_converstation!\n");
        return PAM_CONV_ERR;
    }
    *resp = static_cast<struct pam_response *>(calloc(num_msg, sizeof(struct pam_response)));
    if (!*resp) {
        debug("ERROR: Out of memory!\n");
        return PAM_CONV_ERR;
    }
    (*resp)[0].resp = xstrdup((char *) appdata_ptr);
