}

int
UFSSwapDir::callback()
{
    return IO->callback();
}

void
UFSSwapDir::sync()
{
    IO->sync();
}

void
UFSSwapDir::swappedOut(const StoreEntry &e)
{
    cur_size += fs.blksize * sizeInBlocks(e.swap_file_sz);
    ++n_disk_objects;
}

StoreSearch *
UFSSwapDir::search(String const url, HttpRequest *request)
{
    if (url.size())
        fatal ("Cannot search by url yet\n");

    return new StoreSearchUFS (this);
}

CBDATA_CLASS_INIT(StoreSearchUFS);
StoreSearchUFS::StoreSearchUFS(RefCount<UFSSwapDir> aSwapDir) : sd(aSwapDir), walker (sd->repl->WalkInit(sd->repl)), current (NULL), _done (false)
{}

/* do not link
StoreSearchUFS::StoreSearchUFS(StoreSearchUFS const &);
*/

StoreSearchUFS::~StoreSearchUFS()
{
    walker->Done(walker);
    walker = NULL;
}

void
StoreSearchUFS::next(void (aCallback)(void *cbdata), void *aCallbackArgs)
{
    next();
    aCallback(aCallbackArgs);
}

bool
StoreSearchUFS::next()
{
    /* the walker API doesn't make sense. the store entries referred to are already readwrite
     * from their hash table entries
     */

    if (walker)
        current = const_cast<StoreEntry *>(walker->Next(walker));

    if (current == NULL)
        _done = true;

    return current != NULL;
}

bool
StoreSearchUFS::error() const
{
    return false;
}

bool
StoreSearchUFS::isDone() const
{
    return _done;
}

StoreEntry *
StoreSearchUFS::currentItem()
{
    return current;
}
