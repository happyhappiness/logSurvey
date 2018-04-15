				echo '<p class="error">Config error: RRDTOOL ('.htmlspecialchars(RRDTOOL).') is not executable</p>';
			?></div>
		</div></div>
		<input type="hidden" name="ge_graphid" id="ge_graphid" value="" />
		<table id="ge" class="toolbox" style="position: absolute; display: none; " cellspacing="1" cellpadding="0">
			<tr>
				<td class="c1" rowspan="3"><select id="ge_timespan" name="ge_timespan" onchange="GraphAdjust(null)"><?php
				foreach ($config['timespan'] as &$timespan)
					printf("\t\t\t\t\t\t<option value=\"%s\">%s</option>\n", htmlspecialchars($timespan['name']), htmlspecialchars($timespan['label']));
				?></select><br />
				<label><input id="ge_logarithmic"  name="ge_logarithmic" type="checkbox" value="1" onchange="GraphAdjust(null)" /> Logarithmic scale</label><br />
				<label><input id="ge_tinylegend"  name="ge_tinylegend" type="checkbox" value="1" onchange="GraphAdjust(null)" /> Minimal legend</label></td>
				<td class="c2"><a href="javascript:GraphMoveUp(null)"><img src="move-up.png" alt="UP" title="Move graph up"/></a></td>
			</tr>
			<tr>
				<td class="c2"><a href="javascript:GraphRefresh(null)"><img src="refresh.png" alt="R" title="Refresh graph"/></a>&nbsp;<a href="javascript:GraphRemove(null)"><img src="delete.png" alt="RM" title="Remove graph"/></a></td>
			</tr>
			<tr>
				<td class="c2"><a href="javascript:GraphMoveDown(null)"><img src="move-down.png" alt="DN" title="Move graph down"/></a></td>
			</tr>
		</table>
	</div></body>
</html><?php
}