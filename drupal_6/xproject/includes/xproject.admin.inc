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
    $form['default_settings'] = array(
        '#type' => 'fieldset', 
        '#title' => t('xProject Default Settings'),
        '#description' => t('These may be overridden at the project level.'),
        '#collapsible' => true, 
        '#collapsed' => false,
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
            'Archived' => t('Archived'),
        ), 
        '#description' => t('Status of project'),
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
    );
    $form['default_settings']['xproject_work_weekends'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Work Weekends'),
        '#default_value' => variable_get('xproject_work_weekends', true), 
        '#description' => t('Record planned and actual dates for projects, by default (can be overridden at the project level).'),
    );    
    $form['default_settings']['xproject_approve_project_to_start'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Approve Project to Start'), 
        '#default_value' => variable_get('xproject_approve_project_to_start', true), 
        '#description' => t('Require project to be "approved" in order to set actual start date and make tasks active, by default (can be overridden at the project level).'),
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
        
        $delete_url = 'node/' . $row['nid'] . '/delete';
        $projectinfo['deletelink'] = l('Delete', $delete_url, array(
                'query' => array(
                    'destination' => $current_url
                 )
            	 
              ));
        
        $projectlist[$row['nid']] = $projectinfo;
    
    
    }

    
    return theme('xproject_templates', $projectlist);
}

?>