                 nbufs * SHMBUF_BLKSZ, 0600 | IPC_CREAT);
 
     if (id < 0) {
-        debugs(50, DBG_CRITICAL, "storeDiskdInit: shmget: " << xstrerror());
+        int xerrno = errno;
+        debugs(50, DBG_CRITICAL, MYNAME << "shmget: " << xstrerr(xerrno));
         fatal("shmget failed");
     }
 
     buf = (char *)shmat(id, NULL, 0);
 
     if (buf == (void *) -1) {
-        debugs(50, DBG_CRITICAL, "storeDiskdInit: shmat: " << xstrerror());
+        int xerrno = errno;
+        debugs(50, DBG_CRITICAL, MYNAME << "shmat: " << xstrerr(xerrno));
         fatal("shmat failed");
     }
 
