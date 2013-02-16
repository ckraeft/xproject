<div id='xproject_templates_page'>
    <p><a href="/node/add/xproject">Create New Project Template</a></p>
    <table >
        <thead>
            <th>Template Project</th>
            <th>Hours Planned</th>
            <th>Planned Duration</th>
            <th>Options</th>
        </thead>
        <?php foreach($projectlist as $projectinfo) { ?>
            <tr>
                <td><a href="node/<? print $projectinfo['nid']; ?>"><? print $projectinfo['title']; ?></a></td>
                <td><? print $projectinfo['hours_planned']; ?></td>
                <td><? print $projectinfo['planned_duration']; ?></td>
                <td><? print $projectinfo['copylink']; ?> | <? print $projectinfo['editlink']; ?> | <? print $projectinfo['removelink']; ?></td>
            </tr>
        <?php } ?>
    
    </table>
</div>