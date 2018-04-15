
require Exporter;

our @ISA = qw( Exporter );

our %EXPORT_TAGS = (
	'funcs'    => [ qw( plugin_register plugin_unregister
	                    plugin_dispatch_values plugin_log ) ],
	'types'    => [ qw( TYPE_INIT TYPE_READ TYPE_WRITE TYPE_SHUTDOWN TYPE_LOG
	                    TYPE_DATASET ) ],
	'ds_types' => [ qw( DS_TYPE_COUNTER DS_TYPE_GAUGE ) ],
	'log'      => [ qw( LOG_ERR LOG_WARNING LOG_NOTICE LOG_INFO LOG_DEBUG ) ],
);

{
	my %seen;

	push @{$EXPORT_TAGS{'all'}}, grep {! $seen{$_}++ } @{$EXPORT_TAGS{$_}}
		foreach keys %EXPORT_TAGS;
}

Exporter::export_ok_tags('all');

bootstrap Collectd "4.1.2";

1;

