
static int cpy_notification_callback(const notification_t *notification, user_data_t *data) {
	cpy_callback_t *c = data->data;
	PyObject *ret, *n;

	CPY_LOCK_THREADS
		n = PyObject_CallFunction((void *) &NotificationType, "ssssssdi", notification->type, notification->message,
				notification->plugin_instance, notification->type_instance, notification->plugin,
				notification->host, (double) notification->time, notification->severity);
		ret = PyObject_CallFunctionObjArgs(c->callback, n, c->data, (void *) 0); /* New reference. */
		if (ret == NULL) {
			cpy_log_exception("notification callback");
