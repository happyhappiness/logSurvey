        }

        if (envp) {
                if (arr2envblk(envp, &envblk) ==FALSE) {
                        pproc->last_err = 0;
                        pproc->lerrno = E_NO_MEM;
                        free( command_line );
                        return(-1);
                }
        }
