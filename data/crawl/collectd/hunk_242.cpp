 	Py_BEGIN_ALLOW_THREADS;
 	ret = plugin_write(dest, NULL, &value_list);
 	Py_END_ALLOW_THREADS;
+	meta_data_destroy(value_list.meta);
+	free(value);
 	if (ret != 0) {
 		PyErr_SetString(PyExc_RuntimeError, "error dispatching values, read the logs");
 		return NULL;
 	}
-	free(value);
 	Py_RETURN_NONE;
 }
 