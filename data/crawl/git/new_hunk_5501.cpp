}

proc error_popup {msg {owner .}} {
    if {[tk windowingsystem] eq "win32"} {
        tk_messageBox -icon error -type ok -title [wm title .] \
            -parent $owner -message $msg
    } else {
        set w .error
        ttk_toplevel $w
        make_transient $w $owner
        show_error $w $w $msg
    }
}

proc confirm_popup {msg {owner .}} {
    global confirm_ok NS
    set confirm_ok 0
    set w .confirm
    ttk_toplevel $w
    make_transient $w $owner
    message $w.m -text $msg -justify center -aspect 400
    pack $w.m -side top -fill x -padx 20 -pady 20
    ${NS}::button $w.ok -text [mc OK] -command "set confirm_ok 1; destroy $w"
    pack $w.ok -side left -fill x
    ${NS}::button $w.cancel -text [mc Cancel] -command "destroy $w"
    pack $w.cancel -side right -fill x
    bind $w <Visibility> "grab $w; focus $w"
    bind $w <Key-Return> "set confirm_ok 1; destroy $w"
    bind $w <Key-space>  "set confirm_ok 1; destroy $w"
    bind $w <Key-Escape> "destroy $w"
    tk::PlaceWindow $w widget $owner
    tkwait window $w
    return $confirm_ok
}

proc setoptions {} {
    if {[tk windowingsystem] ne "win32"} {
        option add *Panedwindow.showHandle 1 startupFile
        option add *Panedwindow.sashRelief raised startupFile
        if {[tk windowingsystem] ne "aqua"} {
            option add *Menu.font uifont startupFile
        }
    } else {
        option add *Menu.TearOff 0 startupFile
    }
    option add *Button.font uifont startupFile
    option add *Checkbutton.font uifont startupFile
    option add *Radiobutton.font uifont startupFile
    option add *Menubutton.font uifont startupFile
    option add *Label.font uifont startupFile
    option add *Message.font uifont startupFile
    option add *Entry.font uifont startupFile
    option add *Labelframe.font uifont startupFile
}

# Make a menu and submenus.
