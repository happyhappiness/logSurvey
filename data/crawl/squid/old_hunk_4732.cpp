
ICAPOptions::ICAPOptions(): error("unconfigured"),
        max_connections(-1), allow204(false),
        preview(-1), theTTL(-1), transfer_ext(NULL)
{
    transfers.preview = transfers.ignore = transfers.complete = NULL;
    transfers.other = TRANSFER_NONE;
};

ICAPOptions::~ICAPOptions()
{
    delete transfers.preview;
    delete transfers.ignore;
    delete transfers.complete;
    delete transfer_ext;
};

ICAPOptions::transfer_type ICAPOptions::getTransferExt(const char *s)
{

    if (transfer_ext) {
        List<TransferPair> *data = transfer_ext;

        while (data) {
            if (*(data->element.ext) == *s) {
                return data->element.type;
            }

            data = data->next;
        }
    }

    return TRANSFER_NONE;
}

void ICAPOptions::insertTransferExt(const char *t, transfer_type t_type)
{
    List<TransferPair> **Tail;
    TransferPair t_ext;

    if (t == "*") {
        transfers.other = t_type;
        return;
    }

    for (Tail = &transfer_ext; *Tail; Tail = &((*Tail)->next)) {
        if (*(*Tail)->element.ext == *t) {
            (*Tail)->element.type = t_type;
            return;
        }
    }

    t_ext.ext = xstrdup(t);
    t_ext.type = t_type;
    List<TransferPair> *q = new List<TransferPair>(t_ext);
    *(Tail) = q;

};

void ICAPOptions::cfgTransferListHeader(const HttpHeader *h, const char *fname, transfer_type t_type)
{
    const String s = h->getByName(fname);

    if (!s.size())
        return;

    if (t_type == TRANSFER_PREVIEW)
        transfers.preview = parseExtFileList(s.buf(), s.buf() + s.size(), t_type);
    else if (t_type == TRANSFER_IGNORE)
        transfers.ignore = parseExtFileList(s.buf(), s.buf() + s.size(), t_type);
    else if (t_type == TRANSFER_COMPLETE)
        transfers.complete = parseExtFileList(s.buf(), s.buf() + s.size(), t_type);
    else
        fatalf("Unexpected transfer_type at %s:%d", __FILE__,__LINE__);
}

List<String> *ICAPOptions::parseExtFileList(const char *start, const char *end, transfer_type t_type)
{
    const String s = xstrndup(start, end - start + 1);
    const char *item;
    const char *pos = NULL;
    char *fext = NULL;
    int ilen;
    String t = NULL;

    List<String> **Tail = NULL;
    List<String> *H = NULL;

    for (Tail = &H; *Tail; Tail = &((*Tail)->next))

        ;
    while (strListGetItem(&s, ',', &item, &ilen, &pos)) {
        fext = xstrndup(item, ilen + 1);
        t = fext;
        List<String> *q = new List<String> (t);
        *(Tail) = q;
        Tail = &q->next;
        insertTransferExt(fext, t_type);
    }

    return H;
}

bool ICAPOptions::valid() const
