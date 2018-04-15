 	}
 }
 
-static void collect_perf_system_data(host_config_t *host, na_elem_t *out, void *data) {
-	uint64_t disk_read = 0, disk_written = 0, net_recv = 0, net_sent = 0, cpu_busy = 0, cpu_total = 0;
+static void collect_perf_system_data(host_config_t *host, na_elem_t *out, void *data) { /* {{{ */
+	counter_t disk_read = 0, disk_written = 0;
+	counter_t net_recv = 0, net_sent = 0;
+	counter_t cpu_busy = 0, cpu_total = 0;
+	unsigned int counter_flags = 0;
+
 	perf_system_data_t *perf = data;
-	const char *instance, *name;
+	const char *instance;
 	time_t timestamp;
 	na_elem_t *counter;
-	value_t values[2];
-	value_list_t vl = VALUE_LIST_INIT;
 	
 	timestamp = (time_t) na_child_get_uint64(out, "timestamp", 0);
 	out = na_elem_child(na_elem_child(out, "instances"), "instance-data");
 	instance = na_child_get_string(out, "name");
 
 	na_elem_iter_t iter = na_child_iterator(na_elem_child(out, "counters"));
 	for (counter = na_iterator_next(&iter); counter; counter = na_iterator_next(&iter)) {
+		const char *name;
+		uint64_t value;
+
 		name = na_child_get_string(counter, "name");
+		if (name == NULL)
+			continue;
+
+		value = na_child_get_uint64(counter, "value", UINT64_MAX);
+		if (value == UINT64_MAX)
+			continue;
+
 		if (!strcmp(name, "disk_data_read")) {
-			disk_read = na_child_get_uint64(counter, "value", 0) * 1024;
+			disk_read = (counter_t) (value * 1024);
+			counter_flags |= 0x01;
 		} else if (!strcmp(name, "disk_data_written")) {
-			disk_written = na_child_get_uint64(counter, "value", 0) * 1024;
+			disk_written = (counter_t) (value * 1024);
+			counter_flags |= 0x02;
 		} else if (!strcmp(name, "net_data_recv")) {
-			net_recv = na_child_get_uint64(counter, "value", 0) * 1024;
+			net_recv = (counter_t) (value * 1024);
+			counter_flags |= 0x04;
 		} else if (!strcmp(name, "net_data_sent")) {
-			net_sent = na_child_get_uint64(counter, "value", 0) * 1024;
+			net_sent = (counter_t) (value * 1024);
+			counter_flags |= 0x08;
 		} else if (!strcmp(name, "cpu_busy")) {
-			cpu_busy = na_child_get_uint64(counter, "value", 0);
+			cpu_busy = (counter_t) value;
+			counter_flags |= 0x10;
 		} else if (!strcmp(name, "cpu_elapsed_time")) {
-			cpu_total = na_child_get_uint64(counter, "value", 0);
-		} else if ((perf->flags & PERF_SYSTEM_OPS) && strlen(name) > 4 && !strcmp(name + strlen(name) - 4, "_ops")) {
-			values[0].counter = na_child_get_uint64(counter, "value", 0);
-			if (!values[0].counter) continue;
-			vl.values = values;
-			vl.values_len = 1;
-			vl.time = timestamp;
-			vl.interval = interval_g;
-			sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
-			sstrncpy(vl.host, host->name, sizeof(vl.host));
-			sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
-			sstrncpy(vl.type, "disk_ops_complex", sizeof(vl.type));
-			sstrncpy(vl.type_instance, name, sizeof(vl.plugin_instance));
-			DEBUG("%s/netapp-%s/disk_ops_complex-%s: %llu",
-					host->name, instance, name, values[0].counter);
-			plugin_dispatch_values (&vl);
+			cpu_total = (counter_t) value;
+			counter_flags |= 0x20;
+		} else if ((perf->flags & PERF_SYSTEM_OPS)
+				&& (strlen(name) > 4)
+				&& (!strcmp(name + strlen(name) - 4, "_ops"))) {
+			submit_counter (host->name, instance, "disk_ops_complex", name,
+					(counter_t) value, timestamp);
 		}
+	} /* for (counter) */
+
+	if ((perf->flags & PERF_SYSTEM_DISK)
+			&& ((counter_flags & 0x03) == 0x03))
+		submit_two_counters (host->name, instance, "disk_octets", NULL,
+				disk_read, disk_written, timestamp);
+				
+	if ((perf->flags & PERF_SYSTEM_NET)
+			&& ((counter_flags & 0x0c) == 0x0c))
+		submit_two_counters (host->name, instance, "if_octets", NULL,
+				net_recv, net_sent, timestamp);
+
+	if ((perf->flags & PERF_SYSTEM_CPU)
+			&& ((counter_flags & 0x30) == 0x30)) {
+		submit_counter (host->name, instance, "cpu", "system",
+				cpu_busy, timestamp);
+		submit_counter (host->name, instance, "cpu", "idle",
+				cpu_total - cpu_busy, timestamp);
 	}
-	if ((perf->flags & PERF_SYSTEM_DISK) && disk_read && disk_written) {
-		values[0].counter = disk_read;
-		values[1].counter = disk_written;
-		vl.values = values;
-		vl.values_len = 2;
-		vl.time = timestamp;
-		vl.interval = interval_g;
-		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
-		sstrncpy(vl.host, host->name, sizeof(vl.host));
-		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
-		sstrncpy(vl.type, "disk_octets", sizeof(vl.type));
-		vl.type_instance[0] = 0;
-		DEBUG("%s/netapp-%s/disk_octets: %"PRIu64" %"PRIu64, host->name, instance, disk_read, disk_written);
-		plugin_dispatch_values (&vl);
-	}
-	if ((perf->flags & PERF_SYSTEM_NET) && net_recv && net_sent) {
-		values[0].counter = net_recv;
-		values[1].counter = net_sent;
-		vl.values = values;
-		vl.values_len = 2;
-		vl.time = timestamp;
-		vl.interval = interval_g;
-		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
-		sstrncpy(vl.host, host->name, sizeof(vl.host));
-		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
-		sstrncpy(vl.type, "if_octets", sizeof(vl.type));
-		vl.type_instance[0] = 0;
-		DEBUG("%s/netapp-%s/if_octects: %"PRIu64" %"PRIu64, host->name, instance, net_recv, net_sent);
-		plugin_dispatch_values (&vl);
-	}
-	if ((perf->flags & PERF_SYSTEM_CPU) && cpu_busy && cpu_total) {
-		/* values[0].gauge = (double) (cpu_busy - perf->last_cpu_busy) / (cpu_total - perf->last_cpu_total) * 100; */
-		values[0].counter = cpu_busy / 10000;
-		vl.values = values;
-		vl.values_len = 1;
-		vl.time = timestamp;
-		vl.interval = interval_g;
-		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
-		sstrncpy(vl.host, host->name, sizeof(vl.host));
-		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
-		sstrncpy(vl.type, "cpu", sizeof(vl.type));
-		sstrncpy(vl.type_instance, "system", sizeof(vl.plugin_instance));
-		/* if (perf->last_cpu_busy && perf->last_cpu_total) printf("CPU: busy: %lf - idle: %lf\n", values[0].gauge, 100.0 - values[0].gauge); */
-		/* if (perf->last_cpu_busy && perf->last_cpu_total) plugin_dispatch_values ("cpu", &vl); */
-		DEBUG("%s/netapp-%s/cpu: busy: %"PRIu64" - idle: %"PRIu64, host->name, instance, cpu_busy / 10000, cpu_total / 10000);
-		plugin_dispatch_values (&vl);
-
-		/* values[0].gauge = 100.0 - (double) (cpu_busy - perf->last_cpu_busy) / (cpu_total - perf->last_cpu_total) * 100; */
-		values[0].counter = (cpu_total - cpu_busy) / 10000;
-		vl.values = values;
-		vl.values_len = 1;
-		vl.time = timestamp;
-		vl.interval = interval_g;
-		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
-		sstrncpy(vl.host, host->name, sizeof(vl.host));
-		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
-		sstrncpy(vl.type, "cpu", sizeof(vl.type));
-		sstrncpy(vl.type_instance, "idle", sizeof(vl.plugin_instance));
-		/* if (perf->last_cpu_busy && perf->last_cpu_total) plugin_dispatch_values ("cpu", &vl); */
-		plugin_dispatch_values (&vl);
-
-		perf->last_cpu_busy = cpu_busy;
-		perf->last_cpu_total = cpu_total;
-	}
-}
+} /* }}} void collect_perf_system_data */
 
 int config_init() {
 	char err[256];