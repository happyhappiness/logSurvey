+/**
+ * collectd - src/utils_cms_putval.c
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
+ * Author:
+ *   Florian octo Forster <octo at verplant.org>
+ **/
+
+#include "collectd.h"
+#include "common.h"
+#include "plugin.h"
+
+static int parse_value (const data_set_t *ds, value_list_t *vl,
+		const char *type,
+	       	FILE *fh, char *buffer)
+{
+	char *dummy;
+	char *ptr;
+	char *saveptr;
+	int i;
+
+	char *time_str = buffer;
+	char *value_str = strchr (time_str, ':');
+	if (value_str == NULL)
+	{
+		fprintf (fh, "-1 No time found.");
+		return (-1);
+	}
+	*value_str = '\0'; value_str++;
+
+	vl->time = (time_t) atoi (time_str);
+	if (vl->time == 0)
+		vl->time = time (NULL);
+
+	i = 0;
+	dummy = value_str;
+	saveptr = NULL;
+	while ((ptr = strtok_r (dummy, ":", &saveptr)) != NULL)
+	{
+		dummy = NULL;
+
+		if (i >= vl->values_len)
+		{
+			i = vl->values_len + 1;
+			break;
+		}
+
+		if (strcmp (ptr, "U") == 0)
+			vl->values[i].gauge = NAN;
+		else if (ds->ds[i].type == DS_TYPE_COUNTER)
+			vl->values[i].counter = atoll (ptr);
+		else if (ds->ds[i].type == DS_TYPE_GAUGE)
+			vl->values[i].gauge = atof (ptr);
+
+		i++;
+	} /* while (strtok_r) */
+
+	if (i != vl->values_len)
+	{
+		char identifier[128];
+		FORMAT_VL (identifier, sizeof (identifier), vl, ds);
+		ERROR ("cmd putval: parse_value: "
+				"Number of values incorrect: "
+				"Got %i, expected %i. Identifier is `%s'.",
+				i, vl->values_len, identifier);
+		fprintf (fh, "-1 Number of values incorrect: "
+				"Got %i, expected %i.\n",
+			       	i, vl->values_len);
+		return (-1);
+	}
+
+	plugin_dispatch_values (type, vl);
+	return (0);
+} /* int parse_value */
+
+static int parse_option (value_list_t *vl, char *buffer)
+{
+	char *option = buffer;
+	char *value;
+
+	if ((vl == NULL) || (option == NULL))
+		return (-1);
+
+	value = strchr (option, '=');
+	if (value == NULL)
+		return (-1);
+	*value = '\0'; value++;
+
+	if (strcasecmp ("interval", option) == 0)
+	{
+		vl->interval = atoi (value);
+		if (vl->interval <= 0)
+			vl->interval = interval_g;
+	}
+	else
+		return (1);
+
+	return (0);
+} /* int parse_option */
+
+int handle_putval (FILE *fh, char **fields, int fields_num)
+{
+	char *hostname;
+	char *plugin;
+	char *plugin_instance;
+	char *type;
+	char *type_instance;
+	int   status;
+	int   i;
+
+	const data_set_t *ds;
+	value_list_t vl = VALUE_LIST_INIT;
+
+	if (fields_num < 3)
+	{
+		DEBUG ("unixsock plugin: Wrong number of fields: %i",
+			       	fields_num);
+		fprintf (fh, "-1 Wrong number of fields: Got %i, "
+				"expected at least 3.\n",
+				fields_num);
+		fflush (fh);
+		return (-1);
+	}
+
+	status = parse_identifier (fields[1], &hostname,
+			&plugin, &plugin_instance,
+			&type, &type_instance);
+	if (status != 0)
+	{
+		DEBUG ("unixsock plugin: Cannot parse `%s'", fields[1]);
+		fprintf (fh, "-1 Cannot parse identifier.\n");
+		fflush (fh);
+		return (-1);
+	}
+
+	if ((strlen (hostname) >= sizeof (vl.host))
+			|| (strlen (plugin) >= sizeof (vl.plugin))
+			|| ((plugin_instance != NULL)
+				&& (strlen (plugin_instance) >= sizeof (vl.plugin_instance)))
+			|| ((type_instance != NULL)
+				&& (strlen (type_instance) >= sizeof (vl.type_instance))))
+	{
+		fprintf (fh, "-1 Identifier too long.");
+		return (-1);
+	}
+
+	strcpy (vl.host, hostname);
+	strcpy (vl.plugin, plugin);
+	if (plugin_instance != NULL)
+		strcpy (vl.plugin_instance, plugin_instance);
+	if (type_instance != NULL)
+		strcpy (vl.type_instance, type_instance);
+
+	ds = plugin_get_ds (type);
+	if (ds == NULL)
+		return (-1);
+
+	vl.values_len = ds->ds_num;
+	vl.values = (value_t *) malloc (vl.values_len * sizeof (value_t));
+	if (vl.values == NULL)
+	{
+		fprintf (fh, "-1 malloc failed.");
+		return (-1);
+	}
+
+	/* All the remaining fields are part of the optionlist. */
+	for (i = 2; i < fields_num; i++)
+	{
+		if (strchr (fields[i], ':') != NULL)
+		{
+			/* It's parse_value's job to write an error to `fh'.
+			 * This is not the case with `parse_option below.
+			 * Neither will write an success message. */
+			if (parse_value (ds, &vl, type, fh, fields[i]) != 0)
+				break;
+		}
+		else if (strchr (fields[i], '=') != NULL)
+		{
+			if (parse_option (&vl, fields[i]) != 0)
+			{
+				fprintf (fh, "-1 Error parsing option `%s'",
+						fields[i]);
+				break;
+			}
+		}
+		else
+		{
+			WARNING ("cmd putval: handle_putval: "
+					"Cannot parse field #%i `%s'; "
+					"Ignoring it.\n",
+					i, fields[i]);
+		}
+	}
+	/* Done parsing the options. */
+
+	if (i == fields_num)
+		fprintf (fh, "0 Success\n");
+	fflush (fh);
+
+	sfree (vl.values); 
+
+	return (0);
+} /* int handle_putval */
+
