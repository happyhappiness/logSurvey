 
     theFD = shm_open(theName.termedBuf(), O_RDWR, 0);
     if (theFD < 0) {
-        debugs(54, 5, HERE << "shm_open " << theName << ": " << xstrerror());
+        int xerrno = errno;
+        debugs(54, 5, "shm_open " << theName << ": " << xstrerr(xerrno));
         fatalf("Ipc::Mem::Segment::open failed to shm_open(%s): %s\n",
-               theName.termedBuf(), xstrerror());
+               theName.termedBuf(), xstrerr(xerrno));
     }
 
     theSize = statSize("Ipc::Mem::Segment::open");
