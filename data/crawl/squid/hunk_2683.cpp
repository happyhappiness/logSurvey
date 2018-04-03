         struct stat s;
         memset(&s, 0, sizeof(s));
         if (fstat(theFD, &s)) {
-            debugs(54, 5, "SharedMemory::open: fstat: " << xstrerror());
-        String s = "SharedMemory::open failed 2 ";
+            debugs(54, 5, HERE << "fstat: " << xstrerror());
+        String s = "Ipc::Mem::Segment::open failed to fstat";
         s.append(theName);
         fatal(s.termedBuf());
         }
