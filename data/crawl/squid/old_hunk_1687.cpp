            if (kerberosToken) {
                /* Allocated by parseNegTokenInit, but no matching free function exists.. */
                if (!spnego_flag)
                    xfree((char *) kerberosToken);
                kerberosToken = NULL;
            }
            if (spnego_flag) {
                /* Allocated by makeNegTokenTarg, but no matching free function exists.. */
                if (spnegoToken)
                    xfree((char *) spnegoToken);
                spnegoToken = NULL;
            }
            if (token) {
                xfree(token);
                token = NULL;
            }
            if (host_name) {
                xfree(host_name);
                host_name = NULL;
            }
            fprintf(stdout, "BH quit command\n");
            exit(0);
        }
