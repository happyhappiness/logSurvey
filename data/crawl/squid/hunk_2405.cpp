         mmap(NULL, theSize, PROT_READ | PROT_WRITE, MAP_SHARED, theFD, 0);
     if (p == MAP_FAILED) {
         debugs(54, 5, HERE << "mmap " << theName << ": " << xstrerror());
-        fatal("Ipc::Mem::Segment::attach failed to mmap");
+        fatalf("Ipc::Mem::Segment::attach failed to mmap(%s): %s\n",
+               theName.termedBuf(), xstrerror());
     }
     theMem = p;
 }
