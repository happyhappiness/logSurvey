 #include "wordlist.h"
 
 void *
-ACLIP::operator new (size_t byteCount)
+ACLIP::operator new (size_t)
 {
     fatal ("ACLIP::operator new: unused");
     return (void *)1;
 }
 
 void
-ACLIP::operator delete (void *address)
+ACLIP::operator delete (void *)
 {
     fatal ("ACLIP::operator delete: unused");
 }
