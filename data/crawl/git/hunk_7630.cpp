 
 #ifdef THREADED_DELTA_SEARCH
 
+/*
+ * The main thread waits on the condition that (at least) one of the workers
+ * has stopped working (which is indicated in the .working member of
+ * struct thread_params).
+ * When a work thread has completed its work, it sets .working to 0 and
+ * signals the main thread and waits on the condition that .data_ready
+ * becomes 1.
+ */
+
 struct thread_params {
 	pthread_t thread;
 	struct object_entry **list;
 	unsigned list_size;
 	unsigned remaining;
 	int window;
 	int depth;
+	int working;
+	int data_ready;
+	pthread_mutex_t mutex;
+	pthread_cond_t cond;
 	unsigned *processed;
 };
 
-static pthread_mutex_t data_request  = PTHREAD_MUTEX_INITIALIZER;
-static pthread_mutex_t data_ready    = PTHREAD_MUTEX_INITIALIZER;
-static pthread_mutex_t data_provider = PTHREAD_MUTEX_INITIALIZER;
-static struct thread_params *data_requester;
+static pthread_cond_t progress_cond = PTHREAD_COND_INITIALIZER;
 
 static void *threaded_find_deltas(void *arg)
 {
 	struct thread_params *me = arg;
 
-	for (;;) {
-		pthread_mutex_lock(&data_request);
-		data_requester = me;
-		pthread_mutex_unlock(&data_provider);
-		pthread_mutex_lock(&data_ready);
-		pthread_mutex_unlock(&data_request);
-
-		if (!me->remaining)
-			return NULL;
-
+	while (me->remaining) {
 		find_deltas(me->list, &me->remaining,
 			    me->window, me->depth, me->processed);
+
+		progress_lock();
+		me->working = 0;
+		pthread_cond_signal(&progress_cond);
+		progress_unlock();
+
+		/*
+		 * We must not set ->data_ready before we wait on the
+		 * condition because the main thread may have set it to 1
+		 * before we get here. In order to be sure that new
+		 * work is available if we see 1 in ->data_ready, it
+		 * was initialized to 0 before this thread was spawned
+		 * and we reset it to 0 right away.
+		 */
+		pthread_mutex_lock(&me->mutex);
+		while (!me->data_ready)
+			pthread_cond_wait(&me->cond, &me->mutex);
+		me->data_ready = 0;
+		pthread_mutex_unlock(&me->mutex);
 	}
+	/* leave ->working 1 so that this doesn't get more work assigned */
+	return NULL;
 }
 
 static void ll_find_deltas(struct object_entry **list, unsigned list_size,
 			   int window, int depth, unsigned *processed)
 {
-	struct thread_params *target, p[delta_search_threads];
+	struct thread_params p[delta_search_threads];
 	int i, ret, active_threads = 0;
 
 	if (delta_search_threads <= 1) {
 		find_deltas(list, &list_size, window, depth, processed);
 		return;
 	}
 
-	pthread_mutex_lock(&data_provider);
-	pthread_mutex_lock(&data_ready);
-
-	/* Start work threads. */
+	/* Partition the work amongst work threads. */
 	for (i = 0; i < delta_search_threads; i++) {
+		unsigned sub_size = list_size / (delta_search_threads - i);
+
 		p[i].window = window;
 		p[i].depth = depth;
 		p[i].processed = processed;
-		p[i].remaining = 0;
-		ret = pthread_create(&p[i].thread, NULL,
-				     threaded_find_deltas, &p[i]);
-		if (ret)
-			die("unable to create thread: %s", strerror(ret));
-		active_threads++;
-	}
-
-	/* Then partition the work amongst them. */
-	for (i = 0; i < delta_search_threads; i++) {
-		unsigned sub_size = list_size / (delta_search_threads - i);
-
-		pthread_mutex_lock(&data_provider);
-		target = data_requester;
-		if (!sub_size) {
-			pthread_mutex_unlock(&data_ready);
-			pthread_join(target->thread, NULL);
-			active_threads--;
-			continue;
-		}
+		p[i].working = 1;
+		p[i].data_ready = 0;
+		pthread_mutex_init(&p[i].mutex, NULL);
+		pthread_cond_init(&p[i].cond, NULL);
 
 		/* try to split chunks on "path" boundaries */
 		while (sub_size < list_size && list[sub_size]->hash &&
 		       list[sub_size]->hash == list[sub_size-1]->hash)
 			sub_size++;
 
-		target->list = list;
-		target->list_size = sub_size;
-		target->remaining = sub_size;
-		pthread_mutex_unlock(&data_ready);
+		p[i].list = list;
+		p[i].list_size = sub_size;
+		p[i].remaining = sub_size;
 
 		list += sub_size;
 		list_size -= sub_size;
 	}
 
+	/* Start work threads. */
+	for (i = 0; i < delta_search_threads; i++) {
+		if (!p[i].list_size)
+			continue;
+		ret = pthread_create(&p[i].thread, NULL,
+				     threaded_find_deltas, &p[i]);
+		if (ret)
+			die("unable to create thread: %s", strerror(ret));
+		active_threads++;
+	}
+
 	/*
 	 * Now let's wait for work completion.  Each time a thread is done
 	 * with its work, we steal half of the remaining work from the
