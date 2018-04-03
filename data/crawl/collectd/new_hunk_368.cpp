		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
		sstrncpy(vl.type, "cpu", sizeof(vl.type));
		sstrncpy(vl.type_instance, "system", sizeof(vl.plugin_instance));
		/* if (perf->last_cpu_busy && perf->last_cpu_total) printf("CPU: busy: %lf - idle: %lf\n", values[0].gauge, 100.0 - values[0].gauge); */
		/* if (perf->last_cpu_busy && perf->last_cpu_total) plugin_dispatch_values ("cpu", &vl); */
		DEBUG("%s/netapp-%s/cpu: busy: %"PRIu64" - idle: %"PRIu64, host->name, instance, cpu_busy / 10000, cpu_total / 10000);
		plugin_dispatch_values (&vl);

		/* values[0].gauge = 100.0 - (double) (cpu_busy - perf->last_cpu_busy) / (cpu_total - perf->last_cpu_total) * 100; */
		values[0].counter = (cpu_total - cpu_busy) / 10000;
		vl.values = values;
		vl.values_len = 1;
