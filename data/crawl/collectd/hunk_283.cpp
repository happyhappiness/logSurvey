 	0,                         /* tp_alloc */
 	Values_new                 /* tp_new */
 };
+
+static char severity_doc[] = "The severity of this notification. Assign or compare to\n"
+		"NOTIF_FAILURE, NOTIF_WARNING or NOTIF_OKAY.";
+
+static char message_doc[] = "Some kind of description what's going on and why this Notification was generated.";
+
+static char Notification_doc[] = "The Notification class is a wrapper around the collectd notification.\n"
+		"It can be used to notify other plugins about bad stuff happening. It works\n"
+		"similar to Values but has a severity and a message instead of interval\n"
+		"and time.\n"
+		"Notifications can be dispatched at any time and can be received with register_notification.";
+
+static int Notification_init(PyObject *s, PyObject *args, PyObject *kwds) {
+	Notification *self = (Notification *) s;
+	PyObject *tmp;
+	int severity = 0, ret;
+	double time = 0;
+	const char *message = "";
+	const char *type = "", *plugin_instance = "", *type_instance = "", *plugin = "", *host = "";
+	static char *kwlist[] = {"type", "message", "plugin_instance", "type_instance",
+			"plugin", "host", "time", "severity", NULL};
+	
+	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|ssssssdi", kwlist,
+			&type, &message, &plugin_instance, &type_instance,
+			&plugin, &host, &time, &severity))
+		return -1;
+	
+	tmp = Py_BuildValue("sssssd", type, plugin_instance, type_instance, plugin, host, time);
+	if (tmp == NULL)
+		return -1;
+	ret = PluginDataType.tp_init(s, tmp, NULL);
+	Py_DECREF(tmp);
+	if (ret != 0)
+		return -1;
+	
+	sstrncpy(self->message, message, sizeof(self->message));
+	self->severity = severity;
+	return 0;
+}
+
+static PyObject *Notification_dispatch(Notification *self, PyObject *args, PyObject *kwds) {
+	int ret;
+	const data_set_t *ds;
+	notification_t notification;
+	double t = self->data.time;
+	int severity = self->severity;
+	const char *host = self->data.host;
+	const char *plugin = self->data.plugin;
+	const char *plugin_instance = self->data.plugin_instance;
+	const char *type = self->data.type;
+	const char *type_instance = self->data.type_instance;
+	const char *message = self->message;
+	
+	static char *kwlist[] = {"type", "message", "plugin_instance", "type_instance",
+			"plugin", "host", "time", "severity", NULL};
+	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|ssssssdi", kwlist,
+			&type, &message, &plugin_instance, &type_instance,
+			&plugin, &host, &t, &severity))
+		return NULL;
+
+	if (type[0] == 0) {
+		PyErr_SetString(PyExc_RuntimeError, "type not set");
+		return NULL;
+	}
+	ds = plugin_get_ds(type);
+	if (ds == NULL) {
+		PyErr_Format(PyExc_TypeError, "Dataset %s not found", type);
+		return NULL;
+	}
+
+	notification.time = t;
+	notification.severity = severity;
+	sstrncpy(notification.message, message, sizeof(notification.message));
+	sstrncpy(notification.host, host, sizeof(notification.host));
+	sstrncpy(notification.plugin, plugin, sizeof(notification.plugin));
+	sstrncpy(notification.plugin_instance, plugin_instance, sizeof(notification.plugin_instance));
+	sstrncpy(notification.type, type, sizeof(notification.type));
+	sstrncpy(notification.type_instance, type_instance, sizeof(notification.type_instance));
+	notification.meta = NULL;
+	if (notification.time < 1)
+		notification.time = time(0);
+	if (notification.host[0] == 0)
+		sstrncpy(notification.host, hostname_g, sizeof(notification.host));
+	if (notification.plugin[0] == 0)
+		sstrncpy(notification.plugin, "python", sizeof(notification.plugin));
+	Py_BEGIN_ALLOW_THREADS;
+	ret = plugin_dispatch_notification(&notification);
+	Py_END_ALLOW_THREADS;
+	if (ret != 0) {
+		PyErr_SetString(PyExc_RuntimeError, "error dispatching notification, read the logs");
+		return NULL;
+	}
+	Py_RETURN_NONE;
+}
+
+static PyObject *Notification_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
+	Notification *self;
+	
+	self = (Notification *) PluginData_new(type, args, kwds);
+	if (self == NULL)
+		return NULL;
+	
+	self->message[0] = 0;
+	self->severity = 0;
+	return (PyObject *) self;
+}
+
+static int Notification_setstring(PyObject *self, PyObject *value, void *data) {
+	char *old;
+	const char *new;
+	
+	if (value == NULL) {
+		PyErr_SetString(PyExc_TypeError, "Cannot delete this attribute");
+		return -1;
+	}
+	new = PyString_AsString(value);
+	if (new == NULL) return -1;
+	old = ((char *) self) + (int) data;
+	sstrncpy(old, new, NOTIF_MAX_MSG_LEN);
+	return 0;
+}
+
+static PyObject *Notification_repr(PyObject *s) {
+	PyObject *ret;
+	Notification *self = (Notification *) s;
+	
+	ret = PyString_FromFormat("collectd.Values(type='%s%s%s%s%s%s%s%s%s%s%s',time=%lu,interval=%i)", self->data.type,
+			*self->data.type_instance ? "',type_instance='" : "", self->data.type_instance,
+			*self->data.plugin ? "',plugin='" : "", self->data.plugin,
+			*self->data.plugin_instance ? "',plugin_instance='" : "", self->data.plugin_instance,
+			*self->data.host ? "',host='" : "", self->data.host,
+			*self->message ? "',message='" : "", self->message,
+			(long unsigned) self->data.time, self->severity);
+	return ret;
+}
+
+static PyMethodDef Notification_methods[] = {
+	{"dispatch", (PyCFunction) Notification_dispatch, METH_VARARGS | METH_KEYWORDS, dispatch_doc},
+	{NULL}
+};
+
+static PyMemberDef Notification_members[] = {
+	{"severity", T_INT, offsetof(Notification, severity), 0, severity_doc},
+	{NULL}
+};
+
+static PyGetSetDef Notification_getseters[] = {
+	{"message", PluginData_getstring, Notification_setstring, message_doc, (void *) offsetof(Notification, message)},
+	{NULL}
+};
+
+PyTypeObject NotificationType = {
+	PyObject_HEAD_INIT(NULL)
+	0,                         /* Always 0 */
+	"collectd.Notification",   /* tp_name */
+	sizeof(Notification),      /* tp_basicsize */
+	0,                         /* Will be filled in later */
+	0,                         /* tp_dealloc */
+	0,                         /* tp_print */
+	0,                         /* tp_getattr */
+	0,                         /* tp_setattr */
+	0,                         /* tp_compare */
+	Notification_repr,         /* tp_repr */
+	0,                         /* tp_as_number */
+	0,                         /* tp_as_sequence */
+	0,                         /* tp_as_mapping */
+	0,                         /* tp_hash */
+	0,                         /* tp_call */
+	0,                         /* tp_str */
+	0,                         /* tp_getattro */
+	0,                         /* tp_setattro */
+	0,                         /* tp_as_buffer */
+	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
+	Notification_doc,          /* tp_doc */
+	0,                         /* tp_traverse */
+	0,                         /* tp_clear */
+	0,                         /* tp_richcompare */
+	0,                         /* tp_weaklistoffset */
+	0,                         /* tp_iter */
+	0,                         /* tp_iternext */
+	Notification_methods,      /* tp_methods */
+	Notification_members,      /* tp_members */
+	Notification_getseters,    /* tp_getset */
+	0,                         /* tp_base */
+	0,                         /* tp_dict */
+	0,                         /* tp_descr_get */
+	0,                         /* tp_descr_set */
+	0,                         /* tp_dictoffset */
+	Notification_init,         /* tp_init */
+	0,                         /* tp_alloc */
+	Notification_new           /* tp_new */
+};