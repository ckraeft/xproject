<p><?php print $newtasklink; ?></p>
<table >
    <thead>
        <th>Task</th>
        <th>Status</th>
        <th>Team</th>
        <th>Imp.</th>
        <th>Pri.</th>
        <th>Progress</th>
        <th>Options</th>
    </thead>
    <?php foreach($tasklist as $taskinfo) { ?>
        <tr>
            <td><? print $taskinfo['taskname']; ?></td>
            <td><? print $taskinfo['taskstatus']; ?></td>
            <td><? print $taskinfo['assigned_to_contact']->title; ?></td>
            <td><? print $taskinfo['taskimportance']; ?></td>
            <td><? print $taskinfo['taskpriority']; ?></td>
            <td><? print $taskinfo['progress']; ?>% <? if($taskinfo['delta_progress']) print '('.$taskinfo['delta_progress'].')'; ?></td>
            <td><? print $taskinfo['workloglink']; ?> | <? print $taskinfo['newtasklink']; ?> | <? print $taskinfo['editlink']; ?> | <? print $taskinfo['deletelink']; ?></td>
        </tr>
		<tr>
            <td colspan="7"><div id="<?php print $taskinfo['worklog_div']; ?>" class="worklogformcatcher"></div></td>
        </tr>
    <?php } ?>
    
</table>
<br/>
<div id="taskform"></div>