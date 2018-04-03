/* LOCALS */
char *open_bracket = "{\n";
char *close_bracket = "}\n";
static void statFiledescriptors _PARAMS((StoreEntry *));

/* process utilization information */
void stat_utilization_get(obj, sentry)
     cacheinfo *obj;
     StoreEntry *sentry;
{
    protocol_t proto_id;
    proto_stat *p = &obj->proto_stat_data[PROTO_MAX];
    proto_stat *q = NULL;
    int secs = 0;

    secs = (int) (squid_curtime - squid_starttime);

    storeAppendPrintf(sentry, open_bracket);

    strcpy(p->protoname, "TOTAL");
    p->object_count = 0;
    p->kb.max = 0;
