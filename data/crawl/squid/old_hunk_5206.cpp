                     path, size);

    max_size = size;
}

void
UfsSwapDir::dump(StoreEntry & entry)const
{
    UFSSwapDir::dump (entry);
    dump_cachedir_options(&entry, options, this);
}

/*
