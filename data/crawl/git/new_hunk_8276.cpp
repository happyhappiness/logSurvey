    }
}

# A simple scheduler for compute-intensive stuff.
# The aim is to make sure that event handlers for GUI actions can
# run at least every 50-100 ms.  Unfortunately fileevent handlers are
# run before X event handlers, so reading from a fast source can
# make the GUI completely unresponsive.
proc run args {
    global isonrunq runq

    set script $args
    if {[info exists isonrunq($script)]} return
    if {$runq eq {}} {
	after idle dorunq
    }
    lappend runq [list {} $script]
    set isonrunq($script) 1
}

proc filerun {fd script} {
    fileevent $fd readable [list filereadable $fd $script]
}

proc filereadable {fd script} {
    global runq

    fileevent $fd readable {}
    if {$runq eq {}} {
	after idle dorunq
    }
    lappend runq [list $fd $script]
}

proc dorunq {} {
    global isonrunq runq

    set tstart [clock clicks -milliseconds]
    set t0 $tstart
    while {$runq ne {}} {
	set fd [lindex $runq 0 0]
	set script [lindex $runq 0 1]
	set repeat [eval $script]
	set t1 [clock clicks -milliseconds]
	set t [expr {$t1 - $t0}]
	set runq [lrange $runq 1 end]
	if {$repeat ne {} && $repeat} {
	    if {$fd eq {} || $repeat == 2} {
		# script returns 1 if it wants to be readded
		# file readers return 2 if they could do more straight away
		lappend runq [list $fd $script]
	    } else {
		fileevent $fd readable [list filereadable $fd $script]
	    }
	} elseif {$fd eq {}} {
	    unset isonrunq($script)
	}
	set t0 $t1
	if {$t1 - $tstart >= 80} break
    }
    if {$runq ne {}} {
	after idle dorunq
    }
}

# Start off a git rev-list process and arrange to read its output
proc start_rev_list {view} {
    global startmsecs
    global commfd leftover tclencoding datemode
    global viewargs viewfiles commitidx

    set startmsecs [clock clicks -milliseconds]
    set commitidx($view) 0
    set args $viewargs($view)
    if {$viewfiles($view) ne {}} {
