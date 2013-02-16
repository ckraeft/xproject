<?php if($parentid == false) { ?>
    <p><?php print $newtasklink; ?></p>
<? } ?>
<?php if($parentid == false) { ?>
<table >
    <thead>
        <th class='taskHeader'>Task</th>
        <th class='taskHeader'>Status</th>
        <th class='taskHeader'>Team</th>
        <th class='taskHeader'>Imp.</th>
        <th class='taskHeader'>Pri.</th>
        <th class='taskHeader'>Progress</th>
        <th class='taskHeader'>Options</th>
    </thead>
<?php } ?>
    <?php foreach($tasklist as $taskinfo) { ?>
        <tr>
            <td class='<? if($parentid == false) { print 'taskName'; } else { print 'subtask'.$depth.'Name'; } ?>'><div><? print $taskinfo['taskname']; ?></div></td>
            <td class='taskStatus'><? print $taskinfo['taskstatus']; ?></td>
            <td class='taskAssignedTo'><? print $taskinfo['assigned_to_contact']->title; ?></td>
            <td class='taskImportance'><? print $taskinfo['taskimportance']; ?></td>
            <td class='taskPriority'><? print $taskinfo['taskpriority']; ?></td>
            <td class='taskProgress'><? print $taskinfo['progress']; ?> <? if($taskinfo['delta_progress']) print '('.$taskinfo['delta_progress'].')'; ?></td>
            <td class='taskOptions'><? print $taskinfo['workloglink']; ?> | <? print $taskinfo['newtasklink']; ?> | <? print $taskinfo['editlink']; ?> | <? print $taskinfo['deletelink']; ?></td>
        </tr>
		<tr>
            <td colspan="7">
                <div id="<?php print $taskinfo['worklog_div']; ?>" class="worklogformcatcher"></div>
                <div class="subtasks"><? print $taskinfo['subtasks']; ?></div>
            </td>
        </tr>
    <?php } ?>
    
<?php if($parentid == false) { ?>
</table>
    <br/>
    <div id="taskform"></div>
<?php } ?>
    