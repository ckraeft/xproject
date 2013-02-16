<?php


?>
<table id="xproject_report" border="1">
    <tr>
        <th>Project</th>
        <th>Priority Task</th>
        <th>Assigned To</th>
        <th>Latest Worklog</th>
        <th>Options</th>
    </tr>
    <?
    
    //    print_r($projectlist);
    
        foreach($projectlist as $projectinfo) {
            print '<tr>';
            print '<td>'.l($projectinfo->title, $projectinfo->path).'</td>';
            print '<td>'.l($projectinfo->taskinfo['taskname'], 'node/'.$projectinfo->nid.'/tasklist').'</td>';
            print '<td>'.$projectinfo->taskinfo['assigned_to_contact']->title.'</td>';
            print '<td>'.$projectinfo->worklog['notes'].'</td>';
        
        
        
        
        
        
            print '<td>'.l('Edit', 'node/'.$projectinfo->nid.'/edit').'</td>';
            print "</tr>\n";
        }
        
        
    ?>
</table>