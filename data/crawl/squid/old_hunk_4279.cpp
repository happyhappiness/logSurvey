    if (Config.EmailFrom)
        fprintf(fp, "From: %s\n", Config.EmailFrom);
    else
        fprintf(fp, "From: %s@%s\n", appname, uniqueHostname());

    fprintf(fp, "To: %s\n", Config.adminEmail);

