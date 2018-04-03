        ret = logfile_mod_syslog_open(lf, patharg, bufsz, fatal_flag);
#endif
    } else {
        ret = logfile_mod_stdio_open(lf, patharg, bufsz, fatal_flag);
    }
    if (!ret) {
        if (fatal_flag)
            fatalf("logfileOpen: path %s: couldn't open!\n", path);
        else
            debugs(50, 1, "logfileOpen: path " << path << ": couldn't open!");
        lf->f_close(lf);
        cbdataFree(lf);
        return NULL;
