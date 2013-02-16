<?php if($parentid == false) { ?>
    <p><?php print $newtasklink; ?></p>
    <div id="taskform"></div>
    <p><? print $team_msg; ?></p>
<? } ?>
<?php if($parentid == false) { ?>


    <div class="xtask_header_options">
        
        <? if($parentid == false) { ?>
            <fieldset>
                <legend><strong>Task Filter</strong></legend>
                <form id="task_filter" method="POST" action="<? echo $base_path.'node/'.$projectid.'/tasklist'; ?>">
                    <input type="checkbox" name="status_filter[]" value="Draft" onClick="document.task_filter.submit();" <? if(in_array('Draft', $status_filter)) echo 'checked'; ?> /> Draft
                    <input type="checkbox" name="status_filter[]" value="Pending" onClick="document.task_filter.submit();" <? if(in_array('Pending', $status_filter)) echo 'checked'; ?> /> Pending
                    <input type="checkbox" name="status_filter[]" value="Active" onClick="document.task_filter.submit();" <? if(in_array('Active', $status_filter)) echo 'checked'; ?> /> Active
                    <input type="checkbox" name="status_filter[]" value="Completed" onClick="document.task_filter.submit();" <? if(in_array('Completed', $status_filter)) echo 'checked'; ?> /> Completed
                    <input type="checkbox" name="status_filter[]" value="Archived" onClick="document.task_filter.submit();" <? if(in_array('Archived', $status_filter)) echo 'checked'; ?> /> Archived
                    <input type="submit" value="Filter" />
                </form>
            </fieldset>
        <? } ?>

<form method="POST" action="<? echo $base_path; ?>xtasks/bulkupdate?<? echo drupal_get_destination(); ?>">
        <select name="xtask_action">
            <option value="">Bulk Update Options</option>
            <option value="status_active">Status: Active</option>
            <option value="status_pending">Status: Pending</option>
            <? if(user_access('delete tasks')) { print '<option value="archive">Status: Archive</option>'; } ?>
            <option value="publish">Privacy: Public</option>
            <option value="private">Privacy: Private</option>
            <? if(user_access('delete tasks')) { print '<option value="delete">Delete</option>'; } ?>
            <!-- need options for deprioritizing and incr/decr the importance, as well as set privacy -->
        </select>
        <input type="submit" value="Update" onClick="return confirmBulkSubmit()" />
    </div>

<table class="xtask_list">
    <thead>
        <th class='taskHeader'>Task</th>
        <th class='taskHeader'>Status</th>
        <th class='taskHeader'>Owner</th>
        <? if($team_prefs['view_importance']): ?>
            <th class='taskHeader'>Imp.</th>
        <? endif; ?>
        <? if($team_prefs['view_priority']): ?>
            <th class='taskHeader'>Pri.</th>
        <? endif; ?>
        <? if($team_prefs['view_ratio']): ?>
            <th class='taskHeader'>Progress</th>
        <? endif; ?>
        <? if($team_prefs['view_due_date']): ?>
            <th class='taskHeader'>Due</th>
        <? endif; ?>
        <? if($team_prefs['view_hours_remaining']): ?>
            <th class='taskHeader'>Hrs</th>
        <? endif; ?>
        <th class='taskHeader'>Dep.</th>
        <th class='taskHeader'>Options</th>
    </thead>
<?php } ?>
    <?php foreach($tasklist as $taskinfo) { ?>
        <?  
            print '<tr class="'.$taskinfo['task_class'].' task'.$taskinfo['taskstatus'].'" style="background-color: '.$taskinfo['task_color'].';">';
        ?>
            <td class='<? if($parentid == false) { print 'taskName'; } else { print 'subtask'.$depth.'Name'; } ?>'><div><input type="checkbox" name="xtasklist[]" value="<? print $taskinfo['taskid']; ?>"><? print $taskinfo['num']; ?>) <a href="<? print $taskinfo['tasklink']; ?>" class="tasklink" rel="<? print $taskinfo['worklog_div']; ?>"><? print $taskinfo['taskname']; ?></a>
                <? if($taskinfo['has_attachment']) print '<img src="'.$base_path.'/sites/all/modules/xproject/images/16x16_attachment.png" />'; ?>
                </div>
            </td>
            <td class='taskStatus'><? print $taskinfo['taskstatus']; ?></td>
            <td class='taskAssignedTo'><? print $taskinfo['assigned_to_contact']->title; ?></td>
            <? if($team_prefs['view_importance']): ?>
                <td class='taskImportance'><? print $taskinfo['taskimportance']; ?></td>
            <? endif; ?>
            <? if($team_prefs['view_priority']): ?>
                <td class='taskPriority'><? print $taskinfo['taskpriority']; ?></td>
            <? endif; ?>
            <? if($team_prefs['view_ratio']): ?>
                <td class='taskProgress'><? print $taskinfo['progress']; ?> <? if($taskinfo['delta_progress']) print '('.$taskinfo['delta_progress'].')'; ?></td>
            <? endif; ?>
            <? if($team_prefs['view_due_date']): ?>
                <td class='taskDueDate'><? if(strtotime($taskinfo['planned_end_date']) > 0) print date('M d, Y', strtotime($taskinfo['planned_end_date'])); ?></td>
            <? endif; ?>
            <? if($team_prefs['view_hours_remaining']): ?>
                <td class='taskDueDate'><? if($taskinfo['hours_remaining'] > 0) print $taskinfo['hours_remaining']; ?></td>
            <? endif; ?>
            <td class='taskDependency'><? if($taskinfo['dependency_taskid']) print '('.$tasklist[$taskinfo['dependency_taskid']]['num'].')'; ?></td>
            <td class='taskOptions'><? print $taskinfo['expandlink'].$taskinfo['workloglink'].$taskinfo['newtasklink'].$taskinfo['editlink'].$taskinfo['deletelink']; ?></td>
        </tr>
        <?  
            print '<tr class="'.$taskinfo['task_class'].'">'; // style="background-color: '.$taskinfo['task_color'].';">';
        ?>
            <td colspan="9" class="task_description" id="subtasks<? print $taskinfo['taskid']; ?>">
                <? if($team_prefs['view_description']): ?>
                    <?php if(!empty($taskinfo['taskdetails'])): ?><blockquote><? print $taskinfo['taskdetails']; ?></blockquote><? endif; ?>
                <? endif; ?>
                <div id="<?php print $taskinfo['worklog_div']; ?>" class="worklogformcatcher"></div>
                <div class="subtasks"><? print $taskinfo['subtasks']; ?></div>
            </td>
        </tr>
    <?php } ?>
    
<?php if($parentid == false) { ?>
</table>
</form>
<?php } ?>
    