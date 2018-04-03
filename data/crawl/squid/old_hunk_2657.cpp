void *
Ipc::Mem::Segment::reserve(size_t chunkSize)
{
    assert(chunkSize <= theSize);
    assert(theReserved <= theSize - chunkSize);
    void *result = reinterpret_cast<char*>(mem()) + theReserved;
    theReserved += chunkSize;
    return result;
}

/// Generate name for shared memory segment. Replaces all slashes with dots.
String
Ipc::Mem::Segment::GenerateName(const char *id)
