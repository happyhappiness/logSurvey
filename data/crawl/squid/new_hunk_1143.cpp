static krb5_data *ad_data;
static unsigned char *p;

extern int
check_k5_err(krb5_context context, const char *function, krb5_error_code code);

void
align(int n)
