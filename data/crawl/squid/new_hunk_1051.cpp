
        // default: 64KB
        if (log->bufferSize != 64*1024)
            storeAppendPrintf(entry, " buffer-size=%" PRIuSIZE, log->bufferSize);

        if (log->rotateCount >= 0)
            storeAppendPrintf(entry, " rotate=%d", log->rotateCount);