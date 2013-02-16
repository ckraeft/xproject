<fieldset><legend><strong>Project Information<?php if($node->private) { echo ' <span>[private]</span>'; } ?></legend>

<div class="project-field-row">
    <?php if($node->is_template): ?>
        <div class="">
            <label>Template:</label>
            <span>This project is a template; you may <a href="/node/add/xproject/<?php echo $node->nid; ?>">create new projects using this project</a> as a base...</span>
        </div>    
    <?php elseif($node->tpl_projectid): 
        $template_project = node_load($node->tpl_projectid);
    ?>
        <div class="">
            <label>Template:</label>
            <span><a href="<?php echo $template_project->path; ?>"><?php echo $template_project->title; ?></a></span>
        </div>    
    <?php endif; ?>
</div><div class="clear"></div>

<div class="project-field-row">
    <?php if($node->projectstatus == 'Baseline'): 
        $result = db_query('SELECT nid FROM xproject WHERE baseline_projectid = %d', $node->nid);
        $row = db_fetch_array($result);
        $actual_project = node_load($row['nid']);
    ?>
        <div class="">
            <label>Baseline For:</label>
            <span><a href="<?php echo $actual_project->path; ?>"><?php echo $actual_project->title; ?></a></span>
        </div>    
    <?php elseif($node->baseline_projectid > 0): 
        $baseline_project = node_load($node->baseline_projectid);
    ?>
        <div class="">
            <label>Baseline:</label>
            <span><a href="<?php echo $baseline_project->path; ?>"><?php echo $baseline_project->title; ?></a></span>
        </div>    
    <?php endif; ?>
</div><div class="clear"></div>

<div class="project-field-row">
    <div class="">
        <label>Project Status:</label>
        <span><?php echo $node->projectstatus; ?></span>
    </div>
    
    <div class="">
        <label>Importance:</label>
        <span><?php echo $node->importance; ?></span>
    </div>
    
    <div class="">
        <label>Priority:</label>
        <span><?php echo $node->priority; ?></span>
    </div>
</div><div class="clear"></div>
<? if($node->hours_planned > 0 || $node->hours_spent > 0 || $node->hours_remaining > 0): ?>
<div class="">
    <label>Hours:</label>
    <? if($node->hours_planned > 0) echo '<span>'.$node->hours_planned.' planned</span>,'; ?>
    <? if($node->hours_spent > 0) echo '<span>'.$node->hours_spent.' spent</span>,'; ?>
    <? if($node->hours_remaining > 0) echo '<span>'.$node->hours_remaining.' remaining</span>'; ?>
</div>
<? endif; ?>
<? $current_datetime = time(); ?>
<? if(strtotime($node->planned_start_date) > 0 || strtotime($node->planned_end_date) > 0): ?>
<div class="">
    <label>Planned Dates:</label>
    <? if(strtotime($node->planned_start_date) > 0 && strtotime($node->planned_end_date) > 0): ?>
        <span><?php echo $node->planned_start_date; ?> to <?php echo $node->planned_end_date; ?></span>
    <? elseif(strtotime($node->planned_start_date) > $current_datetime): ?>
        <span>Starting <?php echo $node->planned_start_date; ?></span>
    <? elseif(strtotime($node->planned_start_date) > 0): ?>
        <span>Started <?php echo $node->planned_start_date; ?></span>
    <? elseif(strtotime($node->planned_end_date) > $current_datetime): ?>
        <span>Ending <?php echo $node->planned_end_date; ?></span>
    <? elseif(strtotime($node->planned_end_date) > 0): ?>
        <span>Ended <?php echo $node->planned_end_date; ?></span>
    <? endif; ?>
</div>
<? endif; ?>
<? if(strtotime($node->actual_start_date) > 0 || strtotime($node->actual_end_date) > 0): ?>
<div class="">
    <label>Actual Dates:</label>
    <? if(strtotime($node->actual_start_date) > 0 && strtotime($node->actual_end_date) > 0): ?>
        <span><?php echo $node->actual_start_date; ?> to <?php echo $node->actual_end_date; ?></span>
    <? elseif(strtotime($node->actual_start_date) > $current_datetime): ?>
        <span>Starting <?php echo $node->actual_start_date; ?></span>
    <? elseif(strtotime($node->actual_start_date) > 0): ?>
        <span>Started <?php echo $node->actual_start_date; ?></span>
    <? elseif(strtotime($node->actual_end_date) > $current_datetime): ?>
        <span>Ending <?php echo $node->actual_end_date; ?></span>
    <? elseif(strtotime($node->actual_end_date) > 0): ?>
        <span>Ended <?php echo $node->actual_end_date; ?></span>
    <? endif; ?>
</div>
<? endif; ?>

    <? print $node->activate_project_button; ?>
    <? print $node->hold_project_button; ?>
    <? print $node->reactivate_project_button; ?>
    <? print $node->complete_project_button; ?>
    <? print $node->archive_project_button; ?>
            
</fieldset>
        