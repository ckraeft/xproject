<?php

?>
<div id="criticalpath_container">
    <table id="criticalpath">
        <tr>
            <? foreach($tasklist as $taskinfo) { ?>
                <td class="milestone">
                    <div class="taskName task_row_<? print strtolower($taskinfo['taskstatus']); ?>" style="background-color: <? print $taskinfo['task_color']; ?>"><a href="<? print url('xtasks/'.$taskinfo['taskid']); ?>"><? print $taskinfo['taskname']; ?></a></div>
                    <!--
                    <div class="taskDates"><? print $taskinfo['planned_start_date'].' - '.$taskinfo['planned_end_date']; ?></div>
                    <div class="taskHours"><? print $taskinfo['hours_planned']; ?> hrs</div>
                    <div class="taskDepartment"><? print $taskinfo['department']; ?></div>
                    <div class="taskOwner"><? print $taskinfo['owner']; ?></div>
                    -->
                    <? if(isset($taskinfo['subtasks'])): ?>
                        <table class="tasklist">
                            <tr>
                            <? foreach($taskinfo['subtasks'] as $subtaskinfo) { ?>
                                <td class="task">
                                    <div class="taskName task_row_<? print strtolower($subtaskinfo['taskstatus']); ?>" style="background-color: <? print $taskinfo['task_color']; ?>"><a href="<? print url('xtasks/'.$subtaskinfo['taskid']); ?>"><? print $subtaskinfo['taskname']; ?></a></div>
                                    <div class="taskDates"><strong><? if(strtotime($subtaskinfo['planned_start_date']) > 0) { $planned_start_date = explode(' ', $subtaskinfo['planned_start_date']); print date('y/m/d', strtotime($subtaskinfo['planned_start_date'])); } ?></strong> <em><? print $subtaskinfo['owner_name']; ?></em></div>
                               <!--     <div class="taskHours"><? print $subtaskinfo['hours_planned']; ?> hrs</div>
                                    <div class="taskDepartment"><? print $subtaskinfo['department']; ?></div>
                                    <div class="taskOwner"><? print $subtaskinfo['owner']; ?></div>
                               -->  
                                    <? print $subtaskinfo['department']; ?>
                                    <? if(isset($subtaskinfo['subtasks'])): ?>
                                        <ul class="subtasklist">
                                        <? foreach($subtaskinfo['subtasks'] as $subsubtaskinfo) { ?>
                                            <li class="subtask"><a href="<? print url('xtasks/'.$subsubtaskinfo['taskid']); ?>"><? print $subsubtaskinfo['taskname']; ?></a></li>
                                        <? } ?>
                                        </ul>
                                    <? endif; ?>
                                </td>                
                            <? } ?>
                            </tr>    
                        </table>
                    <? endif; ?>
                </td>
            <? } ?>
        </tr>
    </table>
</div>

    