#if DELAY_POOLS
#include "squid.h"

struct _delayData {
    int class1_aggregate;
    int class2_aggregate;
    /* 254 entries + 1 terminator byte */
    unsigned char class2_individual_map[255];
    /* 254 entries */
    int class2_individual[254];
    int class3_aggregate;
    /* 255 entries + 1 terminator byte */
    unsigned char class3_network_map[256];
    /* 255 entries */
    int class3_network[255];
    /* 255 sets of (254 entries + 1 terminator byte) */
    unsigned char class3_individual_map[255][255];
    /* largest entry = (254<<8)+253 = 65277 */
    int class3_individual[65278];
};

static struct _delayData delay_data;
static OBJH delayPoolStats;
static time_t delay_pools_last_update = 0;
static delay_id delayId(unsigned char class, int position);

static delay_id
delayId(unsigned char class, int position)
{
    assert(class <= 3);
    return (class << 16) | (position & 0xFFFF);
}

int
delayClient(clientHttpRequest * http)
{
    aclCheck_t ch;
    int i;
    int j;
    unsigned int host;
    unsigned char net;
    unsigned char class = 0;
    int position = 0;
    request_t *r = http->request;

    memset(&ch, '\0', sizeof(ch));
    ch.src_addr = http->conn->peer.sin_addr;
    ch.request = r;
    if (aclCheckFast(Config.Delay.class1.access, &ch)) {
	class = 1;
	r->delay_id = delayId(class, position);
	return 1;
    }
    if (aclCheckFast(Config.Delay.class2.access, &ch)) {
	class = 2;
	host = ntohl(ch.src_addr.s_addr) & 0xff;
	if (host == 255 || !host) {
	    debug(77, 0) ("ARGH: Delay requested for host %s\n", inet_ntoa(ch.src_addr));
	    class = 0;
	    r->delay_id = delayId(class, position);
	    return 0;
	}
	for (i = 0;; i++) {
	    if (delay_data.class2_individual_map[i] == host)
		break;
	    if (delay_data.class2_individual_map[i] == 255) {
		delay_data.class2_individual_map[i] = host;
		delay_data.class2_individual_map[i + 1] = 255;
		delay_data.class2_individual[i] = Config.Delay.class2.individual.restore_bps;
		break;
	    }
	}
	position = i;
	r->delay_id = delayId(class, position);
	return 1;
    }
    if (aclCheckFast(Config.Delay.class3.access, &ch)) {
	class = 3;
	host = ntohl(ch.src_addr.s_addr) & 0xffff;
	net = host >> 8;
	host &= 0xff;
	if (host == 255 || !host || net == 255) {
	    debug(77, 0) ("ARGH: Delay requested for host %s\n", inet_ntoa(ch.src_addr));
	    class = 0;
	    r->delay_id = delayId(class, position);
	    return 0;
	}
	for (i = 0;; i++) {
	    if (delay_data.class3_network_map[i] == net)
		break;
	    if (delay_data.class3_network_map[i] == 255) {
		delay_data.class3_network_map[i] = net;
		delay_data.class3_individual_map[i][0] = 255;
		delay_data.class3_network_map[i + 1] = 255;
		delay_data.class3_network[i] = Config.Delay.class3.network.restore_bps;
		break;
	    }
	}
	position = i << 8;
	for (j = 0;; j++) {
	    if (delay_data.class3_individual_map[i][j] == host) {
		position |= j;
		break;
	    }
	    if (delay_data.class3_individual_map[i][j] == 255) {
		delay_data.class3_individual_map[i][j] = host;
		delay_data.class3_individual_map[i][j + 1] = 255;
		delay_data.class3_individual[position |= j] =
		    Config.Delay.class3.individual.restore_bps;
		break;
	    }
	}
	r->delay_id = delayId(class, position);
	return 1;
    }
    class = 0;
    r->delay_id = delayId(class, position);
    return 0;
}


void
delayPoolsUpdate(void *unused)
{
    int incr = squid_curtime - delay_pools_last_update;
    int i;
    int j;
    int mpos;
    int individual_restore_bytes;
    int network_restore_bytes;
    eventAdd("delayPoolsUpdate", delayPoolsUpdate, NULL, 1.0, 1);
    if (incr < 1)
	return;
    delay_pools_last_update = squid_curtime;
    /* Increment 3 aggregate pools */
    if (Config.Delay.class1.aggregate.restore_bps != -1 &&
	(delay_data.class1_aggregate +=
	    Config.Delay.class1.aggregate.restore_bps * incr) >
	Config.Delay.class1.aggregate.max_bytes)
	delay_data.class1_aggregate = Config.Delay.class1.aggregate.max_bytes;
    if (Config.Delay.class2.aggregate.restore_bps != -1 &&
	(delay_data.class2_aggregate +=
	    Config.Delay.class2.aggregate.restore_bps * incr) >
	Config.Delay.class2.aggregate.max_bytes)
	delay_data.class2_aggregate = Config.Delay.class2.aggregate.max_bytes;
    if (Config.Delay.class3.aggregate.restore_bps != -1 &&
	(delay_data.class3_aggregate +=
	    Config.Delay.class3.aggregate.restore_bps * incr) >
	Config.Delay.class3.aggregate.max_bytes)
	delay_data.class3_aggregate = Config.Delay.class3.aggregate.max_bytes;
    /* Increment class 2 individual pools */
    if ((individual_restore_bytes = Config.Delay.class2.individual.restore_bps) != -1) {
	individual_restore_bytes *= incr;
	for (i = 0;; i++) {
	    if (delay_data.class2_individual_map[i] == 255)
		break;
	    if (delay_data.class2_individual[i] == Config.Delay.class2.individual.max_bytes)
		continue;
	    if ((delay_data.class2_individual[i] += individual_restore_bytes) >
		Config.Delay.class2.individual.max_bytes)
		delay_data.class2_individual[i] = Config.Delay.class2.individual.max_bytes;
	}
    }
    /* Increment class 3 individual and network pools */
    if ((network_restore_bytes = Config.Delay.class3.network.restore_bps) != -1 ||
	(individual_restore_bytes = Config.Delay.class3.individual.restore_bps) != -1) {
	individual_restore_bytes *= incr;
	network_restore_bytes *= incr;
	for (i = 0;; i++) {
	    if (delay_data.class3_network_map[i] == 255)
		break;
	    if (individual_restore_bytes != -incr) {
		for (j = 0, mpos = (i << 8);; j++, mpos++) {
		    if (delay_data.class3_individual_map[i][j] == 255)
			break;
		    if (delay_data.class3_individual[mpos] == Config.Delay.class3.individual.max_bytes)
			continue;
		    if ((delay_data.class3_individual[mpos] += individual_restore_bytes) >
			Config.Delay.class3.individual.max_bytes)
			delay_data.class3_individual[mpos] = Config.Delay.class3.individual.max_bytes;
		}
	    }
	    if (network_restore_bytes == -incr ||
		delay_data.class3_network[i] == Config.Delay.class3.network.max_bytes)
		continue;
	    if ((delay_data.class3_network[i] += network_restore_bytes) >
		Config.Delay.class3.network.max_bytes)
		delay_data.class3_network[i] = Config.Delay.class3.network.max_bytes;
	}
    }
}


static void
delayPoolStats(StoreEntry * sentry)
{
    int i;
    int j;
    storeAppendPrintf(sentry, "Class 1 Delay Pool Statistics:\n");
    if (Config.Delay.class1.aggregate.restore_bps != -1) {
	storeAppendPrintf(sentry, "\n\tAggregate:\n");
	storeAppendPrintf(sentry, "\t\tMax: %d\n",
	    Config.Delay.class1.aggregate.max_bytes);
	storeAppendPrintf(sentry, "\t\tRate: %d\n",
	    Config.Delay.class1.aggregate.restore_bps);
	storeAppendPrintf(sentry, "\t\tCurrent: %d\n",
	    delay_data.class1_aggregate);
    } else {
	storeAppendPrintf(sentry, "\n\tAggregate:\n\tDisabled.\n");
    }
    storeAppendPrintf(sentry, "\nClass 2 Delay Pool Statistics:\n");
    if (Config.Delay.class2.aggregate.restore_bps != -1) {
	storeAppendPrintf(sentry, "\n\tAggregate:\n");
	storeAppendPrintf(sentry, "\t\tMax: %d\n",
	    Config.Delay.class2.aggregate.max_bytes);
	storeAppendPrintf(sentry, "\t\tRate: %d\n",
	    Config.Delay.class2.aggregate.restore_bps);
	storeAppendPrintf(sentry, "\t\tCurrent: %d\n",
	    delay_data.class2_aggregate);
    } else {
	storeAppendPrintf(sentry, "\n\tAggregate:\n\tDisabled.\n");
    }
    if (Config.Delay.class2.individual.restore_bps != -1) {
	storeAppendPrintf(sentry, "\n\tIndividual:\n");
	storeAppendPrintf(sentry, "\t\tMax: %d\n",
	    Config.Delay.class2.individual.max_bytes);
	storeAppendPrintf(sentry, "\t\tRate: %d\n",
	    Config.Delay.class2.individual.restore_bps);
	storeAppendPrintf(sentry, "\t\tCurrent: ");
	for (i = 0;; i++) {
	    if (delay_data.class2_individual_map[i] == 255)
		break;
	    storeAppendPrintf(sentry, "%d:%d ",
		delay_data.class2_individual_map[i],
		delay_data.class2_individual[i]);
	}
    } else {
	storeAppendPrintf(sentry, "\n\tIndividual:\n\tDisabled.");
    }
    storeAppendPrintf(sentry, "\n\nClass 3 Delay Pool Statistics:\n");
    if (Config.Delay.class3.aggregate.restore_bps != -1) {
	storeAppendPrintf(sentry, "\n\tAggregate:\n");
	storeAppendPrintf(sentry, "\t\tMax: %d\n",
	    Config.Delay.class3.aggregate.max_bytes);
	storeAppendPrintf(sentry, "\t\tRate: %d\n",
	    Config.Delay.class3.aggregate.restore_bps);
	storeAppendPrintf(sentry, "\t\tCurrent: %d\n",
	    delay_data.class3_aggregate);
    } else {
	storeAppendPrintf(sentry, "\n\tAggregate:\n\tDisabled.\n");
    }
    if (Config.Delay.class3.network.restore_bps != -1) {
	storeAppendPrintf(sentry, "\n\tNetwork:\n");
	storeAppendPrintf(sentry, "\t\tMax: %d\n",
	    Config.Delay.class3.network.max_bytes);
	storeAppendPrintf(sentry, "\t\tRate: %d\n",
	    Config.Delay.class3.network.restore_bps);
	storeAppendPrintf(sentry, "\t\tCurrent: ");
	for (i = 0;; i++) {
	    if (delay_data.class3_network_map[i] == 255)
		break;
	    storeAppendPrintf(sentry, "%d:%d ",
		delay_data.class3_network_map[i],
		delay_data.class3_network[i]);
	}
    } else {
	storeAppendPrintf(sentry, "\n\tNetwork:\n\tDisabled.");
    }
    if (Config.Delay.class3.individual.restore_bps != -1) {
	storeAppendPrintf(sentry, "\n\n\tIndividual:\n");
	storeAppendPrintf(sentry, "\t\tMax: %d\n",
	    Config.Delay.class3.individual.max_bytes);
	storeAppendPrintf(sentry, "\t\tRate: %d\n",
	    Config.Delay.class3.individual.restore_bps);
	for (i = 0;; i++) {
	    if (delay_data.class3_network_map[i] == 255)
		break;
	    storeAppendPrintf(sentry, "\t\tCurrent [Network %d]: ",
		delay_data.class3_network_map[i]);
	    for (j = 0;; j++) {
		if (delay_data.class3_individual_map[i][j] == 255)
		    break;
		storeAppendPrintf(sentry, "%d:%d ",
		    delay_data.class3_individual_map[i][j],
		    delay_data.class3_individual[(i << 8) + j]);
	    }
	    storeAppendPrintf(sentry, "\n");
	}
    } else {
	storeAppendPrintf(sentry, "\n\n\tIndividual:\n\tDisabled.\n");
    }
    storeAppendPrintf(sentry, "\n");
}

void
delayPoolsInit(void)
{
    delay_pools_last_update = getCurrentTime();
    delay_data.class1_aggregate = Config.Delay.class1.aggregate.restore_bps;
    delay_data.class2_aggregate = Config.Delay.class2.aggregate.restore_bps;
    delay_data.class2_individual_map[0] = 255;
    delay_data.class3_aggregate = Config.Delay.class3.aggregate.restore_bps;
    delay_data.class3_network_map[0] = 255;
    cachemgrRegister("delay", "Delay Pool Levels", delayPoolStats, 0, 1);
    eventAdd("delayPoolsUpdate", delayPoolsUpdate, NULL, 1.0, 1);
}

/*
