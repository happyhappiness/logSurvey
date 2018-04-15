		PyErr_SetString(PyExc_TypeError, "Cannot delete this attribute");
		return -1;
	}
	new = PyString_AsString(value);
	if (new == NULL) return -1;
	old = ((char *) self) + (intptr_t) data;
	sstrncpy(old, new, NOTIF_MAX_MSG_LEN);
	return 0;
}

static PyObject *Notification_repr(PyObject *s) {
	PyObject *ret;
	Notification *self = (Notification *) s;
	
