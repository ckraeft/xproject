<table id='workloglistpage'>
    <tr><td colspan="5"><div id="addworklogform"><?php echo  $worklogform; ?></div></td></tr>
    <tr>
        <th>Task / Worklog</th>
        <th>Hours</th>
        <th>Team</th>
        <th>Date</th>
        <th>User</th>
    </tr>
    <?php $current_task = ''; ?>
    <?php foreach($worklog as $loginfo) { ?>
        <tr>
            <td>
            <?php if(!empty($loginfo['taskname']) && $loginfo['taskname'] != $current_task) { $current_task = $loginfo['taskname']; ?>
                <? print $loginfo['taskname']; ?>
            <?php } ?>
            </td>
            <td><? print $loginfo['hours']; ?>hrs</td><td><? print $loginfo['contact_title']; ?></td><td><? print $loginfo['dateworked']; ?></td><td><? print $loginfo['creatorname']; ?></td>
        </tr>
        <?php if(!empty($loginfo['notes'])) { ?>
            <tr><td colspan="5">
                <em><? print $loginfo['notes']; ?></em>
            </td></tr>
        <?php } ?>
    <?php } ?>
</table>