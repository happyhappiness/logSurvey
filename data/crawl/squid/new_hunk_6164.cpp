void
delayBytesIn(delay_id d, int qty)
{
    unsigned short position = d & 0xFFFF;
    unsigned short pool = (d >> 16) - 1;
    unsigned char class;

    if (pool == 0xFFFF)
	return;
    class = Config.Delay.class[pool];
    switch (class) {
    case 1:
	delay_data[pool].class1->aggregate -= qty;
	return;
    case 2:
	delay_data[pool].class2->aggregate -= qty;
	delay_data[pool].class2->individual[position] -= qty;
	return;
    case 3:
	delay_data[pool].class3->aggregate -= qty;
	delay_data[pool].class3->network[position >> 8] -= qty;
	delay_data[pool].class3->individual[position] -= qty;
	return;
    }
    fatalf("delayBytesWanted: Invalid class %d\n", class);
    assert(0);
}

