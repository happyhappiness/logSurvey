 */
int plugin_dispatch_values (const char *name, const value_list_t *vl);

/* TODO: Move plugin_{complain,relief} into `utils_complain.[ch]'. -octo */
void plugin_complain (int level, complain_t *c, const char *format, ...);
void plugin_relief (int level, complain_t *c, const char *format, ...);