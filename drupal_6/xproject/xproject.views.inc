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
	      'handler' => 'views_handler_filter_string',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
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
	      'handler' => 'views_handler_filter_string',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
		),
	);
	$data['xproject']['private'] = array(
	    'title' => t('Private'), 
	    'help' => t('Privacy of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ), 
	);
	$data['xproject']['hours_planned'] = array(
	    'title' => t('Hours planned'), 
	    'help' => t('Hours planned for project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['hours_spent'] = array(
	    'title' => t('Hours spent'), 
	    'help' => t('Hours spent on project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['hours_remaining'] = array(
	    'title' => t('Hours remaining'), 
	    'help' => t('Hours remaining for completion of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['date_approved'] = array(
	    'title' => t('Date approved'), 
	    'help' => t('Date project approved on.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['planned_start_date'] = array(
	    'title' => t('Planned start date'), 
	    'help' => t('Planned start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['planned_end_date'] = array(
	    'title' => t('Planned end date'), 
	    'help' => t('Planned end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['actual_start_date'] = array(
	    'title' => t('Actual start date'), 
	    'help' => t('Actual start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xproject']['actual_end_date'] = array(
	    'title' => t('Actual end date'), 
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
    'title' => t('Project'),
    'help' => t('The node the task belongs to.'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Node'),
    ),
  );
    
    
	$data['xtasks']['taskstatus'] = array(
	    'title' => t('Task status'), 
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
	$data['xtasks']['priority'] = array(
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
	      'handler' => 'views_handler_filter_string',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
		),
	);
	$data['xtasks']['importance'] = array(
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
	      'handler' => 'views_handler_filter_string',
	    ), 
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
		),
	);
	$data['xtasks']['private'] = array(
	    'title' => t('Private'), 
	    'help' => t('Privacy of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field', 
	      'click sortable' => TRUE,
	    ), 
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ), 
	);
	$data['xtasks']['hours_planned'] = array(
	    'title' => t('Hours planned'), 
	    'help' => t('Hours planned for project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['hours_spent'] = array(
	    'title' => t('Hours spent'), 
	    'help' => t('Hours spent on project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['hours_remaining'] = array(
	    'title' => t('Hours remaining'), 
	    'help' => t('Hours remaining for completion of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_numeric', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['date_approved'] = array(
	    'title' => t('Date approved'), 
	    'help' => t('Date project approved on.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['planned_start_date'] = array(
	    'title' => t('Planned start date'), 
	    'help' => t('Planned start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['planned_end_date'] = array(
	    'title' => t('Planned end date'), 
	    'help' => t('Planned end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['actual_start_date'] = array(
	    'title' => t('Actual start date'), 
	    'help' => t('Actual start date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);
	$data['xtasks']['actual_end_date'] = array(
	    'title' => t('Actual end date'), 
	    'help' => t('Actual end date of project.'), 
	    'field' => array(
	      'handler' => 'views_handler_field_date', 
	      'click sortable' => TRUE,
	    ), 
	);

	return $data;
}

?>