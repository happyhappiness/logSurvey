+/**
+ * collectd - src/netapp.c
+ * Copyright (C) 2009  Sven Trenkel
+ *
+ * Permission is hereby granted, free of charge, to any person obtaining a
+ * copy of this software and associated documentation files (the "Software"),
+ * to deal in the Software without restriction, including without limitation
+ * the rights to use, copy, modify, merge, publish, distribute, sublicense,
+ * and/or sell copies of the Software, and to permit persons to whom the
+ * Software is furnished to do so, subject to the following conditions:
+ *
+ * The above copyright notice and this permission notice shall be included in
+ * all copies or substantial portions of the Software.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
+ * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
+ * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
+ * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
+ * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
+ * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
+ * DEALINGS IN THE SOFTWARE.
+ *
+ * Authors:
+ *   Sven Trenkel <sven.trenkel at noris.net>
+ **/
+
+#include "collectd.h"
+#include "common.h"
+
+#include <netapp_api.h>
+
+typedef struct host_config_s host_config_t;
+typedef void service_handler_t(host_config_t *host, na_elem_t *result, void *data);
+
+#define PERF_SYSTEM_CPU            0x01
+#define PERF_SYSTEM_NET            0x02
+#define PERF_SYSTEM_OPS            0x04
+#define PERF_SYSTEM_DISK           0x08
+#define PERF_SYSTEM_ALL            0x0F
+
+/*!
+ * \brief Persistent data for system performence counters
+ */
+
+typedef struct {
+	uint32_t flags;
+	uint64_t last_cpu_busy;
+	uint64_t last_cpu_total;
+} perf_system_data_t;
+
+/*!
+ * \brief Persistent data for WAFL performence counters. (a.k.a. cache performence)
+ */
+
+#define PERF_WAFL_NAME_CACHE       0x01
+#define PERF_WAFL_DIR_CACHE        0x02
+#define PERF_WAFL_BUF_CACHE        0x04
+#define PERF_WAFL_INODE_CACHE      0x08
+#define PERF_WAFL_ALL              0x0F
+
+typedef struct {
+	uint32_t flags;
+	uint64_t last_name_cache_hit;
+	uint64_t last_name_cache_miss;
+	uint64_t last_find_dir_hit;
+	uint64_t last_find_dir_miss;
+	uint64_t last_buf_hash_hit;
+	uint64_t last_buf_hash_miss;
+	uint64_t last_inode_cache_hit;
+	uint64_t last_inode_cache_miss;
+} perf_wafl_data_t;
+
+#define PERF_VOLUME_INIT           0x01
+#define PERF_VOLUME_IO             0x02
+#define PERF_VOLUME_OPS            0x03
+#define PERF_VOLUME_LATENCY        0x08
+#define PERF_VOLUME_ALL            0x0F
+
+typedef struct {
+	uint32_t flags;
+} perf_volume_data_t;
+
+typedef struct {
+	uint32_t flags;
+} volume_data_t;
+
+#define PERF_DISK_BUSIEST          0x01
+#define PERF_DISK_ALL              0x01
+
+typedef struct {
+	uint32_t flags;
+} perf_disk_data_t;
+
+typedef struct {
+	uint32_t flags;
+	time_t last_timestamp;
+	uint64_t last_read_latency;
+	uint64_t last_write_latency;
+	uint64_t last_read_ops;
+	uint64_t last_write_ops;
+} per_volume_perf_data_t;
+
+#define VOLUME_INIT           0x01
+#define VOLUME_DF             0x02
+#define VOLUME_SNAP           0x04
+
+typedef struct {
+	uint32_t flags;
+} per_volume_data_t;
+
+typedef struct {
+	time_t last_update;
+	double last_disk_busy_percent;
+	uint64_t last_disk_busy;
+	uint64_t last_base_for_disk_busy;
+} per_disk_perf_data_t;
+
+typedef struct service_config_s {
+	na_elem_t *query;
+	service_handler_t *handler;
+	int multiplier;
+	int skip_countdown;
+	int interval;
+	void *data;
+	struct service_config_s *next;
+} service_config_t;
+
+#define SERVICE_INIT {0, 0, 1, 1, 0, 0, 0}
+
+typedef struct volume_s {
+	char *name;
+	per_volume_perf_data_t perf_data;
+	per_volume_data_t volume_data;
+	struct volume_s *next;
+} volume_t;
+
+/*!
+ * \brief A disk in the netapp.
+ *
+ * A disk doesn't have any more information than its name atm.
+ * The name includes the "disk_" prefix.
+ */
+
+typedef struct disk_s {
+	char *name;
+	per_disk_perf_data_t perf_data;
+	struct disk_s *next;
+} disk_t;
+
+#define DISK_INIT {0, {0, 0, 0, 0}, 0}
+
+struct host_config_s {
+	na_server_t *srv;
+	char *name;
+	na_server_transport_t protocol;
+	char *host;
+	int port;
+	char *username;
+	char *password;
+	int interval;
+	service_config_t *services;
+	disk_t *disks;
+	volume_t *volumes;
+	struct host_config_s *next;
+};
+
+#define HOST_INIT {0, 0, NA_SERVER_TRANSPORT_HTTPS, 0, 0, 0, 0, 10, 0, 0, 0}
+
+static host_config_t *host_config;
+
+static volume_t *get_volume(host_config_t *host, const char *name) {
+	volume_t *v;
+	
+	for (v = host->volumes; v; v = v->next) {
+		if (!strcmp(v->name/* + 4*/, name)) return v;
+	}
+	v = malloc(sizeof(*v));
+	v->name = strdup(name);
+//	v->name = malloc(strlen(name) + 5);
+//	strcpy(v->name, "vol-");
+//	strcpy(v->name + 4, name);
+	v->perf_data.flags = 0;
+	v->volume_data.flags = 0;
+	v->next = host->volumes;
+	host->volumes = v;
+	return v;
+}
+
+static disk_t *get_disk(host_config_t *host, const char *name) {
+	disk_t *v, init = DISK_INIT;
+	
+	for (v = host->disks; v; v = v->next) {
+		if (!strcmp(v->name/* + 5*/, name)) return v;
+	}
+	v = malloc(sizeof(*v));
+	*v = init;
+	v->name = strdup(name);
+//	v->name = malloc(strlen(name) + 6);
+//	strcpy(v->name, "disk-");
+//	strcpy(v->name + 5, name);
+	v->next = host->disks;
+	host->disks = v;
+	return v;
+}
+
+static void collect_perf_wafl_data(host_config_t *host, na_elem_t *out, void *data) {
+	perf_wafl_data_t *wafl = data;
+	uint64_t name_cache_hit = 0, name_cache_miss = 0, find_dir_hit = 0, find_dir_miss = 0, buf_hash_hit = 0, buf_hash_miss = 0, inode_cache_hit = 0, inode_cache_miss = 0;
+	const char *instance, *name;
+	time_t timestamp;
+	na_elem_t *counter;
+	value_t values[2];
+	value_list_t vl = VALUE_LIST_INIT;
+	
+	timestamp = (time_t) na_child_get_uint64(out, "timestamp", 0);
+	out = na_elem_child(na_elem_child(out, "instances"), "instance-data");
+	instance = na_child_get_string(out, "name");
+
+	na_elem_iter_t iter = na_child_iterator(na_elem_child(out, "counters"));
+	for (counter = na_iterator_next(&iter); counter; counter = na_iterator_next(&iter)) {
+		name = na_child_get_string(counter, "name");
+		if (!strcmp(name, "name_cache_hit")) {
+			name_cache_hit = na_child_get_uint64(counter, "value", 0);
+		} else if (!strcmp(name, "name_cache_miss")) {
+			name_cache_miss = na_child_get_uint64(counter, "value", 0);
+		} else if (!strcmp(name, "find_dir_hit")) {
+			find_dir_hit = na_child_get_uint64(counter, "value", 0);
+		} else if (!strcmp(name, "find_dir_miss")) {
+			find_dir_miss = na_child_get_uint64(counter, "value", 0);
+		} else if (!strcmp(name, "buf_hash_hit")) {
+			buf_hash_hit = na_child_get_uint64(counter, "value", 0);
+		} else if (!strcmp(name, "buf_hash_miss")) {
+			buf_hash_miss = na_child_get_uint64(counter, "value", 0);
+		} else if (!strcmp(name, "inode_cache_hit")) {
+			inode_cache_hit = na_child_get_uint64(counter, "value", 0);
+		} else if (!strcmp(name, "inode_cache_miss")) {
+			inode_cache_miss = na_child_get_uint64(counter, "value", 0);
+		}
+	}
+	if ((wafl->flags & PERF_WAFL_NAME_CACHE) && name_cache_hit && name_cache_miss) {
+		values[0].gauge = 0;
+		if (name_cache_miss - wafl->last_name_cache_miss + name_cache_hit - wafl->last_name_cache_hit) values[0].gauge = 100.0 * (name_cache_hit - wafl->last_name_cache_hit) / (name_cache_miss - wafl->last_name_cache_miss + name_cache_hit - wafl->last_name_cache_hit);
+		vl.values = values;
+		vl.values_len = 1;
+		vl.time = timestamp;
+		vl.interval = interval_g;
+		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+		sstrncpy(vl.host, host->name, sizeof(vl.host));
+		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
+		sstrncpy(vl.type_instance, "name_cache_hit", sizeof(vl.type_instance));
+		if (wafl->last_name_cache_hit && wafl->last_name_cache_miss) {
+			DEBUG("%s/netapp-%s/cache_ratio: %lf", host->name, instance, values[0].gauge);
+			plugin_dispatch_values ("cache_ratio", &vl);
+		}
+		wafl->last_name_cache_hit = name_cache_hit;
+		wafl->last_name_cache_miss = name_cache_miss;
+	}
+	if ((wafl->flags & PERF_WAFL_DIR_CACHE) && find_dir_hit && find_dir_miss) {
+		values[0].gauge = 0;
+		if (find_dir_miss - wafl->last_find_dir_miss + find_dir_hit - wafl->last_find_dir_hit) values[0].gauge = 100.0 * (find_dir_hit - wafl->last_find_dir_hit) / (find_dir_miss - wafl->last_find_dir_miss + find_dir_hit - wafl->last_find_dir_hit);
+		vl.values = values;
+		vl.values_len = 1;
+		vl.time = timestamp;
+		vl.interval = interval_g;
+		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+		sstrncpy(vl.host, host->name, sizeof(vl.host));
+		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
+		sstrncpy(vl.type_instance, "find_dir_hit", sizeof(vl.type_instance));
+		if (wafl->last_find_dir_hit && wafl->last_find_dir_miss) {
+			DEBUG("%s/netapp-%s/cache_ratio: %lf", host->name, instance, values[0].gauge);
+			plugin_dispatch_values ("cache_ratio", &vl);
+		}
+		wafl->last_find_dir_hit = find_dir_hit;
+		wafl->last_find_dir_miss = find_dir_miss;
+	}
+	if ((wafl->flags & PERF_WAFL_BUF_CACHE) && buf_hash_hit && buf_hash_miss) {
+		values[0].gauge = 0;
+		if (buf_hash_miss - wafl->last_buf_hash_miss + buf_hash_hit - wafl->last_buf_hash_hit) values[0].gauge = 100.0 * (buf_hash_hit - wafl->last_buf_hash_hit) / (buf_hash_miss - wafl->last_buf_hash_miss + buf_hash_hit - wafl->last_buf_hash_hit);
+		vl.values = values;
+		vl.values_len = 1;
+		vl.time = timestamp;
+		vl.interval = interval_g;
+		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+		sstrncpy(vl.host, host->name, sizeof(vl.host));
+		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
+		sstrncpy(vl.type_instance, "buf_hash_hit", sizeof(vl.type_instance));
+		if (wafl->last_buf_hash_hit && wafl->last_buf_hash_miss) {
+			DEBUG("%s/netapp-%s/cache_ratio: %lf", host->name, instance, values[0].gauge);
+			plugin_dispatch_values ("cache_ratio", &vl);
+		}
+		wafl->last_buf_hash_hit = buf_hash_hit;
+		wafl->last_buf_hash_miss = buf_hash_miss;
+	}
+	if ((wafl->flags & PERF_WAFL_INODE_CACHE) && inode_cache_hit && inode_cache_miss) {
+		values[0].gauge = 0;
+		if (inode_cache_miss - wafl->last_inode_cache_miss + inode_cache_hit - wafl->last_inode_cache_hit) values[0].gauge = 100.0 * (inode_cache_hit - wafl->last_inode_cache_hit) / (inode_cache_miss - wafl->last_inode_cache_miss + inode_cache_hit - wafl->last_inode_cache_hit);
+		vl.values = values;
+		vl.values_len = 1;
+		vl.time = timestamp;
+		vl.interval = interval_g;
+		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+		sstrncpy(vl.host, host->name, sizeof(vl.host));
+		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
+		sstrncpy(vl.type_instance, "inode_cache_hit", sizeof(vl.type_instance));
+		if (wafl->last_inode_cache_hit && wafl->last_inode_cache_miss) {
+			DEBUG("%s/netapp-%s/cache_ratio: %lf", host->name, instance, values[0].gauge);
+			plugin_dispatch_values ("cache_ratio", &vl);
+		}
+		wafl->last_inode_cache_hit = inode_cache_hit;
+		wafl->last_inode_cache_miss = inode_cache_miss;
+	}
+}
+
+static void collect_perf_disk_data(host_config_t *host, na_elem_t *out, void *data) {
+	perf_disk_data_t *perf = data;
+	const char *name;
+	time_t timestamp;
+	na_elem_t *counter, *inst;
+	disk_t *disk, *worst_disk = 0;
+	value_t values[2];
+	value_list_t vl = VALUE_LIST_INIT;
+	
+	timestamp = (time_t) na_child_get_uint64(out, "timestamp", 0);
+	out = na_elem_child(out, "instances");
+	na_elem_iter_t inst_iter = na_child_iterator(out);
+	for (inst = na_iterator_next(&inst_iter); inst; inst = na_iterator_next(&inst_iter)) {
+		uint64_t disk_busy = 0, base_for_disk_busy = 0;
+
+		disk = get_disk(host, na_child_get_string(inst, "name"));
+		na_elem_iter_t count_iter = na_child_iterator(na_elem_child(inst, "counters"));
+		for (counter = na_iterator_next(&count_iter); counter; counter = na_iterator_next(&count_iter)) {
+			name = na_child_get_string(counter, "name");
+			if (!strcmp(name, "disk_busy")) {
+				disk_busy = na_child_get_uint64(counter, "value", 0);
+			} else if (!strcmp(name, "base_for_disk_busy")) {
+				base_for_disk_busy = na_child_get_uint64(counter, "value", 0);
+			}
+		}
+		if (disk_busy && base_for_disk_busy) {
+			disk->perf_data.last_update = timestamp;
+			disk->perf_data.last_disk_busy_percent = 0;
+			if (base_for_disk_busy - disk->perf_data.last_base_for_disk_busy) disk->perf_data.last_disk_busy_percent = 100.0 * (disk_busy - disk->perf_data.last_disk_busy) / (base_for_disk_busy - disk->perf_data.last_base_for_disk_busy);
+			if (disk->perf_data.last_disk_busy && disk->perf_data.last_base_for_disk_busy && (!worst_disk || worst_disk->perf_data.last_disk_busy_percent < disk->perf_data.last_disk_busy_percent)) worst_disk = disk;
+			disk->perf_data.last_disk_busy = disk_busy;
+			disk->perf_data.last_base_for_disk_busy = base_for_disk_busy;
+		}
+	}
+	if ((perf->flags & PERF_DISK_BUSIEST) && worst_disk) {
+		values[0].gauge = worst_disk->perf_data.last_disk_busy_percent;
+		vl.values = values;
+		vl.values_len = 1;
+		vl.time = timestamp;
+		vl.interval = interval_g;
+		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+		sstrncpy(vl.host, host->name, sizeof(vl.host));
+		sstrncpy(vl.plugin_instance, "system", sizeof(vl.plugin_instance));
+		sstrncpy(vl.type_instance, "disk_busy", sizeof(vl.type_instance));
+		DEBUG("%s/netapp-system/percent-disk_busy: %lf", host->name, worst_disk->perf_data.last_disk_busy_percent);
+		plugin_dispatch_values ("percent", &vl);
+	}
+}
+
+static void collect_volume_data(host_config_t *host, na_elem_t *out, void *data) {
+	na_elem_t *inst, *sis;
+	volume_t *volume;
+	volume_data_t *volume_data = data;
+	value_t values[1];
+	value_list_t vl = VALUE_LIST_INIT;
+
+	out = na_elem_child(out, "volumes");
+	na_elem_iter_t inst_iter = na_child_iterator(out);
+	for (inst = na_iterator_next(&inst_iter); inst; inst = na_iterator_next(&inst_iter)) {
+		uint64_t size_free = 0, size_used = 0, snap_reserved = 0, sis_saved = 0;
+		volume = get_volume(host, na_child_get_string(inst, "name"));
+		if (!(volume->volume_data.flags & VOLUME_INIT)) volume->volume_data.flags = volume_data->flags;
+		if (!(volume->volume_data.flags & VOLUME_DF)) continue;
+		size_free = na_child_get_uint64(inst, "size-available", 0);
+		size_used = na_child_get_uint64(inst, "size-used", 0);
+		snap_reserved = na_child_get_uint64(inst, "snapshot-blocks-reserved", 0) * 1024;
+
+		vl.values_len = 1;
+		vl.values = values;
+		vl.time = time(0);
+		vl.interval = interval_g;
+		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+		sstrncpy(vl.host, host->name, sizeof(vl.host));
+		sstrncpy(vl.plugin_instance, volume->name, sizeof(vl.plugin_instance));
+
+		values[0].gauge = size_used;
+		sstrncpy(vl.type_instance, "used", sizeof(vl.type_instance));
+		DEBUG("%s/netapp-%s/df_complex-used: %llu", host->name, volume->name, size_used);
+		plugin_dispatch_values ("df_complex", &vl);
+
+		values[0].gauge = size_free;
+		sstrncpy(vl.type_instance, "free", sizeof(vl.type_instance));
+		DEBUG("%s/netapp-%s/df_complex-free: %llu", host->name, volume->name, size_free);
+		plugin_dispatch_values ("df_complex", &vl);
+
+		if (snap_reserved) {
+			values[0].gauge = snap_reserved;
+			sstrncpy(vl.type_instance, "snap_reserved", sizeof(vl.type_instance));
+			DEBUG("%s/netapp-%s/df_complex-snap_reserved: %llu", host->name, volume->name, snap_reserved);
+			plugin_dispatch_values ("df_complex", &vl);
+		}
+
+		sis = na_elem_child(inst, "sis");
+		if (sis && !strcmp(na_child_get_string(sis, "state"), "enabled")) {
+			uint64_t sis_saved_reported = na_child_get_uint64(sis, "size-saved", 0), sis_saved_percent = na_child_get_uint64(sis, "percentage-saved", 0);
+			/* size-saved is actually a 32 bit number, so ... time for some guesswork. */
+			if (sis_saved_reported >> 32) {
+				/* In case they ever fix this bug. */
+				sis_saved = sis_saved_reported;
+			} else {
+				uint64_t real_saved = sis_saved_percent * size_used / (100 - sis_saved_percent);
+				uint64_t overflow_guess = real_saved >> 32;
+				uint64_t guess1 = overflow_guess ? ((overflow_guess - 1) << 32) + sis_saved_reported : sis_saved_reported;
+				uint64_t guess2 = (overflow_guess << 32) + sis_saved_reported;
+				uint64_t guess3 = ((overflow_guess + 1) << 32) + sis_saved_reported;
+				
+				if (real_saved < guess2) {
+					if (real_saved - guess1 < guess2 - real_saved) sis_saved = guess1;
+					else sis_saved = guess2;
+				} else {
+					if (real_saved - guess2 < guess3 - real_saved) sis_saved = guess2;
+					else sis_saved = guess3;
+				}
+			}
+			values[0].gauge = sis_saved;
+			sstrncpy(vl.type_instance, "sis_saved", sizeof(vl.type_instance));
+			DEBUG("%s/netapp-%s/df_complex-sis_saved: %llu", host->name, volume->name, sis_saved);
+			plugin_dispatch_values ("df_complex", &vl);
+		}
+	}
+}
+
+static void collect_perf_volume_data(host_config_t *host, na_elem_t *out, void *data) {
+	perf_volume_data_t *perf = data;
+	const char *name;
+	time_t timestamp;
+	na_elem_t *counter, *inst;
+	volume_t *volume;
+	value_t values[2];
+	value_list_t vl = VALUE_LIST_INIT;
+	
+	timestamp = (time_t) na_child_get_uint64(out, "timestamp", 0);
+	out = na_elem_child(out, "instances");
+	na_elem_iter_t inst_iter = na_child_iterator(out);
+	for (inst = na_iterator_next(&inst_iter); inst; inst = na_iterator_next(&inst_iter)) {
+		uint64_t read_data = 0, write_data = 0, read_ops = 0, write_ops = 0, read_latency = 0, write_latency = 0;
+
+		volume = get_volume(host, na_child_get_string(inst, "name"));
+		if (!volume->perf_data.flags) {
+			volume->perf_data.flags = perf->flags;
+			volume->perf_data.last_read_latency = volume->perf_data.last_read_ops = 0;
+			volume->perf_data.last_write_latency = volume->perf_data.last_write_ops = 0;
+		}
+		na_elem_iter_t count_iter = na_child_iterator(na_elem_child(inst, "counters"));
+		for (counter = na_iterator_next(&count_iter); counter; counter = na_iterator_next(&count_iter)) {
+			name = na_child_get_string(counter, "name");
+			if (!strcmp(name, "read_ops")) {
+				read_ops = na_child_get_uint64(counter, "value", 0);
+			} else if (!strcmp(name, "write_ops")) {
+				write_ops = na_child_get_uint64(counter, "value", 0);
+			} else if (!strcmp(name, "read_data")) {
+				read_data = na_child_get_uint64(counter, "value", 0);
+			} else if (!strcmp(name, "write_data")) {
+				write_data = na_child_get_uint64(counter, "value", 0);
+			} else if (!strcmp(name, "read_latency")) {
+				read_latency = na_child_get_uint64(counter, "value", 0);
+			} else if (!strcmp(name, "write_latency")) {
+				write_latency = na_child_get_uint64(counter, "value", 0);
+			}
+		}
+		if (read_ops && write_ops) {
+			values[0].counter = read_ops;
+			values[1].counter = write_ops;
+			vl.values = values;
+			vl.values_len = 2;
+			vl.time = timestamp;
+			vl.interval = interval_g;
+			sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+			sstrncpy(vl.host, host->name, sizeof(vl.host));
+			sstrncpy(vl.plugin_instance, volume->name, sizeof(vl.plugin_instance));
+			vl.type_instance[0] = 0;
+			if (volume->perf_data.flags & PERF_VOLUME_OPS) {
+				/* We might need the data even if it wasn't configured to calculate
+				   the latency. Therefore we just skip the dispatch. */
+				DEBUG("%s/netapp-%s/disk_ops: %llu %llu", host->name, instance, read_ops, write_ops);
+				plugin_dispatch_values("disk_ops", &vl);
+			}
+			if ((volume->perf_data.flags & PERF_VOLUME_LATENCY) && read_latency && write_latency) {
+				values[0].gauge = 0;
+				if (read_ops - volume->perf_data.last_read_ops) values[0].gauge = (read_latency - volume->perf_data.last_read_latency) * (timestamp - volume->perf_data.last_timestamp) / (read_ops - volume->perf_data.last_read_ops);
+				values[1].gauge = 0;
+				if (write_ops - volume->perf_data.last_write_ops) values[1].gauge = (write_latency - volume->perf_data.last_write_latency) * (timestamp - volume->perf_data.last_timestamp) / (write_ops - volume->perf_data.last_write_ops);
+				vl.values = values;
+				vl.values_len = 2;
+				vl.time = timestamp;
+				vl.interval = interval_g;
+				sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+				sstrncpy(vl.host, host->name, sizeof(vl.host));
+				sstrncpy(vl.plugin_instance, volume->name, sizeof(vl.plugin_instance));
+				vl.type_instance[0] = 0;
+				if (volume->perf_data.last_read_ops && volume->perf_data.last_write_ops) {
+					DEBUG("%s/netapp-%s/disk_latency: lrlc: %llu ro: %llu lro: %llu rl: %llu lrl: %llu %llu %llu", host->name, instance, volume->perf_data.last_read_latency_counter, read_ops, volume->perf_data.last_read_ops, read_latency, volume->perf_data.last_read_latency, values[0].counter, values[1].counter);
+					plugin_dispatch_values("disk_latency", &vl);
+				}
+				volume->perf_data.last_timestamp = timestamp;
+				volume->perf_data.last_read_latency = read_latency;
+				volume->perf_data.last_read_ops = read_ops;
+				volume->perf_data.last_write_latency = write_latency;
+				volume->perf_data.last_write_ops = write_ops;
+			}
+		}
+		if ((volume->perf_data.flags & PERF_VOLUME_IO) && read_data && write_data) {
+			values[0].counter = read_data;
+			values[1].counter = write_data;
+			vl.values = values;
+			vl.values_len = 2;
+			vl.time = timestamp;
+			vl.interval = interval_g;
+			sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+			sstrncpy(vl.host, host->name, sizeof(vl.host));
+			sstrncpy(vl.plugin_instance, volume->name, sizeof(vl.plugin_instance));
+			vl.type_instance[0] = 0;
+			DEBUG("%s/netapp-%s/disk_octets: %llu %llu", host->name, instance, read_data, write_data);
+			plugin_dispatch_values ("disk_octets", &vl);
+		}
+	}
+}
+
+static void collect_perf_system_data(host_config_t *host, na_elem_t *out, void *data) {
+	uint64_t disk_read = 0, disk_written = 0, net_recv = 0, net_sent = 0, cpu_busy = 0, cpu_total = 0;
+	perf_system_data_t *perf = data;
+	const char *instance, *name;
+	time_t timestamp;
+	na_elem_t *counter;
+	value_t values[2];
+	value_list_t vl = VALUE_LIST_INIT;
+	
+	timestamp = (time_t) na_child_get_uint64(out, "timestamp", 0);
+	out = na_elem_child(na_elem_child(out, "instances"), "instance-data");
+	instance = na_child_get_string(out, "name");
+
+	na_elem_iter_t iter = na_child_iterator(na_elem_child(out, "counters"));
+	for (counter = na_iterator_next(&iter); counter; counter = na_iterator_next(&iter)) {
+		name = na_child_get_string(counter, "name");
+		if (!strcmp(name, "disk_data_read")) {
+			disk_read = na_child_get_uint64(counter, "value", 0) * 1024;
+		} else if (!strcmp(name, "disk_data_written")) {
+			disk_written = na_child_get_uint64(counter, "value", 0) * 1024;
+		} else if (!strcmp(name, "net_data_recv")) {
+			net_recv = na_child_get_uint64(counter, "value", 0) * 1024;
+		} else if (!strcmp(name, "net_data_sent")) {
+			net_sent = na_child_get_uint64(counter, "value", 0) * 1024;
+		} else if (!strcmp(name, "cpu_busy")) {
+			cpu_busy = na_child_get_uint64(counter, "value", 0);
+		} else if (!strcmp(name, "cpu_elapsed_time")) {
+			cpu_total = na_child_get_uint64(counter, "value", 0);
+		} else if ((perf->flags & PERF_SYSTEM_OPS) && strlen(name) > 4 && !strcmp(name + strlen(name) - 4, "_ops")) {
+			values[0].counter = na_child_get_uint64(counter, "value", 0);
+			if (!values[0].counter) continue;
+			vl.values = values;
+			vl.values_len = 1;
+			vl.time = timestamp;
+			vl.interval = interval_g;
+			sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+			sstrncpy(vl.host, host->name, sizeof(vl.host));
+			sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
+			sstrncpy(vl.type_instance, name, sizeof(vl.plugin_instance));
+			DEBUG("%s/netapp-%s/disk_ops_complex-%s: %llu", host->name, instance, name, values[0].counter);
+			plugin_dispatch_values ("disk_ops_complex", &vl);
+		}
+	}
+	if ((perf->flags & PERF_SYSTEM_DISK) && disk_read && disk_written) {
+		values[0].counter = disk_read;
+		values[1].counter = disk_written;
+		vl.values = values;
+		vl.values_len = 2;
+		vl.time = timestamp;
+		vl.interval = interval_g;
+		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+		sstrncpy(vl.host, host->name, sizeof(vl.host));
+		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
+		vl.type_instance[0] = 0;
+		DEBUG("%s/netapp-%s/disk_octets: %llu %llu", host->name, instance, disk_read, disk_written);
+		plugin_dispatch_values ("disk_octets", &vl);
+	}
+	if ((perf->flags & PERF_SYSTEM_NET) && net_recv && net_sent) {
+		values[0].counter = net_recv;
+		values[1].counter = net_sent;
+		vl.values = values;
+		vl.values_len = 2;
+		vl.time = timestamp;
+		vl.interval = interval_g;
+		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+		sstrncpy(vl.host, host->name, sizeof(vl.host));
+		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
+		vl.type_instance[0] = 0;
+		DEBUG("%s/netapp-%s/if_octects: %llu %llu", host->name, instance, net_recv, net_sent);
+		plugin_dispatch_values ("if_octets", &vl);
+	}
+	if ((perf->flags & PERF_SYSTEM_CPU) && cpu_busy && cpu_total) {
+//		values[0].gauge = (double) (cpu_busy - perf->last_cpu_busy) / (cpu_total - perf->last_cpu_total) * 100;
+		values[0].counter = cpu_busy / 10000;
+		vl.values = values;
+		vl.values_len = 1;
+		vl.time = timestamp;
+		vl.interval = interval_g;
+		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+		sstrncpy(vl.host, host->name, sizeof(vl.host));
+		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
+		sstrncpy(vl.type_instance, "system", sizeof(vl.plugin_instance));
+//		if (perf->last_cpu_busy && perf->last_cpu_total) printf("CPU: busy: %lf - idle: %lf\n", values[0].gauge, 100.0 - values[0].gauge);
+//		if (perf->last_cpu_busy && perf->last_cpu_total) plugin_dispatch_values ("cpu", &vl);
+		DEBUG("%s/netapp-%s/cpu: busy: %llu - idle: %llu", host->name, instance, cpu_busy / 10000, cpu_total / 10000);
+		plugin_dispatch_values ("cpu", &vl);
+
+//		values[0].gauge = 100.0 - (double) (cpu_busy - perf->last_cpu_busy) / (cpu_total - perf->last_cpu_total) * 100;
+		values[0].counter = (cpu_total - cpu_busy) / 10000;
+		vl.values = values;
+		vl.values_len = 1;
+		vl.time = timestamp;
+		vl.interval = interval_g;
+		sstrncpy(vl.plugin, "netapp", sizeof(vl.plugin));
+		sstrncpy(vl.host, host->name, sizeof(vl.host));
+		sstrncpy(vl.plugin_instance, instance, sizeof(vl.plugin_instance));
+		sstrncpy(vl.type_instance, "idle", sizeof(vl.plugin_instance));
+//		if (perf->last_cpu_busy && perf->last_cpu_total) plugin_dispatch_values ("cpu", &vl);
+		plugin_dispatch_values ("cpu", &vl);
+
+		perf->last_cpu_busy = cpu_busy;
+		perf->last_cpu_total = cpu_total;
+	}
+}
+
+int config_init() {
+	char err[256];
+	na_elem_t *e;
+	host_config_t *host;
+	service_config_t *service;
+	
+	if (!host_config) {
+		WARNING("netapp plugin: Plugin loaded but no hosts defined.");
+		return 1;
+	}
+
+	if (!na_startup(err, sizeof(err))) {
+		ERROR("netapp plugin: Error initializing netapp API: %s", err);
+		return 1;
+	}
+
+	for (host = host_config; host; host = host->next) {
+		host->srv = na_server_open(host->host, 1, 1); 
+		na_server_set_transport_type(host->srv, host->protocol, 0);
+		na_server_set_port(host->srv, host->port);
+		na_server_style(host->srv, NA_STYLE_LOGIN_PASSWORD);
+		na_server_adminuser(host->srv, host->username, host->password);
+		na_server_set_timeout(host->srv, 5);
+		for (service = host->services; service; service = service->next) {
+			service->interval = host->interval * service->multiplier;
+			if (service->handler == collect_perf_system_data) {
+				service->query = na_elem_new("perf-object-get-instances");
+				na_child_add_string(service->query, "objectname", "system");
+			} else if (service->handler == collect_perf_volume_data) {
+				service->query = na_elem_new("perf-object-get-instances");
+				na_child_add_string(service->query, "objectname", "volume");
+/*				e = na_elem_new("instances");
+				na_child_add_string(e, "foo", "system");
+				na_child_add(root, e);*/
+				e = na_elem_new("counters");
+				na_child_add_string(e, "foo", "read_ops");
+				na_child_add_string(e, "foo", "write_ops");
+				na_child_add_string(e, "foo", "read_data");
+				na_child_add_string(e, "foo", "write_data");
+				na_child_add_string(e, "foo", "read_latency");
+				na_child_add_string(e, "foo", "write_latency");
+				na_child_add(service->query, e);
+			} else if (service->handler == collect_perf_wafl_data) {
+				service->query = na_elem_new("perf-object-get-instances");
+				na_child_add_string(service->query, "objectname", "wafl");
+/*				e = na_elem_new("instances");
+				na_child_add_string(e, "foo", "system");
+				na_child_add(root, e);*/
+				e = na_elem_new("counters");
+				na_child_add_string(e, "foo", "name_cache_hit");
+				na_child_add_string(e, "foo", "name_cache_miss");
+				na_child_add_string(e, "foo", "find_dir_hit");
+				na_child_add_string(e, "foo", "find_dir_miss");
+				na_child_add_string(e, "foo", "buf_hash_hit");
+				na_child_add_string(e, "foo", "buf_hash_miss");
+				na_child_add_string(e, "foo", "inode_cache_hit");
+				na_child_add_string(e, "foo", "inode_cache_miss");
+//				na_child_add_string(e, "foo", "inode_eject_time");
+//				na_child_add_string(e, "foo", "buf_eject_time");
+				na_child_add(service->query, e);
+			} else if (service->handler == collect_perf_disk_data) {
+				service->query = na_elem_new("perf-object-get-instances");
+				na_child_add_string(service->query, "objectname", "disk");
+				e = na_elem_new("counters");
+				na_child_add_string(e, "foo", "disk_busy");
+				na_child_add_string(e, "foo", "base_for_disk_busy");
+				na_child_add(service->query, e);
+			} else if (service->handler == collect_volume_data) {
+				service->query = na_elem_new("volume-list-info");
+//				na_child_add_string(service->query, "objectname", "volume");
+//			} else if (service->handler == collect_snapshot_data) {
+//				service->query = na_elem_new("snapshot-list-info");
+			}
+		}
+	}
+	return 0;
+}
+
+static void set_global_perf_vol_flag(const host_config_t *host, uint32_t flag, int value) {
+	volume_t *v;
+	
+	for (v = host->volumes; v; v = v->next) {
+		v->perf_data.flags &= ~flag;
+		if (value) v->perf_data.flags |= flag;
+	}
+}
+
+static void set_global_vol_flag(const host_config_t *host, uint32_t flag, int value) {
+	volume_t *v;
+	
+	for (v = host->volumes; v; v = v->next) {
+		v->volume_data.flags &= ~flag;
+		if (value) v->volume_data.flags |= flag;
+	}
+}
+
+static void process_perf_volume_flag(host_config_t *host, perf_volume_data_t *perf_volume, const oconfig_item_t *item, uint32_t flag) {
+	int n;
+	
+	for (n = 0; n < item->values_num; ++n) {
+		int minus = 0;
+		const char *name = item->values[n].value.string;
+		volume_t *v;
+		if (item->values[n].type != OCONFIG_TYPE_STRING) {
+			WARNING("netapp plugin: Ignoring non-string argument in \"GetVolPerfData\" block for host %s", host->name);
+			continue;
+		}
+		if (name[0] == '+') {
+			++name;
+		} else if (name[0] == '-') {
+			minus = 1;
+			++name;
+		}
+		if (!name[0]) {
+			perf_volume->flags &= ~flag;
+			if (!minus) perf_volume->flags |= flag;
+			set_global_perf_vol_flag(host, flag, !minus);
+			continue;
+		}
+		v = get_volume(host, name);
+		if (!v->perf_data.flags) {
+			v->perf_data.flags = perf_volume->flags;
+			v->perf_data.last_read_latency = v->perf_data.last_read_ops = 0;
+			v->perf_data.last_write_latency = v->perf_data.last_write_ops = 0;
+		}
+		v->perf_data.flags &= ~flag;
+		if (!minus) v->perf_data.flags |= flag;
+	}
+}
+
+static void process_volume_flag(host_config_t *host, volume_data_t *volume_data, const oconfig_item_t *item, uint32_t flag) {
+	int n;
+	
+	for (n = 0; n < item->values_num; ++n) {
+		int minus = 0;
+		const char *name = item->values[n].value.string;
+		volume_t *v;
+		if (item->values[n].type != OCONFIG_TYPE_STRING) {
+			WARNING("netapp plugin: Ignoring non-string argument in \"GetVolData\" block for host %s", host->name);
+			continue;
+		}
+		if (name[0] == '+') {
+			++name;
+		} else if (name[0] == '-') {
+			minus = 1;
+			++name;
+		}
+		if (!name[0]) {
+			volume_data->flags &= ~flag;
+			if (!minus) volume_data->flags |= flag;
+			set_global_vol_flag(host, flag, !minus);
+			continue;
+		}
+		v = get_volume(host, name);
+		if (!v->volume_data.flags) v->volume_data.flags = volume_data->flags;
+		v->volume_data.flags &= ~flag;
+		if (!minus) v->volume_data.flags |= flag;
+	}
+}
+
+static void build_perf_vol_config(host_config_t *host, const oconfig_item_t *ci) {
+	int i, had_io = 0, had_ops = 0, had_latency = 0;
+	service_config_t *service;
+	perf_volume_data_t *perf_volume;
+	
+	service = malloc(sizeof(*service));
+	service->query = 0;
+	service->handler = collect_perf_volume_data;
+	perf_volume = service->data = malloc(sizeof(*perf_volume));
+	perf_volume->flags = PERF_VOLUME_INIT;
+	service->next = host->services;
+	host->services = service;
+	for (i = 0; i < ci->children_num; ++i) {
+		oconfig_item_t *item = ci->children + i;
+		
+//		if (!item || !item->key || !*item->key) continue;
+		if (!strcasecmp(item->key, "Multiplier")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_NUMBER || item->values[0].value.number != (int) item->values[0].value.number || item->values[0].value.number < 1) {
+				WARNING("netapp plugin: \"Multiplier\" of host %s service GetVolPerfData needs exactly one positive integer argument.", host->name);
+				continue;
+			}
+			service->skip_countdown = service->multiplier = item->values[0].value.number;
+		} else if (!strcasecmp(item->key, "GetIO")) {
+			had_io = 1;
+			process_perf_volume_flag(host, perf_volume, item, PERF_VOLUME_IO);
+		} else if (!strcasecmp(item->key, "GetOps")) {
+			had_ops = 1;
+			process_perf_volume_flag(host, perf_volume, item, PERF_VOLUME_OPS);
+		} else if (!strcasecmp(item->key, "GetLatency")) {
+			had_latency = 1;
+			process_perf_volume_flag(host, perf_volume, item, PERF_VOLUME_LATENCY);
+		}
+	}
+	if (!had_io) {
+		perf_volume->flags |= PERF_VOLUME_IO;
+		set_global_perf_vol_flag(host, PERF_VOLUME_IO, 1);
+	}
+	if (!had_ops) {
+		perf_volume->flags |= PERF_VOLUME_OPS;
+		set_global_perf_vol_flag(host, PERF_VOLUME_OPS, 1);
+	}
+	if (!had_latency) {
+		perf_volume->flags |= PERF_VOLUME_LATENCY;
+		set_global_perf_vol_flag(host, PERF_VOLUME_LATENCY, 1);
+	}
+}
+
+static void build_volume_config(host_config_t *host, oconfig_item_t *ci) {
+	int i, had_df = 0;
+	service_config_t *service;
+	volume_data_t *volume_data;
+	
+	service = malloc(sizeof(*service));
+	service->query = 0;
+	service->handler = collect_volume_data;
+	volume_data = service->data = malloc(sizeof(*volume_data));
+	volume_data->flags = VOLUME_INIT;
+	service->next = host->services;
+	host->services = service;
+	for (i = 0; i < ci->children_num; ++i) {
+		oconfig_item_t *item = ci->children + i;
+		
+//		if (!item || !item->key || !*item->key) continue;
+		if (!strcasecmp(item->key, "Multiplier")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_NUMBER || item->values[0].value.number != (int) item->values[0].value.number || item->values[0].value.number < 1) {
+				WARNING("netapp plugin: \"Multiplier\" of host %s service GetVolPerfData needs exactly one positive integer argument.", host->name);
+				continue;
+			}
+			service->skip_countdown = service->multiplier = item->values[0].value.number;
+		} else if (!strcasecmp(item->key, "GetDiskUtil")) {
+			had_df = 1;
+			process_volume_flag(host, volume_data, item, VOLUME_DF);
+		}
+	}
+	if (!had_df) {
+		volume_data->flags |= VOLUME_DF;
+		set_global_vol_flag(host, VOLUME_DF, 1);
+	}
+/*	service = malloc(sizeof(*service));
+	service->query = 0;
+	service->handler = collect_snapshot_data;
+	service->data = volume_data;
+	service->next = temp->services;
+	temp->services = service;*/
+}
+
+static void build_perf_disk_config(host_config_t *temp, oconfig_item_t *ci) {
+	int i;
+	service_config_t *service;
+	perf_disk_data_t *perf_disk;
+	
+	service = malloc(sizeof(*service));
+	service->query = 0;
+	service->handler = collect_perf_disk_data;
+	perf_disk = service->data = malloc(sizeof(*perf_disk));
+	perf_disk->flags = PERF_DISK_ALL;
+	service->next = temp->services;
+	temp->services = service;
+	for (i = 0; i < ci->children_num; ++i) {
+		oconfig_item_t *item = ci->children + i;
+		
+//		if (!item || !item->key || !*item->key) continue;
+		if (!strcasecmp(item->key, "Multiplier")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_NUMBER || item->values[0].value.number != (int) item->values[0].value.number || item->values[0].value.number < 1) {
+				WARNING("netapp plugin: \"Multiplier\" of host %s service GetWaflPerfData needs exactly one positive integer argument.", ci->values[0].value.string);
+				continue;
+			}
+			service->skip_countdown = service->multiplier = item->values[0].value.number;
+		} else if (!strcasecmp(item->key, "GetBusy")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN) {
+				WARNING("netapp plugin: \"GetBusy\" of host %s service GetDiskPerfData needs exactly one bool argument.", ci->values[0].value.string);
+				continue;
+			}
+			perf_disk->flags = (perf_disk->flags & ~PERF_SYSTEM_CPU) | (item->values[0].value.boolean ? PERF_DISK_BUSIEST : 0);
+		}
+	}
+}
+
+static void build_perf_wafl_config(host_config_t *temp, oconfig_item_t *ci) {
+	int i;
+	service_config_t *service;
+	perf_wafl_data_t *perf_wafl;
+	
+	service = malloc(sizeof(*service));
+	service->query = 0;
+	service->handler = collect_perf_wafl_data;
+	perf_wafl = service->data = malloc(sizeof(*perf_wafl));
+	perf_wafl->flags = PERF_WAFL_ALL;
+	perf_wafl->last_name_cache_hit = 0;
+	perf_wafl->last_name_cache_miss = 0;
+	perf_wafl->last_find_dir_hit = 0;
+	perf_wafl->last_find_dir_miss = 0;
+	perf_wafl->last_buf_hash_hit = 0;
+	perf_wafl->last_buf_hash_miss = 0;
+	perf_wafl->last_inode_cache_hit = 0;
+	perf_wafl->last_inode_cache_miss = 0;
+	service->next = temp->services;
+	temp->services = service;
+	for (i = 0; i < ci->children_num; ++i) {
+		oconfig_item_t *item = ci->children + i;
+		
+//		if (!item || !item->key || !*item->key) continue;
+		if (!strcasecmp(item->key, "Multiplier")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_NUMBER || item->values[0].value.number != (int) item->values[0].value.number || item->values[0].value.number < 1) {
+				WARNING("netapp plugin: \"Multiplier\" of host %s service GetWaflPerfData needs exactly one positive integer argument.", ci->values[0].value.string);
+				continue;
+			}
+			service->skip_countdown = service->multiplier = item->values[0].value.number;
+		} else if (!strcasecmp(item->key, "GetNameCache")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN) {
+				WARNING("netapp plugin: \"GetNameCache\" of host %s service GetWaflPerfData needs exactly one bool argument.", ci->values[0].value.string);
+				continue;
+			}
+			perf_wafl->flags = (perf_wafl->flags & ~PERF_WAFL_NAME_CACHE) | (item->values[0].value.boolean ? PERF_WAFL_NAME_CACHE : 0);
+		} else if (!strcasecmp(item->key, "GetDirCache")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN) {
+				WARNING("netapp plugin: \"GetDirChache\" of host %s service GetWaflPerfData needs exactly one bool argument.", ci->values[0].value.string);
+				continue;
+			}
+			perf_wafl->flags = (perf_wafl->flags & ~PERF_WAFL_DIR_CACHE) | (item->values[0].value.boolean ? PERF_WAFL_DIR_CACHE : 0);
+		} else if (!strcasecmp(item->key, "GetBufCache")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN) {
+				WARNING("netapp plugin: \"GetBufCache\" of host %s service GetWaflPerfData needs exactly one bool argument.", ci->values[0].value.string);
+				continue;
+			}
+			perf_wafl->flags = (perf_wafl->flags & ~PERF_WAFL_BUF_CACHE) | (item->values[0].value.boolean ? PERF_WAFL_BUF_CACHE : 0);
+		} else if (!strcasecmp(item->key, "GetInodeCache")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN) {
+				WARNING("netapp plugin: \"GetInodeCache\" of host %s service GetWaflPerfData needs exactly one bool argument.", ci->values[0].value.string);
+				continue;
+			}
+			perf_wafl->flags = (perf_wafl->flags & ~PERF_WAFL_INODE_CACHE) | (item->values[0].value.boolean ? PERF_WAFL_INODE_CACHE : 0);
+		}
+	}
+}
+
+static void build_perf_sys_config(host_config_t *temp, oconfig_item_t *ci, const service_config_t *default_service) {
+	int i;
+	service_config_t *service;
+	perf_system_data_t *perf_system;
+	
+	service = malloc(sizeof(*service));
+	*service = *default_service;
+	service->handler = collect_perf_system_data;
+	perf_system = service->data = malloc(sizeof(*perf_system));
+	perf_system->flags = PERF_SYSTEM_ALL;
+	perf_system->last_cpu_busy = 0;
+	perf_system->last_cpu_total = 0;
+	service->next = temp->services;
+	temp->services = service;
+	for (i = 0; i < ci->children_num; ++i) {
+		oconfig_item_t *item = ci->children + i;
+
+//		if (!item || !item->key || !*item->key) continue;
+		if (!strcasecmp(item->key, "Multiplier")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_NUMBER || item->values[0].value.number != (int) item->values[0].value.number || item->values[0].value.number < 1) {
+				WARNING("netapp plugin: \"Multiplier\" of host %s service GetSystemPerfData needs exactly one positive integer argument.", ci->values[0].value.string);
+				continue;
+			}
+			service->skip_countdown = service->multiplier = item->values[0].value.number;
+		} else if (!strcasecmp(item->key, "GetCPULoad")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN) {
+				WARNING("netapp plugin: \"GetCPULoad\" of host %s service GetSystemPerfData needs exactly one bool argument.", ci->values[0].value.string);
+				continue;
+			}
+			perf_system->flags = (perf_system->flags & ~PERF_SYSTEM_CPU) | (item->values[0].value.boolean ? PERF_SYSTEM_CPU : 0);
+		} else if (!strcasecmp(item->key, "GetInterfaces")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN) {
+				WARNING("netapp plugin: \"GetInterfaces\" of host %s service GetSystemPerfData needs exactly one bool argument.", ci->values[0].value.string);
+				continue;
+			}
+			perf_system->flags = (perf_system->flags & ~PERF_SYSTEM_NET) | (item->values[0].value.boolean ? PERF_SYSTEM_NET : 0);
+		} else if (!strcasecmp(item->key, "GetDiskOps")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN) {
+				WARNING("netapp plugin: \"GetDiskOps\" of host %s service GetSystemPerfData needs exactly one bool argument.", ci->values[0].value.string);
+				continue;
+			}
+			perf_system->flags = (perf_system->flags & ~PERF_SYSTEM_OPS) | (item->values[0].value.boolean ? PERF_SYSTEM_OPS : 0);
+		} else if (!strcasecmp(item->key, "GetDiskIO")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN) {
+				WARNING("netapp plugin: \"GetDiskIO\" of host %s service GetSystemPerfData needs exactly one bool argument.", ci->values[0].value.string);
+				continue;
+			}
+			perf_system->flags = (perf_system->flags & ~PERF_SYSTEM_DISK) | (item->values[0].value.boolean ? PERF_SYSTEM_DISK : 0);
+		}
+	}
+}
+
+static host_config_t *build_host_config(const oconfig_item_t *ci, const host_config_t *default_host, const service_config_t *def_def_service) {
+	int i;
+	oconfig_item_t *item;
+	host_config_t *host, *hc, temp = *default_host;
+	service_config_t default_service = *def_def_service;
+	
+	if ((ci->values_num != 1) || (ci->values[0].type != OCONFIG_TYPE_STRING)) {
+		WARNING("netapp plugin: \"Host\" needs exactly one string argument. Ignoring host block.");
+		return 0;
+	}
+
+	temp.name = ci->values[0].value.string;
+	for (i = 0; i < ci->children_num; ++i) {
+		item = ci->children + i;
+
+//		if (!item || !item->key || !*item->key) continue;
+		if (!strcasecmp(item->key, "Address")) {
+			if ((item->values_num != 1) || (item->values[0].type != OCONFIG_TYPE_STRING)) {
+				WARNING("netapp plugin: \"Name\" needs exactly one string argument. Ignoring host block \"%s\".", ci->values[0].value.string);
+				return 0;
+			}
+			temp.host = item->values[0].value.string;
+		} else if (!strcasecmp(item->key, "Port")) {
+			if ((item->values_num != 1) || (item->values[0].type != OCONFIG_TYPE_NUMBER) || (item->values[0].value.number != (int) (item->values[0].value.number)) || (item->values[0].value.number < 1) || (item->values[0].value.number > 65535)) {
+				WARNING("netapp plugin: \"Port\" needs exactly one integer argument in the range of 1-65535. Ignoring host block \"%s\".", ci->values[0].value.string);
+				return 0;
+			}
+			temp.port = item->values[0].value.number;
+		} else if (!strcasecmp(item->key, "Protocol")) {
+			if ((item->values_num != 1) || (item->values[0].type != OCONFIG_TYPE_STRING) || (strcasecmp(item->values[0].value.string, "http") && strcasecmp(item->values[0].value.string, "https"))) {
+				WARNING("netapp plugin: \"Protocol\" needs to be either \"http\" or \"https\". Ignoring host block \"%s\".", ci->values[0].value.string);
+				return 0;
+			}
+			if (!strcasecmp(item->values[0].value.string, "http")) temp.protocol = NA_SERVER_TRANSPORT_HTTP;
+			else temp.protocol = NA_SERVER_TRANSPORT_HTTPS;
+		} else if (!strcasecmp(item->key, "Login")) {
+			if ((item->values_num != 2) || (item->values[0].type != OCONFIG_TYPE_STRING) || (item->values[1].type != OCONFIG_TYPE_STRING)) {
+				WARNING("netapp plugin: \"Login\" needs exactly two string arguments, username and password. Ignoring host block \"%s\".", ci->values[0].value.string);
+				return 0;
+			}
+			temp.username = item->values[0].value.string;
+			temp.password = item->values[1].value.string;
+		} else if (!strcasecmp(item->key, "Interval")) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_NUMBER || item->values[0].value.number != (int) item->values[0].value.number || item->values[0].value.number < 2) {
+				WARNING("netapp plugin: \"Interval\" of host %s needs exactly one integer argument.", ci->values[0].value.string);
+				continue;
+			}
+			temp.interval = item->values[0].value.number;
+		} else if (!strcasecmp(item->key, "GetVolumePerfData")) {
+			build_perf_vol_config(&temp, item);
+		} else if (!strcasecmp(item->key, "GetSystemPerfData")) {
+			build_perf_sys_config(&temp, item, &default_service);
+/*			if ((item->values_num != 1) || (item->values[0].type != OCONFIG_TYPE_STRING)) {
+				WARNING("netapp plugin: \"Collect\" needs exactly one string argument. Ignoring collect block for \"%s\".", ci->values[0].value.string);
+				continue;
+			}
+			build_collect_config(&temp, item);*/
+		} else if (!strcasecmp(item->key, "GetWaflPerfData")) {
+			build_perf_wafl_config(&temp, item);
+		} else if (!strcasecmp(item->key, "GetDiskPerfData")) {
+			build_perf_disk_config(&temp, item);
+		} else if (!strcasecmp(item->key, "GetVolumeData")) {
+			build_volume_config(&temp, item);
+		} else {
+			WARNING("netapp plugin: Ignoring unknown config option \"%s\" in host block \"%s\".", item->key, ci->values[0].value.string);
+		}
+	}
+	
+	if (!temp.host) temp.host = temp.name;
+	if (!temp.port) temp.port = temp.protocol == NA_SERVER_TRANSPORT_HTTP ? 80 : 443;
+	if (!temp.username) {
+		WARNING("netapp plugin: Please supply login information for host \"%s\". Ignoring host block.", temp.name);
+		return 0;
+	}
+	for (hc = host_config; hc; hc = hc->next) {
+		if (!strcasecmp(hc->name, temp.name)) WARNING("netapp plugin: Duplicate definition of host \"%s\". This is probably a bad idea.", hc->name);
+	}
+	host = malloc(sizeof(*host));
+	*host = temp;
+	host->name = strdup(temp.name);
+	host->protocol = temp.protocol;
+	host->host = strdup(temp.host);
+	host->username = strdup(temp.username);
+	host->password = strdup(temp.password);
+	host->next = host_config;
+	host_config = host;
+	return host;
+}
+
+static int build_config (oconfig_item_t *ci) {
+	int i;
+	oconfig_item_t *item;
+	host_config_t default_host = HOST_INIT;
+	service_config_t default_service = SERVICE_INIT;
+	
+	for (i = 0; i < ci->children_num; ++i) {
+		item = ci->children + i;
+
+//		if (!item || !item->key || !*item->key) continue;
+		if (!strcasecmp(item->key, "Host")) {
+			build_host_config(item, &default_host, &default_service);
+		} else {
+			WARNING("netapp plugin: Ignoring unknown config option \"%s\".", item->key);
+		}
+	}
+	return 0;
+}
+
+static int netapp_read() {
+	na_elem_t *out;
+	host_config_t *host;
+	service_config_t *service;
+	
+	for (host = host_config; host; host = host->next) {
+		for (service = host->services; service; service = service->next) {
+			if (--service->skip_countdown > 0) continue;
+			service->skip_countdown = service->multiplier;
+			out = na_server_invoke_elem(host->srv, service->query);
+			if (na_results_status(out) != NA_OK) {
+				int netapp_errno = na_results_errno(out);
+				ERROR("netapp plugin: Error %d from host %s: %s", netapp_errno, host->name, na_results_reason(out));
+				na_elem_free(out);
+				if (netapp_errno == EIO || netapp_errno == ETIMEDOUT) {
+					// Network problems. Just give up on all other services on this host.
+					break;
+				}
+				continue;
+			}
+			service->handler(host, out, service->data);
+			na_elem_free(out);
+		}
+	}
+	return 0;
+}
+
+void module_register() {
+	plugin_register_complex_config("netapp", build_config);
+	plugin_register_init("netapp", config_init);
+	plugin_register_read("netapp", netapp_read);
+}