<p><?php print $newtasklink; ?></p>
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
            <td><? print $taskinfo['workloglink']; ?> | <? print $taskinfo['newtasklink']; ?> | <? print $taskinfo['editlink']; ?> | <? print $taskinfo['deletelink']; ?></td>
        </tr>
		<tr>
            <td colspan="6"><div id="<?php print $taskinfo['worklog_div']; ?>" class="worklogformcatcher"></div></td>
        </tr>
    <?php } ?>
    
</table>
<br/>
<div id="taskform"></div>