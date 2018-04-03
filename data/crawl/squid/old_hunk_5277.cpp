
#if CBDATA_DEBUG
void
_cbdata::dump(StoreEntry *sentry) const
{
    storeAppendPrintf(sentry, "%c%p\t%d\t%d\t%20s:%-5d\n", valid ? ' ' :
                      '!', &data, type, locks, file, line);
}

struct CBDataDumper : public unary_function<_cbdata, void>
{
    CBDataDumper(StoreEntry *anEntry):where(anEntry){}

    void operator()(_cbdata const &x)
    {
        x.dump(where);
    }
