<?php

// Budget Form

//Step 1
function Budget_StepOne( $record, $handler ) {
    $form_name = $record->get_form_settings( 'form_name' );

    if ( 'Budget_StepOne' !== $form_name ) {
        return;
    }

    $raw_fields = $record->get( 'fields' );
    $fields = [];
    foreach ( $raw_fields as $id => $field ) {
        $fields[ $id ] = $field['value'];
    }
	
	$args = array(
        'headers' => array(
            'Content-Type' => 'application/json'//,
            //'Authorization' => 'Bearer ' . $jwt_token
        ),
        'body' => json_encode($fields)
    );

    // Send json
    $response = wp_remote_post('https://webhook.site/ae1da893-bd43-42c8-80cf-101ae9bc2156', $args);

    // Check wether the request was successful
    if ( ! is_wp_error( $response ) && $response['response']['code'] === 200 ) {
        // Get id from api
        $id = wp_remote_retrieve_body( $response );

        // Start or resume session
        if ( ! session_id() ) {
            session_start();
        }

        // Save ID in session
        $id = 'xablaaaau';
        $_SESSION['form_id'] = $id;
    }
}
add_action( 'elementor_pro/forms/new_record', 'Budget_StepOne', 10, 2 );



//Step 2
function Budget_StepTwo( $record, $handler ) {
    $form_name = $record->get_form_settings( 'form_name' );

    if ( 'Budget_StepTwo' !== $form_name ) {
        return;
    }

    $raw_fields = $record->get( 'fields' );
    $fields = [];
    foreach ( $raw_fields as $id => $field ) {
        $fields[ $id ] = $field['value'];
    }
	
	
	// Start or resume session
        if ( ! session_id() ) {
            session_start();
        }
	
		$id = '';
		// Makes sure the ID is available in the session
		if (isset($_SESSION['form_id'])) {
			$id = $_SESSION['form_id'];
		}

			// Delete ID in session
			//unset($_SESSION['form_id']);
			
	
	$args = array(
        'headers' => array(
            'Content-Type' => 'application/json'//,
            //'Authorization' => 'Bearer ' . $jwt_token
        ),
        'body' => json_encode(array(
			'fields' => $fields,
			'id' => $id,
		))
    );
	
    // Send webhook
    $response = wp_remote_post('https://webhook.site/ae1da893-bd43-42c8-80cf-101ae9bc2156', $args);

    // Check wether the request was successful
    if ( ! is_wp_error( $response ) && $response['response']['code'] === 200 ) {

    }
}
add_action( 'elementor_pro/forms/new_record', 'Budget_StepTwo', 10, 2 );

?>