        passwdfile = argv[2];
    }
    if (!passwdfile) {
        fprintf(stderr, "Usage: digest_file_auth [OPTIONS] <passwordfile>\n");
        fprintf(stderr, "  -c   accept digest hashed passwords rather than plaintext in passwordfile\n");
        exit(1);
    }
