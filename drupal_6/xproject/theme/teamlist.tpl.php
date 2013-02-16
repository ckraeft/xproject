<div id='teamlistpage'>
    <table >
        <thead>
            <th>Team Member</th>
            <th>Notifications</th>
            <th>Options</th>
        </thead>
        <?php foreach($teamlist as $teaminfo) { ?>
            <tr>
                <td><? print $teaminfo['title']; ?></td>
                <td><? print $options[$teaminfo['notification_freq']]; ?></td>
                <td><? print $teaminfo['editlink']; ?> | <? print $teaminfo['removelink']; ?></td>
            </tr>
        <?php } ?>
    
    </table>
    <div id="team_form"><?php echo  $newteamlink; ?></div>
</div>