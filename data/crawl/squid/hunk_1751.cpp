 }
 
 void
-aclParseAccessLine(ConfigParser &parser, acl_access ** head)
+aclParseAccessLine(const char *directive, ConfigParser &, acl_access **treep)
 {
-    char *t = NULL;
-    acl_access *A = NULL;
-    acl_access *B = NULL;
-    acl_access **T = NULL;
-
     /* first expect either 'allow' or 'deny' */
+    const char *t = ConfigParser::strtokFile();
 
-    if ((t = strtok(NULL, w_space)) == NULL) {
+    if (!t) {
         debugs(28, DBG_CRITICAL, "aclParseAccessLine: " << cfg_filename << " line " << config_lineno << ": " << config_input_line);
         debugs(28, DBG_CRITICAL, "aclParseAccessLine: missing 'allow' or 'deny'.");
         return;
     }
 
-    A = new acl_access;
-
+    allow_t action = ACCESS_DUNNO;
     if (!strcmp(t, "allow"))
-        A->allow = ACCESS_ALLOWED;
+        action = ACCESS_ALLOWED;
     else if (!strcmp(t, "deny"))
-        A->allow = ACCESS_DENIED;
+        action = ACCESS_DENIED;
     else {
         debugs(28, DBG_CRITICAL, "aclParseAccessLine: " << cfg_filename << " line " << config_lineno << ": " << config_input_line);
         debugs(28, DBG_CRITICAL, "aclParseAccessLine: expecting 'allow' or 'deny', got '" << t << "'.");
-        delete A;
         return;
     }
 
-    aclParseAclList(parser, &A->aclList);
+    const int ruleId = ((treep && *treep) ? (*treep)->childrenCount() : 0) + 1;
+    MemBuf ctxBuf;
+    ctxBuf.init();
+    ctxBuf.Printf("%s#%d", directive, ruleId);
+    ctxBuf.terminate();
 
-    if (A->aclList == NULL) {
-        debugs(28, DBG_CRITICAL, "" << cfg_filename << " line " << config_lineno << ": " << config_input_line);
+    Acl::AndNode *rule = new Acl::AndNode;
+    rule->context(ctxBuf.content(), config_input_line);
+    rule->lineParse();
+    if (rule->empty()) {
+        debugs(28, DBG_CRITICAL, "aclParseAccessLine: " << cfg_filename << " line " << config_lineno << ": " << config_input_line);
         debugs(28, DBG_CRITICAL, "aclParseAccessLine: Access line contains no ACL's, skipping");
-        delete A;
+        delete rule;
         return;
     }
 
-    A->cfgline = xstrdup(config_input_line);
     /* Append to the end of this list */
 
-    for (B = *head, T = head; B; T = &B->next, B = B->next);
-    *T = A;
+    assert(treep);
+    if (!*treep) {
+        *treep = new Acl::Tree;
+        (*treep)->context(directive, config_input_line);
+    }
+
+    (*treep)->add(rule, action);
 
     /* We lock _acl_access structures in ACLChecklist::matchNonBlocking() */
 }
 
+// aclParseAclList does not expect or set actions (cf. aclParseAccessLine)
 void
-aclParseAclList(ConfigParser &parser, ACLList ** head)
+aclParseAclList(ConfigParser &, Acl::Tree **treep, const char *label)
 {
-    ACLList **Tail = head;	/* sane name in the use below */
-    ACL *a = NULL;
-    char *t;
-
-    /* next expect a list of ACL names, possibly preceeded
-     * by '!' for negation */
-
-    while ((t = strtok(NULL, w_space))) {
-        ACLList *L = new ACLList;
-
-        if (*t == '!') {
-            L->negated (true);
-            ++t;
-        }
-
-        debugs(28, 3, "aclParseAclList: looking for ACL name '" << t << "'");
-        a = ACL::FindByName(t);
-
-        if (a == NULL) {
-            debugs(28, DBG_CRITICAL, "aclParseAclList: ACL name '" << t << "' not found.");
-            delete L;
-            parser.destruct();
-            continue;
-        }
-
-        L->_acl = a;
-        *Tail = L;
-        Tail = &L->next;
-    }
+    // accomodate callers unable to convert their ACL list context to string
+    if (!label)
+        label = "...";
+
+    MemBuf ctxLine;
+    ctxLine.init();
+    ctxLine.Printf("(%s %s line)", cfg_directive, label);
+    ctxLine.terminate();
+
+    Acl::AndNode *rule = new Acl::AndNode;
+    rule->context(ctxLine.content(), config_input_line);
+    rule->lineParse();
+
+    MemBuf ctxTree;
+    ctxTree.init();
+    ctxTree.Printf("%s %s", cfg_directive, label);
+    ctxTree.terminate();
+
+    // We want a cbdata-protected Tree (despite giving it only one child node).
+    Acl::Tree *tree = new Acl::Tree;
+    tree->add(rule);
+    tree->context(ctxTree.content(), config_input_line);
+
+    assert(treep);
+    assert(!*treep);
+    *treep = tree;
 }
 
 /*********************/
