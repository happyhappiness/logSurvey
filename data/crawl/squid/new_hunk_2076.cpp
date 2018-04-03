}

int
Fs::Ufs::UFSSwapDir::callback()
{
    return IO->callback();
}

void
Fs::Ufs::UFSSwapDir::sync()
{
    IO->sync();
}

void
Fs::Ufs::UFSSwapDir::swappedOut(const StoreEntry &e)
{
    cur_size += fs.blksize * sizeInBlocks(e.swap_file_sz);
    ++n_disk_objects;
}

StoreSearch *
Fs::Ufs::UFSSwapDir::search(String const url, HttpRequest *request)
{
    if (url.size())
        fatal ("Cannot search by url yet\n");

    return new Fs::Ufs::StoreSearchUFS (this);
}

void
Fs::Ufs::UFSSwapDir::logEntry(const StoreEntry & e, int op) const
{
    StoreSwapLogData *s = new StoreSwapLogData;
    s->op = (char) op;
    s->swap_filen = e.swap_filen;
    s->timestamp = e.timestamp;
    s->lastref = e.lastref;
    s->expires = e.expires;
    s->lastmod = e.lastmod;
    s->swap_file_sz = e.swap_file_sz;
    s->refcount = e.refcount;
    s->flags = e.flags;
    memcpy(s->key, e.key, SQUID_MD5_DIGEST_LENGTH);
    s->finalize();
    file_write(swaplog_fd,
               -1,
               s,
               sizeof(StoreSwapLogData),
               NULL,
               NULL,
               FreeObject);
}

int
Fs::Ufs::UFSSwapDir::DirClean(int swap_index)
{
    DIR *dir_pointer = NULL;

    LOCAL_ARRAY(char, p1, MAXPATHLEN + 1);
    LOCAL_ARRAY(char, p2, MAXPATHLEN + 1);

    int files[20];
    int swapfileno;
    int fn;         /* same as swapfileno, but with dirn bits set */
    int n = 0;
    int k = 0;
    int N0, N1, N2;
    int D0, D1, D2;
    UFSSwapDir *SD;
    N0 = NumberOfUFSDirs;
    D0 = UFSDirToGlobalDirMapping[swap_index % N0];
    SD = dynamic_cast<UFSSwapDir *>(INDEXSD(D0));
    assert (SD);
    N1 = SD->l1;
    D1 = (swap_index / N0) % N1;
    N2 = SD->l2;
    D2 = ((swap_index / N0) / N1) % N2;
    snprintf(p1, MAXPATHLEN, "%s/%02X/%02X",
             SD->path, D1, D2);
    debugs(36, 3, HERE << "Cleaning directory " << p1);
    dir_pointer = opendir(p1);

    if (dir_pointer == NULL) {
        if (errno == ENOENT) {
            debugs(36, DBG_CRITICAL, HERE << "WARNING: Creating " << p1);
#if _SQUID_MSWIN_

            if (mkdir(p1) == 0)
#else

            if (mkdir(p1, 0777) == 0)
#endif

                return 0;
        }

        debugs(50, DBG_CRITICAL, HERE << p1 << ": " << xstrerror());
        safeunlink(p1, 1);
        return 0;
    }

    dirent_t *de;
    while ((de = readdir(dir_pointer)) != NULL && k < 20) {
        if (sscanf(de->d_name, "%X", &swapfileno) != 1)
            continue;

        fn = swapfileno;    /* XXX should remove this cruft ! */

        if (SD->validFileno(fn, 1))
            if (SD->mapBitTest(fn))
                if (UFSSwapDir::FilenoBelongsHere(fn, D0, D1, D2))
                    continue;

        files[k] = swapfileno;
        ++k;
    }

    closedir(dir_pointer);

    if (k == 0)
        return 0;

    qsort(files, k, sizeof(int), rev_int_sort);

    if (k > 10)
        k = 10;

    for (n = 0; n < k; ++n) {
        debugs(36, 3, HERE << "Cleaning file "<< std::setfill('0') << std::hex << std::uppercase << std::setw(8) << files[n]);
        snprintf(p2, MAXPATHLEN + 1, "%s/%08X", p1, files[n]);
        safeunlink(p2, 0);
        ++statCounter.swap.files_cleaned;
    }

    debugs(36, 3, HERE << "Cleaned " << k << " unused files from " << p1);
    return k;
}
