    }
}

static void
delayPoolStats(StoreEntry * sentry)
{
    int i;
    int j;
    storeAppendPrintf(sentry, "Class 1 Delay Pool Statistics:\n");
    storeAppendPrintf(sentry, "\n\tAggregate:\n");
    storeAppendPrintf(sentry, "\t\tMax: %d\n", Config.Delay.class1.aggregate.max_bytes);
    storeAppendPrintf(sentry, "\t\tRate: %d\n", Config.Delay.class1.aggregate.restore_bps);
    storeAppendPrintf(sentry, "\t\tCurrent: %d\n", delay_data.class1_aggregate);
    storeAppendPrintf(sentry, "\nClass 2 Delay Pool Statistics:\n");
    storeAppendPrintf(sentry, "\n\tAggregate:\n");
    storeAppendPrintf(sentry, "\t\tMax: %d\n", Config.Delay.class2.aggregate.max_bytes);
    storeAppendPrintf(sentry, "\t\tRate: %d\n", Config.Delay.class2.aggregate.restore_bps);
    storeAppendPrintf(sentry, "\t\tCurrent: %d\n", delay_data.class2_aggregate);
    storeAppendPrintf(sentry, "\n\tIndividual:\n");
    storeAppendPrintf(sentry, "\t\tMax: %d\n", Config.Delay.class2.individual.max_bytes);
    storeAppendPrintf(sentry, "\t\tRate: %d\n", Config.Delay.class2.individual.restore_bps);
    storeAppendPrintf(sentry, "\t\tCurrent: ");
    for (i = 0;; i++) {
	if (delay_data.class2_individual_map[i] == 255)
	    break;
	storeAppendPrintf(sentry, "%d:%d ", delay_data.class2_individual_map[i],
	    delay_data.class2_individual[i]);
    }
    storeAppendPrintf(sentry, "\n\nClass 3 Delay Pool Statistics:\n");
    storeAppendPrintf(sentry, "\n\tAggregate:\n");
    storeAppendPrintf(sentry, "\t\tMax: %d\n", Config.Delay.class3.aggregate.max_bytes);
    storeAppendPrintf(sentry, "\t\tRate: %d\n", Config.Delay.class3.aggregate.restore_bps);
    storeAppendPrintf(sentry, "\t\tCurrent: %d\n", delay_data.class3_aggregate);
    storeAppendPrintf(sentry, "\n\tNetwork:\n");
    storeAppendPrintf(sentry, "\t\tMax: %d\n", Config.Delay.class3.network.max_bytes);
    storeAppendPrintf(sentry, "\t\tRate: %d\n", Config.Delay.class3.network.restore_bps);
    storeAppendPrintf(sentry, "\t\tCurrent: ");
    for (i = 0;; i++) {
	if (delay_data.class3_network_map[i] == 255)
	    break;
	storeAppendPrintf(sentry, "%d:%d ", delay_data.class3_network_map[i],
	    delay_data.class3_network[i]);
    }
    storeAppendPrintf(sentry, "\n\n\tIndividual:\n");
    storeAppendPrintf(sentry, "\t\tMax: %d\n", Config.Delay.class3.individual.max_bytes);
    storeAppendPrintf(sentry, "\t\tRate: %d\n", Config.Delay.class3.individual.restore_bps);
    for (i = 0;; i++) {
	if (delay_data.class3_network_map[i] == 255)
	    break;
	storeAppendPrintf(sentry, "\t\tCurrent [Network %d]: ",
	    delay_data.class3_network_map[i]);
	for (j = 0;; j++) {
	    if (delay_data.class3_individual_map[i][j] == 255)
		break;
	    storeAppendPrintf(sentry, "%d:%d ", delay_data.class3_individual_map[i][j],
		delay_data.class3_individual[(i << 8) + j]);
	}
	storeAppendPrintf(sentry, "\n");
    }
    storeAppendPrintf(sentry, "\n");
}
