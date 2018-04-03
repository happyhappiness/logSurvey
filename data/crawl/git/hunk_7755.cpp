 		die("bug: unhandled diff status %c", p->status);
 	}
 	fprintf(s->fp, "\n");
+	strbuf_release(&onebuf);
+	strbuf_release(&twobuf);
 }
 
 static void wt_status_print_updated_cb(struct diff_queue_struct *q,
