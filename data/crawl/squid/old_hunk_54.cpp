    aclDestroyAclList(&aclList);
}

Note::Value::Pointer
Note::addValue(const String &value)
{
    Value::Pointer v = new Value(value);
    values.push_back(v);
    return v;
}

const char *
Note::match(HttpRequest *request, HttpReply *reply, const AccessLogEntry::Pointer &al)
{

    typedef Values::iterator VLI;
    ACLFilledChecklist ch(NULL, request, NULL);
    ch.reply = reply;
    if (reply)
        HTTPMSGLOCK(ch.reply);

    for (VLI i = values.begin(); i != values.end(); ++i ) {
        const int ret= ch.fastCheck((*i)->aclList);
        debugs(93, 5, HERE << "Check for header name: " << key << ": " << (*i)->value
               <<", HttpRequest: " << request << " HttpReply: " << reply << " matched: " << ret);
        if (ret == ACCESS_ALLOWED) {
            if (al != NULL && (*i)->valueFormat != NULL) {
                static MemBuf mb;
                mb.reset();
                (*i)->valueFormat->assemble(mb, al, 0);
                return mb.content();
            } else
                return (*i)->value.termedBuf();
        }
    }
    return NULL;
}

Note::Pointer
Notes::add(const String &noteKey)
{
    typedef Notes::NotesList::iterator AMLI;
    for (AMLI i = notes.begin(); i != notes.end(); ++i) {
        if ((*i)->key == noteKey)
            return (*i);
    }

    Note::Pointer note = new Note(noteKey);
    notes.push_back(note);
    return note;
}

Note::Pointer
Notes::parse(ConfigParser &parser)
{
    String key = ConfigParser::NextToken();
    ConfigParser::EnableMacros();
    String value = ConfigParser::NextQuotedToken();
    ConfigParser::DisableMacros();
    bool valueWasQuoted = ConfigParser::LastTokenWasQuoted();
    Note::Pointer note = add(key);
    Note::Value::Pointer noteValue = note->addValue(value);

    String label(key);
    label.append('=');
    label.append(value);
    aclParseAclList(parser, &noteValue->aclList, label.termedBuf());
    if (formattedValues && valueWasQuoted) {
        noteValue->valueFormat =  new Format::Format(descr ? descr : "Notes");
        noteValue->valueFormat->parse(value.termedBuf());
    }
    if (blacklisted) {
        for (int i = 0; blacklisted[i] != NULL; ++i) {
            if (note->key.caseCmp(blacklisted[i]) == 0) {
                fatalf("%s:%d: meta key \"%s\" is a reserved %s name",
                       cfg_filename, config_lineno, note->key.termedBuf(),
                       descr ? descr : "");
            }
        }
    }

    return note;
}

void
Notes::dump(StoreEntry *entry, const char *key)
{
    typedef Notes::NotesList::iterator AMLI;
    for (AMLI m = notes.begin(); m != notes.end(); ++m) {
        typedef Note::Values::iterator VLI;
        for (VLI v =(*m)->values.begin(); v != (*m)->values.end(); ++v ) {
            storeAppendPrintf(entry, "%s " SQUIDSTRINGPH " %s",
                              key, SQUIDSTRINGPRINT((*m)->key), ConfigParser::QuoteString((*v)->value));
            dump_acl_list(entry, (*v)->aclList);
            storeAppendPrintf(entry, "\n");
        }
    }
}

void
Notes::clean()
{
    notes.clear();
}

NotePairs::~NotePairs()
{
    while (!entries.empty()) {
        delete entries.back();
        entries.pop_back();
    }
}

const char *
NotePairs::find(const char *noteKey, const char *sep) const
{
    static String value;
    value.clean();
    for (std::vector<NotePairs::Entry *>::const_iterator  i = entries.begin(); i != entries.end(); ++i) {
        if ((*i)->name.cmp(noteKey) == 0) {
            if (value.size())
                value.append(sep);
            value.append((*i)->value);
        }
    }
    return value.size() ? value.termedBuf() : NULL;
}

const char *
NotePairs::toString(const char *sep) const
{
    static String value;
    value.clean();
    for (std::vector<NotePairs::Entry *>::const_iterator  i = entries.begin(); i != entries.end(); ++i) {
        value.append((*i)->name);
        value.append(": ");
        value.append((*i)->value);
        value.append(sep);
    }
    return value.size() ? value.termedBuf() : NULL;
}

const char *
NotePairs::findFirst(const char *noteKey) const
{
    for (std::vector<NotePairs::Entry *>::const_iterator  i = entries.begin(); i != entries.end(); ++i) {
        if ((*i)->name.cmp(noteKey) == 0)
            return (*i)->value.termedBuf();
    }
    return NULL;
}

void
