<?php

/**
 * Menu callback to load settings form.
 */
function xproject_admin_settings() {
    // content types
    $xproject_types = xproject_get_types();
    $is_configured = count($xproject_types);
    if (!$is_configured) {
        form_set_error('content_types_table', t('You must designate at least one content type to act as a project node and one to act as a contact node. <a href="!create">Create new content type</a> if needed.', array('!create' => url('admin/content/types/add', array('query' => drupal_get_destination())))));
    }
    
    if(!module_exists('content_access')) {
        drupal_set_message(t('The Content Access module was not detected. Published xProjects may be visible to anonymous visitors.'), 'status');
    }

    $form['display_settings'] = array(
        '#type' => 'fieldset', 
        '#title' => t('Task Display Settings'),
        '#description' => t('You may use words for colors (eg: red, lightgreen, darkblue) or hex color values. Prefix hex color values with a pound sign (#).'),
        '#collapsible' => true, 
        '#collapsed' => true,
    );
    
    $form['display_settings']['statuscolor_draft'] = array(
        '#type' => 'textfield', 
        '#title' => t('Draft Task Color'),
        '#default_value' => variable_get('statuscolor_draft', ''), 
//        '#description' => t(''),
        '#size' => 16,
    );
    
    $form['display_settings']['statuscolor_pending'] = array(
        '#type' => 'textfield', 
        '#title' => t('Pending Task Color'),
        '#default_value' => variable_get('statuscolor_pending', ''), 
//        '#description' => t(''),
        '#size' => 16,
    );
    
    $form['display_settings']['statuscolor_active'] = array(
        '#type' => 'textfield', 
        '#title' => t('Active Task Color'),
        '#default_value' => variable_get('statuscolor_active', ''), 
//        '#description' => t(''),
        '#size' => 16,
    );
    
    $form['display_settings']['statuscolor_warning'] = array(
        '#type' => 'textfield', 
        '#title' => t('Warning Task Color'),
        '#default_value' => variable_get('statuscolor_warning', ''), 
//        '#description' => t(''),
        '#size' => 16,
    );
    
    $form['display_settings']['statuscolor_completed'] = array(
        '#type' => 'textfield', 
        '#title' => t('Completed Task Color'),
        '#default_value' => variable_get('statuscolor_completed', ''), 
//        '#description' => t(''),
        '#size' => 16,
    );
    
    $form['display_settings']['statuscolor_archived'] = array(
        '#type' => 'textfield', 
        '#title' => t('Archived Task Color'),
        '#default_value' => variable_get('statuscolor_archived', ''), 
//        '#description' => t(''),
        '#size' => 16,
    );
    
    $form['display_settings']['statuscolor_pri1'] = array(
        '#type' => 'textfield', 
        '#title' => t('Priority 1 Task Color'),
        '#default_value' => variable_get('statuscolor_pri1', ''), 
//        '#description' => t(''),
        '#size' => 16,
    );
    
    $form['display_settings']['statuscolor_late'] = array(
        '#type' => 'textfield', 
        '#title' => t('Late Task Color'),
        '#default_value' => variable_get('statuscolor_late', ''), 
//        '#description' => t(''),
        '#size' => 16,
    );
    
    $form['default_settings'] = array(
        '#type' => 'fieldset', 
        '#title' => t('xProject Default Settings'),
        '#description' => t('These may be overridden at the project level.'),
        '#collapsible' => true, 
        '#collapsed' => false,
    );
    
    $result = db_query("SELECT * FROM {vocabulary} ORDER BY name");
    $voc_options = array(0 => t('Select a Taxonomy Vocabular'));
    while($row = db_fetch_array($result)) {
        $voc_options[$row['vid']] = $row['name'];
    }
    $form['default_settings']['xproject_departments_vid'] = array(
        '#type' => 'select',
        '#title' => t('Departments Vocabulary'),
        '#default_value' => variable_get('xproject_departments_vid', NULL),
        '#options' => $voc_options,
    );

	$form['default_settings']['xproject_default_projectstatus'] = array(
        '#type' => 'select', 
        '#title' => t('Default Project Status'), 
        '#default_value' => variable_get('xproject_default_projectstatus', 'Active'), 
        '#options' => array(
            'Draft' => t('Draft'), 
            'Pending' => t('Pending'), 
            'Active' => t('Active'),
            'On Hold' => t('On Hold'),
            'Completed' => t('Completed'),
            'Archived' => t('Archived'),
            'Baseline' => t('Baseline'),
        ), 
        '#description' => t('Status of project'),
        );
        
    $form['default_settings']['xproject_approve_project_to_start'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Approve Project to Start'), 
        '#default_value' => variable_get('xproject_approve_project_to_start', true), 
        '#description' => t('Require project to be "approved" in order to set actual start date and make tasks active, by default (can be overridden at the project level).'),
    );

	$form['default_settings']['xproject_default_status_workflow'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Use Project Status Workflow'), 
        '#default_value' => variable_get('xproject_default_status_workflow', 0), 
        '#options' => array(
            0 => t('No'),
            1 => t('Yes'),
        ), 
        '#description' => t('In Workflow mode, project Status can only be changed using status buttons by non-admins; the Status dropdown will not be available. Project Status Workflow is dependent on current status. Set the status for new projects using the default above.'),
        );

	$form['default_settings']['xproject_default_use_baselines'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Use Baseline Projects'), 
        '#default_value' => variable_get('xproject_default_use_baselines', 0), 
        '#options' => array(
            0 => t('No'),
            1 => t('Yes'),
        ), 
        '#description' => t('Projects requiring Approval will have their status set to Baseline when Activated and a copy of the project will be created that can then be further edited. Baseline projects cannot have their task details changed or receive worklog entries.'),
        );
        
    $form['default_settings']['xproject_default_importance'] = array(
        '#type' => 'select', 
        '#title' => t('Default Project Importance'), 
        '#default_value' => variable_get('xproject_default_importance', 5), 
        '#options' => array(
            1 => 1, 
            2 => 2, 
            3 => 3,
            4 => 4,
            5 => 5,
            6 => 6,
            7 => 7,
            8 => 8,
            9 => 9,
        ), 
        '#description' => t('New tasks will use the project importance as a default.'),
    );
    $form['default_settings']['xproject_default_priority'] = array(
        '#type' => 'select', 
        '#title' => t('Default Project Priority'), 
        '#default_value' => variable_get('xproject_default_priority', 5), 
        '#options' => array(
            1 => 1, 
            2 => 2, 
            3 => 3,
            4 => 4,
            5 => 5,
            6 => 6,
            7 => 7,
            8 => 8,
            9 => 9,
        ), 
        '#description' => t('New tasks will use the project priority as a default.'),
    );

	$form['default_settings']['xproject_default_cascade_priority'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Cascade Project Priority'), 
        '#default_value' => variable_get('xproject_default_cascade_priority', 0), 
        '#options' => array(
            0 => t('No'),
            1 => t('Yes'),
        ), 
        '#description' => t('Changes to project priority will also be applied to all active tasks in the project... should be used in conjunction with periodic automatic priority incrementing for active projects...'),
        );
        
    $form['default_settings']['xproject_warning_lead'] = array(
        '#type' => 'textfield', 
        '#title' => t('Warning Lead'), 
        '#default_value' => variable_get('xproject_warning_lead', 0), 
        '#description' => t('Days before planned end date that a task will trigger a warning status.'),
        '#size' => 2,
    );
    $form['default_settings']['xproject_enable_team'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Enable Project Teams'), 
        '#default_value' => variable_get('xproject_enable_team', true), 
        '#description' => t('Enable multiple contacts to participate in the same project and be assigned tasks.'),
    );
    $form['default_settings']['xproject_track_dates'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Track Dates'), 
        '#default_value' => variable_get('xproject_track_dates', true), 
        '#description' => t('Record planned and actual dates for projects, by default (can be overridden at the project level).'),
    );
    $form['default_settings']['xproject_hours_per_day'] = array(
        '#type' => 'textfield', 
        '#title' => t('Work Hours per Day'),
        '#default_value' => variable_get('xproject_hours_per_day', 8), 
        '#description' => t('Total working hours per day, by default (can be overridden at the project level).'),
        '#size' => 4,
    );
    $form['default_settings']['xproject_work_weekends'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Work Weekends'),
        '#default_value' => variable_get('xproject_work_weekends', true), 
        '#description' => t('Record planned and actual dates for projects, by default (can be overridden at the project level).'),
    );    
    $form['default_settings']['xproject_track_hours'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Track Hours'), 
        '#default_value' => variable_get('xproject_track_hours', true), 
        '#description' => t('Record hours planned, spent and remaining for projects, by default (can be overridden at the project level).'),
    );
    $form['default_settings']['xproject_show_hours_or_days'] = array(
        '#type' => 'select', 
        '#title' => t('Show Hours or Days'), 
        '#default_value' => variable_get('xproject_show_hours_or_days', 'Hours'), 
        '#options' => array(
            'Hours' => 'Hours',
            'Days' => 'Days',
        ),
        '#description' => t('Display hours or round into days for worklogs, task hours and project hours.'),
    );
    $form['default_settings']['xproject_approve_tasks_to_close'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Approve Tasks to Close'), 
        '#default_value' => variable_get('xproject_approve_tasks_to_close', true), 
        '#description' => t('Require tasks to be approved by their creator before they can be closed, by default (can be overridden at the project level).'),
    );
    $form['default_settings']['xproject_status_buttons'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Use status buttons instead of dropdowns'), 
        '#default_value' => variable_get('xproject_status_buttons', true), 
        '#description' => t('Force visitors to use buttonized workflow for projects.'),
    );
    $form['default_settings']['worklog_htmltable'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Display Worklogs using HTML tables'), 
        '#default_value' => variable_get('worklog_htmltable', false), 
//        '#description' => t('Require tasks to be approved by their creator before they can be closed, by default (can be overridden at the project level).'),
    );
    
    $form['default_settings']['cron_priorities'] = array(
        '#type' => 'checkbox', 
        '#title' => t('CRON Priorities'), 
        '#default_value' => variable_get('cron_priorities', false), 
        '#description' => t('Raise the priority of all tasks in projects without any priority 1 tasks during CRON.'),
    );
      
//    $form['default_settings']['default_importance'] = array();
//    $form['default_settings']['default_status'] = array();

      

    $form['content_types'] = array(
        '#type' => 'fieldset', 
        '#title' => t('xProject Content types'),
        '#description' => t('You may <a href="!create">create new content types</a> as needed. Note that you may have multiple types acting as projects and multiple types are allowed as contacts.', array('!create' => url('admin/content/types/add', array('query' => drupal_get_destination())))),
        '#collapsible' => true, 
        '#collapsed' => $is_configured,
    );
    $header = array(t('Type'), t('Operations'));
    $rows = array();
    
    foreach (node_get_types() as $type) {
        $type_url_str = str_replace('_', '-', $type->type);
        if(xproject_is_xproject($type)) {
            $type_status = 'xProject';
        } else {
            $type_status = '';
        }
        
        $rows[] = array(
            $type->name,
            $type_status,
            l(t('Edit'), "admin/content/node-type/$type_url_str", array('query' => drupal_get_destination()))  
        );
    }
    $form['content_types']['content_types_table'] = array('#value' => theme('table', $header, $rows));
    
    return system_settings_form($form);
}

function xproject_template_projects() {
    
    $sql = "SELECT a.nid FROM node a, xproject b WHERE b.nid = a.nid AND b.is_template = 1 ORDER BY a.title";
    
    $result = db_query($sql);
    
    $current_url = drupal_get_destination();
    
    $projectlist = array();
    while($row = db_fetch_array($result)) {
    
        $projectinfo = (array)node_load($row['nid']);
        

        $copy_url = 'node/add/xproject/' . $row['nid'] . '';
        $projectinfo['copylink'] = l('Copy', $copy_url);
              
        $edit_url = 'node/' . $row['nid'] . '/edit';
        $projectinfo['editlink'] = l('Edit', $edit_url, array(
                'query' => array(
                  'destination' => $current_url
                 )
            	 
              ));
        
        $delete_url = 'xproject/template/' . $row['nid'] . '/remove';
        $projectinfo['removelink'] = l('Remove', $delete_url, array(
                'query' => $current_url
            	 
              ));
        
        $projectlist[$row['nid']] = $projectinfo;
    
    
    }

    
    return theme('xproject_templates', $projectlist);
}

function xproject_template_remove($project_node) {

    $project_node->is_template = 0;
    node_save($project_node);
    $destination = $_REQUEST['destination'];
    
    drupal_goto($destination);

}

function xproject_report() {
    
    $sql = "SELECT a.nid FROM node a, xproject b WHERE b.nid = a.nid AND a.type = 'xproject' AND (b.projectstatus = '%s' OR b.projectstatus = '%s') ORDER BY a.title";
    
    $result = db_query($sql, 'Active', 'Pending');
    
    $projectlist = array();
    while($row = db_fetch_array($result)) {
        $projectinfo = node_load($row['nid']);
        $sql2 = "SELECT * FROM xtasks WHERE xprojectid = %d AND (taskstatus = 'Active' OR taskstatus = 'Pending') ORDER BY taskpriority, taskimportance LIMIT 1";
        $result2 = db_query($sql2, $row['nid']);
        if($row2 = db_fetch_array($result2)) {
            $row2['assigned_to_contact'] = node_load($row2['assigned_to']);
            $projectinfo->taskinfo = $row2;
            $sql3 = "SELECT a.* FROM xworklog a, xtasks b WHERE b.taskid = a.xtaskid AND b.xprojectid = %d ORDER BY datecreated DESC LIMIT 1";
            $result3 = db_query($sql3, $row['nid']);
            if($row3 = db_fetch_array($result3)) {
                $projectinfo->worklog = $row3;
            }
        }
        $projectlist[] = $projectinfo;
    }

    return theme('xproject_report', $projectlist);
}

?>