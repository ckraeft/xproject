<?php if($parentid == false) { ?>
    <p><?php print $newtasklink; ?></p>
    <div id="taskform"></div>
    <p><? print $team_msg; ?></p>
<? } ?>
<?php if($parentid == false) { ?>


    <div class="xtask_header_options">
        
        <? if($parentid == false) print $filter_form; ?>

<form method="POST" action="<? echo $base_path; ?>xtasks/bulkupdate?<? echo drupal_get_destination(); ?>" id="xtasks-bulkupdate-form">
        <select name="xtask_action">
            <option value="">Bulk Update Options</option>
            <option value="status_active">Status: Active</option>
            <option value="status_pending">Status: Pending</option>
            <option value="status_draft">Status: Draft</option>
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
                <td class='taskImportance'><span class="taskImportance_value"><? print $taskinfo['taskimportance']; ?></span>
                
                    <? print l(theme('image', 'misc/arrow-desc.png', t('+'), t('Increase Importance')), 'node/'.$taskinfo['xprojectid'].'/tasklist/'.$taskinfo['taskid'].'/incr_importance', array('html'=>TRUE, 'query' => drupal_get_destination())); ?>
                    <? print l(theme('image', 'misc/arrow-asc.png', t('-'), t('Decrease Importance')), 'node/'.$taskinfo['xprojectid'].'/tasklist/'.$taskinfo['taskid'].'/decr_importance', array('html'=>TRUE, 'query' => drupal_get_destination())); ?>
                    
                    <? //print $taskinfo['btn_imp_incr']; ?>
                    <? //print $taskinfo['btn_imp_decr']; ?>
                
                </td>
            <? endif; ?>
            <? if($team_prefs['view_priority']): ?>
                <td class='taskPriority'><span class="taskPriority_value"><? print $taskinfo['taskpriority']; ?></span>
                
                    <? print l(theme('image', 'misc/arrow-desc.png', t('+'), t('Increase Priority')), 'node/'.$taskinfo['xprojectid'].'/tasklist/'.$taskinfo['taskid'].'/incr_priority', array('html'=>TRUE, 'query' => drupal_get_destination())); ?>
                    <? print l(theme('image', 'misc/arrow-asc.png', t('-'), t('Decrease Priority')), 'node/'.$taskinfo['xprojectid'].'/tasklist/'.$taskinfo['taskid'].'/decr_priority', array('html'=>TRUE, 'query' => drupal_get_destination())); ?>
                </td>
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
            <td class='taskDependency'><? if($taskinfo['dependency_taskid']) print '('.$tasklist['taskid_'.$taskinfo['dependency_taskid']]['num'].')'; ?></td>
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
    