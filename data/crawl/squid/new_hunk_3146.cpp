            strip_kerberos_realm = 1;
            break;
        default:
            fprintf(stderr, PROGRAM_NAME ": FATAL: Unknown command line option '%c'\n", option);
            exit(1);
        }
    }