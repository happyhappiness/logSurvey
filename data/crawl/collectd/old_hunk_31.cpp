}

void cpy_log_exception(const char *context) {
  int l = 0;
  const char *typename = NULL, *message = NULL;
  PyObject *type, *value, *traceback, *tn, *m, *list;

  PyErr_Fetch(&type, &value, &traceback);
  PyErr_NormalizeException(&type, &value, &traceback);
  if (type == NULL)
    return;
  tn = PyObject_GetAttrString(type, "__name__"); /* New reference. */
  m = PyObject_Str(value);                       /* New reference. */
  if (tn != NULL)
