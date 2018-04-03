/* #define DEBUG_VARS_DECODE 1 */
/* #define DEBUG_VARS_ENCODE 1 */

#define ASN_PARSE_ERROR(x) { snmpInASNParseErrs_Add(1); return(x); }

/* Create a new variable_list structure representing oid Name of length Len.
 *
 * Returns NULL upon error.
 */

struct variable_list *snmp_var_new(oid *Name, int Len)
{
  struct variable_list *New;

#ifdef DEBUG_VARS
  printf("VARS: Creating.\n");
#endif

  New = (struct variable_list *)xmalloc(sizeof(struct variable_list));
  if (New == NULL) {
    snmp_set_api_error(SNMPERR_OS_ERR);
    return(NULL);
  }
  memset(New, '\0', sizeof(struct variable_list));
  /*  New->next_variable = NULL; */

  New->type = ASN_NULL;
  New->name_length = Len;

  if (New->name_length == 0) {
    New->name = NULL;
    return(New);
  }

  New->name = (oid *)xmalloc(Len * sizeof(oid));
  if (New->name == NULL) {
    xfree(New);
    snmp_set_api_error(SNMPERR_OS_ERR);
    return(NULL);
  }

#ifdef DEBUG_VARS
  printf("VARS: Copying name, size (%d)\n", Len);
#endif

  /* Only copy a name if it was specified. */
  if (Name)
    xmemcpy((char *)New->name, (char *)Name, Len * sizeof(oid));
  
  /*  New->val.string = NULL; */
  /*  New->val_len = 0; */

#ifdef DEBUG_VARS
  printf("VARS: Created %x.\n", (unsigned int)New);
#endif

#ifdef DEBUG_VARS_MALLOC
  printf("VARS: Created (%x)\n", (unsigned int)New);
  printf("VARS: Name is (%x)\n", (unsigned int)New->name);
#endif
  return(New);
}

/* Clone a variable list.
 *
 * Returns NULL upon error.
 */

struct variable_list *snmp_var_clone(struct variable_list *Src)
{
  struct variable_list *Dest;

#ifdef DEBUG_VARS
  printf("VARS: Cloning.\n");
#endif

  Dest = (struct variable_list *)xmalloc(sizeof(struct variable_list));
  if (Dest == NULL) {
    snmp_set_api_error(SNMPERR_OS_ERR);
    return(NULL);
  }

#ifdef DEBUG_VARS
  printf("VARS: Copying entire variable list.  (Size %d)\n",
	 sizeof(struct variable_list));
#endif

  xmemcpy((char *)Dest, (char *)Src, sizeof(struct variable_list));

  if (Src->name != NULL){
    Dest->name = (oid *)xmalloc(Src->name_length * sizeof(oid));
    if (Dest->name == NULL) {
      snmp_set_api_error(SNMPERR_OS_ERR);
      xfree(Dest);
      return(NULL);
    }
#ifdef DEBUG_VARS
    printf("VARS: Copying name OID. (Size %d)\n", Src->name_length);
#endif
    xmemcpy((char *)Dest->name, (char *)Src->name,
    	   Src->name_length * sizeof(oid));
  }

  /* CISCO Catalyst 2900 returns NULL strings as data of length 0. */
  if ((Src->val.string != NULL) &&
      (Src->val_len)) {
    Dest->val.string = (u_char *)xmalloc(Src->val_len);
    if (Dest->val.string == NULL) {
      snmp_set_api_error(SNMPERR_OS_ERR);
      xfree(Dest->name);
      xfree(Dest);
      return(NULL);
    }

#ifdef DEBUG_VARS
    printf("VARS: Copying value (Size %d)\n", Src->val_len);
#endif
    xmemcpy((char *)Dest->val.string, (char *)Src->val.string, Src->val_len);
  }

#ifdef DEBUG_VARS
  printf("VARS: Cloned %x.\n", (unsigned int)Dest);
#endif
#ifdef DEBUG_VARS_MALLOC
  printf("VARS: Cloned  (%x)\n", (unsigned int)Dest);
  printf("VARS: Name is (%x)\n", (unsigned int)Dest->name);
#endif

  return(Dest);
}

/* Free a variable_list.
 */
void snmp_var_free(struct variable_list *Ptr)
{
#ifdef DEBUG_VARS_MALLOC
  printf("VARS: Free'd  (%x)\n", (unsigned int)Ptr);
  printf("VARS: Name was(%x)\n", (unsigned int)Ptr->name);
#endif

  if (Ptr->name && Ptr->name_length > 0)
    xfree((char *) Ptr->name);

  if (Ptr->val.string && Ptr->val_len > 0)
    xfree((char *) Ptr->val.string);
  else
  if (Ptr->val.integer && Ptr->val_len > 0)
    xfree((char *) Ptr->val.integer);

  xfree(Ptr);
}

/**********************************************************************/
