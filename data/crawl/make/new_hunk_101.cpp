                        pproc->lerrno = E_NO_MEM;
                        free( command_line );
                        if ((pproc->last_err == ERROR_INVALID_PARAMETER
                             || pproc->last_err == ERROR_MORE_DATA)
                            && envsize_needed > 32*1024) {
                                fprintf (stderr, "CreateProcess failed, probably because environment is too large (%d bytes).\n",
                                         envsize_needed);
