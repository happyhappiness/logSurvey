 		oconfig_item_t *item = ci->children + i;
 		
 		if (strcasecmp(item->key, "Interactive") == 0) {
-			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN ||
-					!item->values[0].value.boolean)
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN)
+				continue;
+			do_interactive = item->values[0].value.boolean;
+		} else if (strcasecmp(item->key, "LogTraces") == 0) {
+			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN)
+				continue;
+			if (!item->values[0].value.boolean) {
+				Py_XDECREF(cpy_format_exception);
+				cpy_format_exception = NULL;
+				continue;
+			}
+			if (cpy_format_exception)
 				continue;
-			do_interactive = 1;
+			tb = PyImport_ImportModule("traceback"); /* New reference. */
+			if (tb == NULL) {
+				cpy_log_exception("python initialization");
+				continue;
+			}
+			cpy_format_exception = PyObject_GetAttrString(tb, "format_exception"); /* New reference. */
+			Py_DECREF(tb);
+			if (cpy_format_exception == NULL)
+				cpy_log_exception("python initialization");
 		} else if (strcasecmp(item->key, "ModulePath") == 0) {
 			char *dir = NULL;
 			PyObject *dir_object;
