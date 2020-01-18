<?php
//$Id$
/**
*Implemets hook_schema
*/
function salonsdata_schema() {
$schema[‘salonsdata’] = array(
‘description’ => ‘TODO: please describe this table!’,
‘fields’ => array(
‘salonID’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘serial’,
‘not null’ => TRUE,
),
‘board’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘occupation’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘licensee’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘DBA’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘class’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘address1’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘address2’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘address3’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘city’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘state’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘zip’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘int’,
‘not null’ => TRUE,
),
‘county’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘licenseNum’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘status1’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘status2’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘dateLicensed’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘effectivedate’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘expirationdate’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘military’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘altenateLicenseNum’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘phone’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
’email’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘website’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘varchar’,
‘length’ => ’50’,
‘not null’ => TRUE,
),
‘userID’ => array(
‘description’ => ‘TODO: please describe this field!’,
‘type’ => ‘int’,
‘not null’ => TRUE,
),
),
‘primary key’ => array(‘salonID’),
);
return $schema;
}