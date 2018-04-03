	cd->del_count
    );
    storeAppendPrintf(e, "\t bits: on: %d capacity: %d util: %d%%\n", 
	on_count, bit_count,
	xpercentInt(on_count, bit_count)
    );
}

