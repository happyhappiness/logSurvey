2003-11-05  Hrvoje Niksic  <hniksic@xemacs.org>

	* connect.c (resolve_bind_address): Use a more accurate error
	message -- we're not binding to ANY, we're disabling bind
	altogether.
