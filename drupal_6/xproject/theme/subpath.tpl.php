<?php

?>
<? foreach($tasklist as $taskinfo) { ?>
    <div class="critical_task">
        <div class="taskName"><? print $taskinfo['taskname']; ?></div>
        <div class="taskDates"><? print $taskinfo['planned_start_date'].' - '.$taskinfo['planned_end_date']; ?></div>
        <div class="taskHours"><? print $taskinfo['hours_planned']; ?> hrs</div>
        <div class="taskDepartment"><? print $taskinfo['department']; ?></div>
        <div class="taskOwner"><? print $taskinfo['owner']; ?></div>

    </div>    
<? } ?>

    


    