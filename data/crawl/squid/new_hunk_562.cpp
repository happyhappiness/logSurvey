            fprintf(stderr, "server - In this case server can be used for all Kerberos domains\n");
            fprintf(stderr, "server@  - In this case server can be used for all Kerberos domains\n");
            fprintf(stderr, "server@domain  - In this case server can be used for Kerberos domain domain\n");
            fprintf(stderr, "server1a@domain1:server1b@domain1:server2@domain2:server3@:server4 - A list is build with a colon as separator\n");
            clean_args(&margs);
            exit(0);
        default:
