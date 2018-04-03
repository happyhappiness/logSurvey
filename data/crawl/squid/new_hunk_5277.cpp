
#if CBDATA_DEBUG
void
cbdata::dump(StoreEntry *sentry) const
{
    storeAppendPrintf(sentry, "%c%p\t%d\t%d\t%20s:%-5d\n", valid ? ' ' :
                      '!', &data, type, locks, file, line);
}

struct CBDataDumper : public unary_function<cbdata, void>
{
    CBDataDumper(StoreEntry *anEntry):where(anEntry){}

    void operator()(cbdata const &x)
    {
        x.dump(where);
    }
