 	char buf[512];
 	const char *name;
 
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
+			Py_DECREF(&arg);
 			return NULL;
 		}
 		cpy_build_name(buf, sizeof(buf), arg, NULL);
 		name = buf;
 	}
-	if (unreg(name) == 0)
+	if (unreg(name) == 0) {
+		Py_DECREF(&arg);
 		Py_RETURN_NONE;
+	}
 	PyErr_Format(PyExc_RuntimeError, "Unable to unregister %s callback '%s'.", desc, name);
+	Py_DECREF(&arg);
 	return NULL;
 }
 
