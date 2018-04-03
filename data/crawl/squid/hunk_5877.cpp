 {
     dlink_node *link = memAllocate(MEM_DLINK_NODE);
     dlinkAddTail(r, link, &srv->queue);
-    /* XXX No queue length check here? */
+/* TODO: warning if the queue on this server is more than X
+ * We don't check the queue size at the moment, because
+ * requests hitting here are deferrable 
+ */
+/*    hlp->stats.queue_size++;
+ * if (hlp->stats.queue_size < hlp->n_running)
+ * return;
+ * if (squid_curtime - hlp->last_queue_warn < 600)
+ * return;
+ * if (shutting_down || reconfiguring)
+ * return;
+ * hlp->last_queue_warn = squid_curtime;
+ * debug(14, 0) ("WARNING: All %s processes are busy.\n", hlp->id_name);
+ * debug(14, 0) ("WARNING: %d pending requests queued\n", hlp->stats.queue_size);
+ * if (hlp->stats.queue_size > hlp->n_running * 2)
+ * fatalf("Too many queued %s requests", hlp->id_name);
+ * debug(14, 1) ("Consider increasing the number of %s processes in your config file.\n", hlp->id_name);  */
 }
 
 
