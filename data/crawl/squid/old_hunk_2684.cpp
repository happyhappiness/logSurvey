    void *const p =
        mmap(NULL, theSize, PROT_READ | PROT_WRITE, MAP_SHARED, theFD, 0);
    if (p == MAP_FAILED) {
        debugs(54, 5, "SharedMemory::mmap: mmap: " << xstrerror());
        fatal("SharedMemory::mmap failed");
    }
    theMem = p;
}

/// Unmap the shared memory segment from the process memory space.
void
SharedMemory::detach()
{
    if (!theMem)
        return;

    if (munmap(theMem, theSize)) {
        debugs(54, 5, "SharedMemory::munmap: munmap: " << xstrerror());
        fatal("SharedMemory::munmap failed");
    }
    theMem = 0;
}

/// Generate name for shared memory segment. Replaces all slashes with dots.
String
SharedMemory::GenerateName(const char *id)
{
    String name("/squid-");
    for (const char *slash = strchr(id, '/'); slash; slash = strchr(id, '/')) {
