<h3>Project Information<?php if($node->private) { echo ' <span>[private]</span>'; } ?></h3>

<div class="project-field-row">
    <?php if($node->is_template): ?>
        <div class="">
            <label>Template:</label>
            <span>This project is a template; you may <a href="http://www.miragelab.com/clients/doublehorn/node/add/xproject/<?php echo $node->nid; ?>">create new projects using this project</a> as a base...</span>
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
    <div class="">
        <label>Project Status:</label>
        <span><?php echo $node->projectstatus; ?>
            <? print $node->activate_project_button; ?>
            <? print $node->archive_project_button; ?>
        </span>
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

<div class="">
    <label>Hours:</label>
    <? if($node->hours_planned) echo '<span>'.$node->hours_planned.' planned</span>,'; ?>
    <? if($node->hours_spent) echo '<span>'.$node->hours_spent.' spent</span>,'; ?>
    <? if($node->hours_remaining) echo '<span>'.$node->hours_remaining.' remaining</span>'; ?>
</div>

<? if($node->planned_start_date || $node->planned_end_date): ?>
<div class="">
    <label>Planned Dates:</label>
    <span><?php echo xproject_convert_date2string($node->planned_start_date); ?> to <?php echo xproject_convert_date2string($node->planned_end_date); ?></span>
</div>
<? endif; ?>
<? if($node->actual_start_date || $node->actual_end_date): ?>
<div class="">
    <label>Actual Dates:</label>
    <span><?php echo xproject_convert_date2string($node->actual_start_date); ?> to <?php echo xproject_convert_date2string($node->actual_end_date); ?></span>
</div>
<? endif; ?>


        