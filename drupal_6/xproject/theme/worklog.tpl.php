<div id='workloglistpage'>
    <div id="addworklogform"><?php echo  $worklogform; ?></div>
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
                <td><? print $loginfo['creatorname']; ?></td>
            </tr>
        <?php } ?>
    
    </table>
</div>