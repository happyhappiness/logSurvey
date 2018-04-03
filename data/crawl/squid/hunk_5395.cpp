 	    self_destruct();
 	}
     }
+    if (peerFindByName(p->name))
+	fatalf("ERROR: cache_peer %s specified twice\n", p->name);
     if (p->weight < 1)
 	p->weight = 1;
     p->icp.version = ICP_VERSION_CURRENT;
