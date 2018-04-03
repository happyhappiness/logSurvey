  return 0;
}

static int cpy_build_meta(PyObject *meta, cpy_build_meta_handler_t *meta_func,
                          void *m) {
  int s;
  PyObject *l;

  if ((meta == NULL) || (meta == Py_None))
    return -1;

  l = PyDict_Items(meta); /* New reference. */
  if (!l) {
    cpy_log_exception("building meta data");
    return -1;
  }
  s = PyList_Size(l);
  if (s <= 0) {
    Py_XDECREF(l);
    return -1;
  }

  for (int i = 0; i < s; ++i) {
    const char *string, *keystring;
    PyObject *key, *value, *item, *tmp;
