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
	delay_data.class2_individual[position] -= qty;
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

