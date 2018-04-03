 static void
 free_peer(CachePeer ** P)
 {
-    CachePeer *p;
-
-    while ((p = *P) != NULL) {
-        *P = p->next;
-#if USE_CACHE_DIGESTS
-
-        cbdataReferenceDone(p->digest);
-#endif
-
-        // the mgr job will notice that its owner is gone and stop
-        PeerPoolMgr::Checkpoint(p->standby.mgr, "peer gone");
-        delete p->standby.pool;
-        cbdataFree(p);
-    }
-
+    delete *P;
+    *P = NULL;
     Config.npeers = 0;
 }
 
