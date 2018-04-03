 }
 
 void
-SqString::append(SqString const &old)
+String::append(String const &old)
 {
-    append (old.c_str(), old.size());
+    append (old.buf(), old.len_);
 }
 
-const char&
-SqString::operator [](unsigned int pos) const
+void
+String::absorb(String &old)
 {
-    assert(pos < size_ );
-
-    return buf_[pos];
+    clean();
+    size_ = old.size_;
+    buf (old.buf_);
+    len_ = old.len_;
+    old.size_ = 0;
+    old.buf_ = NULL;
+    old.len_ = 0;
 }
 
-char&
-SqString::operator [](unsigned int pos)
+void
+String::buf(char *newBuf)
 {
-    assert(pos < size_ );
-
-    return buf_[pos];
+    assert (buf_ == NULL);
+    buf_ = newBuf;
 }
 
 #if DEBUGSTRINGS
 void
-SqString::stat(StoreEntry *entry) const
+String::stat(StoreEntry *entry) const
 {
-    storeAppendPrintf(entry, "%p : %d/%d \"%s\"\n",this,len_, size_, c_str());
+    storeAppendPrintf(entry, "%p : %d/%d \"%s\"\n",this,len_, size_, buf());
 }
 
-SqStringRegistry &
-SqStringRegistry::Instance()
+StringRegistry &
+StringRegistry::Instance()
 {
     return Instance_;
 }
