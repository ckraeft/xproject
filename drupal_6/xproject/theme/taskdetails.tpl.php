<?php
//
?>
<div id="taskDetailsPage">

<h3>Project: <a href="node/<? print $taskdetails['xprojectid']; ?>/tasklist"><? print $taskdetails['projectinfo']->title; ?></a></h3>

<h4>Task: <?php print $taskdetails['taskname']; ?></h4>
<!--
<fieldset>
    <legend><strong>Task Details</strong></legend>
    <div class="fieldset-wrapper"><div class="project-field-row">
        <div class="form-item">Status: <? print $taskdetails['taskstatus']; ?></div>
        
        <div class="form-item">Importance: <? print $taskdetails['taskimportance']; ?></div>
        
        <div class="form-item">Priority: <? print $taskdetails['taskpriority']; ?></div>
        <div class="clear"></div>
    </div>
</fieldset>
-->
<? if(!empty($taskdetails['taskdetails'])): ?>
    <fieldset>
        <legend><strong>Task Description</strong></legend>
            
        <div class="form-item"><? print (!empty($taskdetails['taskdetails']) ? $taskdetails['taskdetails'] : t('No task description.')); ?></div>
    </fieldset>
<? endif; ?>
<!--
<fieldset>
    <legend><strong>Advanced Options</strong></legend>
    
    <div class="fieldset-wrapper"><div class="project-field-row">
    
        <div class="form-item">Task Type: <? print $taskdetails['tasktype']; ?></div>
        
        <div class="form-item">Private: <? print ($taskdetails['taskprivate'] ? 'Yes' : 'No'); ?></div>
        <div class="clear"></div>
    </div></div>
    
    <? if($taskdetails['parent_taskid'] > 0): ?>
        <div class="form-item">Parent Task: <a href="<? print url('xtasks/'.$taskdetails['parent_taskid']); ?>"><? print $taskdetails['parent_taskinfo']['taskname']; ?></a></div>
    <? endif; ?>
    <? if($taskdetails['dependency_taskid'] > 0): ?>
        <div class="form-item">Depends on task: <a href="<? print url('xtasks/'.$taskdetails['dependency_taskid']); ?>"><? print $taskdetails['dependency_taskinfo']['taskname']; ?></a></div>
    <? endif; ?>
</fieldset>
-->
<fieldset>
    <legend><strong>Team Members</strong></legend>
    <div class="fieldset-wrapper"><div class="project-field-row">
    
        <div class="form-item">Task Owner: <? print $taskdetails['owner_contact']->title; ?></div>
    
        <div class="form-item">Assigned By: <? print $taskdetails['assigned_by_contact']->title; ?></div>
        
        <div class="form-item">Assigned To: <? print $taskdetails['assigned_to_contact']->title; ?></div>
        <div class="clear"></div>
    </div></div>
</fieldset>
<? if(!empty($taskdetails['date_approved']) 
    || !empty($taskdetails['planned_start_date']) 
    || !empty($taskdetails['planned_end_date']) 
    || !empty($taskdetails['actual_start_date']) 
    || !empty($taskdetails['actual_end_date'])):
?>
    <fieldset>
        <legend><strong>Task Dates</strong></legend>
        
        <div class="form-item">Date Approved: <? print $taskdetails['date_approved']; ?></div>
        
        <div class="fieldset-wrapper"><div class="project-field-row">
            <div class="form-item">Planned Start Date: <? print $taskdetails['planned_start_date']; ?></div>
            
            <div class="form-item">Planned End Date: <? print $taskdetails['planned_end_date']; ?></div>
            <div class="clear"></div>
        </div></div>
        <div class="fieldset-wrapper"><div class="project-field-row">
            <div class="form-item">Actual Start Date: <? print $taskdetails['actual_start_date']; ?></div>
            
            <div class="form-item">Actual End Date: <? print $taskdetails['actual_end_date']; ?></div>
            <div class="clear"></div>
        </div></div>
    </fieldset>
<? endif; ?>
<!--
<fieldset>
    <legend><strong>Task Hours</strong></legend>
    
    <div class="fieldset-wrapper"><div class="project-field-row">
        <div class="form-item">Hours Planned: <? print $taskdetails['hours_planned']; ?></div>
        
        <div class="form-item">Hours Spent: <? print $taskdetails['hours_spent']; ?></div>
        
        <div class="form-item">Hours Remaining: <? print $taskdetails['hours_remaining']; ?></div>
        <div class="clear"></div>
    </div></div>
</fieldset>
-->
<fieldset>
    <legend><strong>Worklog</strong></legend>
    
    <? print $taskdetails['worklog']; ?>

</div>