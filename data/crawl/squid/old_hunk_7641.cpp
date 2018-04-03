	getMyHostname(), Config.Port.http);
    if (Config.errHtmlText == NULL)
	Config.errHtmlText = xstrdup("");

#if !ALLOW_HOT_CACHE
    if (!httpd_accel_mode || Config.Accel.withProxy) {
	/* Not running strict httpd_accel--force hot_vm_factor to be 0 */
	if (Config.hotVmFactor != 0.0) {
	    printf("WARNING: Non-zero hot_vm_factor not allowed unless running only\n");
	    printf("         in httpd_accel mode.  Setting hot_vm_factor to 0.\n");
	    Config.hotVmFactor = 0.0;
	}
    }
#endif /* !ALLOW_HOT_CACHE */
}