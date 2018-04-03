     fatal("Not implemented");
 }
 
-void
-helperStatefulFree(statefulhelper * hlp)
-{
-    fatal("Not implemented");
-}
-
-void
-helperFree(helper * hlp)
+helper::~helper()
 {
     fatal("Not implemented");
 }
 
-CBDATA_TYPE(helper);
-
-helper *
-helperCreate(const char *name)
-{
-    helper *hlp;
-    CBDATA_INIT_TYPE(helper);
-    hlp = cbdataAlloc(helper);
-    hlp->id_name = name;
-    return hlp;
-}
+CBDATA_CLASS_INIT(helper);
 
 void
 helperStats(StoreEntry * sentry, helper * hlp, const char *label)
