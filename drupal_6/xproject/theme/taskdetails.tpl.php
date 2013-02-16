<?php
//
?>
<h4>Task: <?php print $taskdetails['taskname']; ?></h4>

<fieldset>
    <legend><strong>Task Details</strong></legend>
    
    <p>Status: <? print $taskdetails['taskstatus']; ?></p>
    
    <p>importance: <? print $taskdetails['taskimportance']; ?></p>
    
    <p>priority: <? print $taskdetails['taskpriority']; ?></p>
    
    <p>details: <? print $taskdetails['taskdetails']; ?></p>
</fieldset>

<fieldset>
    <legend><strong>Advanced Options</strong></legend>
    
    <p>tasktype: <? print $taskdetails['tasktype']; ?></p>
    
    <p>private: <? print $taskdetails['taskprivate']; ?></p>
    
    <p>Parent Task: <? print $taskdetails['status']; ?></p>
    
    <p>Depends on task: <? print $taskdetails['status']; ?></p>
</fieldset>

<fieldset>
    <legend><strong>Team Members</strong></legend>
    
    <p>owner: <? print $taskdetails['owner']; ?></p>
    
    <p>assigned_by: <? print $taskdetails['assigned_by']; ?></p>
    
    <p>assigned_to: <? print $taskdetails['assigned_to']; ?></p>
</fieldset>

<fieldset>
    <legend><strong>Task Dates</strong></legend>
    
    <p>Date Approved: <? print implode('-', $taskdetails['date_approved']); ?></p>
    
    <p>Planned Start Date: <? print implode('-', $taskdetails['planned_start_date']); ?></p>
    
    <p>Planned End Date: <? print implode('-', $taskdetails['planned_end_date']); ?></p>
    
    <p>Actual Start Date: <? print implode('-', $taskdetails['actual_start_date']); ?></p>
    
    <p>Actual End Date: <? print implode('-', $taskdetails['actual_end_date']); ?></p>
</fieldset>

<fieldset>
    <legend><strong>Task Hours</strong></legend>
    
    <p>Hours Planned: <? print $taskdetails['hours_planned']; ?></p>
    
    <p>Hours Spent: <? print $taskdetails['hours_spent']; ?></p>
    
    <p>Hours Remaining: <? print $taskdetails['hours_remaining']; ?></p>
</fieldset>

     