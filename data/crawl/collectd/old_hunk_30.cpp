  ERROR("ipmi plugin: %s failed: %s", func, errbuf);
} /* void c_ipmi_error */

/*
 * Sensor handlers
 */
/* Prototype for sensor_list_remove, so sensor_read_handler can call it. */
static int sensor_list_remove(ipmi_sensor_t *sensor);

static void sensor_read_handler(ipmi_sensor_t *sensor, int err,
                                enum ipmi_value_present_e value_present,
                                unsigned int __attribute__((unused)) raw_value,
                                double value,
                                ipmi_states_t __attribute__((unused)) * states,
                                void *user_data) {
  value_list_t vl = VALUE_LIST_INIT;

  c_ipmi_sensor_list_t *list_item = (c_ipmi_sensor_list_t *)user_data;

  if (err != 0) {
    if ((err & 0xff) == IPMI_NOT_PRESENT_CC) {
      if (list_item->sensor_not_present == 0) {
        list_item->sensor_not_present = 1;

        INFO("ipmi plugin: sensor_read_handler: sensor %s "
             "not present.",
             list_item->sensor_name);

        if (c_ipmi_notify_notpresent) {
          notification_t n = {
              NOTIF_WARNING, cdtime(), "", "", "ipmi", "", "", "", NULL};

          sstrncpy(n.host, hostname_g, sizeof(n.host));
          sstrncpy(n.type_instance, list_item->sensor_name,
                   sizeof(n.type_instance));
          sstrncpy(n.type, list_item->sensor_type, sizeof(n.type));
