void
Rock::SwapDir::ioCompletedNotification()
{
    if (!theFile) {
        debugs(47, 1, HERE << filePath << ": initialization failure or " <<
            "premature close of rock db file");
        fatalf("Rock cache_dir failed to initialize db file: %s", filePath);
    }

    if (theFile->error()) {
        debugs(47, 1, HERE << filePath << ": " << xstrerror());
        fatalf("Rock cache_dir failed to open db file: %s", filePath);
	}

    // TODO: lower debugging level
    debugs(47,1, "Rock cache_dir[" << index << "] limits: " << 
        std::setw(12) << maxSize() << " disk bytes and " <<
        std::setw(7) << map->entryLimit() << " entries");

