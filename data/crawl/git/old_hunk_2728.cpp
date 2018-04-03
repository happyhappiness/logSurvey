	if (!dst.ptr)
		size = 0;
	dst.size = size;
	xdi_diff(&src, &dst, &xpp, &xecfg, &ecb);
	free(src.ptr);
	free(dst.ptr);
}
