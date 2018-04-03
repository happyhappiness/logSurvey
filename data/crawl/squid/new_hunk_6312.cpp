    cachemgrRegister("delay", "Delay Pool Levels", delayPoolStats, 0, 1);
}

/*
 * this returns the number of bytes the client is permitted. it does not take
 * into account bytes already buffered - that is up to the caller.
 */
int
delayBytesWanted(delay_id d, int max)
{
    int position = d & 0xFFFF;
    unsigned char class = (d & 0xFF0000) >> 16;
    int nbytes = max;
    switch (class) {
    case 0:
	break;

    case 1:
	if (Config.Delay.class1.aggregate.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data.class1_aggregate);
	break;

    case 2:
	if (Config.Delay.class2.aggregate.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data.class2_aggregate);
	if (Config.Delay.class2.individual.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data.class2_individual[position]);
	break;

    case 3:
	if (Config.Delay.class3.aggregate.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data.class3_aggregate);
	if (Config.Delay.class3.individual.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data.class3_individual[position]);
	if (Config.Delay.class3.network.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data.class3_network[position >> 8]);
	break;

    default:
	fatalf("delayBytesWanted: Invalid class %d\n", class);
	break;
    }
    assert(nbytes > 0);
    assert(nbytes <= max);
    return nbytes;
}

/*
 * this records actual bytes recieved.  always recorded, even if the
 * class is disabled - see above for all the cases which would be needed
 * to efficiently not record it, so it's just ignored if not wanted.
 */
void
delayBytesIn(delay_id d, int qty)
{
    int position = d & 0xFFFF;
    unsigned char class = (d & 0xFF0000) >> 16;
    if (class == 0)
	return;
    if (class == 1) {
	delay_data.class1_aggregate -= qty;
	return;
    }
    if (class == 2) {
	delay_data.class2_aggregate -= qty;
	delay_data.class3_individual[position] -= qty;
	return;
    }
    if (class == 3) {
	delay_data.class3_aggregate -= qty;
	delay_data.class3_network[position >> 8] -= qty;
	delay_data.class3_individual[position] -= qty;
	return;
    }
    assert(0);
}

int
delayMostBytesWanted(const MemObject * mem, int max)
{
    int i = 0;
    store_client *sc;
    for (sc = mem->clients; sc; sc = sc->next) {
	if (sc->callback_data == NULL)	/* open slot */
	    continue;
	if (sc->type != STORE_MEM_CLIENT)
	    continue;
	i = XMAX(delayBytesWanted(sc->delay_id, max), i);
    }
    return i;
}

delay_id
delayMostBytesAllowed(const MemObject * mem)
{
    int j;
    int jmax = 0;
    store_client *sc;
    delay_id d = 0;
    for (sc = mem->clients; sc; sc = sc->next) {
	if (sc->callback_data == NULL)	/* open slot */
	    continue;
	if (sc->type != STORE_MEM_CLIENT)
	    continue;
	j = delayBytesWanted(sc->delay_id, SQUID_TCP_SO_RCVBUF);
	if (j > jmax) {
	    jmax = j;
	    d = sc->delay_id;
	}
    }
    return d;
}

void
delaySetStoreClient(StoreEntry * e, void *data, delay_id delay_id)
{
    store_client *sc = storeClientListSearch(e->mem_obj, data);
    assert(sc != NULL);
    sc->delay_id = delay_id;
}

#endif
