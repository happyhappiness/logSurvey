 		PyErr_SetString(PyExc_TypeError, "callback needs a be a callable object.");
 		return NULL;
 	}
-	if (name == NULL) {
-		PyObject *mod;
-		
-		mod = PyObject_GetAttrString(callback, "__module__");
-		if (mod != NULL) name = PyString_AsString(mod);
-		if (name == NULL) {
-			PyErr_SetString(PyExc_ValueError, "No module name specified and "
-				"callback function does not have a \"__module__\" attribute.");
-			return NULL;
-		}
-	}
+	cpy_build_name(buf, sizeof(buf), callback, name);
+	
 	Py_INCREF(callback);
 	Py_XINCREF(data);
 	c = malloc(sizeof(*c));
-	c->name = strdup(name);
+	c->name = strdup(buf);
 	c->callback = callback;
 	c->data = data;
 	c->next = NULL;
 	user_data = malloc(sizeof(*user_data));
 	user_data->free_func = cpy_destroy_user_data;
 	user_data->data = c;
-	plugin_register_log(name, cpy_log_callback, user_data);
-	Py_RETURN_NONE;
+	register_function(buf, handler, user_data);
+	return PyString_FromString(buf);
+}
+
+static PyObject *cpy_register_log(PyObject *self, PyObject *args, PyObject *kwds) {
+	return cpy_register_generic_userdata(plugin_register_log, cpy_log_callback, args, kwds);
+}
+
+static PyObject *cpy_register_write(PyObject *self, PyObject *args, PyObject *kwds) {
+	return cpy_register_generic_userdata(plugin_register_write, cpy_write_callback, args, kwds);
 }
 
 static PyObject *cpy_register_shutdown(PyObject *self, PyObject *args, PyObject *kwds) {
