<h3>Contact Information</h3>
<?php if(!empty($node->company)) { ?>
    <div>
        <label>Company</label>
        <?php print $node->company; ?>
    </div>
<? } ?>
<?php if(!empty($node->alert_email)) { ?>
    <div>
        <label>Alert Email</label>
        <?php print $node->alert_email; ?>
    </div>
<? } ?>

