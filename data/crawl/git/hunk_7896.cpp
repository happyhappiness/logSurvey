 {
 	diff_debug_filespec(p->one, i, "one");
 	diff_debug_filespec(p->two, i, "two");
-	fprintf(stderr, "score %d, status %c stays %d broken %d\n",
+	fprintf(stderr, "score %d, status %c rename_used %d broken %d\n",
 		p->score, p->status ? p->status : '?',
-		p->source_stays, p->broken_pair);
+		p->one->rename_used, p->broken_pair);
 }
 
 void diff_debug_queue(const char *msg, struct diff_queue_struct *q)
