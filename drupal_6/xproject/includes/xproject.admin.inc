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
