abc

    $form['xprojectid'] = array('#type' => 'hidden', '#value' => $projectinfo->nid);
    
    if($parentid) {
        $form['parent_taskid'] = array('#type' => 'hidden', '#value' => $parentid);
    }
    
    if($taskid == true) {
        $data = get_task_detail($taskid);
        $form['taskid'] = array(
            '#type' => 'hidden', 
            '#value' => $taskid,
        );
    }
    
    $form['task'] = array(
        '#type' => 'fieldset',
        '#title' => $taskid ? t('Edit Task') : t('Create Task'),
        '#collapsible' => false,
        '#collapsed' => false,
    );
    
    $form['task']['taskname'] = array(
        '#type' => 'textfield', 
        '#title' => t('Task Name'),
        '#default_value' => $data['taskname'], 
        '#required' => TRUE,
    );
    
    $form['task']['details'] = array(
        '#type' => 'fieldset',
        '#title' => 'Task Details',
        '#collapsible' => true,
        '#collapsed' => true,
    );
    
    if(!isset($projectinfo->projectstatus)) $projectinfo->projectstatus = variable_get('xproject_default_projectstatus', 'Active');
    if(!isset($projectinfo->importance)) $projectinfo->importance = variable_get('xproject_default_importance', 5);
    if(!isset($projectinfo->priority)) $projectinfo->priority = variable_get('xproject_default_priority', 5);
    if(!isset($projectinfo->show_hours_or_days)) $projectinfo->show_hours_or_days = variable_get('xproject_show_hours_or_days', 'Hours');
    
    $form['task']['details']['taskstatus'] = array(
        '#type' => 'select', 
        '#title' => t('Status'), 
        '#default_value' => (!$taskid ? $projectinfo->projectstatus : $data['taskstatus']), 
        '#options' => array(
            'Draft' => t('Draft'), 
            'Pending' => t('Pending'), 
            'Active' => t('Active'),
            'Completed' => t('Completed'),
            'Archived' => t('Archived'),
        ), 
        '#description' => t('Status of task'),
        '#prefix' => '<div class="project-field-row">',
    );
        
  	$form['task']['details']['taskimportance'] = array(
        '#type' => 'select', 
        '#title' => t('Importance'), 
        '#default_value' => (!$taskid ? $projectinfo->importance : $data['taskimportance']), 
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
        '#description' => t('Overall level of task importance'),
    );
  	$form['task']['details']['taskpriority'] = array(
        '#type' => 'select', 
        '#title' => t('Priority'), 
        '#default_value' => (!$taskid ? $projectinfo->priority : $data['taskpriority']), 
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
        '#description' => t('Current priority of the task'),
        '#suffix' => '<div class="clear"></div></div>',
    );
    
    $form['task']['details']['taskdetails'] = array(
        '#type' => 'textarea', 
        '#title' => 'Detailed Task Notes', 
        '#default_value' => $data['taskdetails'], 
        '#rows' => 5, 
    );
    
    
    $form['task']['details']['advanced'] = array(
        '#type' => 'fieldset',
        '#title' => t('Advanced Options'),
        '#collapsible' => true,
        '#collapsed' => true,
    );

    $form['task']['details']['advanced']['tasktype'] = array(
        '#type' => 'select', 
        '#title' => t('Type'), 
        '#default_value' => (!$taskid ? 'Task' : $data['taskstatus']), 
        '#options' => array(
            'Task' => t('Task'), 
            'Milestone' => t('Milestone'), 
            'Parent Task' => t('Parent Task'),
//            'ToDo' => t('ToDo'),
        ), 
        '#description' => t('Task type. (milestones have only a start date and no hours, parent tasks do not have their own hours and sub-tasks do not have their own dates)'),
    );
    
	$form['task']['details']['advanced']['taskprivate'] = array(
		'#type' =>'checkbox', 
		'#title' => t('Private'),
		'#default_value' => $data['taskprivate'],
        '#description' => t('Private tasks cannot be viewed by anyone but the task owner. Other team members may view private tasks in public projects.'),
    );
    $sibling_tasks = xtasks_get_tasklist($projectinfo->nid, $parentid, false);
    $task_options = array(0 => '-select task-');
    foreach($sibling_tasks as $sib_taskid => $sibling_task) {
        $task_options[$sib_taskid] = $sibling_task['taskname'];
    }
//    $sibling_tasks = xtasks_get_project_tasks($projectinfo->nid, $);
    if($taskid) unset($task_options[$taskid]);

    if(count($task_options) > 1) { // first option is 'none'
    	$form['task']['details']['advanced']['parent_taskid'] = array(
            '#type' => 'select', 
            '#title' => t('Parent Task'), 
            '#options' => $task_options,
    		'#default_value' => $data['parent_taskid'], 
            '#description' => t('The parent task selected will collect and summarize hours data for this task.'),
        );
    	$form['task']['details']['advanced']['dependency_taskid'] = array(
            '#type' => 'select', 
            '#title' => t('Depends on task'), 
            '#options' => $task_options,
    		'#default_value' => $data['dependency_taskid'], 
            '#description' => t('When the selected task is Completed, this task will become Active and the Actual Start Date will be set.'),
        );
    }
            
    $contactlist = xteam_get_all_contacts('companies', $projectinfo->nid);
    if(count($contactlist) > 0) {
        $form['task']['details']['teamlist'] = array(
            '#type' => 'fieldset',
            '#title' => t('Task Ownership'),
            '#collapsible' => true,
            '#collapsed' => true,
        );
        $form['task']['details']['teamlist']['owner'] = array(
            '#type' => 'select', 
            '#title' => t('Owner'), 
            '#options' => $contactlist,
    		'#default_value' => $taskid ? $data['owner'] : $user->xcontact, 
            '#description' => t('Who the task was requested by; who can approve the task to be closed.'),
            '#prefix' => '<div class="project-field-row">',
        );
    	$form['task']['details']['teamlist']['assigned_by'] = array(
            '#type' => 'select', 
            '#title' => t('Assigned by'), 
            '#options' => $contactlist,
    		'#default_value' => $taskid ? $data['assigned_by'] : $user->xcontact,
            '#description' => t('Who the task was last assigned by; who the task will be returned to for review.'),
        );
    	$form['task']['details']['teamlist']['assigned_to'] = array(
            '#type' => 'select', 
            '#title' => t('Assigned to'), 
            '#options' => $contactlist,
    		'#default_value' => $taskid ? $data['assigned_to'] : $user->xcontact, 
            '#description' => t('Who the task is currently assigned to.'),
            '#suffix' => '<div class="clear"></div></div>',
        );
    } else {
        if($projectinfo->enable_team) {
            $form['task']['details']['teamlist'] = array(
                '#type' => 'item',
                '#title' => t('Team Members'),
                '#value' => t('Please add some team members to the project for assigning tasks to'),
                '#description' => t('You may need to create contact records for your team members before you can add them.'),
            );
        }
    }        
    
    if($data['parent_taskid'] == false) {
        $form['task']['details']['task_dates'] = array(
            '#type' => 'fieldset',
            '#title' => t('Task Dates'),
            '#collapsible' => true,
            '#collapsed' => true,
        );
    	$form['task']['details']['task_dates']['date_approved'] = array(
    		'#type' => 'date', 
    		'#title' => 'Date Approved', 
    		'#default_value' => $data['date_approved'], 
    		'#description' => '',
        );
    	$form['task']['details']['task_dates']['planned_start_date'] = array(
    		'#type' => 'date', 
    		'#title' => 'Planned Start Date', 
    		'#default_value' => $data['planned_start_date'], 
    		'#description' => '',
            '#prefix' => '<div class="project-field-row">',
        );
    	$form['task']['details']['task_dates']['planned_end_date'] = array(
    		'#type' => 'date', 
    		'#title' => 'Planned End Date', 
    		'#default_value' => $data['planned_end_date'], 
    		'#description' => '',
            '#suffix' => '<div class="clear"></div></div>',
        );
    	$form['task']['details']['task_dates']['actual_start_date'] = array(
    		'#type' => 'date', 
    		'#title' => 'Actual Start Date', 
    		'#default_value' => $data['actual_start_date'], 
    		'#description' => '',
            '#prefix' => '<div class="project-field-row">',
        );
    	$form['task']['details']['task_dates']['actual_end_date'] = array(
    		'#type' => 'date', 
    		'#title' => 'Actual End Date', 
    		'#default_value' => $data['actual_end_date'], 
    		'#description' => '',
            '#suffix' => '<div class="clear"></div></div>', );	
    }
    
    if($data['ttlsubtasks'] == false) {
        $form['task']['details']['task_hours'] = array(
            '#type' => 'fieldset',
            '#title' => t('Task Hours'),
            '#collapsible' => true,
            '#collapsed' => true,
        );
        if($taskid == true) {
            $form['task']['details']['task_hours']['#description'] = t('Task hours will automatically be updated by worklog entries. Manually changing hours will not automatically be applied to parent tasks or projects.');
        } else {
            $form['task']['details']['task_hours']['#description'] = t('Hours remaining will default to hours planned if left blank.');
        }
    	$form['task']['details']['task_hours']['hours_planned'] = array(
    		'#type' => 'textfield', 
    		'#title' => t('Hours Planned'), 
    		'#default_value' =>$data['hours_planned'] , 
    		'#size' =>6 , 
    		'#maxlength' => 16,
            '#prefix' => '<div class="project-field-row">', );
    	$form['task']['details']['task_hours']['hours_spent'] = array(
    		'#type' => 'textfield', 
    		'#title' => t('Hours Spent'), 
    		'#default_value' => $taskid == true ? $data['hours_spent'] : 0,
    		'#size' =>6 , 
    		'#maxlength' => 16, );
    	$form['task']['details']['task_hours']['hours_remaining'] = array(
    		'#type' => 'textfield', 
    		'#title' => t('Hours Remaining'), 
    		'#default_value' =>$data['hours_remaining'] , 
    		'#size' =>6 , 
    		'#maxlength' => 16,
            '#suffix' => '<div class="clear"></div></div>', );	
    }
//    print_r($projectinfo);
    if($projectinfo->show_hours_or_days == 'Days') {
        $form['task']['details']['task_hours']['#title'] = t('Task Days');
    	$form['task']['details']['task_hours']['hours_planned']['#title'] = t('Days Planned');
    	$form['task']['details']['task_hours']['hours_spent']['#title'] = t('Days Spent');
    	$form['task']['details']['task_hours']['hours_remaining']['#title'] = t('Days Remaining');
    }
     