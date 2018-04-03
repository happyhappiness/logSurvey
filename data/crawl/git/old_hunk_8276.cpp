    }
}

proc start_rev_list {view} {
    global startmsecs nextupdate
    global commfd leftover tclencoding datemode
    global viewargs viewfiles commitidx

    set startmsecs [clock clicks -milliseconds]
    set nextupdate [expr {$startmsecs + 100}]
    set commitidx($view) 0
    set args $viewargs($view)
    if {$viewfiles($view) ne {}} {
