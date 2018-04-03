 }
 #endif /* USE_AUTH */
 
+static void
+ParseAclWithAction(acl_access **access, const allow_t &action, const char *desc, ACL *acl = nullptr)
+{
+    assert(access);
+    SBuf name;
+    if (!*access) {
+        *access = new Acl::Tree;
+        name.Printf("(%s rules)", desc);
+        (*access)->context(name.c_str(), config_input_line);
+    }
+    Acl::AndNode *rule = new Acl::AndNode;
+    name.Printf("(%s rule)", desc);
+    rule->context(name.c_str(), config_input_line);
+    acl ? rule->add(acl) : rule->lineParse();
+    (*access)->add(rule, action);
+}
+
 /* TODO: just return the object, the # is irrelevant */
 static int
 find_fstype(char *type)
