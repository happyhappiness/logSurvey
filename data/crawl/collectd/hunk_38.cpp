   ERROR("ipmi plugin: %s failed: %s", func, errbuf);
 } /* void c_ipmi_error */
 
+static void c_ipmi_log(os_handler_t *handler, const char *format,
+                       enum ipmi_log_type_e log_type, va_list ap) {
+  char msg[1024];
+
+  vsnprintf(msg, sizeof(msg), format, ap);
+
+  switch (log_type) {
+  case IPMI_LOG_INFO:
+    INFO("ipmi plugin: %s", msg);
+    break;
+  case IPMI_LOG_WARNING:
+    NOTICE("ipmi plugin: %s", msg);
+    break;
+  case IPMI_LOG_SEVERE:
+    WARNING("ipmi plugin: %s", msg);
+    break;
+  case IPMI_LOG_FATAL:
+    ERROR("ipmi plugin: %s", msg);
+    break;
+  case IPMI_LOG_ERR_INFO:
+    ERROR("ipmi plugin: %s", msg);
+    break;
+#if COLLECT_DEBUG
+  case IPMI_LOG_DEBUG_START:
+  case IPMI_LOG_DEBUG:
+    fprintf(stderr, "ipmi plugin: %s\n", msg);
+    break;
+  case IPMI_LOG_DEBUG_CONT:
+  case IPMI_LOG_DEBUG_END:
+    fprintf(stderr, "%s\n", msg);
+    break;
+#else
+  case IPMI_LOG_DEBUG_START:
+  case IPMI_LOG_DEBUG:
+  case IPMI_LOG_DEBUG_CONT:
+  case IPMI_LOG_DEBUG_END:
+    break;
+#endif
+  }
+} /* void c_ipmi_log */
+
 /*
  * Sensor handlers
  */
 /* Prototype for sensor_list_remove, so sensor_read_handler can call it. */
-static int sensor_list_remove(ipmi_sensor_t *sensor);
+static int sensor_list_remove(c_ipmi_instance_t *st, ipmi_sensor_t *sensor);
 
 static void sensor_read_handler(ipmi_sensor_t *sensor, int err,
                                 enum ipmi_value_present_e value_present,
                                 unsigned int __attribute__((unused)) raw_value,
-                                double value,
-                                ipmi_states_t __attribute__((unused)) * states,
+                                double value, ipmi_states_t *states,
                                 void *user_data) {
   value_list_t vl = VALUE_LIST_INIT;
 
   c_ipmi_sensor_list_t *list_item = (c_ipmi_sensor_list_t *)user_data;
+  c_ipmi_instance_t *st = list_item->instance;
+
+  list_item->use--;
 
   if (err != 0) {
-    if ((err & 0xff) == IPMI_NOT_PRESENT_CC) {
+    if (IPMI_IS_IPMI_ERR(err) &&
+        IPMI_GET_IPMI_ERR(err) == IPMI_NOT_PRESENT_CC) {
       if (list_item->sensor_not_present == 0) {
         list_item->sensor_not_present = 1;
 
-        INFO("ipmi plugin: sensor_read_handler: sensor %s "
+        INFO("ipmi plugin: sensor_read_handler: sensor `%s` of `%s` "
              "not present.",
-             list_item->sensor_name);
+             list_item->sensor_name, st->name);
 
-        if (c_ipmi_notify_notpresent) {
+        if (st->notify_notpresent) {
           notification_t n = {
               NOTIF_WARNING, cdtime(), "", "", "ipmi", "", "", "", NULL};
 
-          sstrncpy(n.host, hostname_g, sizeof(n.host));
+          sstrncpy(n.host, (st->host != NULL) ? st->host : hostname_g,
+                   sizeof(n.host));
           sstrncpy(n.type_instance, list_item->sensor_name,
                    sizeof(n.type_instance));
           sstrncpy(n.type, list_item->sensor_type, sizeof(n.type));
