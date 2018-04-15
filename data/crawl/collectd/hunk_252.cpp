 				CPY_RETURN_FROM_THREADS 0;
 			}
 		}
-		v = PyObject_CallFunction((void *) &ValuesType, "sOssssdi", value_list->type, list,
-				value_list->plugin_instance, value_list->type_instance, value_list->plugin,
-				value_list->host, (double) value_list->time, value_list->interval);
-		Py_DECREF(list);
+		v = PyObject_New(Values, (void *) &ValuesType);
+		sstrncpy(v->data.host, value_list->host, sizeof(v->data.host));
+		sstrncpy(v->data.type, value_list->type, sizeof(v->data.type));
+		sstrncpy(v->data.type_instance, value_list->type_instance, sizeof(v->data.type_instance));
+		sstrncpy(v->data.plugin, value_list->plugin, sizeof(v->data.plugin));
+		sstrncpy(v->data.plugin_instance, value_list->plugin_instance, sizeof(v->data.plugin_instance));
+		v->data.time = value_list->time;
+		v->interval = value_list->interval;
+		v->values = list;
 		ret = PyObject_CallFunctionObjArgs(c->callback, v, c->data, (void *) 0); /* New reference. */
 		if (ret == NULL) {
 			cpy_log_exception("write callback");
