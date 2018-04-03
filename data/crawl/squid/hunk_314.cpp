     assert(aSize > 0);
     assert(theFD < 0);
 
+    int xerrno = errno; // XXX: where does errno come from?
+
     // Why a brand new segment? A Squid crash may leave a reusable segment, but
     // our placement-new code requires an all-0s segment. We could truncate and
     // resize the old segment, but OS X does not allow using O_TRUNC with
     // shm_open() and does not support ftruncate() for old segments.
-    if (!createFresh() && errno == EEXIST) {
+    if (!createFresh() && xerrno == EEXIST) {
         unlink();
         createFresh();
     }
 
     if (theFD < 0) {
-        debugs(54, 5, HERE << "shm_open " << theName << ": " << xstrerror());
+        debugs(54, 5, "shm_open " << theName << ": " << xstrerr(xerrno));
         fatalf("Ipc::Mem::Segment::create failed to shm_open(%s): %s\n",
-               theName.termedBuf(), xstrerror());
+               theName.termedBuf(), xstrerr(xerrno));
     }
 
     if (ftruncate(theFD, aSize)) {
