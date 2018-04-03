}

proc error_popup {msg {owner .}} {
    set w .error
    toplevel $w
    make_transient $w $owner
    show_error $w $w $msg
}

proc confirm_popup {msg {owner .}} {
    global confirm_ok
    set confirm_ok 0
    set w .confirm
    toplevel $w
    make_transient $w $owner
    message $w.m -text $msg -justify center -aspect 400
    pack $w.m -side top -fill x -padx 20 -pady 20
    button $w.ok -text [mc OK] -command "set confirm_ok 1; destroy $w"
    pack $w.ok -side left -fill x
    button $w.cancel -text [mc Cancel] -command "destroy $w"
    pack $w.cancel -side right -fill x
    bind $w <Visibility> "grab $w; focus $w"
    bind $w <Key-Return> "set confirm_ok 1; destroy $w"
    bind $w <Key-space>  "set confirm_ok 1; destroy $w"
    bind $w <Key-Escape> "destroy $w"
    tkwait window $w
    return $confirm_ok
}

proc setoptions {} {
    option add *Panedwindow.showHandle 1 startupFile
    option add *Panedwindow.sashRelief raised startupFile
    option add *Button.font uifont startupFile
    option add *Checkbutton.font uifont startupFile
    option add *Radiobutton.font uifont startupFile
    if {[tk windowingsystem] ne "aqua"} {
	option add *Menu.font uifont startupFile
    }
    option add *Menubutton.font uifont startupFile
    option add *Label.font uifont startupFile
    option add *Message.font uifont startupFile
    option add *Entry.font uifont startupFile
}

# Make a menu and submenus.
