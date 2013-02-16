<h3>Project Information<?php if($node->private) { echo ' <span>[private]</span>'; } ?></h3>

<div class="project-field-row">
    <?php if($node->is_template): ?>
        <div class="">
            <label>Template:</label>
            <span>This project is a template; you may create new projects using this project as a base...</span>
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

<div class="">
    <label>Hours:</label>
    <span><?php echo $node->hours_planned; ?> planned</span>,
    <span><?php echo $node->hours_spent; ?> spent</span>,
    <span><?php echo $node->hours_remaining; ?> remaining</span>
</div>


<div class="">
    <label>Planned Dates:</label>
    <span>From <?php echo xproject_convert_date2string($node->planned_start_date); ?> to <?php echo xproject_convert_date2string($node->planned_end_date); ?></span>
</div>

<div class="">
    <label>Actual Dates:</label>
    <span>From <?php echo xproject_convert_date2string($node->actual_start_date); ?> to <?php echo xproject_convert_date2string($node->actual_end_date); ?></span>
</div>


        