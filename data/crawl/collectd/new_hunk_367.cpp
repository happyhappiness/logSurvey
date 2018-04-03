	}
}

static void collect_perf_system_data(host_config_t *host, na_elem_t *out, void *data) { /* {{{ */
	counter_t disk_read = 0, disk_written = 0;
	counter_t net_recv = 0, net_sent = 0;
	counter_t cpu_busy = 0, cpu_total = 0;
	unsigned int counter_flags = 0;

	perf_system_data_t *perf = data;
	const char *instance;
	time_t timestamp;
	na_elem_t *counter;
	
	timestamp = (time_t) na_child_get_uint64(out, "timestamp", 0);
	out = na_elem_child(na_elem_child(out, "instances"), "instance-data");
	instance = na_child_get_string(out, "name");

	na_elem_iter_t iter = na_child_iterator(na_elem_child(out, "counters"));
	for (counter = na_iterator_next(&iter); counter; counter = na_iterator_next(&iter)) {
		const char *name;
		uint64_t value;

		name = na_child_get_string(counter, "name");
		if (name == NULL)
			continue;

		value = na_child_get_uint64(counter, "value", UINT64_MAX);
		if (value == UINT64_MAX)
			continue;

		if (!strcmp(name, "disk_data_read")) {
			disk_read = (counter_t) (value * 1024);
			counter_flags |= 0x01;
		} else if (!strcmp(name, "disk_data_written")) {
			disk_written = (counter_t) (value * 1024);
			counter_flags |= 0x02;
		} else if (!strcmp(name, "net_data_recv")) {
			net_recv = (counter_t) (value * 1024);
			counter_flags |= 0x04;
		} else if (!strcmp(name, "net_data_sent")) {
			net_sent = (counter_t) (value * 1024);
			counter_flags |= 0x08;
		} else if (!strcmp(name, "cpu_busy")) {
			cpu_busy = (counter_t) value;
			counter_flags |= 0x10;
		} else if (!strcmp(name, "cpu_elapsed_time")) {
			cpu_total = (counter_t) value;
			counter_flags |= 0x20;
		} else if ((perf->flags & PERF_SYSTEM_OPS)
				&& (strlen(name) > 4)
				&& (!strcmp(name + strlen(name) - 4, "_ops"))) {
			submit_counter (host->name, instance, "disk_ops_complex", name,
					(counter_t) value, timestamp);
		}
	} /* for (counter) */

	if ((perf->flags & PERF_SYSTEM_DISK)
			&& ((counter_flags & 0x03) == 0x03))
		submit_two_counters (host->name, instance, "disk_octets", NULL,
				disk_read, disk_written, timestamp);
				
	if ((perf->flags & PERF_SYSTEM_NET)
			&& ((counter_flags & 0x0c) == 0x0c))
		submit_two_counters (host->name, instance, "if_octets", NULL,
				net_recv, net_sent, timestamp);

	if ((perf->flags & PERF_SYSTEM_CPU)
			&& ((counter_flags & 0x30) == 0x30)) {
		submit_counter (host->name, instance, "cpu", "system",
				cpu_busy, timestamp);
		submit_counter (host->name, instance, "cpu", "idle",
				cpu_total - cpu_busy, timestamp);
	}
} /* }}} void collect_perf_system_data */

int config_init() {
	char err[256];