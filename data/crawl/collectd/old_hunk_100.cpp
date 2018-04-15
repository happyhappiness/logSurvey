		Py_Finalize();
		return 0;
	}
	PyEval_InitThreads();
	/* Now it's finally OK to use python threads. */
	for (cpy_callback_t *c = cpy_init_callbacks; c; c = c->next) {
		ret = PyObject_CallFunctionObjArgs(c->callback, c->data, (void *) 0); /* New reference. */
		if (ret == NULL)
			cpy_log_exception("init callback");
		else
			Py_DECREF(ret);
	}
	state = PyEval_SaveThread();
	main_thread = pthread_self();
	if (do_interactive) {
		if (plugin_thread_create(&thread, NULL, cpy_interactive, NULL)) {
			ERROR("python: Error creating thread for interactive interpreter.");
		}
	}

	return 0;
}