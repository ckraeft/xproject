<?php

/**
 * @file contactlog.tpl.php
 * Default theme implementation for contactlogs.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: Body of the post.
 * - $date: Date and time of posting.
 * - $links: Various operational links.
 * - $new: New contactlog marker.
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   contactlog-unpublished, contactlog-published or contactlog-preview.
 * - $submitted: By line with date and time.
 * - $title: Linked title.
 *
 * These two variables are provided for context.
 * - $contactlog: Full contactlog object.
 * - $node: Node object the contactlogs are attached to.
 *
 * @see template_preprocess_contactlog()
 * @see theme_contactlog()
 */
?>
<div class="contactlog<?php print ($contactlog->new) ? ' contactlog-new' : ''; print ' '. $status ?> clear-block">
  <?php print $picture ?>

  <h4><?php print $title ?></h4>

  <div class="submitted">
    <?php print $submitted ?>
  </div>

  <div class="content">
    <?php print $content ?>
  </div>

  <?php print $links ?>
</div>
