     memset(&s, 0, sizeof(s));
 
     if (fstat(theFD, &s) != 0) {
-        debugs(54, 5, HERE << "fstat " << theName << ": " << xstrerror());
-        String s = context;
-        s.append("failed to fstat(2) ");
-        s.append(theName);
-        fatal(s.termedBuf());
+        debugs(54, 5, HERE << context << " fstat " << theName << ": " << xstrerror());
+        fatalf("Ipc::Mem::Segment::statSize: %s failed to fstat(%s): %s\n",
+               context, theName.termedBuf(), xstrerror());
     }
 
     return s.st_size;
