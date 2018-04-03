#if DELAY_POOLS
#include "squid.h"

struct _class1DelayPool {
    int aggregate;
};

struct _class2DelayPool {
    int aggregate;
    /* OK: -1 is terminator.  individual[255] is always host 255. */
    /* 255 entries + 1 terminator byte */
    unsigned char individual_map[256];
    unsigned char individual_255_used;
    /* 256 entries */
    int individual[256];
};

struct _class3DelayPool {
    int aggregate;
    /* OK: -1 is terminator.  network[255] is always host 255. */
    /* 255 entries + 1 terminator byte */
    unsigned char network_map[256];
    unsigned char network_255_used;
    /* 256 entries */
    int network[256];
    /* 256 sets of (255 entries + 1 terminator byte) */
    unsigned char individual_map[256][256];
    /* Pack this into one bit per net */
    unsigned char individual_255_used[32];
    /* largest entry = (255<<8)+255 = 65535 */
    int individual[65536];
};

typedef struct _class1DelayPool class1DelayPool;
typedef struct _class2DelayPool class2DelayPool;
typedef struct _class3DelayPool class3DelayPool;

union _delayPool {
    class1DelayPool *class1;
    class2DelayPool *class2;
    class3DelayPool *class3;
};

typedef union _delayPool delayPool;

static delayPool *delay_data = NULL;
static fd_set delay_no_delay;
static time_t delay_pools_last_update = 0;

static OBJH delayPoolStats;

void
delayPoolsInit(void)
{
    delay_pools_last_update = getCurrentTime();
    FD_ZERO(&delay_no_delay);
    cachemgrRegister("delay", "Delay Pool Levels", delayPoolStats, 0, 1);
}

void
delayInitDelayData(unsigned short pools)
{
    if (pools) {
	delay_data = xcalloc(pools, sizeof(delayPool));
	eventAdd("delayPoolsUpdate", delayPoolsUpdate, NULL, 1.0, 1);
    }
}

void
delayFreeDelayData()
{
    safe_free(delay_data);
}

void
delayCreateDelayPool(unsigned short pool, u_char class)
{
    switch (class) {
    case 1:
	delay_data[pool].class1 = xmalloc(sizeof(class1DelayPool));
	break;
    case 2:
	delay_data[pool].class2 = xmalloc(sizeof(class2DelayPool));
	break;
    case 3:
	delay_data[pool].class3 = xmalloc(sizeof(class3DelayPool));
	break;
    default:
	assert(0);
    }
}

void
delayInitDelayPool(unsigned short pool, u_char class, delaySpecSet * rates)
{
    /* delaySetSpec may be pointer to partial structure so MUST pass by
     * reference.
     */
    switch (class) {
    case 1:
	delay_data[pool].class1->aggregate = (rates->aggregate.max_bytes *
	    Config.Delay.initial) / 100;
	break;
    case 2:
	delay_data[pool].class2->aggregate = (rates->aggregate.max_bytes *
	    Config.Delay.initial) / 100;
	delay_data[pool].class2->individual_map[0] = 255;
	delay_data[pool].class2->individual_255_used = 0;
	break;
    case 3:
	delay_data[pool].class3->aggregate = (rates->aggregate.max_bytes *
	    Config.Delay.initial) / 100;
	delay_data[pool].class3->network_map[0] = 255;
	delay_data[pool].class3->network_255_used = 0;
	memset(&delay_data[pool].class3->individual_255_used, '\0',
	    sizeof(delay_data[pool].class3->individual_255_used));
	break;
    default:
	assert(0);
    }
}

void
delayFreeDelayPool(unsigned short pool)
{
    /* this is a union - and all free() cares about is the pointer location */
    safe_free(delay_data[pool].class1);
}

void
delaySetNoDelay(int fd)
{
    FD_SET(fd, &delay_no_delay);
}

void
delayClearNoDelay(int fd)
{
    FD_CLR(fd, &delay_no_delay);
}

int
delayIsNoDelay(int fd)
{
    return FD_ISSET(fd, &delay_no_delay);
}

static delay_id
delayId(unsigned short pool, unsigned short position)
{
    return (pool << 16) | position;
}

delay_id
delayClient(request_t *r)
{
    aclCheck_t ch;
    int i;
    int j;
    unsigned int host;
    unsigned short pool, position;
    unsigned char class, net;

    memset(&ch, '\0', sizeof(ch));
    ch.src_addr = r->client_addr;
    ch.my_addr = r->my_addr;
    ch.request = r;
    for (pool = 0; pool < Config.Delay.pools; pool++) {
	if (aclCheckFast(Config.Delay.access[pool], &ch))
	    break;
    }
    if (pool == Config.Delay.pools)
	return delayId(0, 0);
    class = Config.Delay.class[pool];
    if (class == 0)
	return delayId(0, 0);
    if (class == 1)
	return delayId(pool + 1, 0);
    if (class == 2) {
	host = ntohl(ch.src_addr.s_addr) & 0xff;
	if (host == 255) {
	    if (!delay_data[pool].class2->individual_255_used) {
		delay_data[pool].class2->individual_255_used = 1;
		delay_data[pool].class2->individual[255] =
		    (Config.Delay.rates[pool]->individual.max_bytes *
		    Config.Delay.initial) / 100;
	    }
	    return delayId(pool + 1, 255);
	}
	for (i = 0;; i++) {
	    if (delay_data[pool].class2->individual_map[i] == host)
		break;
	    if (delay_data[pool].class2->individual_map[i] == 255) {
		delay_data[pool].class2->individual_map[i] = host;
		delay_data[pool].class2->individual_map[i + 1] = 255;
		delay_data[pool].class2->individual[i] =
		    (Config.Delay.rates[pool]->individual.max_bytes *
		    Config.Delay.initial) / 100;
		break;
	    }
	}
	return delayId(pool + 1, i);
    }
    /* class == 3 */
    host = ntohl(ch.src_addr.s_addr) & 0xffff;
    net = host >> 8;
    host &= 0xff;
    if (net == 255) {
	i = 255;
	if (!delay_data[pool].class3->network_255_used) {
	    delay_data[pool].class3->network_255_used = 1;
	    delay_data[pool].class3->network[255] =
		(Config.Delay.rates[pool]->network.max_bytes *
		Config.Delay.initial) / 100;
	}
    } else {
	for (i = 0;; i++) {
	    if (delay_data[pool].class3->network_map[i] == net)
		break;
	    if (delay_data[pool].class3->network_map[i] == 255) {
		delay_data[pool].class3->network_map[i] = net;
		delay_data[pool].class3->individual_map[i][0] = 255;
		delay_data[pool].class3->network_map[i + 1] = 255;
		delay_data[pool].class3->network[i] =
		    (Config.Delay.rates[pool]->network.max_bytes *
		    Config.Delay.initial) / 100;
		break;
	    }
	}
    }
    position = i << 8;
    if (host == 255) {
	position |= 255;
	if (!(delay_data[pool].class3->individual_255_used[i / 8] & (1 << (i % 8)))) {
	    delay_data[pool].class3->individual_255_used[i / 8] |= (1 << (i % 8));
	    delay_data[pool].class3->individual[position] =
		(Config.Delay.rates[pool]->individual.max_bytes *
		Config.Delay.initial) / 100;
	}
	return delayId(pool + 1, position);
    }
    for (j = 0;; j++) {
	if (delay_data[pool].class3->individual_map[i][j] == host) {
	    position |= j;
	    break;
	}
	if (delay_data[pool].class3->individual_map[i][j] == 255) {
	    delay_data[pool].class3->individual_map[i][j] = host;
	    delay_data[pool].class3->individual_map[i][j + 1] = 255;
	    delay_data[pool].class3->individual[position |= j] =
		(Config.Delay.rates[pool]->individual.max_bytes *
		Config.Delay.initial) / 100;
	    break;
	}
    }
    return delayId(pool + 1, position);
}

static void
delayUpdateClass1(class1DelayPool * class1, delaySpecSet * rates, int incr)
{
    /* delaySetSpec may be pointer to partial structure so MUST pass by
     * reference.
     */
    if (rates->aggregate.restore_bps != -1 &&
	(class1->aggregate += rates->aggregate.restore_bps * incr) >
	rates->aggregate.max_bytes)
	class1->aggregate = rates->aggregate.max_bytes;
}

static void
delayUpdateClass2(class2DelayPool * class2, delaySpecSet * rates, int incr)
{
    int restore_bytes;
    unsigned char i;
    /* delaySetSpec may be pointer to partial structure so MUST pass by
     * reference.
     */
    if (rates->aggregate.restore_bps != -1 &&
	(class2->aggregate += rates->aggregate.restore_bps * incr) >
	rates->aggregate.max_bytes)
	class2->aggregate = rates->aggregate.max_bytes;
    if ((restore_bytes = rates->individual.restore_bps) == -1)
	return;
    restore_bytes *= incr;
    if (class2->individual_255_used)
	i = 255;
    else
	i = 0;
    for (;;) {
	if (i != 255 && class2->individual_map[i] == 255)
	    return;
	if (class2->individual[i] != rates->individual.max_bytes &&
	    (class2->individual[i] += restore_bytes) > rates->individual.max_bytes)
	    class2->individual[i] = rates->individual.max_bytes;
	if (++i == 255)
	    return;
    }
}

static void
delayUpdateClass3(class3DelayPool * class3, delaySpecSet * rates, int incr)
{
    int individual_restore_bytes, network_restore_bytes;
    int mpos;
    unsigned char i, j;
    /* delaySetSpec may be pointer to partial structure so MUST pass by
     * reference.
     */
    if (rates->aggregate.restore_bps != -1 &&
	(class3->aggregate += rates->aggregate.restore_bps * incr) >
	rates->aggregate.max_bytes)
	class3->aggregate = rates->aggregate.max_bytes;
    /* the following line deliberately uses &, not &&, in an if statement
     * to avoid conditional execution
     */
    if (((network_restore_bytes = rates->network.restore_bps) == -1) &
	((individual_restore_bytes = rates->individual.restore_bps) == -1))
	return;
    individual_restore_bytes *= incr;
    network_restore_bytes *= incr;
    if (class3->network_255_used)
	i = 255;
    else
	i = 0;
    for (;;) {
	if (i != 255 && class3->network_map[i] == 255)
	    return;
	if (individual_restore_bytes != -incr) {
	    mpos = i << 8;
	    if (class3->individual_255_used[i / 8] & (1 << (i % 8)))
		j = 255;
	    else
		j = 0;
	    for (;;) {
		if (j != 255 && class3->individual_map[i][j] == 255)
		    break;
		if (class3->individual[mpos] != rates->individual.max_bytes &&
		    (class3->individual[mpos] += individual_restore_bytes) >
		    rates->individual.max_bytes)
		    class3->individual[mpos] = rates->individual.max_bytes;
		mpos++;
		if (j == 255)
		    mpos -= 256;
		if (++j == 255)
		    break;
	    }
	}
	if (network_restore_bytes != -incr &&
	    class3->network[i] != rates->network.max_bytes &&
	    (class3->network[i] += network_restore_bytes) >
	    rates->network.max_bytes)
	    class3->network[i] = rates->network.max_bytes;
	if (++i == 255)
	    return;
    }
}

void
delayPoolsUpdate(void *unused)
{
    int incr = squid_curtime - delay_pools_last_update;
    unsigned short i;
    unsigned char class;
    if (!Config.Delay.pools)
	return;
    eventAdd("delayPoolsUpdate", delayPoolsUpdate, NULL, 1.0, 1);
    if (incr < 1)
	return;
    delay_pools_last_update = squid_curtime;
    for (i = 0; i < Config.Delay.pools; i++) {
	class = Config.Delay.class[i];
	if (!class)
	    continue;
	switch (class) {
	case 1:
	    delayUpdateClass1(delay_data[i].class1, Config.Delay.rates[i], incr);
	    break;
	case 2:
	    delayUpdateClass2(delay_data[i].class2, Config.Delay.rates[i], incr);
	    break;
	case 3:
	    delayUpdateClass3(delay_data[i].class3, Config.Delay.rates[i], incr);
	    break;
	default:
	    assert(0);
	}
    }
}

/*
