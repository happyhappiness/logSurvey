int
delayBytesWanted(delay_id d, int min, int max)
{
    unsigned short position = d & 0xFFFF;
    unsigned short pool = (d >> 16) - 1;
    unsigned char class = (pool == 0xFFFF) ? 0 : Config.Delay.class[pool];
    int nbytes = max;

    switch (class) {
    case 0:
	break;

    case 1:
	if (Config.Delay.rates[pool]->aggregate.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data[pool].class1->aggregate);
	break;

    case 2:
	if (Config.Delay.rates[pool]->aggregate.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data[pool].class2->aggregate);
	if (Config.Delay.rates[pool]->individual.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data[pool].class2->individual[position]);
	break;

    case 3:
	if (Config.Delay.rates[pool]->aggregate.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data[pool].class3->aggregate);
	if (Config.Delay.rates[pool]->individual.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data[pool].class3->individual[position]);
	if (Config.Delay.rates[pool]->network.restore_bps != -1)
	    nbytes = XMIN(nbytes, delay_data[pool].class3->network[position >> 8]);
	break;

    default:
	fatalf("delayBytesWanted: Invalid class %d\n", class);
	break;
    }
    nbytes = XMAX(min, nbytes);
    return nbytes;
}

