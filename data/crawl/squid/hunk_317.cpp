         return;
 
     if (munmap(theMem, theSize)) {
-        debugs(54, 5, HERE << "munmap " << theName << ": " << xstrerror());
+        int xerrno = errno;
+        debugs(54, 5, "munmap " << theName << ": " << xstrerr(xerrno));
         fatalf("Ipc::Mem::Segment::detach failed to munmap(%s): %s\n",
-               theName.termedBuf(), xstrerror());
+               theName.termedBuf(), xstrerr(xerrno));
     }
     theMem = 0;
 }
