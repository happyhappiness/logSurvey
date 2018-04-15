	}
	size = (int) PySequence_Length(values);
	if (size != ds->ds_num) {
		PyErr_Format(PyExc_RuntimeError, "type %s needs %d values, got %i", value_list.type, ds->ds_num, size);
		return NULL;
	}
	value = malloc(size * sizeof(*value));
