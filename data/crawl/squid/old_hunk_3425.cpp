        host_name = gethost_name();
        if (!host_name) {
            fprintf(stderr,
                    "%s| %s: Local hostname could not be determined. Please specify the service principal\n",
                    LogTime(), PROGRAM);
            fprintf(stdout, "BH hostname error\n");
            exit(-1);
