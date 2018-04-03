        return;

    if (munmap(theMem, theSize)) {
        int xerrno = errno;
        debugs(54, 5, "munmap " << theName << ": " << xstrerr(xerrno));
        fatalf("Ipc::Mem::Segment::detach failed to munmap(%s): %s\n",
               theName.termedBuf(), xstrerr(xerrno));
    }
    theMem = 0;
}

/// Lock the segment into RAM, ensuring that the OS has enough RAM for it [now]
/// and preventing segment bytes from being swapped out to disk later by the OS.
void
Ipc::Mem::Segment::lock()
{
    if (!Config.shmLocking) {
        debugs(54, 5, "mlock(2)-ing disabled");
        return;
    }

#if defined(_POSIX_MEMLOCK_RANGE)
    debugs(54, 7, "mlock(" << theName << ',' << theSize << ") starts");
    if (mlock(theMem, theSize) != 0) {
        const int savedError = errno;
        fatalf("shared_memory_locking on but failed to mlock(%s, %" PRId64 "): %s\n",
               theName.termedBuf(),static_cast<int64_t>(theSize), xstrerr(savedError));
    }
    // TODO: Warn if it took too long.
    debugs(54, 7, "mlock(" << theName << ',' << theSize << ") OK");
#else
    debugs(54, 5, "insufficient mlock(2) support");
    if (Config.shmLocking.configured()) { // set explicitly
        static bool warnedOnce = false;
        if (!warnedOnce) {
            debugs(54, DBG_IMPORTANT, "ERROR: insufficient mlock(2) support prevents " <<
                   "honoring `shared_memory_locking on`. " <<
                   "If you lack RAM, kernel will kill Squid later.");
            warnedOnce = true;
        }
    }
#endif
}

void
Ipc::Mem::Segment::unlink()
{
    if (shm_unlink(theName.termedBuf()) != 0) {
        int xerrno = errno;
        debugs(54, 5, "shm_unlink(" << theName << "): " << xstrerr(xerrno));
    } else
        debugs(54, 3, "unlinked " << theName << " segment");
}

/// determines the size of the underlying "file"
