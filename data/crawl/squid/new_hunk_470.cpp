static std::stack<StoreEntry*> LateReleaseStack;
MemAllocator *StoreEntry::pool = NULL;

void
Store::Stats(StoreEntry * output)
{
    assert(output);
    Root().stat(*output);
}

void
StoreEntry::makePublic()
{
