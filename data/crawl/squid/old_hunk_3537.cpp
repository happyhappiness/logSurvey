}

int
UFSSwapDir::createDirectory(const char *path, int should_exist)
{
    int created = 0;

    struct stat st;
    getCurrentTime();

    if (0 == ::stat(path, &st)) {
        if (S_ISDIR(st.st_mode)) {
            debugs(47, (should_exist ? 3 : 1), path << " exists");
        } else {
            fatalf("Swap directory %s is not a directory.", path);
        }

#ifdef _SQUID_MSWIN_

    } else if (0 == mkdir(path)) {
#else

    } else if (0 == mkdir(path, 0755)) {
#endif
        debugs(47, (should_exist ? 1 : 3), path << " created");
        created = 1;
    } else {
        fatalf("Failed to make swap directory %s: %s",
               path, xstrerror());
    }

    return created;
}

bool
UFSSwapDir::pathIsDirectory(const char *path)const
{

    struct stat sb;

    if (::stat(path, &sb) < 0) {
        debugs(47, 0, "" << path << ": " << xstrerror());
        return false;
    }

    if (S_ISDIR(sb.st_mode) == 0) {
        debugs(47, 0, "" << path << " is not a directory");
        return false;
    }

