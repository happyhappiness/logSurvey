static int cpy_shutdown(void) {
	PyObject *ret;

	PyEval_RestoreThread(state);

	for (cpy_callback_t *c = cpy_shutdown_callbacks; c; c = c->next) {
		ret = PyObject_CallFunctionObjArgs(c->callback, c->data, (void *) 0); /* New reference. */
