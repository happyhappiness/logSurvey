    void dumpTimeOption(StoreEntry * e) const;
    bool parseRateOption(char const *option, const char *value, int reconfiguring);
    void dumpRateOption(StoreEntry * e) const;
    bool parseSizeOption(char const *option, const char *value, int reconfiguring);
    void dumpSizeOption(StoreEntry * e) const;

    void rebuild(); ///< starts loading and validating stored entry metadata

    bool full() const; ///< no more entries can be stored without purging
    void trackReferences(StoreEntry &e); ///< add to replacement policy scope
    void ignoreReferences(StoreEntry &e); ///< delete from repl policy scope

    int64_t diskOffsetLimit() const;
    int entryLimit() const { return map->entryLimit(); }
    int entryMaxPayloadSize() const;
    int entriesNeeded(const int64_t objSize) const;

    void anchorEntry(StoreEntry &e, const sfileno filen, const Ipc::StoreMapAnchor &anchor);
    bool updateCollapsedWith(StoreEntry &collapsed, const Ipc::StoreMapAnchor &anchor);

    friend class Rebuild;
    friend class IoState;
    const char *filePath; ///< location of cache storage file inside path/
    DirMap *map; ///< entry key/sfileno to MaxExtras/inode mapping

private:
    void createError(const char *const msg);

    DiskIOStrategy *io;
    RefCount<DiskFile> theFile; ///< cache storage for this cache_dir
    Ipc::Mem::Pointer<Ipc::Mem::PageStack> freeSlots; ///< all unused slots
    Ipc::Mem::PageId *waitingForPage; ///< one-page cache for a "hot" free slot

    /* configurable options */
    DiskFile::Config fileConfig; ///< file-level configuration options
