 	const char *name;
 	cpy_callback_t *prev = NULL, *tmp;
 
-	if (PyUnicode_Check(arg)) {
-		arg = PyUnicode_AsEncodedString(arg, NULL, NULL);
-		if (arg == NULL)
-			return NULL;
-		name = PyString_AsString(arg);
-		Py_DECREF(arg);
-	} else if (PyString_Check(arg)) {
-		name = PyString_AsString(arg);
-	} else {
+	Py_INCREF(arg);
+	name = cpy_unicode_or_bytes_to_string(&arg);
+	if (name == NULL) {
+		PyErr_Clear();
 		if (!PyCallable_Check(arg)) {
 			PyErr_SetString(PyExc_TypeError, "This function needs a string or a callable object as its only parameter.");
+			Py_DECREF(arg);
 			return NULL;
 		}
 		cpy_build_name(buf, sizeof(buf), arg, NULL);
