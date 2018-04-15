	print("</response>");
}

function dhtml_response_graphs(&$graphs, $method) {
	header("Content-Type: text/xml");

	print('<?xml version="1.0" encoding="utf-8" ?>'."\n");
	print("<response>\n");
	printf(" <method>%s</method>\n", htmlspecialchars($method));
	print(" <result>\n");
	foreach ($graphs as &$graph)
		printf('  <graph host="%s" plugin="%s" plugin_instance="%s" type="%s" type_instance="%s" timespan="%s" logarithmic="%d" tinyLegend="%d" />'."\n",
		       htmlspecialchars($graph['host']), htmlspecialchars($graph['plugin']), htmlspecialchars($graph['pinst']),
		       htmlspecialchars($graph['type']), htmlspecialchars($graph['tinst']), htmlspecialchars($graph['timespan']),
		       htmlspecialchars($graph['logarithmic']), htmlspecialchars($graph['tinyLegend']));
	print(" </result>\n");
	print("</response>");
}

/**
 * Product page body with selection fields
 */
