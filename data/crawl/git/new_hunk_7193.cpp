    set gdttype [mc "touching paths:"]
}

proc save_file_from_commit {filename output what} {
    global nullfile

    if {[catch {exec git show $filename -- > $output} err]} {
	if {[string match "fatal: bad revision *" $err]} {
	    return $nullfile
	}
	error_popup "Error getting \"$filename\" from $what: $err"
	return {}
    }
    return $output
}

proc external_diff_get_one_file {diffid filename diffdir} {
    global nullid nullid2 nullfile
    global gitdir

    if {$diffid == $nullid} {
        set difffile [file join [file dirname $gitdir] $filename]
	if {[file exists $difffile]} {
	    return $difffile
	}
	return $nullfile
    }
    if {$diffid == $nullid2} {
        set difffile [file join $diffdir "\[index\] [file tail $filename]"]
        return [save_file_from_commit :$filename $difffile index]
    }
    set difffile [file join $diffdir "\[$diffid\] [file tail $filename]"]
    return [save_file_from_commit $diffid:$filename $difffile \
	       "revision $diffid"]
}

proc external_diff {} {
    global gitktmpdir nullid nullid2
    global flist_menu_file
    global diffids
    global diffnum
    global gitdir extdifftool

    if {[llength $diffids] == 1} {
        # no reference commit given
        set diffidto [lindex $diffids 0]
        if {$diffidto eq $nullid} {
            # diffing working copy with index
            set diffidfrom $nullid2
        } elseif {$diffidto eq $nullid2} {
            # diffing index with HEAD
            set diffidfrom "HEAD"
        } else {
            # use first parent commit
            global parentlist selectedline
            set diffidfrom [lindex $parentlist $selectedline 0]
        }
    } else {
        set diffidfrom [lindex $diffids 0]
        set diffidto [lindex $diffids 1]
    }

    # make sure that several diffs wont collide
    if {![info exists gitktmpdir]} {
	set gitktmpdir [file join [file dirname $gitdir] \
			    [format ".gitk-tmp.%s" [pid]]]
	if {[catch {file mkdir $gitktmpdir} err]} {
	    error_popup "Error creating temporary directory $gitktmpdir: $err"
	    unset gitktmpdir
	    return
	}
	set diffnum 0
    }
    incr diffnum
    set diffdir [file join $gitktmpdir $diffnum]
    if {[catch {file mkdir $diffdir} err]} {
	error_popup "Error creating temporary directory $diffdir: $err"
	return
    }

    # gather files to diff
    set difffromfile [external_diff_get_one_file $diffidfrom $flist_menu_file $diffdir]
    set difftofile [external_diff_get_one_file $diffidto $flist_menu_file $diffdir]

    if {$difffromfile ne {} && $difftofile ne {}} {
        set cmd [concat | [shellsplit $extdifftool] \
		     [list $difffromfile $difftofile]]
        if {[catch {set fl [open $cmd r]} err]} {
            file delete -force $diffdir
            error_popup [mc "$extdifftool: command failed: $err"]
        } else {
            fconfigure $fl -blocking 0
            filerun $fl [list delete_at_eof $fl $diffdir]
        }
    }
}

# delete $dir when we see eof on $f (presumably because the child has exited)
proc delete_at_eof {f dir} {
    while {[gets $f line] >= 0} {}
    if {[eof $f]} {
	if {[catch {close $f} err]} {
	    error_popup "External diff viewer failed: $err"
	}
	file delete -force $dir
	return 0
    }
    return 1
}

# Functions for adding and removing shell-type quoting

proc shellquote {str} {
