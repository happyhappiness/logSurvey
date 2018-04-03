aclLookupProxyAuthDone(void *data, char *result)
{
    aclCheck_t *checklist = data;
    checklist->state[ACL_PROXY_AUTH] = ACL_LOOKUP_DONE;
    debug(28, 4) ("aclLookupProxyAuthDone: result = %s\n",
	result ? result : "NULL");
    if (NULL == result)
	checklist->auth_user->passwd_ok = 0;
    else if (0 == strncasecmp(result, "OK", 2))
	checklist->auth_user->passwd_ok = 1;
    else {
	if (strlen(result) > sizeof("ERR "))
	    checklist->auth_user->message = xstrdup(result + 4);
	checklist->auth_user->passwd_ok = 0;
    }
    aclCheck(checklist);
}
