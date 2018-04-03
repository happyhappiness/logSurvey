 #define READ	    1
 #define WRITE	    0
 
-#define SNM_RESERVE1    0
-#define SNM_RESERVE2    1
-#define SNM_COMMIT      2
-#define SNM_ACTION      3
-#define SNM_FREE        4
+#define SNMP_RESERVE1    0
+#define SNMP_RESERVE2    1
+#define SNMP_COMMIT      2
+#define SNMP_FREE        3
 
-#define RONLY	0xAAAA		/* read access for everyone */
-#define RWRITE	0xAABA		/* add write access for community private */
-#define NOACCESS 0x0000		/* no access for anybody */
+#define RONLY	0xAAAA	/* read access for everyone */
+#define RWRITE	0xAABA	/* add write access for community private */
+#define NOACCESS 0x0000	/* no access for anybody */
 
 #define INTEGER	    ASN_INTEGER
 #define STRING	    ASN_OCTET_STR
 #define OBJID	    ASN_OBJECT_ID
 #define NULLOBJ	    ASN_NULL
 
-/* defined types (from the SMI, RFC 1065) */
-#define IPADDRESS   (ASN_APPLICATION | 0)
-#define COUNTER	    (ASN_APPLICATION | 1)
-#define GAUGE	    (ASN_APPLICATION | 2)
-#define TIMETICKS   (ASN_APPLICATION | 3)
-#define OPAQUE	    (ASN_APPLICATION | 4)
-
-#define NSAP        (ASN_APPLICATION | 5)
-#define COUNTER64   (ASN_APPLICATION | 6)
-#define UINTEGER    (ASN_APPLICATION | 7)
-
-#undef DEBUG
-#ifdef DEBUG
-#define ERROR(string)	fprintf(stderr,"%s(%d): ERROR %s\n",__FILE__, __LINE__, string);
-#else
-#define ERROR(string)
-#endif
 
-/* from snmp.c */
-extern u_char sid[];		/* size SID_MAX_LEN */
-
-extern u_char *snmp_parse_var_op(u_char * data,
-    oid * var_name,
-    int *var_name_len,
-    u_char * var_val_type,
-    int *var_val_len,
-    u_char ** var_val,
-    int *listlength);
-
-extern u_char *snmp_build_var_op(u_char * data,
-    oid * var_name,
-    int *var_name_len,
-    u_char var_val_type,
-    int var_val_len,
-    u_char * var_val,
-    int *listlength);
-
-extern u_char *snmp_auth_parse(u_char * data,
-    int *length,
-    u_char * sid,
-    int *slen,
-    long *version);
-
-extern u_char *snmp_auth_build(u_char * data,
-    int *length,
-    struct snmp_session *session,
-    int is_agent,
-    int messagelen);
+struct trapVar {
+    oid	    *varName;
+    int	    varNameLen;
+    u_char  varType;
+    int	    varLen;
+    u_char  *varVal;
+    struct trapVar *next;  
+};
 
-#endif
+/* from snmp.c*/
+extern u_char	sid[];	/* size SID_MAX_LEN */
+
+#endif /* _SNMP_IMPL_H_ */
