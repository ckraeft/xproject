<div id='workloglistpage'>
    <div id="addworklogform"><?php echo  $worklogform; ?></div>
    <?php $current_task = ''; ?>
    <?php foreach($worklog as $loginfo) { ?>
        <?php if(!empty($loginfo['taskname']) && $loginfo['taskname'] != $current_task) { $current_task = $loginfo['taskname']; ?>
            <div>Task: <strong><? print $loginfo['taskname']; ?></strong></div>
        <?php } ?>
        <div>
            <? print $loginfo['hours']; ?>hrs by <? print $loginfo['contact_title']; ?> on <? print $loginfo['dateworked']; ?> (recorded by <? print $loginfo['creatorname']; ?>)
            <a rel="xworklog_form_<? print $loginfo['logid']; ?>" href="<? print $loginfo['editlink']; ?>" class="xworklog_edit">Edit</a> | <a rel="xworklog_form_<? print $loginfo['logid']; ?>" href="<? print $loginfo['deletelink']; ?>" class="xworklog_delete">Delete</a>
        </div>
        <div id="xworklog_form_<? print $loginfo['logid']; ?>"></div>
        <?php if(!empty($loginfo['notes'])) { ?>
            <blockquote>
                <em><? print $loginfo['notes']; ?></em>
            </blockquote>
        <?php } ?>
    <?php } ?>
</div>