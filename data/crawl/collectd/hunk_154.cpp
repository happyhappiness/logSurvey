 static int kafka_write(const data_set_t *, const value_list_t *, user_data_t *);
 static int32_t kafka_partition(const rd_kafka_topic_t *, const void *, size_t,
                                int32_t, void *, void *);
+static void kafka_log(const rd_kafka_t *, int, const char *, const char *);
+
+static void kafka_log(const rd_kafka_t *rkt, int level,
+                      const char *fac, const char *msg)
+{
+    plugin_log(level, "%s", msg);
+}
 
 static int32_t kafka_partition(const rd_kafka_topic_t *rkt,
                                const void *keydata, size_t keylen,
