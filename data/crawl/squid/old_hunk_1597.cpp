            }
            gss_release_buffer(&min_stat, &status_string);
        }
        fprintf(stderr, "%s failed: %s\n", function, buf);
        return (1);
    }
    return (0);
}

/*
 * Get gssapi token for service HTTP/<server>
 * User has to initiate a kinit user@DOMAIN on commandline first for the
 * function to be successful
 * Returns base64 encoded token if successful
 *         string "ERROR" if unsuccessful
 */
static char *
