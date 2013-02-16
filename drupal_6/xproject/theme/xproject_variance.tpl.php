

<table>
    <tr>
        <th></th>
        <th><?php print $projectinfo->title; ?></th>
        <th><?php print $baseline_projectinfo->title; ?></th>
    </tr>
    <tr>
        <td>Status</th>
        <th><?php print $projectinfo->projectstatus; ?></th>
        <th><?php print $baseline_projectinfo->projectstatus; ?></th>
    </tr>
    <tr>
        <td>Importance</th>
        <th><?php print $projectinfo->importance; ?></th>
        <th><?php print $baseline_projectinfo->importance; ?></th>
    </tr>
    <tr>
        <td>Priority</th>
        <th><?php print $projectinfo->priority; ?></th>
        <th><?php print $baseline_projectinfo->priority; ?></th>
    </tr>
    <tr>
        <td>Planned Start Date</th>
        <th><?php print $projectinfo->planned_start_date; ?></th>
        <th><?php print $baseline_projectinfo->planned_start_date; ?></th>
    </tr>
    <tr>
        <td>Planned End Date</th>
        <th><?php print $projectinfo->planned_end_date; ?></th>
        <th><?php print $baseline_projectinfo->planned_end_date; ?></th>
    </tr>
    <tr>
        <td>Actual Start Date</th>
        <th><?php print $projectinfo->actual_start_date; ?></th>
        <th><?php print $baseline_projectinfo->actual_start_date; ?></th>
    </tr>
    <tr>
        <td>Actual End Date</th>
        <th><?php print $projectinfo->actual_end_date; ?></th>
        <th><?php print $baseline_projectinfo->actual_end_date; ?></th>
    </tr>
    <!-- need to include duration -->
    <!-- need to toggle between display of hours and days -->
    <tr>
        <td>Hours Planned</th>
        <th><?php print $projectinfo->hours_planned; ?></th>
        <th><?php print $baseline_projectinfo->hours_planned; ?></th>
    </tr>
    <tr>
        <td>Hours Spent</th>
        <th><?php print $projectinfo->hours_spent; ?></th>
        <th><?php print $baseline_projectinfo->hours_spent; ?></th>
    </tr>
    <tr>
        <td>Hours Remaining</th>
        <th><?php print $projectinfo->hours_remaining; ?></th>
        <th><?php print $baseline_projectinfo->hours_remaining; ?></th>
    </tr>
    <tr>
        <td>Total Tasks</th>
    </tr>
    <tr>
        <td>Tasks Added</th>
    </tr>
    <tr>
        <td>Tasks Removed</th>
    </tr>
    <tr>
        <td>Tasks Underestimated</th>
    </tr>
    <tr>
        <td>Tasks Rescheduled</th>
    </tr>
</table>
        
      
      
        