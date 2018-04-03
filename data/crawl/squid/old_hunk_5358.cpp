    assert(e);

    HttpHeaderStats[0].parsedCount =
	HttpHeaderStats[hoRequest].parsedCount + HttpHeaderStats[hoReply].parsedCount;
    HttpHeaderStats[0].ccParsedCount =
	HttpHeaderStats[hoRequest].ccParsedCount + HttpHeaderStats[hoReply].ccParsedCount;
    HttpHeaderStats[0].destroyedCount =
	HttpHeaderStats[hoRequest].destroyedCount + HttpHeaderStats[hoReply].destroyedCount;
    HttpHeaderStats[0].busyDestroyedCount =
	HttpHeaderStats[hoRequest].busyDestroyedCount + HttpHeaderStats[hoReply].busyDestroyedCount;

    for (i = 1; i < HttpHeaderStatCount; i++) {
	httpHeaderStatDump(HttpHeaderStats + i, e);
	storeAppendPrintf(e, "%s\n", "<br>");
    }
    /* field stats for all messages */
    storeAppendPrintf(e, "\nHttp Fields Stats (replies and requests)\n");
    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\t %6s\n",
	"id", "name", "#alive", "%err", "%repeat");
    for (ht = (http_hdr_type)0; ht < HDR_ENUM_END; ++ht) {
	HttpHeaderFieldInfo *f = Headers + ht;
	storeAppendPrintf(e, "%2d\t %-20s\t %5d\t %6.3f\t %6.3f\n",
	    f->id, f->name.buf(), f->stat.aliveCount,
	    xpercent(f->stat.errCount, f->stat.parsCount),
	    xpercent(f->stat.repCount, f->stat.seenCount));
    }
    storeAppendPrintf(e, "Headers Parsed: %d + %d = %d\n",
	HttpHeaderStats[hoRequest].parsedCount,
	HttpHeaderStats[hoReply].parsedCount,
	HttpHeaderStats[0].parsedCount);
    storeAppendPrintf(e, "Hdr Fields Parsed: %d\n", HeaderEntryParsedCount);
}

http_hdr_type
httpHeaderIdByName(const char *name, int name_len, const HttpHeaderFieldInfo * info, int end)
{
    int i;
    for (i = 0; i < end; ++i) {
	if (name_len >= 0 && name_len != info[i].name.size())
	    continue;
	if (!strncasecmp(name, info[i].name.buf(),
		name_len < 0 ? info[i].name.size() + 1 : name_len))
	    return info[i].id;
    }
    return HDR_BAD_HDR;
}

http_hdr_type
httpHeaderIdByNameDef(const char *name, int name_len)
{
    if (!Headers)
	Headers = httpHeaderBuildFieldsInfo(HeadersAttrs, HDR_ENUM_END);
    return httpHeaderIdByName(name, name_len, Headers, HDR_ENUM_END);
}

const char *
httpHeaderNameById(int id)
{
    if (!Headers)
	Headers = httpHeaderBuildFieldsInfo(HeadersAttrs, HDR_ENUM_END);
    assert(id >= 0 && id < HDR_ENUM_END);
    return HeadersAttrs[id].name;
}
