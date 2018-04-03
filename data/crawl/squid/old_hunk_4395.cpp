    }

    if (fp == NULL)
        fatalf("Unable to open configuration file: %s: %s",
               file_name, xstrerror());

#ifdef _SQUID_WIN32_

