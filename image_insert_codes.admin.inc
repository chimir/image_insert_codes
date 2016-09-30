<?php

function image_insert_codes_admin_settings($form, $form_state){
  $form['image_insert_codes_code'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Image insert codes'),
    '#options' => array(
      1 => t('HTML full image'),
      2 => t('HTML clickable preview'),
      3 => t('BBCode full image'),
      4 => t('BBCode lickable preview'),
      5 => t('Picture URL'),
    ),
    '#default_value' => variable_get('image_insert_codes_code', array(1, 2, 3, 4, 5)),
  );

  $options = array();
  foreach (field_info_field_map() as $field_name => $field_info) {
    if ($field_info['type'] == 'image') {
      $options[$field_name] = $field_name;
    }
  }
  $form['image_insert_codes_field'] = array(
    '#type' => 'select',
    '#title' => t('Image field'),
    '#description' => t('Select the image field that will be used.'),
    '#options' => $options,
    '#default_value' => variable_get('image_insert_codes_field', 'field_image'),
  );

  $form['image_insert_codes_image_style'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#description' => t('Select the size of the image that will be used for preview.'),
    '#options' => image_style_options(),
    '#default_value' => variable_get('image_insert_codes_image_style', 'thumbnail'),
  );

  $form['image_insert_codes_collapsible'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show codes collapsible.'),
    '#default_value' => variable_get('image_insert_codes_collapsible', ''),
  );

  return system_settings_form($form);
}

