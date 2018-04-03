    HttpHeader(http_hdr_owner_type const &owner);
    ~HttpHeader();
    /* Interface functions */
    void clean();
    void append(const HttpHeader * src);
    void update (HttpHeader const *fresh, HttpHeaderMask const *denied_mask);
    int reset();
    int parse(const char *header_start, const char *header_end);
    void packInto(Packer * p) const;
    HttpHeaderEntry *getEntry(HttpHeaderPos * pos) const;
    HttpHeaderEntry *findEntry(http_hdr_type id) const;
    int delByName(const char *name);
    int delById(http_hdr_type id);
    void delAt(HttpHeaderPos pos);
    void addEntry(HttpHeaderEntry * e);
    void insertEntry(HttpHeaderEntry * e);
    String getList(http_hdr_type id) const;
    String getStrOrList(http_hdr_type id) const;
    String getByName(const char *name) const;
    String getByNameListMember(const char *name, const char *member, const char separator) const;
    String getListMember(http_hdr_type id, const char *member, const char separator) const;
    int has(http_hdr_type id) const;
    void putInt(http_hdr_type id, int number);
    void putTime(http_hdr_type id, time_t htime);
    void insertTime(http_hdr_type id, time_t htime);
    void putStr(http_hdr_type id, const char *str);
    void putAuth(const char *auth_scheme, const char *realm);
    void putCc(const HttpHdrCc * cc);
    void putContRange(const HttpHdrContRange * cr);
    void putRange(const HttpHdrRange * range);
    void putSc(HttpHdrSc *sc);
    void putExt(const char *name, const char *value);
    int getInt(http_hdr_type id) const;
    time_t getTime(http_hdr_type id) const;
    const char *getStr(http_hdr_type id) const;
    const char *getLastStr(http_hdr_type id) const;
    HttpHdrCc *getCc() const;
    HttpHdrRange *getRange() const;
    HttpHdrSc *getSc() const;
    HttpHdrContRange *getContRange() const;
    const char *getAuth(http_hdr_type id, const char *auth_scheme) const;
    ETag getETag(http_hdr_type id) const;
    TimeOrTag getTimeOrTag(http_hdr_type id) const;
    int hasListMember(http_hdr_type id, const char *member, const char separator) const;
    int hasByNameListMember(const char *name, const char *member, const char separator) const;
    void removeConnectionHeaderEntries();
    /* protected, do not use these, use interface functions instead */
    Vector<HttpHeaderEntry *> entries;		/* parsed fields in raw format */
    HttpHeaderMask mask;	/* bit set <=> entry present */
    http_hdr_owner_type owner;	/* request or reply */
    int len;			/* length when packed, not counting terminating '\0' */

private:
    HttpHeaderEntry *findLastEntry(http_hdr_type id) const;
};

extern int httpHeaderParseQuotedString (const char *start, String *val);
SQUIDCEXTERN int httpHeaderHasByNameListMember(const HttpHeader * hdr, const char *name, const char *member, const char separator);
SQUIDCEXTERN void httpHeaderUpdate(HttpHeader * old, const HttpHeader * fresh, const HttpHeaderMask * denied_mask);
int httpMsgIsPersistent(HttpVersion const &http_ver, const HttpHeader * hdr);
