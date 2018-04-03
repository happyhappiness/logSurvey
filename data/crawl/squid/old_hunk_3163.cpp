            }
        } else {
            result = 0;
            fprintf(stderr, "%s NetUserGetGroups() failed.'\n", myname);
        }
    } else {
        fprintf(stderr, "%s Can't find DC for local domain '%s'\n", myname, machinedomain);
    }
    /*
     * Free the allocated memory.
