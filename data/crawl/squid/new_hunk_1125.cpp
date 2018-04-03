                      smblib_err, smb_errorclass, smb_errorcode, nb_error);
                /* Should I use smblib_err? Actually it seems I can do as well
                 * without it.. */
                if (nb_error != 0) {    /* netbios-level error */
                    SEND("BH NetBios error!");
                    fprintf(stderr, "NetBios error code %d (%s)\n", nb_error,
                            RFCNB_Error_Strings[abs(nb_error)]);
