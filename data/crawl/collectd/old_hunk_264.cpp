	Config *self = (Config *) s;
	static char *kwlist[] = {"key", "parent", "values", "children", NULL};
	
	if (!PyArg_ParseTupleAndKeywords(args, kwds, "S|OOO", kwlist,
			&key, &parent, &values, &children))
		return -1;
	
	if (values == NULL) {
		values = PyTuple_New(0);
		PyErr_Clear();
