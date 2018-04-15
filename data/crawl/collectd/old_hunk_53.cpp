    sstrncpy(notification.plugin, "python", sizeof(notification.plugin));
  Py_BEGIN_ALLOW_THREADS;
  ret = plugin_dispatch_notification(&notification);
  Py_END_ALLOW_THREADS;
  if (ret != 0) {
    PyErr_SetString(PyExc_RuntimeError,
