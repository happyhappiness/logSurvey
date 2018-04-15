     PyErr_Format(PyExc_TypeError, "Dataset %s not found", notification.type);
     return NULL;
   }
+  if (meta != NULL && meta != Py_None && !PyDict_Check(meta)) {
+    PyErr_Format(PyExc_TypeError, "meta must be a dict");
+    return NULL;
+  }
+  cpy_build_notification_meta(&notification, meta);
 
   if (notification.time == 0)
     notification.time = cdtime();
