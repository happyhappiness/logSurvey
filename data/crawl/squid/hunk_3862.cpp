 {
     typedef Groups::iterator GI;
     for (GI i = AllGroups().begin(); i != AllGroups().end(); ++i)
-        storeAppendPrintf(entry, "%s %s\n", name, (*i)->id.unsafeBuf());
+        storeAppendPrintf(entry, "%s " SQUIDSTRINGPH "\n", name, SQUIDSTRINGPRINT((*i)->id));
 }
 
 void
