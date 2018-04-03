        return;

    if (munmap(theMem, theSize)) {
        debugs(54, 5, HERE << "munmap " << theName << ": " << xstrerror());
        fatalf("Ipc::Mem::Segment::detach failed to munmap(%s): %s\n",
               theName.termedBuf(), xstrerror());
    }
    theMem = 0;
}

void
Ipc::Mem::Segment::unlink()
{
    if (shm_unlink(theName.termedBuf()) != 0)
        debugs(54, 5, HERE << "shm_unlink(" << theName << "): " << xstrerror());
    else
        debugs(54, 3, HERE << "unlinked " << theName << " segment");
}

/// determines the size of the underlying "file"
