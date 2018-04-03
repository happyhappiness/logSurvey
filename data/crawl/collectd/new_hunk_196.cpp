		int siblings;

		if (cpu_is_not_present(i)) {
			WARNING("cpu%d NOT PRESENT", i);
			continue;
		}
		cpus[i].core_id = get_core_id(i);