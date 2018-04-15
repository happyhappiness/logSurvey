 			module = PyImport_ImportModule(module_name); /* New reference. */
 			if (module == NULL) {
 				ERROR("python plugin: Error importing module \"%s\".", module_name);
+				cpy_log_exception("python initialization");
 				PyErr_Print();
 			}
 			free(module_name);
