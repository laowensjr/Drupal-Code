<?php
/**
* @file
* Salon Data Administration
*/
function salonsdata_form($form, $form_state){
$form = array();
$header = array(
‘salonID’ => t(‘Salon ID’),
‘licensee’ => t(‘Licensee Name’),
‘dba’ => t(‘DBA’),
‘address1’ => t(‘Street Address’),
‘address2’ => t(‘Apt/Suite’),
‘city’ => t(‘City’),
‘state’ => t(‘State’),
‘zip’ => t(‘Zip’),
‘county’ => t(‘County’),
‘status1’ => t(‘License Status’),
‘status2’ => t(‘Operating Status’),
);
$orderby = ‘salonID’;
$orderMovement = ‘ASC’;
//$myzip = 32063;
$sql = db_select(‘salonsdata’, ‘sd’)->extend(‘PagerDefault’);
$sql
->fields(‘sd’, array(‘salonID’, ‘licensee’,’dba’, ‘address1’, ‘address2’, ‘city’, ‘state’, ‘zip’, ‘county’, ‘status1’, ‘status2’))
//->condition(‘zip’, $myzip, ‘LIKE’)
//->isNotNull(‘licensee’)
->orderBy($orderby, $orderMovement)
->limit(25);
$results = $sql->execute();

$rows = array();
foreach ($results as $result){
switch ($result->status2){
case ‘ ‘:
$result->status2 = ‘UNKNOWN’;
break;
case ‘Inactive’:
$result->status2 = ‘INACTIVE’;
break;
}
$rows[] = array(
‘salonID’ => $result->salonID,
‘licensee’ => $result->licensee,
‘dba’ => $result->dba,
‘address1’ => $result->address1,
‘address2’ => $result->address2,
‘city’ => $result->city,
‘state’ => $result->state,
‘zip’ => $result->zip,
‘county’ => $result->county,
‘status1’ => $result->status1,
‘status2’ => $result->status2,
‘#attributes’ => array(‘class’ => array(‘application-row’)),
);
}
$form[‘salonsdata_status’][‘listverifyeditsalon’] = array(
‘#type’ => ‘select’,
‘#title’ => ‘Actions’,
‘#options’ => array(
‘AllSalonsListedByCounty’ => t(‘List ALL Active Salons’),
‘ActiveSalonsByCounty’ => t(‘List Active Salons Listed by County’),
‘NonActive’ => t(‘List Non Active’),
‘Expired’ => t(‘List Expired Licensed Salons’),
‘PendingApproval’ => t(‘List Salons Needing Verification if Active’),
‘VerifiedActive’ => t(‘List Recently Verified Active Salons’),
‘VerifyOverride’ => t(‘VERIFY NOW Mark Salon Operation as Active’),
‘UNVerifyOverride’ => t(‘Mark Salon Operation as Inactive’),
‘VerifyUNKNOWN’ => t(‘MARK SALON Operation as UNKNOWN’),
‘EditSalon ‘ => t(‘Edit Salon Info’),
),
);
$form[‘salonsdata_salons’] = array(
‘#type’ => ‘tableselect’,
‘#header’ => $header,
‘#options’ => $rows,
‘#empty’ => t(‘No Salons Found’),
‘#attributes’ => array(‘class’ => array(‘salondata’)),
);
$form[‘pager’] = array(‘#markup’ => theme(‘pager’));
$form[‘submit’] = array(
‘#type’ => ‘submit’,
‘#value’ => t(‘Submit’),
);
return $form;
}
function salonsdata_form_submit($form, $form_state){
$action = $form_state[‘values’][‘listverifyeditsalon’];
$values = array();
foreach ($form_state[‘values’][‘salonsdata_salons’] as $key => $value) {
if(is_string($value) == TRUE){
$values[] = $form_state[‘complete form’][‘salonsdata_salons’][‘#options’][$value];
}
}
salonsdata_administration($action, $values);
}
function salonsdata_administration($action, $values){
switch($action){
case ‘AllSalonsListedByCounty’:

break;
case ‘ActiveSalonsByCounty’:
$sql->orderBy(‘county’, ‘ASC’);
break;
case ‘NonActive’:
$sql->orderBy(‘status2’, ‘ASC’);
break;
case ‘Expired’:
$sql->orderBy(‘county’, ‘ASC’);
break;
case ‘PendingApproval’:
$sql->orderBy(‘county’, ‘ASC’);
break;
case ‘VerifiedActive’:
$sql->orderBy(‘county’, ‘ASC’);
break;
case ‘VerifyOverride’:
$status = ‘Verified Active ‘;
foreach($values as $key => $value){
$salon_updated = db_update(‘salonsdata’)
->fields(array(‘status2’ => $status))
->condition(‘salonID’, $value[‘salonID’])
->execute();
watchdog(‘salonsdata’, t(“!licensee’s status was !status”,
array(‘!licensee’ => $value[‘licensee’], ‘!status’ => $status)));
}
break;
case ‘UNVerifyOverride’:
$status = ‘Un-Verified Active’;
foreach($values as $key => $value){
$salon_updated = db_update(‘salonsdata’)
->fields(array(‘status2’ => $status,))
->condition(‘salonID’,$value[‘salonID’])
->execute();
watchdog(‘salonsdata’, t(“!licensee’s status was !status”,
array(‘!licensee’ => $value[‘licensee’], ‘!status’ => $status)));
}
break;
case ‘VerifyUNKNOWN’:
$status = ‘UNKNOWN ACTIVE’;
foreach($values as $key => $value){
$salon_updated = db_update(‘salonsdata’)
->fields(array(‘status2’ => $status,))
->condition(‘salonID’,$value[‘salonID’])
->execute();
watchdog(‘salonsdata’, t(“!licensee’s status was !status”,
array(‘!licensee’ => $value[‘licensee’], ‘!status’ => $status)));
}
break;
case ‘EditSalon’:
$sql->orderBy(‘county’, ‘ASC’);
break;
}
}