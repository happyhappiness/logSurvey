                size2id_array[0]=realloc(size2id_array[0],size2id_alloc*sizeof(int));
                size2id_array[1]=realloc(size2id_array[1],size2id_alloc*sizeof(int));
	}
	size2id_array[0][size2id_len-1]=sz;
	size2id_array[1][size2id_len-1]=0;
	return size2id_len-1;
}

