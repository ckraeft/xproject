<div id='teamlistpage'>
    <table >
        <thead>
            <th>Team Member</th>
            <th>Notifications</th>
            <th>Options</th>
        </thead>
        <?php foreach($teamlist as $teaminfo) { ?>
            <tr>
                <td><? print l($teaminfo['title'], 'node/'.$teaminfo['contactid']); ?></td>
                <td>
                    <?
                        $alerts = array();
                        if($teaminfo['instant_alerts']) $alerts[] = 'Instant';
                        if($teaminfo['daily_digest']) $alerts[] = 'Daily';
                        if($teaminfo['weekly_digest']) $alerts[] = 'Weekly';
                        if($teaminfo['monthly_digest']) $alerts[] = 'Monthly';
                        print implode(', ', $alerts);
                    ?>
                </td>
                <td><? print $teaminfo['editlink']; ?> | <? print $teaminfo['removelink']; ?></td>
            </tr>
        <?php } ?>
    
    </table>
    <?php echo  $newteamlink; ?>
    <div id="team_form"></div>
</div>