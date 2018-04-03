  *     }
  *   }
  */
-u_char *snmp_var_EncodeVarBind(u_char *Buffer, int *BufLenP,
-			       struct variable_list *VarList,
-			       int Version)
+u_char *
+snmp_var_EncodeVarBind(u_char * Buffer, int *BufLenP,
+    variable_list * VarList,
+    int Version)
 {
-  struct variable_list *Vars;
-  u_char *bufp;
-  u_char *HeaderStart;
-  u_char *HeaderEnd;
-  int FakeArg = *BufLenP;
-#ifdef DEBUG_VARS_ENCODE
-  int StartLen = *BufLenP;
-  int Counter = 1;
-#endif
-
-  bufp = Buffer;
-
-#ifdef DEBUG_VARS_ENCODE
-  printf("VARS: Encoding Variable list into buffer at 0x%x.\n", Buffer);
-#endif
-
-  for (Vars=VarList; Vars; Vars=Vars->next_variable) {
-
-#ifdef DEBUG_VARS_ENCODE
-    printf("VARS %d: Encoding Variable 0x%x.\n", Counter, Vars);
-    printf("VARS %d: Starting at 0x%x (%d bytes left)\n", 
-	   Counter, bufp, *BufLenP);
-#endif
-
-    /* Build the header for this variable
-     *
-     * Use Maximum size.
-     */
-    HeaderStart = bufp;
-    HeaderEnd = asn_build_header(HeaderStart, BufLenP,
-				 (u_char)(ASN_SEQUENCE | ASN_CONSTRUCTOR), 
-				 FakeArg);
-    if (HeaderEnd == NULL)
-      return(NULL);
-
-#ifdef DEBUG_VARS_ENCODE
-    printf("VARS %d: Encoding Object Identifier 0x%x (%d bytes) at 0x%x (%d bytes left)\n", 
-	   Counter, Vars,
-	   Vars->name_length, HeaderEnd, *BufLenP);
-    print_oid(Vars->name, Vars->name_length),
-#endif
-    /* Now, let's put the Object Identifier into the buffer */
-    bufp = asn_build_objid(HeaderEnd, BufLenP,
-			   (u_char)(ASN_UNIVERSAL | 
-				    ASN_PRIMITIVE | 
-				    ASN_OBJECT_ID),
-			   Vars->name, Vars->name_length);
-    if (bufp == NULL)
-      return(NULL);
-
-    /* Now put the data in */
-    switch(Vars->type) {
-
-    case ASN_INTEGER:
-#ifdef DEBUG_VARS_ENCODE
-      printf("VARS %d: Encoding Integer %d at 0x%x\n", Counter,
-	     *(Vars->val.integer), bufp);
-#endif
-
-      bufp = asn_build_int(bufp, 
-			   BufLenP, Vars->type,
-			   (int *)Vars->val.integer, Vars->val_len);
-      break;
-
-    case SMI_COUNTER32:
-    case SMI_GAUGE32:
-      /*  case SMI_UNSIGNED32: */
-    case SMI_TIMETICKS:
-#ifdef DEBUG_VARS_ENCODE
-      printf("VARS %d: Encoding Timeticks %d at 0x%x\n", Counter,
-	     *(Vars->val.integer), bufp);
-#endif
-      bufp = asn_build_unsigned_int(bufp, BufLenP, 
-				    Vars->type,
-				    (u_int *)Vars->val.integer, Vars->val_len);
-      break;
-
-    case ASN_OCTET_STR:
-    case SMI_IPADDRESS:
-    case SMI_OPAQUE:
-#ifdef DEBUG_VARS_ENCODE
-      printf("VARS %d: Encoding String %s (%d bytes) at 0x%x\n", Counter,
-	     (Vars->val.string), Vars->val_len, bufp);
-#endif
-      bufp = asn_build_string(bufp, BufLenP, Vars->type,
-			      Vars->val.string, Vars->val_len);
-      break;
-
-    case ASN_OBJECT_ID:
-#ifdef DEBUG_VARS_ENCODE
-      printf("VARS %d: Encoding Object Identifier (%d bytes) at 0x%x\n",
-	     Counter,
-	     Vars->val_len, bufp);
-#endif
-      bufp = asn_build_objid(bufp, BufLenP, Vars->type,
-			     (oid *)Vars->val.objid, Vars->val_len / sizeof(oid));
-      break;
-
-    case SMI_NOSUCHINSTANCE:
-    case SMI_NOSUCHOBJECT:
-    case SMI_ENDOFMIBVIEW:
-
-#ifdef DEBUG_VARS_ENCODE
-      printf("VARS %d: Encoding NULL at 0x%x\n", Counter, bufp);
-#endif
-      if (Version == SNMP_VERSION_1) {
-        /* SNMP Version 1 does not support these error codes. */
-	bufp = asn_build_null(bufp, BufLenP, SMI_NOSUCHOBJECT);
-      } else {
-	bufp = asn_build_exception(bufp, BufLenP, Vars->type);
-      }
-      break;
-
-    case ASN_NULL:
-#ifdef DEBUG_VARS_ENCODE
-      printf("VARS %d: Encoding NULL at 0x%x\n", Counter, bufp);
-#endif
-      bufp = asn_build_null(bufp, BufLenP, Vars->type);
-      break;
-
-    case SMI_COUNTER64:
-      snmplib_debug(2, "Unable to encode type SMI_COUNTER64!\n");
-      /* Fall through */
-
-    default:
-      snmp_set_api_error(SNMPERR_UNSUPPORTED_TYPE);
-      return(NULL);
-    }
-
-    /* ASSERT:  bufp should now point to the next valid byte. */
-    if (bufp == NULL)
-      return(NULL);
-
-    /* Rebuild the header with the appropriate length */
-#ifdef DEBUG_VARS_ENCODE
-    printf("VARS %d: Resetting length to %d at 0x%x (%d bytes left)\n",
-	   Counter,
-	   (bufp - HeaderEnd), HeaderStart, *BufLenP);
-#endif
-    HeaderEnd = asn_build_header(HeaderStart, &FakeArg,
-				 (u_char)(ASN_SEQUENCE | ASN_CONSTRUCTOR), 
-				 (bufp - HeaderEnd));
+    struct variable_list *Vars;
+    u_char *bufp;
+    u_char *HeaderStart;
+    u_char *HeaderEnd;
+    int FakeArg = *BufLenP;
+
+    bufp = Buffer;
+
+    for (Vars = VarList; Vars; Vars = Vars->next_variable) {
+
+	/* Build the header for this variable
+	 *
+	 * Use Maximum size.
+	 */
+	HeaderStart = bufp;
+	HeaderEnd = asn_build_header(HeaderStart, BufLenP,
+	    (u_char) (ASN_SEQUENCE | ASN_CONSTRUCTOR),
+	    FakeArg);
+	if (HeaderEnd == NULL)
+	    return (NULL);
+
+	/* Now, let's put the Object Identifier into the buffer */
+	bufp = asn_build_objid(HeaderEnd, BufLenP,
+	    (u_char) (ASN_UNIVERSAL |
+		ASN_PRIMITIVE |
+		ASN_OBJECT_ID),
+	    Vars->name, Vars->name_length);
+	if (bufp == NULL)
+	    return (NULL);
+
+	/* Now put the data in */
+	switch (Vars->type) {
+
+	case ASN_INTEGER:
+	    bufp = asn_build_int(bufp,
+		BufLenP, Vars->type,
+		(int *) Vars->val.integer, Vars->val_len);
+	    break;
+
+	case SMI_COUNTER32:
+	case SMI_GAUGE32:
+	    /*  case SMI_UNSIGNED32: */
+	case SMI_TIMETICKS:
+	    bufp = asn_build_unsigned_int(bufp, BufLenP,
+		Vars->type,
+		(u_int *) Vars->val.integer, Vars->val_len);
+	    break;
+
+	case ASN_OCTET_STR:
+	case SMI_IPADDRESS:
+	case SMI_OPAQUE:
+	    bufp = asn_build_string(bufp, BufLenP, Vars->type,
+		Vars->val.string, Vars->val_len);
+	    break;
+
+	case ASN_OBJECT_ID:
+	    bufp = asn_build_objid(bufp, BufLenP, Vars->type,
+		(oid *) Vars->val.objid, Vars->val_len / sizeof(oid));
+	    break;
+
+	case SMI_NOSUCHINSTANCE:
+	case SMI_NOSUCHOBJECT:
+	case SMI_ENDOFMIBVIEW:
+	    if (Version == SNMP_VERSION_1) {
+		/* SNMP Version 1 does not support these error codes. */
+		bufp = asn_build_null(bufp, BufLenP, SMI_NOSUCHOBJECT);
+	    } else {
+		bufp = asn_build_exception(bufp, BufLenP, Vars->type);
+	    }
+	    break;
+
+	case ASN_NULL:
+	    bufp = asn_build_null(bufp, BufLenP, Vars->type);
+	    break;
+
+	case SMI_COUNTER64:
+	    snmplib_debug(2, "Unable to encode type SMI_COUNTER64!\n");
+	    /* Fall through */
+
+	default:
+	    snmp_set_api_error(SNMPERR_UNSUPPORTED_TYPE);
+	    return (NULL);
+	}
+
+	/* ASSERT:  bufp should now point to the next valid byte. */
+	if (bufp == NULL)
+	    return (NULL);
+
+	/* Rebuild the header with the appropriate length */
+	HeaderEnd = asn_build_header(HeaderStart, &FakeArg,
+	    (u_char) (ASN_SEQUENCE | ASN_CONSTRUCTOR),
+	    (bufp - HeaderEnd));
+
+	/* Returns NULL */
+	if (HeaderEnd == NULL)
+	    return (NULL);
 
-    /* Returns NULL */
-    if (HeaderEnd == NULL)
-      return(NULL);
-
-#ifdef DEBUG_VARS_ENCODE
-    Counter++;
-#endif
-  }
-
-#ifdef DEBUG_VARS_ENCODE
-  printf("VARS: Variable list of %d vars takes up %d bytes.\n",
-	 --Counter, StartLen - *BufLenP);
-#endif
+    }
 
-  /* or the end of the entire thing */
-  return(bufp);
+    /* or the end of the entire thing */
+    return (bufp);
 }
 
-			      
+
 
 
 /* Parse all Vars from the buffer */
-u_char *snmp_var_DecodeVarBind(u_char *Buffer, int *BufLen,
-			       struct variable_list **VarP,
-			       int Version)
+u_char *
+snmp_var_DecodeVarBind(u_char * Buffer, int *BufLen,
+    struct variable_list ** VarP,
+    int Version)
 {
-  struct variable_list *Var, **VarLastP;
-  u_char *bufp, *tmp;
-  u_char  VarBindType;
-  u_char *DataPtr;
-  int     DataLen;
-  oid TmpBuf[MAX_NAME_LEN];
+    struct variable_list *Var, **VarLastP;
+    u_char *bufp, *tmp;
+    u_char VarBindType;
+    u_char *DataPtr;
+    int DataLen;
+    oid TmpBuf[MAX_NAME_LEN];
 
-  int AllVarLen = *BufLen;
-  int ThisVarLen = 0;
+    int AllVarLen = *BufLen;
+    int ThisVarLen = 0;
 
-  VarLastP = VarP;
+    VarLastP = VarP;
 #ifdef DEBUG_VARS_DECODE
-  printf("VARS: Decoding buffer of length %d\n", *BufLen);
+    printf("VARS: Decoding buffer of length %d\n", *BufLen);
 #endif
 
-  /* Now parse the variables */
-  bufp = asn_parse_header(Buffer, &AllVarLen, &VarBindType);
-  if (bufp == NULL)
-    ASN_PARSE_ERROR(NULL);
-
-  if (VarBindType != (u_char)(ASN_SEQUENCE | ASN_CONSTRUCTOR)) {
-      snmp_set_api_error(SNMPERR_PDU_PARSE);
-      ASN_PARSE_ERROR(NULL);
-  }
+    /* Now parse the variables */
+    bufp = asn_parse_header(Buffer, &AllVarLen, &VarBindType);
+    if (bufp == NULL)
+	ASN_PARSE_ERROR(NULL);
 
-#ifdef DEBUG_VARS_DECODE
-  printf("VARS: All Variable length %d\n", AllVarLen);
-#endif
-
-  /* We know how long the variable list is.  Parse it. */
-  while ((int)AllVarLen > 0) {
-
-    /* Create a new variable */
-    Var = snmp_var_new(NULL, MAX_NAME_LEN);
-    if (Var == NULL)
-      return(NULL);
-    
-    /* Parse the header to find out the length of this variable. */
-    ThisVarLen = AllVarLen;
-    tmp = asn_parse_header(bufp, &ThisVarLen, &VarBindType);
-    if (tmp == NULL)
-      ASN_PARSE_ERROR(NULL);
-
-    /* Now that we know the length , figure out how it relates to 
-     * the entire variable list
-     */
-    AllVarLen = AllVarLen - (ThisVarLen + (tmp - bufp));
-    bufp = tmp;
-
-    /* Is it valid? */
-    if (VarBindType != (u_char)(ASN_SEQUENCE | ASN_CONSTRUCTOR)) {
-      snmp_set_api_error(SNMPERR_PDU_PARSE);
-      ASN_PARSE_ERROR(NULL);
+    if (VarBindType != (u_char) (ASN_SEQUENCE | ASN_CONSTRUCTOR)) {
+	snmp_set_api_error(SNMPERR_PDU_PARSE);
+	ASN_PARSE_ERROR(NULL);
     }
-
 #ifdef DEBUG_VARS_DECODE
-    printf("VARS: Header type 0x%x (%d bytes left)\n", VarBindType, ThisVarLen);
+    printf("VARS: All Variable length %d\n", AllVarLen);
+#endif
+
+    /* We know how long the variable list is.  Parse it. */
+    while ((int) AllVarLen > 0) {
+
+	/* Create a new variable */
+	Var = snmp_var_new(NULL, MAX_NAME_LEN);
+	if (Var == NULL)
+	    return (NULL);
+
+	/* Parse the header to find out the length of this variable. */
+	ThisVarLen = AllVarLen;
+	tmp = asn_parse_header(bufp, &ThisVarLen, &VarBindType);
+	if (tmp == NULL)
+	    ASN_PARSE_ERROR(NULL);
+
+	/* Now that we know the length , figure out how it relates to 
+	 * the entire variable list
+	 */
+	AllVarLen = AllVarLen - (ThisVarLen + (tmp - bufp));
+	bufp = tmp;
+
+	/* Is it valid? */
+	if (VarBindType != (u_char) (ASN_SEQUENCE | ASN_CONSTRUCTOR)) {
+	    snmp_set_api_error(SNMPERR_PDU_PARSE);
+	    ASN_PARSE_ERROR(NULL);
+	}
+#ifdef DEBUG_VARS_DECODE
+	printf("VARS: Header type 0x%x (%d bytes left)\n", VarBindType, ThisVarLen);
 #endif
 
-    /* Parse the OBJID */
-    bufp = asn_parse_objid(bufp, &ThisVarLen, &VarBindType, 
-			   Var->name, &(Var->name_length));
-    if (bufp == NULL)
-      ASN_PARSE_ERROR(NULL);
-
-    if (VarBindType != (u_char)(ASN_UNIVERSAL | 
-				ASN_PRIMITIVE | 
-				ASN_OBJECT_ID)) {
-      snmp_set_api_error(SNMPERR_PDU_PARSE);
-      ASN_PARSE_ERROR(NULL);
-    }
+	/* Parse the OBJID */
+	bufp = asn_parse_objid(bufp, &ThisVarLen, &VarBindType,
+	    Var->name, &(Var->name_length));
+	if (bufp == NULL)
+	    ASN_PARSE_ERROR(NULL);
 
+	if (VarBindType != (u_char) (ASN_UNIVERSAL |
+		ASN_PRIMITIVE |
+		ASN_OBJECT_ID)) {
+	    snmp_set_api_error(SNMPERR_PDU_PARSE);
+	    ASN_PARSE_ERROR(NULL);
+	}
 #ifdef DEBUG_VARS_DECODE
-    printf("VARS: Decoded OBJID (%d bytes). (%d bytes left)\n", 
-	   Var->name_length, ThisVarLen);
+	printf("VARS: Decoded OBJID (%d bytes). (%d bytes left)\n",
+	    Var->name_length, ThisVarLen);
 #endif
 
-    /* Keep a pointer to this object */
-    DataPtr = bufp;
-    DataLen = ThisVarLen;
+	/* Keep a pointer to this object */
+	DataPtr = bufp;
+	DataLen = ThisVarLen;
 
-    /* find out type of object */
-    bufp = asn_parse_header(bufp, &ThisVarLen, &(Var->type));
-    if (bufp == NULL)
-      ASN_PARSE_ERROR(NULL);
-    ThisVarLen = DataLen;
+	/* find out type of object */
+	bufp = asn_parse_header(bufp, &ThisVarLen, &(Var->type));
+	if (bufp == NULL)
+	    ASN_PARSE_ERROR(NULL);
+	ThisVarLen = DataLen;
 
 #ifdef DEBUG_VARS_DECODE
-    printf("VARS: Data type %d\n", Var->type);
+	printf("VARS: Data type %d\n", Var->type);
 #endif
 
-    /* Parse the type */
-    
-    switch((short)Var->type){
+	/* Parse the type */
 
-    case ASN_INTEGER:
-      Var->val.integer = (int *)xmalloc(sizeof(int));
-      if (Var->val.integer == NULL) {
-	snmp_set_api_error(SNMPERR_OS_ERR);
-	return(NULL);
-      }
-      Var->val_len = sizeof(int);
-      bufp = asn_parse_int(DataPtr, &ThisVarLen, 
-			   &Var->type, (int *)Var->val.integer, 
-			   Var->val_len);
-#ifdef DEBUG_VARS_DECODE
-      printf("VARS: Decoded integer '%d' (%d bytes left)\n",
-	     *(Var->val.integer), ThisVarLen);
-#endif
-      break;
+	switch ((short) Var->type) {
 
-    case SMI_COUNTER32:
-    case SMI_GAUGE32:
-      /*  case SMI_UNSIGNED32: */
-    case SMI_TIMETICKS:
-      Var->val.integer = (int *)xmalloc(sizeof(u_int));
-      if (Var->val.integer == NULL) {
-	snmp_set_api_error(SNMPERR_OS_ERR);
-	return(NULL);
-      }
-      Var->val_len = sizeof(u_int);
-      bufp = asn_parse_unsigned_int(DataPtr, &ThisVarLen, 
-				    &Var->type, (u_int *)Var->val.integer, 
-				    Var->val_len);
+	case ASN_INTEGER:
+	    Var->val.integer = (int *) xmalloc(sizeof(int));
+	    if (Var->val.integer == NULL) {
+		snmp_set_api_error(SNMPERR_OS_ERR);
+		return (NULL);
+	    }
+	    Var->val_len = sizeof(int);
+	    bufp = asn_parse_int(DataPtr, &ThisVarLen,
+		&Var->type, (int *) Var->val.integer,
+		Var->val_len);
 #ifdef DEBUG_VARS_DECODE
-      printf("VARS: Decoded timeticks '%d' (%d bytes left)\n",
-	     *(Var->val.integer), ThisVarLen);
-#endif
-      break;
-
-    case ASN_OCTET_STR:
-    case SMI_IPADDRESS:
-    case SMI_OPAQUE:
-      Var->val_len = *&ThisVarLen; /* String is this at most */
-      Var->val.string = (u_char *)xmalloc((unsigned)Var->val_len);
-      if (Var->val.string == NULL) {
-	snmp_set_api_error(SNMPERR_OS_ERR);
-	return(NULL);
-      }
-      bufp = asn_parse_string(DataPtr, &ThisVarLen, 
-			      &Var->type, Var->val.string, 
-			      &Var->val_len);
+	    printf("VARS: Decoded integer '%d' (%d bytes left)\n",
+		*(Var->val.integer), ThisVarLen);
+#endif
+	    break;
+
+	case SMI_COUNTER32:
+	case SMI_GAUGE32:
+	    /*  case SMI_UNSIGNED32: */
+	case SMI_TIMETICKS:
+	    Var->val.integer = (int *) xmalloc(sizeof(u_int));
+	    if (Var->val.integer == NULL) {
+		snmp_set_api_error(SNMPERR_OS_ERR);
+		return (NULL);
+	    }
+	    Var->val_len = sizeof(u_int);
+	    bufp = asn_parse_unsigned_int(DataPtr, &ThisVarLen,
+		&Var->type, (u_int *) Var->val.integer,
+		Var->val_len);
 #ifdef DEBUG_VARS_DECODE
-      printf("VARS: Decoded string '%s' (length %d) (%d bytes left)\n",
-	     (Var->val.string), Var->val_len, ThisVarLen);
-#endif
-      break;
-         
-    case ASN_OBJECT_ID:
-      Var->val_len = MAX_NAME_LEN;
-      bufp = asn_parse_objid(DataPtr, &ThisVarLen, 
-			     &Var->type, TmpBuf, &Var->val_len);
-      Var->val_len *= sizeof(oid);
-      Var->val.objid = (oid *)xmalloc((unsigned)Var->val_len);
-      if (Var->val.integer == NULL) {
-	snmp_set_api_error(SNMPERR_OS_ERR);
-	return(NULL);
-      }
-      /* Only copy if we successfully decoded something */
-      if (bufp) {
-	xmemcpy((char *)Var->val.objid, (char *)TmpBuf, Var->val_len);
-      }
+	    printf("VARS: Decoded timeticks '%d' (%d bytes left)\n",
+		*(Var->val.integer), ThisVarLen);
+#endif
+	    break;
+
+	case ASN_OCTET_STR:
+	case SMI_IPADDRESS:
+	case SMI_OPAQUE:
+	    Var->val_len = *&ThisVarLen;	/* String is this at most */
+	    Var->val.string = (u_char *) xmalloc((unsigned) Var->val_len);
+	    if (Var->val.string == NULL) {
+		snmp_set_api_error(SNMPERR_OS_ERR);
+		return (NULL);
+	    }
+	    bufp = asn_parse_string(DataPtr, &ThisVarLen,
+		&Var->type, Var->val.string,
+		&Var->val_len);
 #ifdef DEBUG_VARS_DECODE
-      printf("VARS: Decoded OBJID (length %d) (%d bytes left)\n",
-	      Var->val_len, ThisVarLen);
-#endif
-      break;
-
-    case ASN_NULL:
-    case SMI_NOSUCHINSTANCE:
-    case SMI_NOSUCHOBJECT:
-    case SMI_ENDOFMIBVIEW:
-      break;
-
-    case SMI_COUNTER64:
-      snmplib_debug(2, "Unable to parse type SMI_COUNTER64!\n");
-      snmp_set_api_error(SNMPERR_UNSUPPORTED_TYPE);
-      return(NULL);
-      break;
-
-    default:
-      snmplib_debug(2, "bad type returned (%x)\n", Var->type);
-      snmp_set_api_error(SNMPERR_PDU_PARSE);
-      return(NULL);
-      break;
-    } /* End of var type switch */
+	    printf("VARS: Decoded string '%s' (length %d) (%d bytes left)\n",
+		(Var->val.string), Var->val_len, ThisVarLen);
+#endif
+	    break;
+
+	case ASN_OBJECT_ID:
+	    Var->val_len = MAX_NAME_LEN;
+	    bufp = asn_parse_objid(DataPtr, &ThisVarLen,
+		&Var->type, TmpBuf, &Var->val_len);
+	    Var->val_len *= sizeof(oid);
+	    Var->val.objid = (oid *) xmalloc((unsigned) Var->val_len);
+	    if (Var->val.integer == NULL) {
+		snmp_set_api_error(SNMPERR_OS_ERR);
+		return (NULL);
+	    }
+	    /* Only copy if we successfully decoded something */
+	    if (bufp) {
+		xmemcpy((char *) Var->val.objid, (char *) TmpBuf, Var->val_len);
+	    }
+#ifdef DEBUG_VARS_DECODE
+	    printf("VARS: Decoded OBJID (length %d) (%d bytes left)\n",
+		Var->val_len, ThisVarLen);
+#endif
+	    break;
 
-    if (bufp == NULL)
-      return(NULL);
+	case ASN_NULL:
+	case SMI_NOSUCHINSTANCE:
+	case SMI_NOSUCHOBJECT:
+	case SMI_ENDOFMIBVIEW:
+	    break;
+
+	case SMI_COUNTER64:
+	    snmplib_debug(2, "Unable to parse type SMI_COUNTER64!\n");
+	    snmp_set_api_error(SNMPERR_UNSUPPORTED_TYPE);
+	    return (NULL);
+	    break;
+
+	default:
+	    snmplib_debug(2, "bad type returned (%x)\n", Var->type);
+	    snmp_set_api_error(SNMPERR_PDU_PARSE);
+	    return (NULL);
+	    break;
+	}			/* End of var type switch */
+
+	if (bufp == NULL)
+	    return (NULL);
 
 #ifdef DEBUG_VARS_DECODE
-    printf("VARS:  Adding to list.\n");
+	printf("VARS:  Adding to list.\n");
 #endif
-    /* Add variable to the list */
-    *VarLastP = Var;
-    VarLastP = &(Var->next_variable);
-  }
+	/* Add variable to the list */
+	*VarLastP = Var;
+	VarLastP = &(Var->next_variable);
+    }
 
-  return(bufp);
+    return (bufp);
 }
