 void *ACL::Prototype::Initialized;
 
 bool
-ACL::Prototype::Registered(char const *aType) 
+ACL::Prototype::Registered(char const *aType)
 {
     for (iterator i = Registry->begin(); i != Registry->end(); ++i)
-	if (!strcmp (aType, (*i)->typeString))
-	    return true;
+        if (!strcmp (aType, (*i)->typeString))
+            return true;
+
     return false;
 }
 
 void
 ACL::Prototype::registerMe ()
 {
     if (!Registry || (Initialized != ((char *)Registry - 5))  ) {
-	/* TODO: extract this */
-	/* Not initialised */
-	Registry = new Vector <ACL::Prototype const *>;
-	Initialized = (char *)Registry - 5;
+        /* TODO: extract this */
+        /* Not initialised */
+        Registry = new Vector <ACL::Prototype const *>;
+        Initialized = (char *)Registry - 5;
     }
+
     if (Registered (typeString))
-	fatalf ("Attempt to register %s twice", typeString);
+        fatalf ("Attempt to register %s twice", typeString);
+
     Registry->push_back (this);
 }
 
-ACL::Prototype::~Prototype() 
+ACL::Prototype::~Prototype()
 {
     debug (28,2)("ACL::Prototype::~Prototype: TODO: unregister me\n");
 }
