$ if f$search("make.opt").nes."" then $ del make.opt;*
$ exit
$!
$ compileit : subroutine
$ ploc = f$locate("]",p1)
$ filnam = p1
$ if ploc .lt. f$length(p1) then filnam=f$extract(ploc+1,100,p1)
$ write optf "''filnam'"
$ cc'ccopt'/include=([],[.glob])/define=("allocated_variable_expand_for_file=alloc_var_expand_for_file","unlink=remove","HAVE_CONFIG_H","VMS") 'p1'
$ exit
$ endsubroutine : compileit
