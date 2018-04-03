   }
   size = (size_t)PySequence_Length(values);
   if (size != ds->ds_num) {
-    PyErr_Format(PyExc_RuntimeError, "type %s needs %zu values, got %zu",
+    PyErr_Format(PyExc_RuntimeError,
+                 "type %s needs %" PRIsz " values, got %" PRIsz,
                  value_list.type, ds->ds_num, size);
     return NULL;
   }
