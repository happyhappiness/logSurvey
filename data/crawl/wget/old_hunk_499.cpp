EOT
}

sub emit_undocumented_opts
{
    my ($tex, $opts) = @_;

    my %items;
    while ($tex =~ /^\@item\w*? \s+? --([\w\-]+)/gmx) {
        my $opt = $1;
        $items{$opt} = true;
    }
    my @options;
    foreach my $opt (@$opts) {
        my $opt_name = $opt->{long_name};
        if (not $items{$opt_name}
          || ($opt_name !~ /^no/
            ? $items{"no-$opt_name"}
            : false)
          || $opt->{deprecated})
        {
            push @options, $opt_name;
        }
    }

    local $" = "\n";
    print <<EOT;
Undocumented options
====================
@options
EOT
}

sub emit_undocumented_cmds
