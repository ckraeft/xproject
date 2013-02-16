<h3>Contact Information</h3>
<?php if(!empty($node->company)) { ?>
    <div class="field">
        <div class="field-label-inline-first">Company</div>
        <?php print $node->company; ?>
    </div>
<? } ?>
<?php if(!empty($node->alert_email)) { ?>
    <div class="field">
        <div class="field-label-inline-first">Alert Email</div>
        <?php print $node->alert_email; ?>
    </div>
<? } ?>

