    HttpHeader(http_hdr_owner_type const &owner);
    ~HttpHeader();
    /* Interface functions */
    void update (HttpHeader const *fresh, HttpHeaderMask const *denied_mask);
    void clean();
    void removeConnectionHeaderEntries();
    /* protected, do not use these, use interface functions instead */
    Vector<HttpHeaderEntry *> entries;		/* parsed fields in raw format */
    HttpHeaderMask mask;	/* bit set <=> entry present */
    http_hdr_owner_type owner;	/* request or reply */
    int len;			/* length when packed, not counting terminating '\0' */
};

extern int httpHeaderParseQuotedString (const char *start, String *val);
extern int httpHeaderHasListMember(const HttpHeader * hdr, http_hdr_type id, const char *member, const char separator);
SQUIDCEXTERN int httpHeaderHasByNameListMember(const HttpHeader * hdr, const char *name, const char *member, const char separator);
SQUIDCEXTERN void httpHeaderUpdate(HttpHeader * old, const HttpHeader * fresh, const HttpHeaderMask * denied_mask);
int httpMsgIsPersistent(HttpVersion const &http_ver, const HttpHeader * hdr);
