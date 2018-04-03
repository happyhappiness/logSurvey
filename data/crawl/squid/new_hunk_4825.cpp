
/* test if a field is present */
int
HttpHeader::has(http_hdr_type id) const
{
    assert_eid(id);
    assert(id != HDR_OTHER);
    debug(55, 9) ("%p lookup for %d\n", this, id);
    return CBIT_TEST(mask, id);
}

void
HttpHeader::putInt(http_hdr_type id, int number)
{
    assert_eid(id);
    assert(Headers[id].type == ftInt);	/* must be of an appropriate type */
    assert(number >= 0);
    addEntry(httpHeaderEntryCreate(id, NULL, xitoa(number)));
}

void
HttpHeader::putTime(http_hdr_type id, time_t htime)
{
    assert_eid(id);
    assert(Headers[id].type == ftDate_1123);	/* must be of an appropriate type */
    assert(htime >= 0);
    addEntry(httpHeaderEntryCreate(id, NULL, mkrfc1123(htime)));
}

void
HttpHeader::insertTime(http_hdr_type id, time_t htime)
{
    assert_eid(id);
    assert(Headers[id].type == ftDate_1123);	/* must be of an appropriate type */
    assert(htime >= 0);
    insertEntry(httpHeaderEntryCreate(id, NULL, mkrfc1123(htime)));
}

void
HttpHeader::putStr(http_hdr_type id, const char *str)
{
    assert_eid(id);
    assert(Headers[id].type == ftStr);	/* must be of an appropriate type */
    assert(str);
    addEntry(httpHeaderEntryCreate(id, NULL, str));
}

void
HttpHeader::putAuth(const char *auth_scheme, const char *realm)
{
    assert(auth_scheme && realm);
    httpHeaderPutStrf(this, HDR_WWW_AUTHENTICATE, "%s realm=\"%s\"", auth_scheme, realm);
}

void
HttpHeader::putCc(const HttpHdrCc * cc)
{
    MemBuf mb;
    Packer p;
    assert(cc);
    /* remove old directives if any */
    delById(HDR_CACHE_CONTROL);
    /* pack into mb */
    mb.init();
    packerToMemInit(&p, &mb);
    httpHdrCcPackInto(cc, &p);
    /* put */
    addEntry(httpHeaderEntryCreate(HDR_CACHE_CONTROL, NULL, mb.buf));
    /* cleanup */
    packerClean(&p);
    mb.clean();
}

void
HttpHeader::putContRange(const HttpHdrContRange * cr)
{
    MemBuf mb;
    Packer p;
    assert(cr);
    /* remove old directives if any */
    delById(HDR_CONTENT_RANGE);
    /* pack into mb */
    mb.init();
    packerToMemInit(&p, &mb);
    httpHdrContRangePackInto(cr, &p);
    /* put */
    addEntry(httpHeaderEntryCreate(HDR_CONTENT_RANGE, NULL, mb.buf));
    /* cleanup */
    packerClean(&p);
    mb.clean();
}

void
HttpHeader::putRange(const HttpHdrRange * range)
{
    MemBuf mb;
    Packer p;
    assert(range);
    /* remove old directives if any */
    delById(HDR_RANGE);
    /* pack into mb */
    mb.init();
    packerToMemInit(&p, &mb);
    range->packInto(&p);
    /* put */
    addEntry(httpHeaderEntryCreate(HDR_RANGE, NULL, mb.buf));
    /* cleanup */
    packerClean(&p);
    mb.clean();
}

void
HttpHeader::putSc(HttpHdrSc *sc)
{
    MemBuf mb;
    Packer p;
    assert(sc);
    /* remove old directives if any */
    delById(HDR_RANGE);
    /* pack into mb */
    mb.init();
    packerToMemInit(&p, &mb);
    httpHdrScPackInto(sc, &p);
    /* put */
    addEntry(httpHeaderEntryCreate(HDR_SURROGATE_CONTROL, NULL, mb.buf));
    /* cleanup */
    packerClean(&p);
    mb.clean();
}

/* add extension header (these fields are not parsed/analyzed/joined, etc.) */
void
HttpHeader::putExt(const char *name, const char *value)
{
    assert(name && value);
    debug(55, 8) ("%p adds ext entry '%s: %s'\n", this, name, value);
    addEntry(httpHeaderEntryCreate(HDR_OTHER, name, value));
}

int
