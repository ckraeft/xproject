
<table >
    <thead>
        <th>Task</th>
        <th>Task Status</th>
        <th>Task Approved on</th>
        <th>Edit Task</th>
        <th>Delete Task</th>
        <th>Worklogs</th>
    </thead>
    <?php foreach($tasklist as $taskinfo) { ?>
        <tr>
            <td><? print $taskinfo['taskname']; ?></td>
            <td><? print $taskinfo['taskstatus']; ?></td>
            <td><? print $taskinfo['date_approved']; ?></td>
            <td><? print $taskinfo['editlink']; ?></td>
            <td><? print $taskinfo['deletelink']; ?></td>
            <td><? print $taskinfo['workloglink']; ?></td>
        </tr>
    <?php } ?>
    <tr>
        <td>&nbsp;</td>
        <td colspan="5">
            <div id="<?php print $taskinfo['worklog_div']; ?>" ></div>
        </td>
    </tr>
</table>
<br/>
<div id="taskeditform"></div>