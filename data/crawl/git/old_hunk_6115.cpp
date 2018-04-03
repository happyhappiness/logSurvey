------------------------------------------------------------------
        git_config(git_default_config);
        if (argc != 3)
                usage("git-cat-file [-t|-s|-e|-p|<type>] <sha1>");
        if (get_sha1(argv[2], sha1))
                die("Not a valid object name %s", argv[2]);
------------------------------------------------------------------
