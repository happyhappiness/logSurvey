 }
 
 #endif
+
+static void dump_HeaderWithAclList(StoreEntry * entry, const char *name, HeaderWithAclList *headers)
+{
+    if (!headers)
+        return;
+
+    for (HeaderWithAclList::iterator hwa = headers->begin(); hwa != headers->end(); ++hwa) {
+        storeAppendPrintf(entry, "%s ", hwa->fieldName.c_str());
+        storeAppendPrintf(entry, "%s ", hwa->fieldValue.c_str());
+        if (hwa->aclList)
+            dump_acl_list(entry, hwa->aclList);
+        storeAppendPrintf(entry, "\n");
+    }
+}
+
+static void parse_HeaderWithAclList(HeaderWithAclList **headers)
+{
+    char *fn;
+    if (!*headers) {
+        *headers = new HeaderWithAclList;
+    }
+    if ((fn = strtok(NULL, w_space)) == NULL) {
+        self_destruct();
+        return;
+    }
+    HeaderWithAcl hwa;
+    hwa.fieldName = fn;
+    hwa.fieldId = httpHeaderIdByNameDef(fn, strlen(fn));
+    if (hwa.fieldId == HDR_BAD_HDR)
+        hwa.fieldId = HDR_OTHER;
+
+    String buf;
+    bool wasQuoted;
+    ConfigParser::ParseQuotedString(&buf, &wasQuoted);
+    hwa.fieldValue = buf.termedBuf();
+    hwa.quoted = wasQuoted;
+    if (hwa.quoted) {
+        Format::Format *nlf =  new ::Format::Format("hdrWithAcl");
+        if (!nlf->parse(hwa.fieldValue.c_str())) {
+            self_destruct();
+            return;
+        }
+        hwa.valueFormat = nlf;
+    }
+    aclParseAclList(LegacyParser, &hwa.aclList);
+    (*headers)->push_back(hwa);
+}
+
+static void free_HeaderWithAclList(HeaderWithAclList **header)
+{
+    if (!(*header))
+        return;
+
+    for (HeaderWithAclList::iterator hwa = (*header)->begin(); hwa != (*header)->end(); ++hwa) {
+        if (hwa->aclList)
+            aclDestroyAclList(&hwa->aclList);
+
+        if (hwa->valueFormat) {
+            delete hwa->valueFormat;
+            hwa->valueFormat = NULL;
+        }
+    }
+    delete *header;
+    *header = NULL;
+}
