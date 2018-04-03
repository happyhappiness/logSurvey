 
     if (keyExtrasLine.size() > 0)
         storeAppendPrintf(entry, "%s %s key_extras \"%s\"\n", name, scheme->type(), keyExtrasLine.termedBuf());
+
+    return true;
 }
 
 void
