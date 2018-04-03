     aclDestroyAclList(&aclList);
 }
 
-Note::Value::Pointer
-Note::addValue(const String &value)
+Note::Value::Value(const char *aVal, const bool quoted, const char *descr, const Method m)
+    : aclList(nullptr), valueFormat(nullptr), theValue(aVal), theMethod(m)
 {
-    Value::Pointer v = new Value(value);
-    values.push_back(v);
-    return v;
+    if (quoted) {
+        valueFormat = new Format::Format(descr ? descr : "Notes");
+        valueFormat->parse(theValue.c_str());
+    }
 }
 
-const char *
-Note::match(HttpRequest *request, HttpReply *reply, const AccessLogEntry::Pointer &al)
+const SBuf &
+Note::Value::format(const AccessLogEntryPointer &al)
 {
+    if (al && valueFormat) {
+        static MemBuf mb;
+        mb.reset();
+        valueFormat->assemble(mb, al, 0);
+        theFormattedValue.assign(mb.content());
+        return theFormattedValue;
+    }
+    return theValue;
+}
 
-    typedef Values::iterator VLI;
-    ACLFilledChecklist ch(NULL, request, NULL);
+Note::Value::Pointer
+Note::addValue(const char *value, const bool quoted, const char *descr, const Value::Method m)
+{
+    values.push_back(new Value(value, quoted, descr, m));
+    return values.back();
+}
+
+bool
+Note::match(HttpRequest *request, HttpReply *reply, const AccessLogEntry::Pointer &al, SBuf &matched)
+{
+    ACLFilledChecklist ch(nullptr, request, nullptr);
     ch.reply = reply;
     if (reply)
         HTTPMSGLOCK(ch.reply);
 
-    for (VLI i = values.begin(); i != values.end(); ++i ) {
-        const int ret= ch.fastCheck((*i)->aclList);
-        debugs(93, 5, HERE << "Check for header name: " << key << ": " << (*i)->value
-               <<", HttpRequest: " << request << " HttpReply: " << reply << " matched: " << ret);
+    for (auto v: values) {
+        assert(v->aclList);
+        const int ret = ch.fastCheck(v->aclList);
+        debugs(93, 5, "Check for header name: " << theKey << ": " << v->value() <<
+               ", HttpRequest: " << request << " HttpReply: " << reply << " matched: " << ret);
         if (ret == ACCESS_ALLOWED) {
-            if (al != NULL && (*i)->valueFormat != NULL) {
-                static MemBuf mb;
-                mb.reset();
-                (*i)->valueFormat->assemble(mb, al, 0);
-                return mb.content();
-            } else
-                return (*i)->value.termedBuf();
+            matched = v->format(al);
+            return true;
         }
     }
-    return NULL;
+    matched.clear();
+    return false;
 }
 
-Note::Pointer
-Notes::add(const String &noteKey)
+void
+Note::updateNotePairs(NotePairs::Pointer pairs, const CharacterSet *delimiters, const AccessLogEntryPointer &al)
 {
-    typedef Notes::NotesList::iterator AMLI;
-    for (AMLI i = notes.begin(); i != notes.end(); ++i) {
-        if ((*i)->key == noteKey)
-            return (*i);
+    for (auto v: values) {
+        const SBuf &formatted = v->format(al);
+        if (!pairs->empty() && v->method() == Value::mhReplace)
+            pairs->remove(theKey);
+        if (delimiters)
+            pairs->addStrList(key(), formatted, *delimiters);
+        else
+            pairs->add(key(), formatted);
     }
+}
 
-    Note::Pointer note = new Note(noteKey);
-    notes.push_back(note);
-    return note;
+void
+Note::dump(StoreEntry *entry, const char *k)
+{
+    for (auto v: values) {
+        storeAppendPrintf(entry, "%s %.*s %s",
+                          k, key().length(), key().rawContent(), ConfigParser::QuoteString(SBufToString(v->value())));
+        dump_acl_list(entry, v->aclList);
+        storeAppendPrintf(entry, "\n");
+    }
+}
+
+SBuf
+Note::toString(const char *sep) const
+{
+    SBuf result;
+    for (auto val: values)
+        result.appendf("%.*s: %.*s%s", key().length(), key().rawContent(),
+                       val->value().length(), val->value().rawContent(), sep);
+    return result;
 }
 
 Note::Pointer
-Notes::parse(ConfigParser &parser)
+Notes::add(const SBuf &noteKey)
+{
+    if (Note::Pointer p = find(noteKey))
+        return p;
+    notes.push_back(new Note(noteKey));
+    return notes.back();
+}
+
+Note::Pointer
+Notes::find(const SBuf &noteKey)
+{
+    for (auto n: notes)
+        if (n->key() == noteKey)
+            return n;
+    return nullptr;
+}
+
+void
+Notes::validateKey(const SBuf &key) const
 {
-    String key = ConfigParser::NextToken();
-    ConfigParser::EnableMacros();
-    String value = ConfigParser::NextQuotedToken();
-    ConfigParser::DisableMacros();
-    bool valueWasQuoted = ConfigParser::LastTokenWasQuoted();
-    Note::Pointer note = add(key);
-    Note::Value::Pointer noteValue = note->addValue(value);
-
-    String label(key);
-    label.append('=');
-    label.append(value);
-    aclParseAclList(parser, &noteValue->aclList, label.termedBuf());
-    if (formattedValues && valueWasQuoted) {
-        noteValue->valueFormat =  new Format::Format(descr ? descr : "Notes");
-        noteValue->valueFormat->parse(value.termedBuf());
-    }
     if (blacklisted) {
-        for (int i = 0; blacklisted[i] != NULL; ++i) {
-            if (note->key.caseCmp(blacklisted[i]) == 0) {
-                fatalf("%s:%d: meta key \"%s\" is a reserved %s name",
-                       cfg_filename, config_lineno, note->key.termedBuf(),
+        for (int i = 0; blacklisted[i] != nullptr; ++i) {
+            if (!key.cmp(blacklisted[i])) {
+                fatalf("%s:%d: meta key \"%.*s\" is a reserved %s name",
+                       cfg_filename, config_lineno, key.length(), key.rawContent(),
                        descr ? descr : "");
             }
         }
     }
+    // TODO: fix code duplication: the same set of specials is produced
+    // by isKeyNameChar().
+    static const CharacterSet allowedSpecials = CharacterSet::ALPHA +
+            CharacterSet::DIGIT + CharacterSet("specials", "-_");
+    const auto specialIndex = key.findFirstNotOf(allowedSpecials);
+    if (specialIndex != SBuf::npos) {
+        debugs(28, DBG_CRITICAL, "Warning: used special character '" <<
+               key[specialIndex] << "' within annotation name. " <<
+               "Future Squid versions will not support this.");
+    }
+}
 
+Note::Pointer
+Notes::parse(ConfigParser &parser)
+{
+    const char *tok = ConfigParser::NextToken();
+    if (!tok)
+        fatalf("FATAL: Missing note key");
+    SBuf key(tok);
+    validateKey(key);
+    ConfigParser::EnableMacros();
+    const char *val = ConfigParser::NextQuotedToken();
+    if (!val)
+        fatalf("FATAL: Missing note value");
+    ConfigParser::DisableMacros();
+    Note::Pointer note = add(key);
+    Note::Value::Pointer noteValue = note->addValue(val, formattedValues && ConfigParser::LastTokenWasQuoted(), descr);
+    key.append('=');
+    key.append(val);
+    aclParseAclList(parser, &noteValue->aclList, key.c_str());
     return note;
 }
 
 void
-Notes::dump(StoreEntry *entry, const char *key)
-{
-    typedef Notes::NotesList::iterator AMLI;
-    for (AMLI m = notes.begin(); m != notes.end(); ++m) {
-        typedef Note::Values::iterator VLI;
-        for (VLI v =(*m)->values.begin(); v != (*m)->values.end(); ++v ) {
-            storeAppendPrintf(entry, "%s " SQUIDSTRINGPH " %s",
-                              key, SQUIDSTRINGPRINT((*m)->key), ConfigParser::QuoteString((*v)->value));
-            dump_acl_list(entry, (*v)->aclList);
-            storeAppendPrintf(entry, "\n");
+Notes::parseKvPair() {
+    char *k, *v;
+    int parsedPairs = 0;
+    while (ConfigParser::NextKvPair(k, v)) {
+        int keyLen = strlen(k);
+        const Note::Value::Method method = (k[keyLen - 1] == '+') ? Note::Value::mhAppend : Note::Value::mhReplace;
+        if (method == Note::Value::mhAppend)
+            keyLen--;
+        else {
+            assert(method == Note::Value::mhReplace);
+            if (Note::Pointer oldNote = find(SBuf(k, keyLen)))
+                debugs(28, DBG_CRITICAL, "Warning: annotation configuration with key " << k <<
+                        " already exists and will be overwritten");
         }
+        SBuf key(k, keyLen);
+        validateKey(key);
+        Note::Pointer note = add(key);
+        (void)note->addValue(v, formattedValues && ConfigParser::LastTokenWasQuoted(), descr, method);
+        parsedPairs++;
     }
+    if (!parsedPairs)
+        fatalf("FATAL: Missing annotation kv pair");
 }
 
 void
-Notes::clean()
+Notes::updateNotePairs(NotePairs::Pointer pairs, const CharacterSet *delimiters, const AccessLogEntry::Pointer &al)
 {
-    notes.clear();
+    for (auto n: notes)
+        n->updateNotePairs(pairs, delimiters, al);
 }
 
-NotePairs::~NotePairs()
+void
+Notes::dump(StoreEntry *entry, const char *key)
 {
-    while (!entries.empty()) {
-        delete entries.back();
-        entries.pop_back();
-    }
+    for (auto n: notes)
+        n->dump(entry, key);
 }
 
 const char *
-NotePairs::find(const char *noteKey, const char *sep) const
+Notes::toString(const char *sep) const
+{
+    static SBuf result;
+    result.clear();
+    for (auto note: notes)
+        result.append(note->toString(sep));
+    return result.isEmpty() ? nullptr : result.c_str();
+}
+
+bool
+NotePairs::find(SBuf &resultNote, const char *noteKey, const char *sep) const
 {
-    static String value;
-    value.clean();
-    for (std::vector<NotePairs::Entry *>::const_iterator  i = entries.begin(); i != entries.end(); ++i) {
-        if ((*i)->name.cmp(noteKey) == 0) {
-            if (value.size())
-                value.append(sep);
-            value.append((*i)->value);
+    resultNote.clear();
+    for (auto e: entries) {
+        if (!e->name().cmp(noteKey)) {
+            if (!resultNote.isEmpty())
+                resultNote.append(sep);
+            resultNote.append(e->value());
         }
     }
-    return value.size() ? value.termedBuf() : NULL;
+    return resultNote.length();
 }
 
 const char *
 NotePairs::toString(const char *sep) const
 {
-    static String value;
-    value.clean();
-    for (std::vector<NotePairs::Entry *>::const_iterator  i = entries.begin(); i != entries.end(); ++i) {
-        value.append((*i)->name);
-        value.append(": ");
-        value.append((*i)->value);
-        value.append(sep);
-    }
-    return value.size() ? value.termedBuf() : NULL;
+    static SBuf result;
+    result.clear();
+    for (auto e: entries)
+        result.appendf("%.*s: %.*s%s", e->name().length(), e->name().rawContent(),
+                       e->value().length(), e->value().rawContent(), sep);
+    return result.isEmpty() ? nullptr : result.c_str();
 }
 
 const char *
 NotePairs::findFirst(const char *noteKey) const
 {
-    for (std::vector<NotePairs::Entry *>::const_iterator  i = entries.begin(); i != entries.end(); ++i) {
-        if ((*i)->name.cmp(noteKey) == 0)
-            return (*i)->value.termedBuf();
-    }
-    return NULL;
+    for (auto e: entries)
+        if (!e->name().cmp(noteKey))
+            return const_cast<SBuf &>(e->value()).c_str();
+    return nullptr;
 }
 
 void
