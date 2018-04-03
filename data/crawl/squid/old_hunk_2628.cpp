        fatal("Rock Store db creation error");
    }

    if (ftruncate(swap, maximumSize()) != 0) {
        debugs(47,0, "Failed to initialize Rock Store db in " << filePath <<
            "; truncate error: " << xstrerror());
        fatal("Rock Store db creation error");
