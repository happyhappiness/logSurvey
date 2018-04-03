 			struct lline *ll;
 			int j;
 			unsigned long p_mask;
-			sl = &sline[lno++];
+			struct sline *sl = &sline[lno++];
 			ll = (sl->flag & no_pre_delete) ? NULL : sl->lost_head;
 			while (ll) {
 				fputs(c_old, stdout);
