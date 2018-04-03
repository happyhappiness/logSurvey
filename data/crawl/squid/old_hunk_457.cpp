    ++n_disk_objects;
}

StoreSearch *
Fs::Ufs::UFSSwapDir::search(String const url, HttpRequest *)
{
    if (url.size())
        fatal ("Cannot search by url yet\n");

    return new Fs::Ufs::StoreSearchUFS (this);
}

void
Fs::Ufs::UFSSwapDir::logEntry(const StoreEntry & e, int op) const
{
