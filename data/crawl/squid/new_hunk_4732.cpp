
ICAPOptions::ICAPOptions(): error("unconfigured"),
        max_connections(-1), allow204(false),
        preview(-1), theTTL(-1)
{
    theTransfers.preview.name = "Transfer-Preview";
    theTransfers.preview.kind = xferPreview;
    theTransfers.ignore.name = "Transfer-Ignore";
    theTransfers.ignore.kind = xferIgnore;
    theTransfers.complete.name = "Transfer-Complete";
    theTransfers.complete.kind = xferComplete;

    // Section 4.10.2 of RFC 3507 says that default is no Preview
    // TODO: provide a squid.conf option to overwrite the default
    theTransfers.byDefault = &theTransfers.complete;
}

ICAPOptions::~ICAPOptions()
{
}

// future optimization note: this method is called by ICAP ACL code at least
// twice for each HTTP message to see if the message should be ignored. For any
// non-ignored HTTP message, ICAP calls to check whether a preview is needed.
ICAPOptions::TransferKind ICAPOptions::transferKind(const String &urlPath) const
{
    if (theTransfers.preview.matches(urlPath))
        return xferPreview;

    if (theTransfers.complete.matches(urlPath))
        return xferComplete;

    if (theTransfers.ignore.matches(urlPath))
        return xferIgnore;

    debugs(93,7, "ICAPOptions url " << urlPath << " matches no extensions; " <<
        "using default: " << theTransfers.byDefault->name);
    return theTransfers.byDefault->kind;
}

bool ICAPOptions::valid() const
