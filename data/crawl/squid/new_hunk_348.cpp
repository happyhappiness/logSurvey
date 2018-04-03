    virtual bool doneAll() const;
    virtual void swanSong();

    bool doneLoading() const;
    bool doneValidating() const;

private:
    void checkpoint();
    void steps();
    void loadingSteps();
    void validationSteps();
    void loadOneSlot();
    void validateOneEntry(const sfileno fileNo);
    void validateOneSlot(const SlotId slotId);
    bool importEntry(Ipc::StoreMapAnchor &anchor, const sfileno slotId, const DbCellHeader &header);
    void freeBadEntry(const sfileno fileno, const char *eDescription);

    void failure(const char *msg, int errNo = 0);

    LoadingEntry loadingEntry(const sfileno fileNo);
    void startNewEntry(const sfileno fileno, const SlotId slotId, const DbCellHeader &header);
    void primeNewEntry(Ipc::StoreMapAnchor &anchor, const sfileno fileno, const DbCellHeader &header);
    void finalizeOrFree(const sfileno fileNo, LoadingEntry &le);
    void finalizeOrThrow(const sfileno fileNo, LoadingEntry &le);
    void addSlotToEntry(const sfileno fileno, const SlotId slotId, const DbCellHeader &header);
    void useNewSlot(const SlotId slotId, const DbCellHeader &header);

    LoadingSlot loadingSlot(const SlotId slotId);
    void mapSlot(const SlotId slotId, const DbCellHeader &header);
    void freeUnusedSlot(const SlotId slotId, const bool invalid);
    void freeSlot(const SlotId slotId, const bool invalid);

    template <class SlotIdType>
    void chainSlots(SlotIdType &from, const SlotId to);

    bool sameEntry(const sfileno fileno, const DbCellHeader &header) const;

    SwapDir *sd;
    LoadingParts *parts; ///< parts of store entries being loaded from disk

    int64_t dbSize;
    int dbSlotSize; ///< the size of a db cell, including the cell header
