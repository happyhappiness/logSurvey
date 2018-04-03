        // no need to distinguish ENOENT from other possible stat() errors.
        debugs (47, DBG_IMPORTANT, "Creating Rock db directory: " << path);
        const int res = mkdir(path, 0700);
        if (res != 0)
            createError("mkdir");
    }

    debugs (47, DBG_IMPORTANT, "Creating Rock db: " << filePath);
    const int swap = open(filePath, O_WRONLY|O_CREAT|O_TRUNC|O_BINARY, 0600);
    if (swap < 0)
        createError("create");

#if SLOWLY_FILL_WITH_ZEROS
    char block[1024];
    Must(maxSize() % sizeof(block) == 0);
    memset(block, '\0', sizeof(block));

    for (off_t offset = 0; offset < maxSize(); offset += sizeof(block)) {
        if (write(swap, block, sizeof(block)) != sizeof(block))
            createError("write");
    }
#else
    if (ftruncate(swap, maxSize()) != 0)
        createError("truncate");

    char header[HeaderSize];
    memset(header, '\0', sizeof(header));
    if (write(swap, header, sizeof(header)) != sizeof(header))
        createError("write");
#endif

    close(swap);
}

// report Rock DB creation error and exit
void
Rock::SwapDir::createError(const char *const msg)
{
    debugs(47, DBG_CRITICAL, "ERROR: Failed to initialize Rock Store db in " <<
           filePath << "; " << msg << " error: " << xstrerror());
    fatal("Rock Store db creation error");
}

void