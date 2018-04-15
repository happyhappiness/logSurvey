 		PyErr_SetString(PyExc_TypeError, "Cannot delete this attribute");
 		return -1;
 	}
-	new = PyString_AsString(value);
-	if (new == NULL) return -1;
+	Py_INCREF(value);
+	new = cpy_unicode_or_bytes_to_string(&value);
+	if (new == NULL) {
+		Py_DECREF(value);
+		return -1;
+	}
 	old = ((char *) self) + (intptr_t) data;
 	sstrncpy(old, new, NOTIF_MAX_MSG_LEN);
+	Py_DECREF(value);
 	return 0;
 }
 
-static PyObject *Notification_repr(PyObject *s) {
+/*static PyObject *Notification_repr(PyObject *s) {
 	PyObject *ret;
 	Notification *self = (Notification *) s;
 	
