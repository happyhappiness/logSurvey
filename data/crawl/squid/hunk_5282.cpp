     return "N/A";
 }
 
+void
+NullStoreEntry::operator delete(void*)
+{
+    fatal ("Attempt to delete NullStoreEntry\n");
+}
+
 char const *
 NullStoreEntry::getSerialisedMetaData()
 {
