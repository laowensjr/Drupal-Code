<?php
//$Id$
/**
* @file
* A module exemplifying Drupal coding practices and APIs.
* by Lawrence Owens
*/
/**
* Implements hook_help().
*/
function salonsdata_help($path, $arg) {
if ($path == ‘admin/help#salonsdata’) {
return t(‘A module that lets you work with salon data’);
}
}
/**
* Implements hook_menu().
*/
function salonsdata_menu() {
$items[‘admin/structure/salonsdata’] = array(
‘title’ => ‘Salons Data Title’,
‘description’ => ‘Find and manage Salons.’,
‘page callback’ => ‘drupal_get_form’,
‘page arguments’ => array(‘salonsdata_form’),
‘access callback’ => ‘salonsdata_permission’,
//’access arguments’ => array(‘access content),
‘weight’ => -10,
‘file’ => ‘salonsdata.admin.inc’,
);
return $items;
}
/**
* Implements hook_permission().
*/
function salonsdata_permission(){
return TRUE;
}