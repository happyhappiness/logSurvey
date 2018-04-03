requirePathnameExists(const char *name, const char *path)
{
    struct stat sb;
    assert(path != NULL);
    if (stat(path, &sb) < 0)
	fatalf("%s: %s", path, xstrerror());
}

char *