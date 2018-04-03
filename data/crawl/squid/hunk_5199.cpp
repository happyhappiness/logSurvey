 
 void
 SwapDir::logEntry(const StoreEntry & e, int op) const{}
+
+char const *
+SwapDir::type() const
+{
+    return theType;
+}
+
+/* NOT performance critical. Really. Don't bother optimising for speed
+ * - RBC 20030718 
+ */
+SwapDirOption *
+SwapDir::getOptionTree() const
+{
+    SwapDirOptionVector *result = new SwapDirOptionVector;
+    result->options.push_back(new SwapDirOptionAdapter<SwapDir>(*const_cast<SwapDir *>(this), &SwapDir::optionReadOnlyParse, &SwapDir::optionReadOnlyDump));
+    result->options.push_back(new SwapDirOptionAdapter<SwapDir>(*const_cast<SwapDir *>(this), &SwapDir::optionMaxSizeParse, &SwapDir::optionMaxSizeDump));
+    return result;
+}
+
+void
+SwapDir::parseOptions(int reconfiguring)
+{
+    unsigned int old_read_only = flags.read_only;
+    char *name, *value;
+
+    SwapDirOption *newOption = getOptionTree();
+
+    while ((name = strtok(NULL, w_space)) != NULL) {
+        value = strchr(name, '=');
+
+        if (value)
+            *value++ = '\0';	/* cut on = */
+
+        if (newOption)
+            if (!newOption->parse(name, value, reconfiguring))
+                self_destruct();
+    }
+
+    delete newOption;
+
+    /*
+     * Handle notifications about reconfigured single-options with no value
+     * where the removal of the option cannot be easily detected in the
+     * parsing...
+     */
+
+    if (reconfiguring) {
+        if (old_read_only != flags.read_only) {
+            debug(3, 1) ("Cache dir '%s' now %s\n",
+                         path, flags.read_only ? "Read-Only" : "Read-Write");
+        }
+    }
+}
+
+void
+SwapDir::dumpOptions(StoreEntry * entry) const
+{
+    SwapDirOption *newOption = getOptionTree();
+
+    if (newOption)
+        newOption->dump(entry);
+
+    delete newOption;
+}
+
+bool
+SwapDir::optionReadOnlyParse(char const *option, const char *value, int reconfiguring)
+{
+    if (strcmp(option, "read-only") != 0)
+        return false;
+
+    int read_only = 0;
+
+    if (value)
+        read_only = xatoi(value);
+    else
+        read_only = 1;
+
+    flags.read_only = read_only;
+
+    return true;
+}
+
+void
+SwapDir::optionReadOnlyDump(StoreEntry * e) const
+{
+    if (flags.read_only)
+        storeAppendPrintf(e, " read-only");
+}
+
+bool
+SwapDir::optionMaxSizeParse(char const *option, const char *value, int reconfiguring)
+{
+    if (strcmp(option, "max-size") != 0)
+        return false;
+
+    if (!value)
+        self_destruct();
+
+    ssize_t size = xatoi(value);
+
+    if (reconfiguring && max_objsize != size)
+        debug(3, 1) ("Cache dir '%s' max object size now %ld\n", path, (long int) size);
+
+    max_objsize = size;
+
+    return true;
+}
+
+void
+SwapDir::optionMaxSizeDump(StoreEntry * e) const
+{
+    if (max_objsize != -1)
+        storeAppendPrintf(e, " max-size=%ld", (long int) max_objsize);
+}
+
+SwapDirOptionVector::~SwapDirOptionVector()
+{
+    while (options.size()) {
+        delete options.back();
+        options.pop_back();
+    }
+}
+
+bool
+SwapDirOptionVector::parse(char const *option, const char *value, int reconfiguring)
+{
+    Vector<SwapDirOption *>::iterator i = options.begin();
+
+    while (i != options.end()) {
+        if ((*i)->parse(option,value, reconfiguring))
+            return true;
+
+        ++i;
+    }
+
+    return false;
+}
+
+void
+SwapDirOptionVector::dump(StoreEntry * e) const
+{
+    for(Vector<SwapDirOption *>::const_iterator i = options.begin();
+            i != options.end(); ++i)
+        (*i)->dump(e);
+}
