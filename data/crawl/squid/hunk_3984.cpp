 {
     typedef Groups::iterator GI;
     for (GI i = AllGroups().begin(); i != AllGroups().end(); ++i)
-        storeAppendPrintf(entry, "%s %s\n", name, (*i)->id.buf());
+        storeAppendPrintf(entry, "%s %s\n", name, (*i)->id.unsafeBuf());
 }
 
 void
