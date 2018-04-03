 
 ICAPOptions::ICAPOptions(): error("unconfigured"),
         max_connections(-1), allow204(false),
-        preview(-1), theTTL(-1), transfer_ext(NULL)
+        preview(-1), theTTL(-1)
 {
-    transfers.preview = transfers.ignore = transfers.complete = NULL;
-    transfers.other = TRANSFER_NONE;
-};
+    theTransfers.preview.name = "Transfer-Preview";
+    theTransfers.preview.kind = xferPreview;
+    theTransfers.ignore.name = "Transfer-Ignore";
+    theTransfers.ignore.kind = xferIgnore;
+    theTransfers.complete.name = "Transfer-Complete";
+    theTransfers.complete.kind = xferComplete;
+
+    // Section 4.10.2 of RFC 3507 says that default is no Preview
+    // TODO: provide a squid.conf option to overwrite the default
+    theTransfers.byDefault = &theTransfers.complete;
+}
 
 ICAPOptions::~ICAPOptions()
 {
-    delete transfers.preview;
-    delete transfers.ignore;
-    delete transfers.complete;
-    delete transfer_ext;
-};
-
-ICAPOptions::transfer_type ICAPOptions::getTransferExt(const char *s)
-{
-
-    if (transfer_ext) {
-        List<TransferPair> *data = transfer_ext;
-
-        while (data) {
-            if (*(data->element.ext) == *s) {
-                return data->element.type;
-            }
-
-            data = data->next;
-        }
-    }
-
-    return TRANSFER_NONE;
 }
 
-void ICAPOptions::insertTransferExt(const char *t, transfer_type t_type)
+// future optimization note: this method is called by ICAP ACL code at least
+// twice for each HTTP message to see if the message should be ignored. For any
+// non-ignored HTTP message, ICAP calls to check whether a preview is needed.
+ICAPOptions::TransferKind ICAPOptions::transferKind(const String &urlPath) const
 {
-    List<TransferPair> **Tail;
-    TransferPair t_ext;
-
-    if (t == "*") {
-        transfers.other = t_type;
-        return;
-    }
+    if (theTransfers.preview.matches(urlPath))
+        return xferPreview;
 
-    for (Tail = &transfer_ext; *Tail; Tail = &((*Tail)->next)) {
-        if (*(*Tail)->element.ext == *t) {
-            (*Tail)->element.type = t_type;
-            return;
-        }
-    }
+    if (theTransfers.complete.matches(urlPath))
+        return xferComplete;
 
-    t_ext.ext = xstrdup(t);
-    t_ext.type = t_type;
-    List<TransferPair> *q = new List<TransferPair>(t_ext);
-    *(Tail) = q;
+    if (theTransfers.ignore.matches(urlPath))
+        return xferIgnore;
 
-};
-
-void ICAPOptions::cfgTransferListHeader(const HttpHeader *h, const char *fname, transfer_type t_type)
-{
-    const String s = h->getByName(fname);
-
-    if (!s.size())
-        return;
-
-    if (t_type == TRANSFER_PREVIEW)
-        transfers.preview = parseExtFileList(s.buf(), s.buf() + s.size(), t_type);
-    else if (t_type == TRANSFER_IGNORE)
-        transfers.ignore = parseExtFileList(s.buf(), s.buf() + s.size(), t_type);
-    else if (t_type == TRANSFER_COMPLETE)
-        transfers.complete = parseExtFileList(s.buf(), s.buf() + s.size(), t_type);
-    else
-        fatalf("Unexpected transfer_type at %s:%d", __FILE__,__LINE__);
-}
-
-List<String> *ICAPOptions::parseExtFileList(const char *start, const char *end, transfer_type t_type)
-{
-    const String s = xstrndup(start, end - start + 1);
-    const char *item;
-    const char *pos = NULL;
-    char *fext = NULL;
-    int ilen;
-    String t = NULL;
-
-    List<String> **Tail = NULL;
-    List<String> *H = NULL;
-
-    for (Tail = &H; *Tail; Tail = &((*Tail)->next))
-
-        ;
-    while (strListGetItem(&s, ',', &item, &ilen, &pos)) {
-        fext = xstrndup(item, ilen + 1);
-        t = fext;
-        List<String> *q = new List<String> (t);
-        *(Tail) = q;
-        Tail = &q->next;
-        insertTransferExt(fext, t_type);
-    }
-
-    return H;
+    debugs(93,7, "ICAPOptions url " << urlPath << " matches no extensions; " <<
+        "using default: " << theTransfers.byDefault->name);
+    return theTransfers.byDefault->kind;
 }
 
 bool ICAPOptions::valid() const
