	return cpy_register_generic(&cpy_shutdown_callbacks, args, kwds);
}

static PyMethodDef cpy_methods[] = {
	{"register_init", (PyCFunction) cpy_register_init, METH_VARARGS | METH_KEYWORDS, "This is an unhelpful text."},
	{"register_config", (PyCFunction) cpy_register_config, METH_VARARGS | METH_KEYWORDS, "This is an unhelpful text."},
	{"register_shutdown", (PyCFunction) cpy_register_shutdown, METH_VARARGS | METH_KEYWORDS, "This is an unhelpful text."},