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
      'xproject_handler_filter_xproject_nid' => array(
        'parent' => 'views_handler_filter_many_to_one',
      ),
      'xproject_handler_filter_xproject_type_all' => array(
        'parent' => 'views_handler_filter',
      ),
      'xproject_handler_filter_xproject_type' => array(
        'parent' => 'views_handler_filter_node_type',
      ),
      'xproject_handler_filter_xproject_priority' => array(
        'parent' => 'views_handler_filter',
      ),
      'xproject_handler_filter_xproject_importance' => array(
        'parent' => 'views_handler_filter',
      ),
      'xproject_handler_filter_xproject_hours_remaining' => array(
        'parent' => 'views_handler_filter',
      ),
      // field
      'xproject_handler_field_xproject_tpl_projectid' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_is_template' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_status' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_importance' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_priority' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_is_private' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_hours_planned' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_hours_spent' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_hours_remaining' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_is_approved' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_planned_start' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_planned_end' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_actual_start' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_actual_end' => array(
        'parent' => 'views_handler_field_numeric',
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
	      'handler' => 'views_handler_filter_string',
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
	      'handler' => 'views_handler_filter_numeric',
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
	      'handler' => 'views_handler_filter_numeric',
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
	      'handler' => 'views_handler_filter_boolean_operator',
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
	);
	$data['xproject']['planned_start_date'] = array(
	    'title' => t('Planned Start Date'), 
	    'help' => t('Planned start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['planned_end_date'] = array(
	    'title' => t('Planned End Date'), 
	    'help' => t('Planned end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['actual_start_date'] = array(
	    'title' => t('Actual Start Date'), 
	    'help' => t('Actual start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['actual_end_date'] = array(
	    'title' => t('Actual End Date'), 
	    'help' => t('Actual end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
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
            'left_field' => 'xprojectid',
            'field' => 'nid',
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
	);
	$data['xtasks']['planned_start_date'] = array(
	    'title' => t('Planned Start Date'), 
	    'help' => t('Planned start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['planned_end_date'] = array(
	    'title' => t('Planned End Date'), 
	    'help' => t('Planned end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['actual_start_date'] = array(
	    'title' => t('Actual Start Date'), 
	    'help' => t('Actual start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['actual_end_date'] = array(
	    'title' => t('Actual End Date'), 
	    'help' => t('Actual end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
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
        'help' => t('Worklogs belonging to the Task'),
        'relationship' => array(
            'base' => 'xworklog',
            'base field' => 'logid',
            'handler' => 'views_handler_relationship',
            'label' => t('xTasks'),
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
	      'handler' => 'views_handler_filter_string',
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
	      'handler' => 'views_handler_filter_string',
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