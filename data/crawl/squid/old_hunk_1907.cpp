            continue;
        user = strtok(buf, ":\n");
        if (!user) {
            fprintf(stderr, "digest_file_auth: missing user name at line %u in '%'\n", lineCount, passwordFile);
            continue;
        }
        realm = strtok(NULL, ":\n");