 	CPY_RELEASE_THREADS
 }
 
-static PyObject *cpy_register_generic(cpy_callback_t **list_head, PyObject *args, PyObject *kwds) {
+static void cpy_flush_callback(int timeout, const char *id, user_data_t *data) {
+	cpy_callback_t * c = data->data;
+	PyObject *ret;
+
+	CPY_LOCK_THREADS
+	if (c->data == NULL)
+		ret = PyObject_CallFunction(c->callback, "is", timeout, id); /* New reference. */
+	else
+		ret = PyObject_CallFunction(c->callback, "isO", timeout, id, c->data); /* New reference. */
+
+	if (ret == NULL) {
+		cpy_log_exception("flush callback");
+	} else {
+		Py_DECREF(ret);
+	}
+	CPY_RELEASE_THREADS
+}
+
+static PyObject *cpy_register_generic(cpy_callback_t **list_head, PyObject *args, PyObject *kwds, int short_name) {
+	char buf[512];
 	cpy_callback_t *c;
 	const char *name = NULL;
 	PyObject *callback = NULL, *data = NULL, *mod = NULL;
