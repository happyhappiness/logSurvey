 
     if (munmap(theMem, theSize)) {
         debugs(54, 5, HERE << "munmap " << theName << ": " << xstrerror());
-        fatal("Ipc::Mem::Segment::detach failed to munmap");
+        fatalf("Ipc::Mem::Segment::detach failed to munmap(%s): %s\n",
+               theName.termedBuf(), xstrerror());
     }
     theMem = 0;
 }
