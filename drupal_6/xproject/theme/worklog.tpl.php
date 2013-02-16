<div id='workloglistpage'>
<table >
    <thead>
        <th>Hours</th>
        <th>Notes</th>
        <th>Date worked</th>
        <th>Creator</th>
    </thead>
    <?php foreach($worklog as $loginfo) { ?>
        <tr>
            <td><? print $loginfo['hours']; ?></td>
            <td><? print $loginfo['notes']; ?></td>
            <td><? print $loginfo['dateworked']; ?></td>
            <td><? print $loginfo['creator']; ?></td>
        </tr>
    <?php } ?>

</table>
<div id="addworklogform"><?php if ($worklog['show_addlog_form']){ echo  drupal_get_form('xworklog_form'); }?></div>
</div>