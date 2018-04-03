void *
Ipc::Mem::Segment::reserve(size_t chunkSize)
{
    // check for overflows
    assert(static_cast<off_t>(chunkSize) >= 0);
    assert(static_cast<off_t>(chunkSize) <= theSize);
    assert(theReserved <= theSize - static_cast<off_t>(chunkSize));
    void *result = reinterpret_cast<char*>(mem()) + theReserved;
    theReserved += chunkSize;
    return result;
}

/// determines the size of the underlying "file"
off_t
Ipc::Mem::Segment::statSize(const char *context) const
{
    Must(theFD >= 0);

    struct stat s;
    memset(&s, 0, sizeof(s));

    if (fstat(theFD, &s) != 0) {
        debugs(54, 5, HERE << "fstat: " << xstrerror());
        String s = context;
        s.append("failed to fstat(2)");
        s.append(theName);
        fatal(s.termedBuf());
    }

    return s.st_size;
}

/// Generate name for shared memory segment. Replaces all slashes with dots.
String
Ipc::Mem::Segment::GenerateName(const char *id)
