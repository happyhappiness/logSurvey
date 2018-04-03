 	     * in the same order attached to our mklist */
 	    for (m = t->rn_mklist; m && x; x = x->rn_dupedkey)
 		if (m == x->rn_mklist) {
-		    struct radix_mask *mm = m->rm_mklist;
+		    struct squid_radix_mask *mm = m->rm_mklist;
 		    x->rn_mklist = 0;
 		    if (--(m->rm_refs) < 0)
-			MKFree(m);
+			squid_MKFree(m);
 		    m = mm;
 		}
 #if RN_DEBUG
 	    if (m)
 		fprintf(stderr, "%s %x at %x\n",
-		    "rn_delete: Orphaned Mask", (int) m, (int) x);
+		    "squid_rn_delete: Orphaned Mask", (int) m, (int) x);
 #else
 	    assert(m == NULL);
 #endif
