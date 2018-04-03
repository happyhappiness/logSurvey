    my ($tex, $main, $opts) = @_;

    my (%tex_items, %main_items);
    while ($tex =~ /^\@item\w*? \s+? --([-a-z0-9]+)/gmx) {
        $tex_items{$1} = true;
    }
    my ($help) = $main =~ /\n print_help .*? \{\n (.*) \n\} \n/sx;
    while ($help =~ /--([-a-z0-9]+)/g) {
        $main_items{$1} = true;
    }

    my @options;
    foreach my $opt (@$opts) {
        next if $opt->{deprecated};
        find_documentation(\@options, $opt, \%tex_items, \%main_items);
    }

    my ($opt, $not_found_in);

format STDOUT_TOP =
Undocumented options          Not In:
====================          ==================
.

format STDOUT =
@<<<<<<<<<<<<<<<<<<<          @<<<<<<<<<<<<<<<<<
$opt->{name},                 $not_found_in
.
    foreach $opt (@options) {
        $not_found_in = join ' ', (
            ! $opt->{tex}                  ? 'texinfo' : (),
            !($opt->{tex} || $opt->{main}) ? 'nor'     : (),
            ! $opt->{main}                 ? '--help'  : (),
        );
        write;
    }
}

