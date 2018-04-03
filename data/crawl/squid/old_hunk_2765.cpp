    if (fp == NULL)
        fatalf("Unable to open configuration file: %s: %s", file_name, xstrerror());

#ifdef _SQUID_WIN32_

    setmode(fileno(fp), O_TEXT);

#endif

    SetConfigFilename(file_name, bool(is_pipe));
