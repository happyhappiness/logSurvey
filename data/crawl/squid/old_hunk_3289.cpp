            opt = optopt;
            /* fall thru to default */
        default:
            fprintf(stderr, "Unknown option: -%c. Exiting\n", opt);
            had_error = 1;
        }
    }
    if (had_error) {
        usage();
        exit(1);
    }
}

/* Main program for simple authentication.
   Scans and checks for Squid input, and attempts to validate the user.
*/

int
main(int argc, char **argv)

{
    char wstr[256];
    char username[256];
    char password[256];
    char *p;
