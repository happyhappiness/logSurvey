+/**
+ * collectd - src/csv.c
+ * Copyright (C) 2007  Florian octo Forster
+ *
+ * This program is free software; you can redistribute it and/or modify it
+ * under the terms of the GNU General Public License as published by the
+ * Free Software Foundation; only version 2 of the License is applicable.
+ *
+ * This program is distributed in the hope that it will be useful, but
+ * WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License along
+ * with this program; if not, write to the Free Software Foundation, Inc.,
+ * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
+ *
+ * Authors:
+ *   Florian octo Forster <octo at verplant.org>
+ **/
+
+#include "collectd.h"
+#include "plugin.h"
+#include "common.h"
+#include "utils_debug.h"
+
+static int value_list_to_string (char *buffer, int buffer_len,
+		const data_set_t *ds, const value_list_t *vl)
+{
+	int offset;
+	int status;
+	int i;
+
+	memset (buffer, '\0', sizeof (buffer_len));
+
+	status = snprintf (buffer, buffer_len, "%u", (unsigned int) vl->time);
+	if ((status < 1) || (status >= buffer_len))
+		return (-1);
+	offset = status;
+
+	for (i = 0; i < ds->ds_num; i++)
+	{
+		if ((ds->ds[i].type != DS_TYPE_COUNTER)
+				&& (ds->ds[i].type != DS_TYPE_GAUGE))
+			return (-1);
+
+		if (ds->ds[i].type == DS_TYPE_COUNTER)
+			status = snprintf (buffer + offset, buffer_len - offset,
+					",%llu", vl->values[i].counter);
+		else
+			status = snprintf (buffer + offset, buffer_len - offset,
+					",%lf", vl->values[i].gauge);
+
+		if ((status < 1) || (status >= (buffer_len - offset)))
+			return (-1);
+
+		offset += status;
+	} /* for ds->ds_num */
+
+	return (0);
+} /* int value_list_to_string */
+
+static int value_list_to_filename (char *buffer, int buffer_len,
+		const data_set_t *ds, const value_list_t *vl)
+{
+	int offset = 0;
+	int status;
+
+	status = snprintf (buffer + offset, buffer_len - offset,
+			"%s/", vl->host);
+	if ((status < 1) || (status >= buffer_len - offset))
+		return (-1);
+	offset += status;
+
+	if (strlen (vl->plugin_instance) > 0)
+		status = snprintf (buffer + offset, buffer_len - offset,
+				"%s-%s/", vl->plugin, vl->plugin_instance);
+	else
+		status = snprintf (buffer + offset, buffer_len - offset,
+				"%s/", vl->plugin);
+	if ((status < 1) || (status >= buffer_len - offset))
+		return (-1);
+	offset += status;
+
+	if (strlen (vl->type_instance) > 0)
+		status = snprintf (buffer + offset, buffer_len - offset,
+				"%s-%s", ds->type, vl->type_instance);
+	else
+		status = snprintf (buffer + offset, buffer_len - offset,
+				"%s", ds->type);
+	if ((status < 1) || (status >= buffer_len - offset))
+		return (-1);
+	offset += status;
+
+	{
+		time_t now;
+		struct tm *tm;
+
+		/* TODO: Find a way to minimize the calls to `localtime', since
+		 * they are pretty expensive.. */
+		now = time (NULL);
+		tm = localtime (&now);
+
+		strftime (buffer + offset, buffer_len - offset,
+				"-%Y-%m-%d", tm);
+
+		/* `localtime(3)' returns a pointer to static data,
+		 * therefore the pointer may not be free'd. */
+	}
+
+	return (0);
+} /* int value_list_to_filename */
+
+static int csv_create_file (const char *filename, const data_set_t *ds)
+{
+	FILE *csv;
+	int i;
+
+	if (check_create_dir (filename))
+		return (-1);
+
+	csv = fopen (filename, "w");
+	if (csv == NULL)
+	{
+		syslog (LOG_ERR, "csv plugin: fopen (%s) failed: %s",
+				filename, strerror(errno));
+		return (-1);
+	}
+
+	fprintf (csv, "epoch");
+	for (i = 0; i < ds->ds_num; i++)
+		fprintf (csv, ",%s", ds->ds[i].name);
+
+	fprintf (csv, "\n");
+	fclose (csv);
+
+	return 0;
+} /* int csv_create_file */
+
+static int csv_write (const data_set_t *ds, const value_list_t *vl)
+{
+	struct stat  statbuf;
+	char         filename[512];
+	char         values[512];
+	FILE        *csv;
+	int          csv_fd;
+	struct flock fl = { F_WRLCK, SEEK_SET, 0, 0, getpid () };
+	int          status;
+
+	if (value_list_to_filename (filename, sizeof (filename), ds, vl) != 0)
+		return (-1);
+
+	if (value_list_to_string (values, sizeof (values), ds, vl) != 0)
+		return (-1);
+
+	if (stat (filename, &statbuf) == -1)
+	{
+		if (errno == ENOENT)
+		{
+			if (csv_create_file (filename, ds))
+				return (-1);
+		}
+		else
+		{
+			syslog (LOG_ERR, "stat(%s) failed: %s",
+					filename, strerror (errno));
+			return (-1);
+		}
+	}
+	else if (!S_ISREG (statbuf.st_mode))
+	{
+		syslog (LOG_ERR, "stat(%s): Not a regular file!",
+				filename);
+		return (-1);
+	}
+
+	csv = fopen (filename, "a");
+	if (csv == NULL)
+	{
+		syslog (LOG_ERR, "csv plugin: fopen (%s) failed: %s",
+				filename, strerror (errno));
+		return (-1);
+	}
+	csv_fd = fileno (csv);
+
+	status = fcntl (csv_fd, F_SETLK, &fl);
+	if (status != 0)
+	{
+		syslog (LOG_ERR, "csv plugin: flock (%s) failed: %s",
+				filename, strerror (errno));
+		fclose (csv);
+		return (-1);
+	}
+
+	fprintf (csv, "%s\n", values);
+
+	/* The lock is implicitely released. I we don't release it explicitely
+	 * because the `FILE *' may need to flush a cache first */
+	fclose (csv);
+
+	return (0);
+} /* int csv_write */
+
+void module_register (void)
+{
+	plugin_register_write ("csv", csv_write);
+}