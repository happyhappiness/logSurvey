     typedef Vector<ServiceConfig*>::const_iterator VISCI;
     const Vector<ServiceConfig*> &configs = serviceConfigs;
     debugs(93,3, "Found " << configs.size() << " service configs.");
-    for (VISCI ci = configs.begin(); ci != configs.end(); ++ci) {
-        ServicePointer s = createService(**ci);
+    for (VISCI i = configs.begin(); i != configs.end(); ++i) {
+        ServicePointer s = createService(**i);
         if (s != NULL)
-            AddService(s);
+            AllServices().push_back(s);
     }
 
-    debugs(93,1, "Initialized " << configs.size() <<
+    debugs(93,3, "Created " << configs.size() <<
         " message adaptation services.");
 }
 
-void
-Adaptation::Config::Finalize()
+// poor man for_each
+template <class Collection>
+static void
+FinalizeEach(Collection &collection, const char *label)
 {
-    // link classes with the service reps they use
-    typedef Classes::iterator CI;
-    for (CI ci = AllClasses().begin(); ci != AllClasses().end(); ++ci) {
-        Class *c = *ci;
-        c->finalize(); // TODO: fail on failures
-    }
+    typedef typename Collection::iterator CI;
+    for (CI i = collection.begin(); i != collection.end(); ++i)
+        (*i)->finalize();
 
-    debugs(93,2, "Initialized " << AllClasses().size() <<
-        " message adaptation service classes.");
+    debugs(93,2, "Initialized " << collection.size() << ' ' << label);
 }
 
 void
-Adaptation::Config::parseClass()
+Adaptation::Config::Finalize()
 {
-    Class *C = new Class();
-
-    if (C->prepare()) {
-        AddClass(C);
-    } else {
-        delete C;
-    }
-};
+    FinalizeEach(AllServices(), "message adaptation services");
+    FinalizeEach(AllGroups(), "message adaptation service groups");
+    FinalizeEach(AllRules(), "message adaptation access rules");
+}
 
 void
-Adaptation::Config::freeClass()
+Adaptation::Config::ParseServiceSet()
 {
-    // XXX: leaking Classes here?
+    ServiceSet *g = new ServiceSet();
+    g->parse();
+    AllGroups().push_back(g);
 }
 
 void
-Adaptation::Config::dumpClass(StoreEntry *entry, const char *name) const
+Adaptation::Config::FreeServiceSet()
 {
-    typedef Classes::iterator CI;
-    for (CI i = AllClasses().begin(); i != AllClasses().end(); ++i)
-        storeAppendPrintf(entry, "%s %s\n", name, (*i)->key.buf());
+    while (!AllGroups().empty()) {
+		delete AllGroups().back();
+		AllGroups().pop_back();
+	}
 }
 
 void
-Adaptation::Config::parseAccess(ConfigParser &parser)
+Adaptation::Config::DumpServiceSet(StoreEntry *entry, const char *name)
 {
-    String aKey;
-    ConfigParser::ParseString(&aKey);
-    Class *c = FindClass(aKey);
-
-    if (!c)
-        fatalf("Did not find  class '%s' referenced on line %d\n",
-               aKey.buf(), config_lineno);
+    typedef Groups::iterator GI;
+    for (GI i = AllGroups().begin(); i != AllGroups().end(); ++i)
+        storeAppendPrintf(entry, "%s %s\n", name, (*i)->id.buf());
+}
 
-    aclParseAccessLine(parser, &c->accessList);
-};
+void
+Adaptation::Config::ParseAccess(ConfigParser &parser)
+{
+    AccessRule *r = new AccessRule;
+    r->parse(parser);
+    AllRules().push_back(r);
+}
 
 void
-Adaptation::Config::freeAccess()
+Adaptation::Config::FreeAccess()
 {
-    (void) 0;
+    while (!AllRules().empty()) {
+        delete AllRules().back();
+        AllRules().pop_back();
+	}
 }
 
 void
-Adaptation::Config::dumpAccess(StoreEntry *entry, const char *name) const
+Adaptation::Config::DumpAccess(StoreEntry *entry, const char *name)
 {
     LOCAL_ARRAY(char, nom, 64);
 
-    typedef Classes::iterator CI;
-    for (CI i = AllClasses().begin(); i != AllClasses().end(); ++i) {
-        snprintf(nom, 64, "%s %s", name, (*i)->key.buf());
-        dump_acl_access(entry, nom, (*i)->accessList);
+    typedef AccessRules::iterator CI;
+    for (CI i = AllRules().begin(); i != AllRules().end(); ++i) {
+        snprintf(nom, 64, "%s %s", name, (*i)->groupId.buf());
+        dump_acl_access(entry, nom, (*i)->acl);
 	}
 }
 
