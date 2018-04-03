            opt = optopt;
            /* fall thru to default */
        default:
            fprintf(stderr, "FATAL: Unknown option: -%c\n", opt);
            usage();
            exit(1);
        }
    }
}

/* Main program for simple authentication.
   Scans and checks for Squid input, and attempts to validate the user.
*/
int
main(int argc, char **argv)
{
    char wstr[HELPER_INPUT_BUFFER];
    char username[256];
    char password[256];
    char *p;
