 		PyErr_SetString(PyExc_TypeError, "callback needs a be a callable object.");
 		return NULL;
 	}
-	cpy_build_name(buf, sizeof(buf), callback, name);
+	cpy_build_name(buf, sizeof(buf), callback, name, 0);
 	
 	Py_INCREF(callback);
 	Py_XINCREF(data);
