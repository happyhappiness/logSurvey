    minutes = timeticks / 60;
    seconds = timeticks % 60;

    if (days == 0){
	snprintf(buf,32,  "%d:%02d:%02d", hours, minutes, seconds);
    } else if (days == 1) {
	snprintf(buf,32, "%d day, %d:%02d:%02d", days, hours, minutes, seconds);
    } else {
	snprintf(buf,32,  "%d days, %d:%02d:%02d", days, hours, minutes, seconds);
    }
    return buf;
}

static void sprint_hexstring(buf, cp, len)
    char *buf;
    u_char  *cp;
    int	    len;
{

    for(; len >= 16; len -= 16){
	snprintf(buf,26, "%02X %02X %02X %02X %02X %02X %02X %02X ", cp[0], cp[1], cp[2], cp[3], cp[4], cp[5], cp[6], cp[7]);
	buf += strlen(buf);
	cp += 8;
	snprintf(buf,26, "%02X %02X %02X %02X %02X %02X %02X %02X\n", cp[0], cp[1], cp[2], cp[3], cp[4], cp[5], cp[6], cp[7]);
	buf += strlen(buf);
	cp += 8;
    }
    for(; len > 0; len--){
	snprintf(buf, 4, "%02X ", *cp++);
	buf += strlen(buf);
    }
    *buf = '\0';
}

static void sprint_asciistring(buf, cp, len)
    char *buf;
    u_char  *cp;
    int	    len;
{
    int	x;

    for(x = 0; x < len; x++){
	if (isprint(*cp)){
	    *buf++ = *cp++;
	} else {
	    *buf++ = '.';
	    cp++;
	}
	if ((x % 48) == 47)
	    *buf++ = '\n';
    }
    *buf = '\0';
}

static void
sprint_octet_string(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
void *foo;
    int quiet;
{
    int hex, x;
    u_char *cp;

    if (var->type != ASN_OCTET_STR){
	sprintf(buf, "Wrong Type (should be OCTET STRING): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
	return;
    }
    hex = 0;
    for(cp = var->val.string, x = 0; x < var->val_len; x++, cp++){
	if (!(isprint(*cp) || isspace(*cp)))
	    hex = 1;
    }
    if (var->val_len <= 4)
	hex = 1;    /* not likely to be ascii */
    if (hex){
      if (!quiet) {
	sprintf(buf, "OCTET STRING-   (hex):\t");
	buf += strlen(buf);
      }
	sprint_hexstring(buf, var->val.string, var->val_len);
    } else {
      if (!quiet) {
	sprintf(buf, "OCTET STRING- (ascii):\t");
	buf += strlen(buf);
      }
	sprint_asciistring(buf, var->val.string, var->val_len);
    }
}

static void
sprint_opaque(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
    void *foo;
    int quiet;
{

    if (var->type != SMI_OPAQUE){
	sprintf(buf, "Wrong Type (should be Opaque): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
	return;
    }
    if (!quiet) {
      sprintf(buf, "OPAQUE -   (hex):\t");
      buf += strlen(buf);
    }
    sprint_hexstring(buf, var->val.string, var->val_len);
}

static void
sprint_object_identifier(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
    void *foo;
    int quiet;
{
    if (var->type != SMI_OBJID){
	sprintf(buf, "Wrong Type (should be OBJECT IDENTIFIER): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
	return;
    }
    if (!quiet) {
      sprintf(buf, "OBJECT IDENTIFIER:\t");
      buf += strlen(buf);
    }
    sprint_objid(buf, (oid *)(var->val.objid), var->val_len / sizeof(oid));
}

static void
sprint_timeticks(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
    void *foo;
    int quiet;
{
    char timebuf[32];

    if (var->type != SMI_TIMETICKS){
	sprintf(buf, "Wrong Type (should be Timeticks): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
	return;
    }
    if (!quiet) {
      sprintf(buf, "Timeticks: ");
      buf += strlen(buf);
    }
    sprintf(buf, "(%u) %s", 
	    *(var->val.integer), 
	    uptimeString(*(var->val.integer), timebuf));
}

static void
sprint_integer(buf, var, enums, quiet)
    char *buf;
    variable_list *var;
    struct enum_list	    *enums;
    int quiet;
{
    char    *enum_string = NULL;

    if (var->type != SMI_INTEGER){
	sprintf(buf, "Wrong Type (should be INTEGER): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
	return;
    }
    for (; enums; enums = enums->next)
	if (enums->value == *var->val.integer){
	    enum_string = enums->label;
	    break;
	}

    if (!quiet) {
      sprintf(buf, "INTEGER: ");
      buf += strlen(buf);
    }
 
    if (enum_string == NULL)
	sprintf(buf, "%u", *var->val.integer);
    else
	sprintf(buf, "%s(%u)", enum_string, *var->val.integer);
}

static void
sprint_gauge(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
void *foo;
int quiet;
{
    if (var->type != SMI_GAUGE32){
	sprintf(buf, "Wrong Type (should be Gauge): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
	return;
    }
    if (!quiet) {
      sprintf(buf, "Gauge: ");
      buf += strlen(buf);
    }
    sprintf(buf, "%u", *var->val.integer);
}

static void
sprint_counter(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
void *foo;
    int quiet;
{
    if (var->type != SMI_COUNTER32){
	sprintf(buf, "Wrong Type (should be Counter): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
	return;
    }
    if (!quiet) {
      sprintf(buf, "Counter: ");
      buf += strlen(buf);
    }
    sprintf(buf, "%u", *var->val.integer);
}

static void
sprint_networkaddress(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
void *foo;
    int quiet;
{
    int x, len;
    u_char *cp;

    if (!quiet) {
      sprintf(buf, "Network Address:\t");
      buf += strlen(buf);
    }
    cp = var->val.string;    
    len = var->val_len;
    for(x = 0; x < len; x++){
	sprintf(buf, "%02X", *cp++);
	buf += strlen(buf);
	if (x < (len - 1))
