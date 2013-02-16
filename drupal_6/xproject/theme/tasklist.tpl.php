
<table >
    <thead>
        <th>Task</th>
        <th>Task Status</th>
        <th>Task Approved on</th>
        <th>Options</th>
    </thead>
    <?php foreach($tasklist as $taskinfo) { ?>
        <tr>
            <td><? print $taskinfo['taskname']; ?></td>
            <td><? print $taskinfo['taskstatus']; ?></td>
            <td><? print $taskinfo['date_approved']; ?></td>
            <td><? print $taskinfo['editlink']; ?> | <? print $taskinfo['deletelink']; ?> | <? print $taskinfo['workloglink']; ?></td>
        </tr>
		<tr>
        <td>&nbsp;</td>
        <td colspan="5">
            <div id="<?php print $taskinfo['worklog_div']; ?>" ></div>
        </td>
    </tr>
    <?php } ?>
    
</table>
<br/>
<div id="taskeditform"></div>