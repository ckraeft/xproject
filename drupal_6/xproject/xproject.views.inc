<?php


/**
 * Implementation of hook_views_handlers().
 */
function xproject_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'xproject') .'/views',
    ),
    'handlers' => array(
      // filter
      'views_handler_filter_xproject_nid' => array(
        'parent' => 'views_handler_filter_many_to_one',
      ),
      'views_handler_filter_xproject_type_all' => array(
        'parent' => 'views_handler_filter',
      ),
      'views_handler_filter_xproject_type' => array(
        'parent' => 'views_handler_filter_node_type',
      ),
      'views_handler_filter_xproject_priority' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'views_handler_filter_xproject_importance' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'views_handler_filter_xproject_hours_remaining' => array(
        'parent' => 'views_handler_filter',
      ),
      'views_handler_filter_xproject_status' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      // field
      'views_handler_field_xproject_tpl_projectid' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'views_handler_field_xproject_is_template' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'views_handler_field_xproject_status' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'views_handler_field_xproject_importance' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'views_handler_field_xproject_priority' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'views_handler_field_xproject_is_approved' => array(
        'parent' => 'views_handler_field_numeric',
      ),

      'views_handler_filter_xcontact_company' => array(
        'parent' => 'views_handler_filter_many_to_one',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */

function xproject_views_data() {
  
	$data = array();
	$data['xproject']['table']['group'] = t('xProject');
	$data['xproject']['table']['join'] = array(
        'node' => array(
            'left_field' => 'nid',
            'field' => 'nid',
        ),
	);
    /*
	$data['xproject']['is_xproject'] = array(
	    'title' => t('Is Project'), 
	    'help' => t('Checks node type through xProject.'), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ),
	);
    */
    
	$data['xproject']['projectstatus'] = array(
	    'title' => t('Status'), 
	    'help' => t('Gives project status.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ), 
	    'filter' => array(
            'label' => t('Status'),
            'type' => 'yes-no',
	      'handler' => 'views_handler_filter_xproject_status',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
		),
	);
	$data['xproject']['priority'] = array(
	    'title' => t('Priority'), 
	    'help' => t('Priority of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_xproject_priority',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_numeric',
		),
	);
	$data['xproject']['importance'] = array(
	    'title' => t('Importance'), 
	    'help' => t('Importance of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_xproject_importance',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_numeric',
		),
	);
	$data['xproject']['private'] = array(
	    'title' => t('Private'), 
	    'help' => t('Privacy of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_boolean', 
	      'click sortable' => TRUE,
	    ), 
	    'filter' => array(
            'label' => t('Private'),
            'handler' => 'views_handler_filter_boolean_operator',
            'type' => 'yes-no',
	    ), 
	);
	$data['xproject']['hours_planned'] = array(
	    'title' => t('Hours Planned'), 
	    'help' => t('Hours planned for project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['hours_spent'] = array(
	    'title' => t('Hours Spent'), 
	    'help' => t('Hours spent on project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['hours_remaining'] = array(
	    'title' => t('Hours Remaining'), 
	    'help' => t('Hours remaining for completion of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['date_approved'] = array(
	    'title' => t('Date Approved'), 
	    'help' => t('Date project approved on.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
	$data['xproject']['planned_start_date'] = array(
	    'title' => t('Planned Start Date'), 
	    'help' => t('Planned start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
	$data['xproject']['planned_end_date'] = array(
	    'title' => t('Planned End Date'), 
	    'help' => t('Planned end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
	$data['xproject']['actual_start_date'] = array(
	    'title' => t('Actual Start Date'), 
	    'help' => t('Actual start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
	$data['xproject']['actual_end_date'] = array(
	    'title' => t('Actual End Date'), 
	    'help' => t('Actual end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
	$data['xproject']['progress'] = array(
	    'title' => t('Progress'), 
	    'help' => t('Project Progress.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_numeric',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_numeric',
        ),
	);
	$data['xproject']['is_template'] = array(
	    'title' => t('Progress'), 
	    'help' => t('Project Progress.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_boolean', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_boolean_operator',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_boolean_operator',
        ),
	);
    
    
	$data['xproject_team']['table']['group'] = t('xTeam');

    $data['xproject_team']['table']['base'] = array(
        'field' => 'contactid',
        'title' => t('xTeam'),
        'help' => t("Team members belonging to project."),
    );
	$data['xproject_team']['table']['join'] = array(
	    'title' => t('xProject'),
	    'help' => t("Team members in the xProjects module."),
	    'weight' => -10,
        'node' => array(
            'left_field' => 'nid',
            'field' => 'projectid',
        ),
	);
    $data['xproject_team']['contactid'] = array(
        'title' => t('xContact'),
        'help' => t('Contact records for team members'),
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
        'relationship' => array(
            'base' => 'xcontact',
            'base field' => 'contactid',
            'handler' => 'views_handler_relationship',
            'label' => t('xContact'),
        ),
    );
	$data['xproject_team']['team_member'] = array(
	    'title' => t('Team Member'), 
	    'help' => t('Project Team Member.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
    
    
	$data['xtasks']['table']['group'] = t('xTasks');

    $data['xtasks']['table']['base'] = array(
        'field' => 'taskid',
        'title' => t('xTasks'),
        'help' => t("Tasks belong to node content."),
    );
	$data['xtasks']['table']['join'] = array(
	    'title' => t('xTasks'),
	    'help' => t("Tasks in the xProjects module."),
	    'weight' => -10,
        'node' => array(
            'left_field' => 'nid',
            'field' => 'xprojectid',
        ),
	);
/*
	$data['xtasks']['table']['join'] = array(
	    'title' => t('Parent Task'),
	    'help' => t("Task this is a sub-task of."),
	    'weight' => -10,
        'node' => array(
            'left_field' => 'taskid',
            'field' => 'parent_taskid',
        ),
	);
*/

    $data['xtasks']['parent_taskid'] = array(
        'title' => t('Parent Task'),
        'help' => t('The task this task belongs to.'),
        'relationship' => array(
            'base' => 'xtasks',
            'base field' => 'taskid',
            'handler' => 'views_handler_relationship',
            'label' => t('xTasks'),
        ),
    );
    
    $data['xtasks']['dependency_taskid'] = array(
        'title' => t('Parent Task'),
        'help' => t('The task this task belongs to.'),
        'relationship' => array(
            'base' => 'xtasks',
            'base field' => 'taskid',
            'handler' => 'views_handler_relationship',
            'label' => t('xTasks'),
        ),
    );
    

    $data['xtasks']['xprojectid'] = array(
        'title' => t('xProject'),
        'help' => t('The node the task belongs to.'),
        'relationship' => array(
            'base' => 'node',
            'base field' => 'nid',
            'handler' => 'views_handler_relationship',
            'label' => t('Node'),
        ),
    );
    

    $data['xtasks']['taskid'] = array(
        'title' => t('xTasks'),
        'help' => t('Tasks belonging to the node'),
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
        'relationship' => array(
            'base' => 'xtasks',
            'base field' => 'taskid',
            'handler' => 'views_handler_relationship',
            'label' => t('xTasks'),
        ),
    );
	$data['xtasks']['taskname'] = array(
	    'title' => t('Task Name'), 
	    'help' => t('The name of the task.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
		),
	);
    
    
	$data['xtasks']['taskstatus'] = array(
	    'title' => t('Task Status'), 
	    'help' => t('Gives task status.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
		),
	);
	$data['xtasks']['owner'] = array(
	    'title' => t('Owner'), 
	    'help' => t('Who created the task.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_numeric',
		),
	);
	$data['xtasks']['assigned_to'] = array(
	    'title' => t('Assigned To'), 
	    'help' => t('Who the Task is assigned to.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_numeric',
		),
	);
	$data['xtasks']['taskpriority'] = array(
	    'title' => t('Priority'), 
	    'help' => t('Priority of Task.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_numeric',
		),
	);
	$data['xtasks']['taskimportance'] = array(
	    'title' => t('Importance'), 
	    'help' => t('Importance of task.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_numeric',
		),
	);
	$data['xtasks']['taskprivate'] = array(
	    'title' => t('Private'), 
	    'help' => t('Privacy of task.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_boolean', 
	      'click sortable' => TRUE,
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_boolean_operator',
	    ), 
	);
	$data['xtasks']['hours_planned'] = array(
	    'title' => t('Hours Planned'), 
	    'help' => t('Hours planned for project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['hours_spent'] = array(
	    'title' => t('Hours Spent'), 
	    'help' => t('Hours spent on project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['hours_remaining'] = array(
	    'title' => t('Hours Remaining'), 
	    'help' => t('Hours remaining for completion of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['date_approved'] = array(
	    'title' => t('Date Approved'), 
	    'help' => t('Date project approved on.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
	$data['xtasks']['planned_start_date'] = array(
	    'title' => t('Planned Start Date'), 
	    'help' => t('Planned start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
	$data['xtasks']['planned_end_date'] = array(
	    'title' => t('Planned End Date'), 
	    'help' => t('Planned end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
	$data['xtasks']['actual_start_date'] = array(
	    'title' => t('Actual Start Date'), 
	    'help' => t('Actual start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
	$data['xtasks']['actual_end_date'] = array(
	    'title' => t('Actual End Date'), 
	    'help' => t('Actual end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);
	$data['xtasks']['progress'] = array(
	    'title' => t('Progress'), 
	    'help' => t('Task Progress.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
	);

    
    
    
    
	$data['xworklog']['table']['group'] = t('xWorklog');

    $data['xworklog']['table']['base'] = array(
        'field' => 'logid',
        'title' => t('xWorklog'),
        'help' => t("Worklogs belonging to xTasks."),
    );
	$data['xworklog']['table']['join'] = array(
	    'title' => t('xWorklog'),
	    'help' => t("Tasks in the xProjects module."),
	    'weight' => -10,
        'node' => array(
            'left_field' => 'xtaskid',
            'field' => 'taskid',
        ),
	);
    

    $data['xworklog']['logid'] = array(
        'title' => t('xWorklog'),
        'help' => t('Worklogs ID'),
	    'field' => array(
	      'handler' => 'views_handler_field', 
	    ), 
    );
    $data['xworklog']['xtaskid'] = array(
        'title' => t('xTask'),
        'help' => t('Worklogs belonging to the Task'),
	    'field' => array(
	      'handler' => 'views_handler_field', 
	    ), 
        'relationship' => array(
            'base' => 'xtasks',
            'base field' => 'taskid',
            'handler' => 'views_handler_relationship',
            'label' => t('xTasks'),
        ),
    );
	$data['xworklog']['hours'] = array(
	    'title' => t('Hours'), 
	    'help' => t('Hours worked.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xworklog']['xcontactid'] = array(
	    'title' => t('Contact'), 
	    'help' => t('Work performed by.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	    ), 
	);
	$data['xworklog']['dateworked'] = array(
	    'title' => t('Date'), 
	    'help' => t('Date worked.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort_date',
	    ), 
	);
    
	$data['xworklog']['notes'] = array(
	    'title' => t('Worklog Notes'), 
	    'help' => t('Updates and details of the work performed.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_in_operator',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
		),
	);
    
	$data['xcontact']['table']['group'] = t('xContact');
	$data['xcontact']['table']['join'] = array(
        'node' => array(
            'left_field' => 'nid',
            'field' => 'nid',
        ),
	);
    /*
	$data['xproject']['is_xproject'] = array(
	    'title' => t('Is Project'), 
	    'help' => t('Checks node type through xProject.'), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ),
	);
    */
    
	$data['xcontact']['company'] = array(
	    'title' => t('Company'), 
	    'help' => t('The Company the contact works for.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_xcontact_company',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
		),
	);
    
	$data['xcontact']['alert_email'] = array(
	    'title' => t('Alert Email'), 
	    'help' => t('The email address that alerts for this contact will be sent to.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
		),
	);
    
	return $data;
}

?>