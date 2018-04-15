  return (0);
} /* }}} int http_config */

static int http_write (const data_set_t *ds, const value_list_t *vl, /* {{{ */
    user_data_t __attribute__((unused)) *user_data)
{
