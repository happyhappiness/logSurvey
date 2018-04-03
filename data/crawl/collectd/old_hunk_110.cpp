    PyErr_Format(PyExc_TypeError, "Dataset %s not found", notification.type);
    return NULL;
  }

  if (notification.time == 0)
    notification.time = cdtime();
