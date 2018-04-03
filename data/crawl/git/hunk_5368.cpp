 }
 
 #ifdef ASYNC_AS_THREAD
+static pthread_t main_thread;
+static int main_thread_set;
+static pthread_key_t async_key;
+
 static void *run_thread(void *data)
 {
 	struct async *async = data;
+
+	pthread_setspecific(async_key, async);
+
 	intptr_t ret = async->proc(async->proc_in, async->proc_out, async->data);
 	return (void *)ret;
 }
+
+static NORETURN void die_async(const char *err, va_list params)
+{
+	vreportf("fatal: ", err, params);
+
+	if (!pthread_equal(main_thread, pthread_self())) {
+		struct async *async = pthread_getspecific(async_key);
+		if (async->proc_in >= 0)
+			close(async->proc_in);
+		if (async->proc_out >= 0)
+			close(async->proc_out);
+		pthread_exit((void *)128);
+	}
+
+	exit(128);
+}
 #endif
 
 int start_async(struct async *async)
