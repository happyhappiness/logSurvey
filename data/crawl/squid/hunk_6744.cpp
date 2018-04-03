     minutes = timeticks / 60;
     seconds = timeticks % 60;
 
-    if (days == 0) {
-	snprintf(buf, 32, "%d:%02d:%02d", hours, minutes, seconds);
+    if (days == 0){
+	snprintf(buf,32,  "%d:%02d:%02d", hours, minutes, seconds);
     } else if (days == 1) {
-	snprintf(buf, 32, "%d day, %d:%02d:%02d", days, hours, minutes, seconds);
+	snprintf(buf,32, "%d day, %d:%02d:%02d", days, hours, minutes, seconds);
     } else {
-	snprintf(buf, 32, "%d days, %d:%02d:%02d", days, hours, minutes, seconds);
+	snprintf(buf,32,  "%d days, %d:%02d:%02d", days, hours, minutes, seconds);
     }
     return buf;
 }
 
-static void
-sprint_hexstring(char *buf, unsigned char *cp, int len)
+static void sprint_hexstring(buf, cp, len)
+    char *buf;
+    u_char  *cp;
+    int	    len;
 {
 
-    for (; len >= 16; len -= 16) {
-	sprintf(buf, "%02X %02X %02X %02X %02X %02X %02X %02X ", cp[0], cp[1], cp[2], cp[3], cp[4], cp[5], cp[6], cp[7]);
+    for(; len >= 16; len -= 16){
+	snprintf(buf,26, "%02X %02X %02X %02X %02X %02X %02X %02X ", cp[0], cp[1], cp[2], cp[3], cp[4], cp[5], cp[6], cp[7]);
 	buf += strlen(buf);
 	cp += 8;
-	sprintf(buf, "%02X %02X %02X %02X %02X %02X %02X %02X\n", cp[0], cp[1], cp[2], cp[3], cp[4], cp[5], cp[6], cp[7]);
+	snprintf(buf,26, "%02X %02X %02X %02X %02X %02X %02X %02X\n", cp[0], cp[1], cp[2], cp[3], cp[4], cp[5], cp[6], cp[7]);
 	buf += strlen(buf);
 	cp += 8;
     }
-    for (; len > 0; len--) {
-	sprintf(buf, "%02X ", *cp++);
+    for(; len > 0; len--){
+	snprintf(buf, 4, "%02X ", *cp++);
 	buf += strlen(buf);
     }
     *buf = '\0';
 }
 
-static void
-sprint_asciistring(char *buf, unsigned char *cp, int len)
+static void sprint_asciistring(buf, cp, len)
+    char *buf;
+    u_char  *cp;
+    int	    len;
 {
-    int x;
+    int	x;
 
-    for (x = 0; x < len; x++) {
-	if (isprint(*cp)) {
+    for(x = 0; x < len; x++){
+	if (isprint(*cp)){
 	    *buf++ = *cp++;
 	} else {
 	    *buf++ = '.';
 	    cp++;
 	}
-#if 0
 	if ((x % 48) == 47)
 	    *buf++ = '\n';
-#endif
     }
     *buf = '\0';
 }
 
-#ifdef UNUSED
-int
-read_rawobjid(char *input, oid * output, int *out_len)
-{
-    char buf[12], *cp;
-    oid *op = output;
-    u_long subid;
-
-    while (*input != '\0') {
-	if (!isdigit(*input))
-	    break;
-	cp = buf;
-	while (isdigit(*input))
-	    *cp++ = *input++;
-	*cp = '\0';
-	subid = atoi(buf);
-	if (subid > MAX_SUBID) {
-	    fprintf(stderr, "sub-identifier too large: %s\n", buf);
-	    return 0;
-	}
-	if ((*out_len)-- <= 0) {
-	    fprintf(stderr, "object identifier too long\n");
-	    return 0;
-	}
-	*op++ = subid;
-	if (*input++ != '.')
-	    break;
-    }
-    *out_len = op - output;
-    if (*out_len == 0)
-	return 0;
-    return 1;
-}
-
-#endif /* UNUSED */
-
-/*
- * 0
- * < 4
- * hex
- * 
- * 0 ""
- * < 4 hex Hex: oo oo oo
- * < 4     "fgh" Hex: oo oo oo
- * > 4 hex Hex: oo oo oo oo oo oo oo oo
- * > 4     "this is a test"
- * 
- */
 static void
-sprint_octet_string(char *buf, struct variable_list *var, struct enum_list *enums)
+sprint_octet_string(buf, var, foo, quiet)
+    char *buf;
+    variable_list *var;
+void *foo;
+    int quiet;
 {
     int hex, x;
     u_char *cp;
 
-    if (var->type != ASN_OCTET_STR) {
+    if (var->type != ASN_OCTET_STR){
 	sprintf(buf, "Wrong Type (should be OCTET STRING): ");
 	buf += strlen(buf);
-	sprint_by_type(buf, var, (struct enum_list *) NULL);
+	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
 	return;
     }
     hex = 0;
-    for (cp = var->val.string, x = 0; x < var->val_len; x++, cp++) {
+    for(cp = var->val.string, x = 0; x < var->val_len; x++, cp++){
 	if (!(isprint(*cp) || isspace(*cp)))
 	    hex = 1;
     }
-    if (var->val_len == 0) {
-	strcpy(buf, "\"\"");
-	return;
-    }
-    if (!hex) {
-	*buf++ = '"';
-	sprint_asciistring(buf, var->val.string, var->val_len);
-	buf += strlen(buf);
-	*buf++ = '"';
-	*buf = '\0';
-    }
-    if (hex || var->val_len <= 4) {
-	sprintf(buf, " Hex: ");
+    if (var->val_len <= 4)
+	hex = 1;    /* not likely to be ascii */
+    if (hex){
+      if (!quiet) {
+	sprintf(buf, "OCTET STRING-   (hex):\t");
 	buf += strlen(buf);
+      }
 	sprint_hexstring(buf, var->val.string, var->val_len);
+    } else {
+      if (!quiet) {
+	sprintf(buf, "OCTET STRING- (ascii):\t");
+	buf += strlen(buf);
+      }
+	sprint_asciistring(buf, var->val.string, var->val_len);
     }
 }
 
 static void
-sprint_opaque(char *buf, struct variable_list *var, struct enum_list *enums)
+sprint_opaque(buf, var, foo, quiet)
+    char *buf;
+    variable_list *var;
+    void *foo;
+    int quiet;
 {
 
-    if (var->type != OPAQUE) {
+    if (var->type != SMI_OPAQUE){
 	sprintf(buf, "Wrong Type (should be Opaque): ");
 	buf += strlen(buf);
-	sprint_by_type(buf, var, (struct enum_list *) NULL);
+	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
 	return;
     }
-    sprintf(buf, "OPAQUE: ");
-    buf += strlen(buf);
+    if (!quiet) {
+      sprintf(buf, "OPAQUE -   (hex):\t");
+      buf += strlen(buf);
+    }
     sprint_hexstring(buf, var->val.string, var->val_len);
 }
 
 static void
-sprint_object_identifier(char *buf, struct variable_list *var, struct enum_list *enums)
+sprint_object_identifier(buf, var, foo, quiet)
+    char *buf;
+    variable_list *var;
+    void *foo;
+    int quiet;
 {
-    if (var->type != ASN_OBJECT_ID) {
+    if (var->type != SMI_OBJID){
 	sprintf(buf, "Wrong Type (should be OBJECT IDENTIFIER): ");
 	buf += strlen(buf);
-	sprint_by_type(buf, var, (struct enum_list *) NULL);
+	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
 	return;
     }
-    sprintf(buf, "OID: ");
-    buf += strlen(buf);
-    sprint_objid(buf, (oid *) (var->val.objid), var->val_len / sizeof(oid));
+    if (!quiet) {
+      sprintf(buf, "OBJECT IDENTIFIER:\t");
+      buf += strlen(buf);
+    }
+    sprint_objid(buf, (oid *)(var->val.objid), var->val_len / sizeof(oid));
 }
 
 static void
-sprint_timeticks(char *buf, struct variable_list *var, struct enum_list *enums)
+sprint_timeticks(buf, var, foo, quiet)
+    char *buf;
+    variable_list *var;
+    void *foo;
+    int quiet;
 {
     char timebuf[32];
 
-    if (var->type != TIMETICKS) {
+    if (var->type != SMI_TIMETICKS){
 	sprintf(buf, "Wrong Type (should be Timeticks): ");
 	buf += strlen(buf);
-	sprint_by_type(buf, var, (struct enum_list *) NULL);
+	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
 	return;
     }
-    sprintf(buf, "Timeticks: (%ld) %s", *(u_long *) (var->val.integer),
-	uptimeString(*(u_long *) (var->val.integer), timebuf));
+    if (!quiet) {
+      sprintf(buf, "Timeticks: ");
+      buf += strlen(buf);
+    }
+    sprintf(buf, "(%u) %s", 
+	    *(var->val.integer), 
+	    uptimeString(*(var->val.integer), timebuf));
 }
 
 static void
-sprint_integer(char *buf, struct variable_list *var, struct enum_list *enums)
+sprint_integer(buf, var, enums, quiet)
+    char *buf;
+    variable_list *var;
+    struct enum_list	    *enums;
+    int quiet;
 {
-    char *enum_string = NULL;
+    char    *enum_string = NULL;
 
-    if (var->type != ASN_INTEGER) {
+    if (var->type != SMI_INTEGER){
 	sprintf(buf, "Wrong Type (should be INTEGER): ");
 	buf += strlen(buf);
-	sprint_by_type(buf, var, (struct enum_list *) NULL);
+	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
 	return;
     }
     for (; enums; enums = enums->next)
-	if (enums->value == *var->val.integer) {
+	if (enums->value == *var->val.integer){
 	    enum_string = enums->label;
 	    break;
 	}
-    if (enum_string == NULL)
-	sprintf(buf, "%ld", *var->val.integer);
-    else
-	sprintf(buf, "%s(%ld)", enum_string, *var->val.integer);
-}
-
-static void
-sprint_uinteger(char *buf, struct variable_list *var, struct enum_list *enums)
-{
-    char *enum_string = NULL;
 
-    if (var->type != UINTEGER) {
-	sprintf(buf, "Wrong Type (should be UInteger32): ");
-	buf += strlen(buf);
-	sprint_by_type(buf, var, (struct enum_list *) NULL);
-	return;
+    if (!quiet) {
+      sprintf(buf, "INTEGER: ");
+      buf += strlen(buf);
     }
-    for (; enums; enums = enums->next)
-	if (enums->value == *var->val.integer) {
-	    enum_string = enums->label;
-	    break;
-	}
+ 
     if (enum_string == NULL)
-	sprintf(buf, "%ld", *var->val.integer);
+	sprintf(buf, "%u", *var->val.integer);
     else
-	sprintf(buf, "%s(%ld)", enum_string, *var->val.integer);
+	sprintf(buf, "%s(%u)", enum_string, *var->val.integer);
 }
 
 static void
-sprint_gauge(char *buf, struct variable_list *var, struct enum_list *enums)
+sprint_gauge(buf, var, foo, quiet)
+    char *buf;
+    variable_list *var;
+void *foo;
+int quiet;
 {
-    if (var->type != GAUGE) {
+    if (var->type != SMI_GAUGE32){
 	sprintf(buf, "Wrong Type (should be Gauge): ");
 	buf += strlen(buf);
-	sprint_by_type(buf, var, (struct enum_list *) NULL);
+	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
 	return;
     }
-    sprintf(buf, "Gauge: %lu", *var->val.integer);
+    if (!quiet) {
+      sprintf(buf, "Gauge: ");
+      buf += strlen(buf);
+    }
+    sprintf(buf, "%u", *var->val.integer);
 }
 
 static void
-sprint_counter(char *buf, struct variable_list *var, struct enum_list *enums)
+sprint_counter(buf, var, foo, quiet)
+    char *buf;
+    variable_list *var;
+void *foo;
+    int quiet;
 {
-    if (var->type != COUNTER) {
+    if (var->type != SMI_COUNTER32){
 	sprintf(buf, "Wrong Type (should be Counter): ");
 	buf += strlen(buf);
-	sprint_by_type(buf, var, (struct enum_list *) NULL);
+	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
 	return;
     }
-    sprintf(buf, "%lu", *var->val.integer);
+    if (!quiet) {
+      sprintf(buf, "Counter: ");
+      buf += strlen(buf);
+    }
+    sprintf(buf, "%u", *var->val.integer);
 }
 
 static void
-sprint_networkaddress(char *buf, struct variable_list *var, struct enum_list *enums)
+sprint_networkaddress(buf, var, foo, quiet)
+    char *buf;
+    variable_list *var;
+void *foo;
+    int quiet;
 {
     int x, len;
     u_char *cp;
 
-    sprintf(buf, "Network Address: ");
-    buf += strlen(buf);
-    cp = var->val.string;
+    if (!quiet) {
+      sprintf(buf, "Network Address:\t");
+      buf += strlen(buf);
+    }
+    cp = var->val.string;    
     len = var->val_len;
-    for (x = 0; x < len; x++) {
+    for(x = 0; x < len; x++){
 	sprintf(buf, "%02X", *cp++);
 	buf += strlen(buf);
 	if (x < (len - 1))
