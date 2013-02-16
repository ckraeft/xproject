<?php

/**
 * @file contactlog-wrapper.tpl.php
 * Default theme implementation to wrap contactlogs.
 *
 * Available variables:
 * - $content: All contactlogs for a given page. Also contains sorting controls
 *   and contactlog forms if the site is configured for it.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the contactlogs are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT_COLLAPSED
 *   - COMMENT_MODE_FLAT_EXPANDED
 *   - COMMENT_MODE_THREADED_COLLAPSED
 *   - COMMENT_MODE_THREADED_EXPANDED
 * - $display_order
 *   - COMMENT_ORDER_NEWEST_FIRST
 *   - COMMENT_ORDER_OLDEST_FIRST
 * - $contactlog_controls_state
 *   - COMMENT_CONTROLS_ABOVE
 *   - COMMENT_CONTROLS_BELOW
 *   - COMMENT_CONTROLS_ABOVE_BELOW
 *   - COMMENT_CONTROLS_HIDDEN
 *
 * @see template_preprocess_contactlog_wrapper()
 * @see theme_contactlog_wrapper()
 */
?>
<div id="contactlogs">
  <?php print $content; ?>
</div>
