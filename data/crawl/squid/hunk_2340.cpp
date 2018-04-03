 
     *var = xstrdup((char *) token);
 }
+#endif
 
-void
-parse_wordlist(wordlist ** list)
+void parse_wordlist(wordlist ** list) STUB
+#if 0
 {
     char *token;
     char *t = strtok(NULL, "");
 
     while ((token = strwordtok(NULL, &t)))
         wordlistAdd(list, token);
 }
-
-void
-requirePathnameExists(const char *name, const char *path)
-{
-    /* tee-hee. ignore this for testing  */
-}
-
-void
-parse_time_t(time_t * var)
-{
-    fatal("not implemented 6");
-}
-
-char *
-strtokFile(void)
-{
-    fatal("not implemented 9");
-    return NULL;
-}
-
-void
-ConfigParser::ParseUShort(unsigned short *var)
-{
-    fatal("not implemented 10");
-}
-
-void
-dump_acl_access(StoreEntry * entry, const char *name, acl_access * head)
-{
-    fatal("not implemented 11");
-}
-
-YesNoNone::operator void*() const
-{
-    /* ignore this for testing  */
-    return NULL;
-}
-
-/*
- * DO NOT MODIFY:
- * arch-tag: 9bbc3b5f-8d7b-4fdc-af59-0b524a785307
- */
+#endif
+
+void requirePathnameExists(const char *name, const char *path) STUB_NOP
+void parse_time_t(time_t * var) STUB
+char * strtokFile(void) STUB_RETVAL(NULL)
+void ConfigParser::ParseUShort(unsigned short *var) STUB
+void dump_acl_access(StoreEntry * entry, const char *name, acl_access * head) STUB
+YesNoNone::operator void*() const { STUB_NOP; return NULL; }
