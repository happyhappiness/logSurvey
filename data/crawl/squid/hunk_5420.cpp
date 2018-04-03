 
 /* to be split into separate files in the future */
 
-MemPool *acl_user_data::Pool(NULL);
+#if USE_SSL
+MemPool *acl_cert_data::Pool(NULL);
 void *
-acl_user_data::operator new (size_t byteCount)
+acl_cert_data::operator new (size_t byteCount)
 {
     /* derived classes with different sizes must implement their own new */
-    assert (byteCount == sizeof (acl_user_data));
+    assert (byteCount == sizeof (acl_cert_data));
     if (!Pool)
-	Pool = memPoolCreate("acl_user_data", sizeof (acl_user_data));
+	Pool = memPoolCreate("acl_cert_data", sizeof (acl_cert_data));
     return memPoolAlloc(Pool);
 }
 
 void
-acl_user_data::operator delete (void *address)
+acl_cert_data::operator delete (void *address)
 {
     memPoolFree (Pool, address);
 }
 
 void
-acl_user_data::deleteSelf() const
+acl_cert_data::deleteSelf() const
 {
     delete this;
 }
+#endif /* USE_SSL */
 
-#if USE_SSL
-MemPool *acl_cert_data::Pool(NULL);
+MemPool *ACLList::Pool(NULL);
 void *
-acl_cert_data::operator new (size_t byteCount)
+ACLList::operator new (size_t byteCount)
 {
     /* derived classes with different sizes must implement their own new */
-    assert (byteCount == sizeof (acl_cert_data));
+    assert (byteCount == sizeof (ACLList));
     if (!Pool)
-	Pool = memPoolCreate("acl_cert_data", sizeof (acl_cert_data));
+	Pool = memPoolCreate("ACLList", sizeof (ACLList));
     return memPoolAlloc(Pool);
 }
 
 void
-acl_cert_data::operator delete (void *address)
+ACLList::operator delete (void *address)
 {
     memPoolFree (Pool, address);
 }
 
 void
-acl_cert_data::deleteSelf() const
+ACLList::deleteSelf() const
 {
     delete this;
 }
-#endif /* USE_SSL */
+
+
+CBDATA_CLASS_INIT(acl_access);
+
+void *
+acl_access::operator new (size_t)
+{
+    CBDATA_INIT_TYPE(acl_access);
+    acl_access *result = cbdataAlloc(acl_access);
+    return result;
+}
+
+void
+acl_access::operator delete (void *address)
+{
+    acl_access *t = static_cast<acl_access *>(address);
+    cbdataFree(t);
+}
+
+void
+acl_access::deleteSelf () const
+{
+    delete this;
+}
+
+void
+ACLChecklist::AsyncState::changeState (ACLChecklist *checklist, AsyncState *newState) const
+{
+    checklist->changeState(newState);
+}
+
+ACLChecklist::NullState *
+ACLChecklist::NullState::Instance()
+{
+    return &_instance;
+}
+
+void
+ACLChecklist::NullState::checkForAsync(ACLChecklist *) const
+{
+}
+
+ACLChecklist::NullState ACLChecklist::NullState::_instance;
+
+void
+ACLChecklist::changeState (AsyncState *newState)
+{
+    /* only change from null to active and back again,
+     * not active to active.
+     * relax this once conversion to states is complete
+     * RBC 02 2003
+     */
+    assert (state_ == NullState::Instance() || newState == NullState::Instance());
+    state_ = newState;
+}
+
+ACLChecklist::AsyncState *
+ACLChecklist::asyncState() const
+{
+    return state_;
+}
+
+ACL::Prototype::Prototype() : prototype (NULL), typeString (NULL) {}
+
+ACL::Prototype::Prototype (ACL const *aPrototype, char const *aType) : prototype (aPrototype), typeString (aType) 
+{
+    registerMe ();
+}
+
+Vector<ACL::Prototype const *> * ACL::Prototype::Registry;
+void *ACL::Prototype::Initialized;
+
+bool
+ACL::Prototype::Registered(char const *aType) 
+{
+    for (iterator i = Registry->begin(); i != Registry->end(); ++i)
+	if (!strcmp (aType, (*i)->typeString))
+	    return true;
+    return false;
+}
+
+void
+ACL::Prototype::registerMe ()
+{
+    if (!Registry || (Initialized != ((char *)Registry - 5))  ) {
+	/* TODO: extract this */
+	/* Not initialised */
+	Registry = new Vector <ACL::Prototype const *>;
+	Initialized = (char *)Registry - 5;
+    }
+    if (Registered (typeString))
+	fatalf ("Attempt to register %s twice", typeString);
+    Registry->push_back (this);
+}
+
+ACL::Prototype::~Prototype() 
+{
+    debug (28,2)("ACL::Prototype::~Prototype: TODO: unregister me\n");
+}
+
+ACL *
+ACL::Prototype::Factory (char const *typeToClone)
+{
+    for (iterator i = Registry->begin(); i != Registry->end(); ++i)
+	if (!strcmp (typeToClone, (*i)->typeString)) 
+	    return (*i)->prototype->clone();
+    return NULL;
+}
+
+ACL *
+ACL::clone()const
+{
+    fatal ("Cannot clone base class");
+    return NULL;
+}
